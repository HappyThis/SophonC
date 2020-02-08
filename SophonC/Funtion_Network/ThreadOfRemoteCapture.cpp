#include "ThreadOfRemoteCapture.h"

ThreadOfRemoteCapture::ThreadOfRemoteCapture() :activeState(0) {

}

ThreadOfRemoteCapture::~ThreadOfRemoteCapture() {

}

void ThreadOfRemoteCapture::Stop() {

	(void)activeState.fetchAndStoreOrdered(0);
}

void ThreadOfRemoteCapture::ip4tos(u_long in, char * addressV4)
{
	u_char *p;

	p = (u_char*)&in;

	sprintf(addressV4, "%d.%d.%d.%d", p[0], p[1], p[2], p[3]);

	return;
}

void ThreadOfRemoteCapture::ip6tos(sockaddr * sockaddr, char * addressV6, int addrlen)
{

	socklen_t sockaddrlen;

#ifdef WIN32
	sockaddrlen = sizeof(struct sockaddr_in6);
#else
	sockaddrlen = sizeof(struct sockaddr_storage);
#endif


	if (getnameinfo(sockaddr,
		sockaddrlen,
		addressV6,
		addrlen,
		NULL,
		0,
		NI_NUMERICHOST) != 0) addressV6 = NULL;

	return;


}

void ThreadOfRemoteCapture::StartCap(QString ip) {

	bool suc = false;
	u_int netmask;
	struct bpf_program fcode;
	pcap_if_t *alldevs;
	char errbuf[PCAP_ERRBUF_SIZE];
	pcap_t *adhandle;
	struct pcap_pkthdr *header;
	const u_char *pkt_data;
	time_t local_tv_sec;
	struct tm *ltime;

	char source[50]{ '\0' };

	strcat(source, "rpcap://");
	strcat(source, ip.toStdString().data());
	strcat(source, "/adaptername");


	if (pcap_findalldevs_ex(source, NULL, &alldevs, errbuf) == -1) {
		fprintf(stderr, "Error in pcap_findalldevs_ex: %s\n", errbuf);
		return;
	}

	for (pcap_if_t *d = alldevs; d != NULL && !suc; d = d->next)
	{
		for (pcap_addr* t = d->addresses; t && !suc; t = t->next)
		{
			if (t->addr->sa_family != AF_INET) {

				continue;
			}
			char ipV4[4 * 3 + 3 + 1];
			ip4tos(((struct sockaddr_in *)t->addr)->sin_addr.s_addr, ipV4);

			if (strcmp(ipV4, ip.toStdString().data()) == 0)
			{
				qDebug() << "Adapter match succeeded";

				if ((adhandle = pcap_open(d->name,
					65536,
					PCAP_OPENFLAG_NOCAPTURE_RPCAP,
					1000,
					NULL,
					errbuf
				)) == NULL)
				{
					fprintf(stderr, "\nUnable to open the adapter. %s is not supported by WinPcap\n", d->name);

					pcap_freealldevs(d);
					return;
				}
				if (d->addresses != NULL)
					netmask = ((struct sockaddr_in *)(d->addresses->netmask))->sin_addr.S_un.S_addr;
				else
					netmask = 0xffffff;
				if (pcap_compile(adhandle, &fcode, "not port 1997", 1, netmask) < 0)
				{
					fprintf(stderr, "\nUnable to compile the packet filter. Check the syntax.\n");

					pcap_freealldevs(alldevs);

					return;
				}
				if (pcap_setfilter(adhandle, &fcode) < 0)
				{
					fprintf(stderr, "\nError setting the filter.\n");

					pcap_freealldevs(alldevs);
					return;
				}
				suc = true;

			}

		}
	}

	if (suc == false) {
		qDebug() << "No Mached!";
		return;
	}
	(void)activeState.fetchAndStoreOrdered(1);

	int res;

	QFile file(ip + "-" + "Captured.libpcap");

	if (file.exists()){
		file.remove();
	}

	pcap_dumper_t *dumpfile = pcap_dump_open(adhandle,(ip+"-"+"Captured.libpcap").toStdString().data());


	while ((res = pcap_next_ex(adhandle, &header, &pkt_data)) >= 0 ) {

		if (activeState.testAndSetOrdered(0, 0)) {
			
			break;
		}
		if (res == 0) {
			continue;
		}

		RCU = new RemoteCaptureUint();

		local_tv_sec = header->ts.tv_sec;

		ltime = localtime(&local_tv_sec);

		strftime(RCU->time, sizeof(RCU->time), "%H:%M:%S:", ltime);

		strcat(RCU->time, QString("%1").arg(header->ts.tv_usec).toStdString().data());

		RCU->lenth = header->len;

		AnalyzeEth(pkt_data);

		emit NewPacket(*RCU);

		delete RCU;

		pcap_dump((unsigned char *)dumpfile, header, pkt_data);

	}

}

