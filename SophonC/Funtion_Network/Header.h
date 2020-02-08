#pragma once

#define HAVE_REMOTE

#define WPCAP

#include<pcap.h>

#pragma comment(lib,"winpcap/wpcap.lib")

#define OTHER 0

#define ARP 1
#define IPV4 2
#define IPV6 3

#define IGMP 4
#define ICMP 5
#define TCP 6
#define UDP 7
#define OSPF 8
#define EIGRP 9

#define FTP 10
#define SSH 11
#define TELNET 12
#define SMTP 13
#define DNS 14
#define DHCP 15
#define TFTP 16
#define HTTP 17
#define POP3 18
#define NTP 19
#define SNMP 20
#define SNMPTRAP 21
#define BGP 22
#define LDAP 23
#define HTTPS 24
#define KerberosV5 25
#define ISAKMP 26
#define SYSLOG 27
#define RIP 28
#define RADIUS 29
#define L2TP 30
#define RDP 31
#define NAT_T 32
#define OICQ 33
#define NBNS 34



struct ethhdr {
	u_char dest[6];
	u_char src[6];
	u_short type;
};


struct arphdr
{
	u_short ar_hrd;
	u_short ar_pro;
	u_char ar_hln;
	u_char ar_pln;
	u_short ar_op;
	u_char ar_srcmac[6];
	u_char ar_srcip[4];
	u_char ar_destmac[6];
	u_char ar_destip[4];
};

struct iphdr {

	u_char  ihl : 4;
	u_char version : 4;

	u_char tos;
	u_short tlen;
	u_short id;
	u_short frag_off;
	u_char ttl;
	u_char proto;
	u_short check;
	u_int saddr;
	u_int daddr;
	u_int	op_pad;
};

struct iphdr6 {
	u_int version : 4;
	u_int flowtype : 8;
	u_int flowid : 20;
	u_short plen;
	u_char nh;
	u_char hlim;
	u_short saddr[8];
	u_short daddr[8];
};

struct tcphdr
{
	u_short sport;
	u_short dport;
	u_int seq;
	u_int ack_seq;
	u_short res1 : 4;
	u_short doff : 4;
	u_short fin : 1;
	u_short syn : 1;
	u_short rst : 1;
	u_short psh : 1;
	u_short ack : 1;
	u_short urg : 1;
	u_short ece : 1;
	u_short cwr : 1;
	u_short window;
	u_short check;
	u_short urg_ptr;
	u_int opt;
};


struct udphdr
{
	u_short sport;
	u_short dport;
	u_short len;
	u_short check;
};
