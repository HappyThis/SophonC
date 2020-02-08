#include "NetworkServer.h"


NetworkServer::NetworkServer(Linker * arg) :BasisFunction(arg) {

	ui.setupUi(this);

	resize(1400, 600);

	QObject::connect(ui.QTW, SIGNAL(tabBarClicked(int)), this, SLOT(GetNewInfo(int)));

	setWindowTitle(QString(arg->ip) + "---" + "网络分析");

	// create chart
	chartOfProtocol = new QChart();

	chartOfProtocol->setTitle("各协议占比");

	chartOfProtocol->setAnimationOptions(QChart::AllAnimations);

	// create series
	seriesOfProtocol = new QPieSeries();
	seriesOfProtocol->setLabelsVisible();
	chartOfProtocol->addSeries(seriesOfProtocol);
	// create chart view
	QChartView* m_chartView = new QChartView(chartOfProtocol);

	QVBoxLayout *settingsLayout = new QVBoxLayout();

	settingsLayout->addWidget(m_chartView);

	ui.Q1->setLayout(settingsLayout);

	m_chartView->show();


	ipConter = new QBarSet("IP");

	seriesOfIp = new QBarSeries();

	seriesOfIp->append(ipConter);

	chartOfIp = new QChart();

	chartOfIp->addSeries(seriesOfIp);

	chartOfIp->setTitle("IP访问统计");

	chartOfIp->setAnimationOptions(QChart::SeriesAnimations);


	axis = new QBarCategoryAxis();

	chartOfIp->createDefaultAxes();

	chartOfIp->setAxisX(axis, seriesOfIp);

	chartOfIp->legend()->setVisible(false);

	chartOfIp->legend()->setAlignment(Qt::AlignBottom);

	QChartView *chartView = new QChartView(chartOfIp);

	chartView->setRenderHint(QPainter::Antialiasing);

	QGridLayout *settingsLayoutG = new QGridLayout();

	settingsLayoutG->addWidget(chartView, 0, 1);

	table = new QTableWidget(ui.Q2);

	table->setColumnCount(5);

	table->horizontalHeader()->setSectionsClickable(false);

	table->horizontalHeader()->setStretchLastSection(true);
	
	table->verticalHeader()->setDefaultSectionSize(10);
	table->setFrameShape(QFrame::NoFrame);
	table->setShowGrid(false);
	table->setSelectionBehavior(QAbstractItemView::SelectRows);
	table->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

	QStringList header;

	header << "IP" << "访问次数" << "开始时间" << "结束时间" << "主要协议";

	table->setHorizontalHeaderLabels(header);


	settingsLayoutG->addWidget(table, 0, 0);

	ui.Q2->setLayout(settingsLayoutG);

	chartView->show();

	//![1]
	seriesOfIo = nullptr;
	//![1]

	//![2]
	chartOfIo = new QChart();

	chartOfIo->legend()->hide();

	chartOfIo->setTitle("网络数据IO");

	//![4]
	QChartView *chartView1 = new QChartView(chartOfIo);
	chartView1->setRenderHint(QPainter::Antialiasing);
	settingsLayout = new QVBoxLayout();
	settingsLayout->addWidget(chartView1);
	ui.Q3->setLayout(settingsLayout);
	chartView1->show();
}