void ThreadOfRemoteCapture::AnalyzeEth(const u_char * pkt) {

	struct ethhdr *ethh = (struct ethhdr *)pkt;

	switch (ntohs(ethh->type)) {

	case 0x0806: {
		/*
		* 分析ARP
		*/

		AnalyzeArp(pkt + sizeof(ethhdr));

		break;
	}
	case 0x0800: {
		/*
		* 分析IPV4
		*/
		AnalyzeIpV4(pkt + sizeof(ethhdr));

		break;
	}
	case 0x86dd: {
		/*
		* 分析IPV6
		*/
		AnalyzeIpV6(pkt + sizeof(ethhdr));

		break;
	}
	default: {

		/*其他*/

		strcpy(RCU->source, (const char*)ethh->src);

		strcpy(RCU->dest, (const char*)ethh->dest);

		RCU->protocol.append("OTHER");

	}
	}
}
void ThreadOfRemoteCapture::AnalyzeArp(const u_char * pkt) {

	struct arphdr* arph = (struct arphdr *)pkt;

	QString destip, srcip;

	for (int i = 0; i < 4; i++) {
		if (i == 3) {
			destip.append(QString::number(arph->ar_destip[i]));
			srcip.append(QString::number(arph->ar_srcip[i]));
		}
		else {
			destip.append(QString::number(arph->ar_destip[i]) + ".");
			srcip.append(QString::number(arph->ar_srcip[i]) + ".");
		}
	}

	strcpy(RCU->source, srcip.toStdString().data());

	strcpy(RCU->dest, destip.toStdString().data());

	RCU->protocol.append("ARP");

}
void ThreadOfRemoteCapture::AnalyzeIpV6(const u_char * pkt) {

	/*确定IPV6地址*/

	struct iphdr6 *ip6h = (iphdr6*)pkt;

	inet_ntop(AF_INET6, ip6h->daddr, RCU->dest, sizeof(RCU->dest));

	inet_ntop(AF_INET6, ip6h->saddr, RCU->source, sizeof(RCU->source));

	switch (ip6h->nh) {
		/*ICMPV6*/
	case 0x003a: {

		RCU->protocol.append("ICMPV6");

		break;
	}
				 /*IGMP*/
	case 0x0002: {

		RCU->protocol.append("IGMP");
		break;
	}
				 /*TCP*/
	case 0x0006: {

		AnalyzeTcp(pkt + 40);
		break;
	}
				 /*UDP*/
	case 0x0011: {

		AnalyzeUdp(pkt + 40);
		break;
	}
				 /*OSPF*/
	case 0x0059: {

		RCU->protocol.append("OSPF");

		break;
	}
				 /*EIGRP*/
	case 0x0058: {

		RCU->protocol.append("EIGRP");


		break;
	}
	default: {
		RCU->protocol.append("IPV6");
	}
	}
}

void ThreadOfRemoteCapture::AnalyzeIpV4(const u_char * pkt) {


	/*确定IPv4地址*/
	struct iphdr *iph = (iphdr*)pkt;

	inet_ntop(AF_INET, (const void*)&iph->daddr, RCU->dest, sizeof(RCU->dest));

	inet_ntop(AF_INET, (const void*)&iph->saddr, RCU->source, sizeof(RCU->source));

	int iplen = iph->ihl * 4;

	switch (iph->proto)
	{
		/*IGMP*/
	case 0x0002: {

		RCU->protocol.append("IGMP");


		break;
	}
				 /*ICMP*/
	case 0x0001: {

		RCU->protocol.append("ICMP");


		break;
	}
				 /*TCP*/
	case 0x0006: {

		AnalyzeTcp(pkt + iplen);

		break;
	}
				 /*UDP*/
	case 0x0011: {

		AnalyzeUdp(pkt + iplen);

		break;
	}
				 /*OSPF*/
	case 0x0059: {

		RCU->protocol.append("OSPF");
		break;
	}
				 /*EIGRP*/
	case 0x0058: {
		RCU->protocol.append("EIGRP");


		break;
	}

	default: {
		RCU->protocol.append("IPV4");


		/*统计结束*/

	}
	}

}

