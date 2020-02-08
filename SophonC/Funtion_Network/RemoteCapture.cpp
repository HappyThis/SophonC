#include "RemoteCapture.h"

RemoteCapture::RemoteCapture(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	threadOfRemoteCapture = new ThreadOfRemoteCapture();

	instanceOfRemoteCapture = new QThread();

	threadOfRemoteCapture->moveToThread(instanceOfRemoteCapture);

	QObject::connect(this, SIGNAL(StartCap(QString)), threadOfRemoteCapture, SLOT(StartCap(QString)));

	QObject::connect(threadOfRemoteCapture,
		SIGNAL(NewPacket(RemoteCaptureUint)),
		this,
		SLOT(NewPacket(RemoteCaptureUint)));

	setAttribute(Qt::WA_DeleteOnClose);

	setAttribute(Qt::WA_QuitOnClose, false);

	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

	ui.tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

	ui.tableWidget->horizontalHeader()->setSectionsClickable(false);

}

RemoteCapture::~RemoteCapture(){


	Stop();

	delete threadOfRemoteCapture;

	delete instanceOfRemoteCapture;

	QString savePath = QFileDialog::getSaveFileName(this,
		"捕获数据包保存",
		"",
		tr("Captured Data(*.libpcap)"));

	if (!savePath.isNull()) {

		QFile file(ip + "-" + "Captured.libpcap");

		file.open(QIODevice::ReadOnly);

		QByteArray fileData = file.readAll();

		file.close();

		QFile write(savePath);

		write.open(QIODevice::WriteOnly);

		write.write(fileData);

		write.close();
	}
}

void RemoteCapture::Start(QString ip){

	this->ip = ip;

	setWindowTitle(ip + "----"+"远程捕获");

	instanceOfRemoteCapture->start();

	emit StartCap(ip);

}

void RemoteCapture::Stop(){

	threadOfRemoteCapture->Stop();

	instanceOfRemoteCapture->exit();

	instanceOfRemoteCapture->wait();

}

void  RemoteCapture::NewPacket(RemoteCaptureUint RCU) {

	int Row = ui.tableWidget->rowCount();

	ui.tableWidget->insertRow(Row);

	ui.tableWidget->setItem(Row, 0, new QTableWidgetItem(QString(RCU.time)));

	ui.tableWidget->setItem(Row, 1, new QTableWidgetItem(QString(RCU.source)));

	ui.tableWidget->setItem(Row, 2, new QTableWidgetItem(QString(RCU.dest)));

	ui.tableWidget->setItem(Row, 3, new QTableWidgetItem(RCU.protocol));

	ui.tableWidget->setItem(Row, 4, new QTableWidgetItem(QString::number(RCU.lenth)));
}