NetworkServer::~NetworkServer() {

	qDebug() << "Close a new function";

	Send(new SendInfo(CommandCloseNetworkServer));

}
QString NetworkServer::Distinguish(int Number)
{
	switch (Number) {
	case 0:
		return QString("OTHER");
	case 1:
		return QString("ARP");
	case 2:
		return QString("IPV4");
	case 3:
		return QString("IPV6");
	case 4:
		return QString("IGMP");
	case 5:
		return QString("ICMP");
	case 6:
		return QString("TCP");
	case 7:
		return QString("UDP");
	case 8:
		return QString("OSPF");
	case 9:
		return QString("EIGRP");
	case 10:
		return QString("FTP");
	case 11:
		return QString("SSH");
	case 12:
		return QString("TELNET");
	case 13:
		return QString("SMTP");
	case 14:
		return QString("DNS");
	case 15:
		return QString("DHCP");
	case 16:
		return QString("TFTP");
	case 17:
		return QString("HTTP");
	case 18:
		return QString("POP3");
	case 19:
		return QString("NTP");
	case 20:
		return QString("SNMP");
	case 21:
		return QString("SNMPTRAP");
	case 22:
		return QString("BGP");
	case 23:
		return QString("LDAP");
	case 24:
		return QString("HTTPS");
	case 25:
		return QString("KerberosV5");
	case 26:
		return QString("ISAKMP");
	case 27:
		return QString("SYSLOG");
	case 28:
		return QString("RIP");
	case 29:
		return QString("RADIUS");
	case 30:
		return QString("L2TP");
	case 31:
		return QString("RDP");
	case 32:
		return QString("NAT_T");
	case 33:
		return QString("OICQ");
	case 34:
		return QString("NBNS");
	default:
		break;
	}
	return QString();
}
void NetworkServer::ProcInfo(Token token, QByteArray data, Linker* linker) {

	switch (token) {

	case CommandGetIp: {

		int size = data.size() / sizeof(IpContainerUnit);

		IpContainerUnit  *arrayOfIpInfo = new IpContainerUnit[size];

		CopyMemory(arrayOfIpInfo, data.data(), data.size());

		QStringList categories;

		seriesOfIp->remove(ipConter);

		chartOfIp->removeSeries(seriesOfIp);

		chartOfIp->removeAxis(axis);

		int RowCont0 = table->rowCount();

		for (int i = 0; i <= RowCont0; i++) {

			table->removeRow(0);

		}
		seriesOfIp = new QBarSeries();

		ipConter = new QBarSet("IP");

		for (int i = 0; i < size; i++) {

			ipConter->append(arrayOfIpInfo[i].conter);

			categories.append(QString::number(i + 1));

			int RowCont1 = table->rowCount();

			table->insertRow(RowCont1);

			QTableWidgetItem* Item;

			Item = new QTableWidgetItem(QString(arrayOfIpInfo[i].ip));

			Item->setTextAlignment(Qt::AlignCenter);

			table->setItem(RowCont1, 0,Item);

			Item = new QTableWidgetItem(QString::number(arrayOfIpInfo[i].conter));

			Item->setTextAlignment(Qt::AlignCenter);

			table->setItem(RowCont1, 1, Item);

			Item = new QTableWidgetItem(QString(arrayOfIpInfo[i].startTime));

			Item->setTextAlignment(Qt::AlignCenter);

			table->setItem(RowCont1, 2, Item);

			Item = new QTableWidgetItem(QString(arrayOfIpInfo[i].endTime));

			Item->setTextAlignment(Qt::AlignCenter);

			table->setItem(RowCont1, 3, Item);

			QString ip;

			for (int j = 0; j < MaxProtocol; j++) {

				if (arrayOfIpInfo[i].protocol[j]) {

						ip = ip + Distinguish(j)+" ";

				}
			}

			Item = new QTableWidgetItem(ip);

			table->setItem(RowCont1, 4,Item);
		}

		seriesOfIp->append(ipConter);

		chartOfIp->addSeries(seriesOfIp);

		axis = new QBarCategoryAxis();

		axis->append(categories);

		chartOfIp->createDefaultAxes();

		chartOfIp->setAxisX(axis, seriesOfIp);


		break;
	}

	case CommandGetIo: {

		QList<QPointF>IoInfo;

		if (seriesOfIo != nullptr) {

			chartOfIo->removeSeries(seriesOfIo);

			chartOfIo->removeAxis(axisX);

			chartOfIo->removeAxis(axisY);

		}
		int size = data.size() / sizeof(int);

		if (size < 4)
			break;

		seriesOfIo = new QLineSeries();

		unsigned int * arrayOfIoInfo = new unsigned int[size];

		CopyMemory(arrayOfIoInfo, data.data(), data.size());

		for (int i = 0; i < size; i += 2) {

			IoInfo.append(QPoint(arrayOfIoInfo[i], arrayOfIoInfo[i + 1]));

		}
		delete arrayOfIoInfo;

		seriesOfIo->append(IoInfo);

		chartOfIo->addSeries(seriesOfIo);

		axisX = new QValueAxis();
		axisX->setTitleText("开机运行时间(MS)");
		axisX->setLabelFormat("%i");
		chartOfIo->addAxis(axisX, Qt::AlignBottom);
		seriesOfIo->attachAxis(axisX);

		axisY = new QLogValueAxis();
		axisY->setTitleText("数值(BYTE)");
		axisY->setLabelFormat("%g");
		axisY->setBase(2);
		chartOfIo->addAxis(axisY, Qt::AlignLeft);
		seriesOfIo->attachAxis(axisY);


		break;
	}

	case CommandGetProtocol: {

		seriesOfProtocol->clear();

		CopyMemory(Protocol, data.data(), sizeof(unsigned int)*MaxProtocol);

		for (int i = 0; i < MaxProtocol; i++) {

			if (Protocol[i]) {

				seriesOfProtocol->append(new CustomSlice(Distinguish(i), Protocol[i]));
			}

		}
		seriesOfProtocol->setLabelsVisible();

		break;
	}

	default:
		break;
	}

}

void NetworkServer::GetNewInfo(int index) {

	if (index == 0) {

		/*Protocol*/

		Send(new SendInfo(CommandGetProtocol));

	}
	else if (index == 1) {

		Send(new SendInfo(CommandGetIp));

	}
	else {
		Send(new SendInfo(CommandGetIo));
	}

}