void ThreadOfRemoteCapture::AnalyzeTcp(const u_char * pkt) {

	struct tcphdr *tcph = (struct tcphdr*)pkt;

	tcph->dport = ntohs(tcph->dport);


	tcph->sport = ntohs(tcph->sport);

	if (tcph->dport == 20 || tcph->sport == 20 || tcph->dport == 21 || tcph->sport == 21) {


		RCU->protocol.append("FTP");

	}
	else if (tcph->dport == 22 || tcph->sport == 22) {

		RCU->protocol.append("SSH");


	}
	else if (tcph->dport == 23 || tcph->sport == 23) {

		RCU->protocol.append("TELNET");


	}
	else if (tcph->dport == 25 || tcph->sport == 25) {

		RCU->protocol.append("SMTP");


	}
	else if (tcph->dport == 53 || tcph->sport == 53) {

		RCU->protocol.append("DNS");


	}
	else if (tcph->dport == 68 || tcph->sport == 68) {

		RCU->protocol.append("DHCP");


	}
	else if (tcph->dport == 80 || tcph->sport == 80) {
		RCU->protocol.append("HTTP");


	}
	else if (tcph->dport == 110 || tcph->sport == 110) {
		RCU->protocol.append("POP3");

	}
	else if (tcph->dport == 179 || tcph->sport == 179) {
		RCU->protocol.append("BGP");


	}
	else if (tcph->dport == 443 || tcph->sport == 443) {
		RCU->protocol.append("HTTPS");


	}
	else if (tcph->dport == 464 || tcph->sport == 464) {
		RCU->protocol.append("KerberosV5");


	}
	else if (tcph->dport == 514 || tcph->sport == 514) {

		RCU->protocol.append("SYSLOG");

	}
	else if (tcph->dport == 3389 || tcph->sport == 3389) {

		RCU->protocol.append("RDP");
	}
	else {
		RCU->protocol.append("TCP");
	}
}

void ThreadOfRemoteCapture::AnalyzeUdp(const u_char * pkt) {

	struct udphdr* udph = (struct udphdr*)pkt;

	udph->dport = ntohs(udph->dport);

	udph->sport = ntohs(udph->sport);


	if (udph->dport == 53 || udph->sport == 53) {

		RCU->protocol.append("DNS");
	}
	else if (udph->dport == 67 || udph->sport == 67) {

		RCU->protocol.append("DHCP");
	}
	else if (udph->dport == 69 || udph->sport == 69) {
		RCU->protocol.append("TFTP");
	}
	else if (udph->dport == 123 || udph->sport == 123) {
		RCU->protocol.append("NTP");
	}
	else if (udph->dport == 161 || udph->sport == 161) {
		RCU->protocol.append("SNMP");
	}
	else if (udph->dport == 162 || udph->sport == 162) {
		RCU->protocol.append("SNMPTRAP");
	}
	else if (udph->dport == 389 || udph->sport == 389) {
		RCU->protocol.append("LDAP");
	}
	else if (udph->dport == 500 || udph->sport == 500) {
		RCU->protocol.append("ISAKMP");
	}
	else if (udph->dport == 520 || udph->sport == 520) {
		RCU->protocol.append("RIP");
	}
	else if (udph->dport == 1812 || udph->sport == 1812 || udph->dport == 1813 || udph->sport == 1813) {
		RCU->protocol.append("RADIUS");
	}
	else if (udph->dport == 1701 || udph->sport == 1701) {
		RCU->protocol.append("L2TP");
	}
	else if (udph->dport == 4500 || udph->sport == 4500) {
		RCU->protocol.append("NAT_T");
	}
	else if (udph->dport == 8000 || udph->sport == 8000) {
		RCU->protocol.append("OICQ");
	}
	else if (udph->dport == 137 || udph->sport == 137) {
		RCU->protocol.append("NBNS");
	}
	else {
		RCU->protocol.append("UDP");
	}

}
