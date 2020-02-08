#include "SophonC.h"

SophonC::SophonC(QMainWindow *parent)
	: QMainWindow(parent), currentLinker(nullptr), fileSend(nullptr),instanceOfRemoteCapture(nullptr),threadOfRemoteCapture(nullptr)
{
	ui.setupUi(this);

	setAttribute(Qt::WA_QuitOnClose, true);

	setWindowIcon(QIcon(":/SophonC/logo.ico"));

	/*Register connection component*/


	qRegisterMetaType<Token>("Token");

	qRegisterMetaType<Linker*>("Linker*");

	qRegisterMetaType<RemoteCaptureUint>("RemoteCaptureUint");

	linkerManager = LinkerManager::GetInstance();

	iocp = IocpServer::GetInstance();


	QObject::connect(iocp,
		SIGNAL(CreateInstance(Token, QByteArray, Linker*)),
		this,
		SLOT(CreateInstance(Token, QByteArray, Linker*))
	);

	QObject::connect(linkerManager,
		SIGNAL(DeleteServer(int)),
		this,
		SLOT(DeleteARow(int))
	);

	QObject::connect(ui.actionOfRedirect, SIGNAL(triggered()),this,SLOT( Redirect()));

	QObject::connect(ui.actionOfStart, SIGNAL(triggered()), this, SLOT(StartIocp()));

	QObject::connect(ui.tableWidget, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(DoubleClickedToAdd(int, int)));

	QObject::connect(ui.tableWidgetOfAdd, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(DoubleClickedToDel(int, int)));

	QObject::connect(ui.tableWidget, SIGNAL(itemClicked(QTableWidgetItem *)), this, SLOT(itemClickedToReflashInfo(QTableWidgetItem *)));

	ui.QTW->setCurrentWidget(0);

	permanent = new QLabel(this);

	permanent->setFrameStyle(QFrame::Box | QFrame::Sunken);

	permanent->setText("运行状态:停止运行  |  总计:0");

	permanent->setOpenExternalLinks(true);

	ui.statusBar->addPermanentWidget(permanent);


	//ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	ui.tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);

	popMenu = new QMenu(ui.tableWidget);

	actionOfRemote = new QAction("远程抓包", this);

	actionOfNetwork = new QAction("网络数据信息统计", this);

	actionOfSys = new QAction("远程任务管理器", this);

	actionOfCmd = new QAction("远程命令行", this);

	actionOfGetOnlineInfo= new QAction("获取上线信息", this);

	actionOfLsp = new QAction("LSP测试版",this);

	hideCap= new QAction("远程抓包(后台模式)", this);

	popMenu->addAction(actionOfNetwork);

	popMenu->addAction(actionOfRemote);

	popMenu->addAction(actionOfSys);

	popMenu->addAction(actionOfCmd);

	popMenu->addAction(actionOfGetOnlineInfo);

	popMenu->addAction(actionOfLsp);

	popMenu->addAction(hideCap);

	QObject::connect(ui.tableWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(ExecPopMenu(QPoint)));

	QObject::connect(actionOfNetwork, SIGNAL(triggered()), this, SLOT(StartNetwork()));

	QObject::connect(actionOfGetOnlineInfo, SIGNAL(triggered()), this, SLOT(GetOnlineInfo()));

	QObject::connect(actionOfRemote, SIGNAL(triggered()), this, SLOT(StartRemoteCapture()));

	QObject::connect(actionOfSys, SIGNAL(triggered()), this, SLOT(StartTaskManager()));

	QObject::connect(actionOfCmd, SIGNAL(triggered()), this, SLOT(StartCmd()));

	QObject::connect(actionOfLsp, SIGNAL(triggered()), this, SLOT(TestLsp()));

	QObject::connect(hideCap, SIGNAL(triggered()), this, SLOT(StartRemoteCaptureHide()));

	QObject::connect(ui.buttonOfRemotePath, SIGNAL(clicked()), this, SLOT(StartChoosePath()));

	QObject::connect(ui.addFileSendingQueue, SIGNAL(clicked()), this, SLOT(AddQueueClick()));

	QObject::connect(ui.chooleFile, SIGNAL(clicked()), this, SLOT(ChooseFileClick()));

	QObject::connect(ui.clearFileSendingQueue, SIGNAL(clicked()), this, SLOT(ClearQueueClick()));

	QObject::connect(ui.fileSend, SIGNAL(clicked()), this, SLOT(FileSendClick()));



	ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	ui.tableWidgetOfAdd->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	setWindowTitle("Sophon");

	ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");

	ui.tableWidgetOfAdd->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");

	ui.tableWidget->hideColumn(0);

	ui.tableWidgetOfAdd->hideColumn(0);

	QPalette palette;

	palette.setColor(QPalette::Background, QColor(255, 0, 0));

	permanent->setAutoFillBackground(true);

	permanent->setPalette(palette);


	ui.statusBar->showMessage("READY", 5000);

	ui.statusBar->setSizeGripEnabled(true);
}

void SophonC::CreateInstance(Token token, QByteArray data, Linker* linker) {

	switch (token) {

	case TokenLogin: {

		qDebug() << "The user goes online and identifies the main interface." << linker->Number;

		linkerManager->SetFatherAndInstanceByNumber(linker->Number, linker, new MainFunction(linker), Mainfunction);

		int RowCont = ui.tableWidget->rowCount();

		ui.tableWidget->insertRow(RowCont);

		permanent->setText("运行状态:正在运行  |  总计:" + QString::number(RowCont + 1));

		QDateTime currentDateTime = QDateTime::currentDateTime();

		QString currentDate = currentDateTime.toString("yyyy.MM.dd hh:mm:ss.zzz ddd");

		QByteArrayList list = data.split('|');

		ui.tableWidget->setItem(RowCont, 0, new QTableWidgetItem(QString::number(linker->Number)));

		ui.tableWidget->setItem(RowCont, 1, new QTableWidgetItem(QString(linker->ip)));

		linker->os.clear();
		linker->os.append(QString(list.at(0)));

		ui.tableWidget->setItem(RowCont, 2, new QTableWidgetItem(QString(list.at(0))));
		linker->computerName.clear();
		linker->computerName.append(QString(list.at(1)));

		ui.tableWidget->setItem(RowCont, 3, new QTableWidgetItem(QString(list.at(1))));
		linker->onlineTime.clear();
		linker->onlineTime.append(currentDate);
		ui.tableWidget->setItem(RowCont, 4, new QTableWidgetItem(currentDate));

		ui.statusBar->showMessage("用户上线", 3000);

		linker->cpu.clear();
		linker->cpu.append(QString("CPU信息:\n") + QString(list.at(2)));

		linker->memory.clear();
		linker->memory.append(QString("内存信息(已用/总计):\n") + QString(list.at(3)));


		linker->disk.clear();

		linker->disk.append(QString("硬盘信息(可用/总计):\n") + QString(list.at(4)));

		linker->remotePath.clear();

		linker->remotePath.append("./");

		break;

	}
	case CommandOpenNetworkServer: {

		/*-----------------------------------------------Demo-Start-------------------------------------------------------*/

		UINT Father;

		/*1.Get the father number*/

		CopyMemory(&Father, data.data(), sizeof(UINT));

		/*2.Set Instance*/

		/*If it is the first case, the GUI and Linker are one-to-one relationships.
		You need to create a new GUI object.like this*/

		NetworkServer *networkServer = new NetworkServer(linker);

		linkerManager->SetFatherAndInstanceByNumber(Father, linker, networkServer, NetWork);

		networkServer->show();


		/*If it is the second case, If the GUI and Linker are one-to-many relationships.
		You need to pass the pointer of the created GUI object as a parameter to the function.*/

		/*You should add this sentence*/

		/*networkServer->AddNewLinker(linker);*/

		/*-----------------------------------------------Demo-End-------------------------------------------------------*/


		break;

	}
	case CommandOpenCmd: {

		UINT Father;

		CopyMemory(&Father, data.data(), sizeof(UINT));

		RemoteCmd *remotecmd = new RemoteCmd(linker);

		linkerManager->SetFatherAndInstanceByNumber(Father, linker, remotecmd, Remotecmd);

		remotecmd->show();

		break;
	}

	case CommandOpenDoucmentFuntion: {

		UINT Father;

		CopyMemory(&Father, data.data(), sizeof(UINT));

		linkerManager->SetFatherAndInstanceByNumber(Father, linker, fileSend, Filesend);

		fileSend->AddNewServer(linker);

		QList<QTableWidgetItem*> listOfSend = ui.tableOfFileSend->findItems(QString::number(Father, 10), Qt::MatchExactly);

		if (listOfSend.size() == 1) {
			
			int Row = listOfSend.at(0)->row();

			ui.tableOfFileSend->item(Row, 1)->setText("就绪");
			ui.tableOfFileSend->item(Row, 0)->setBackgroundColor(QColor(255, 255, 0));
			ui.tableOfFileSend->item(Row, 1)->setBackgroundColor(QColor(255, 255, 0));
			ui.tableOfFileSend->item(Row, 2)->setBackgroundColor(QColor(255, 255, 0));

		}


		break;
	}

	default: {

		break;

	}

	}
}
SophonC::~SophonC()
{
}
void SophonC::StartIocp() {

	if (iocp->Start()) {

		ui.statusBar->showMessage("正在初始化", 3000);

		permanent->setText("运行状态:正在运行  |  总计:0");

		QPalette palette;

		palette.setColor(QPalette::Background, QColor(0, 255, 0));

		permanent->setAutoFillBackground(true);

		permanent->setPalette(palette);

		ui.actionOfStart->setEnabled(false);

	}
	else {

		ui.statusBar->showMessage("初始化失败", 3000);

		permanent->setText("运行状态:停止运行  |  总计:0");

		QPalette palette;

		palette.setColor(QPalette::Background, QColor(255, 0, 0));

		permanent->setAutoFillBackground(true);

		permanent->setPalette(palette);

	}

}

void SophonC::StartNetwork() {

	int cRow = ui.tableWidget->currentRow();

	QTableWidgetItem* cItem = ui.tableWidget->item(cRow, 0);

	linkerManager->GetInstanceByNumber(cItem->text().toInt())->Send(new SendInfo(CommandOpenNetworkServer));

}

void SophonC::StartTaskManager() {

	int cRow = ui.tableWidget->currentRow();

	QTableWidgetItem* cItem = ui.tableWidget->item(cRow, 0);

	linkerManager->GetInstanceByNumber(cItem->text().toInt())->Send(new SendInfo(CommandOpenNetworkServer/*commandTaskManager*/));

}

void SophonC::StartRemoteCapture() {

	int cRow = ui.tableWidget->currentRow();

	QTableWidgetItem* cItem = ui.tableWidget->item(cRow, 1);

	RemoteCapture *rc = new RemoteCapture();

	rc->Start(cItem->text());

	rc->show();

}

void SophonC::StartRemoteCaptureHide(){

	int cRow = ui.tableWidget->currentRow();

	QTableWidgetItem* cItem = ui.tableWidget->item(cRow, 0);

	if (!linkerManager->GetLinkerByNumber(cItem->text().toInt())->isHideCapture) {

		linkerManager->GetLinkerByNumber(cItem->text().toInt())->isHideCapture = true;

		threadOfRemoteCapture = new ThreadOfRemoteCapture();

		instanceOfRemoteCapture = new QThread();
		threadOfRemoteCapture->moveToThread(instanceOfRemoteCapture);
	    

		QObject::connect(this, SIGNAL(StartCap(QString)), threadOfRemoteCapture, SLOT(StartCap(QString)));

		instanceOfRemoteCapture->start();

		emit StartCap(QString(linkerManager->GetLinkerByNumber(cItem->text().toInt())->ip));

		
	}
	else {
		linkerManager->GetLinkerByNumber(cItem->text().toInt())->isHideCapture = false;

		if (instanceOfRemoteCapture != nullptr) {


			threadOfRemoteCapture->Stop();

			instanceOfRemoteCapture->exit();

			instanceOfRemoteCapture->wait();

			delete threadOfRemoteCapture;

			delete instanceOfRemoteCapture;

			QString savePath = QFileDialog::getSaveFileName(this,
				"捕获数据包保存",
				"",
				tr("Captured Data(*.libpcap)"));

			if (!savePath.isNull()) {

				QFile file(QString(linkerManager->GetLinkerByNumber(cItem->text().toInt())->ip) + "-" + "Captured.libpcap");

				file.open(QIODevice::ReadOnly);

				QByteArray fileData = file.readAll();

				file.close();

				QFile write(savePath);

				write.open(QIODevice::WriteOnly);

				write.write(fileData);

				write.close();
			}

			instanceOfRemoteCapture = nullptr;

			threadOfRemoteCapture = nullptr;
		}
	}

}

void SophonC::StartCmd() {

	int cRow = ui.tableWidget->currentRow();

	QTableWidgetItem* cItem = ui.tableWidget->item(cRow, 0);

	linkerManager->GetInstanceByNumber(cItem->text().toInt())->Send(new SendInfo(CommandOpenCmd));
}

void SophonC::StartChoosePath() {

	if (currentLinker == nullptr) {
		return;
	}

	ChoosePath* choosePath = new ChoosePath();

	choosePath->SetLinker(currentLinker);

	choosePath->show();

	QObject::connect(currentLinker->instance, SIGNAL(Proc(Linker*, QByteArray, Token)), choosePath, SLOT(Proc(Linker*, QByteArray, Token)));
}

void SophonC::TestLsp(){

	int cRow = ui.tableWidget->currentRow();

	QTableWidgetItem* cItem = ui.tableWidget->item(cRow, 0);

	linkerManager->GetInstanceByNumber(cItem->text().toInt())->Send(new SendInfo(CommandOpenCmd/*TestLspp*/));

}

void SophonC::Redirect()
{

	if (!iocp->IsActive()) {

		ui.statusBar->showMessage("网络服务未启动", 3000);
		return;
	}

	ui.statusBar->showMessage("监听线程与检查线程暂时关闭", 3000);

	iocp->CloseListenAndCheckThread();

	redirect= QInputDialog::getText(NULL, "IP地址重定向",
		"请输入重定向的IP地址",
		QLineEdit::Normal,
		"127.0.0.1",
		NULL);

	int Row = ui.tableWidget->rowCount();

	for (int i = 0; i < Row; i++) {

		int aimServer= ui.tableWidget->item(i, 0)->text().toInt();

		SendInfo *tempSendINfo= new SendInfo(CommandRedirectIp);

		tempSendINfo->GetInfo()->append(redirect);

		linkerManager->GetInstanceByNumber(aimServer)->Send(tempSendINfo);
	}

	iocp->StartListenAndCheckThread();

	ui.statusBar->showMessage("监听线程与检查线程重新启动", 3000);

}

void SophonC::GetOnlineInfo(){


	int cRow = ui.tableWidget->currentRow();

	QTableWidgetItem* cItem = ui.tableWidget->item(cRow, 0);

	MainFunction* mainFunction= dynamic_cast<MainFunction*>(linkerManager->GetInstanceByNumber(cItem->text().toInt()));

	ui.tableWidget->setItem(cRow, 5, new QTableWidgetItem(""));

	mainFunction->SetItem(ui.tableWidget->item(cRow, 5));

	linkerManager->GetInstanceByNumber(cItem->text().toInt())->Send(new SendInfo(CommandGetOnlineInfo));
}

void SophonC::DeleteARow(int Number) {


	QList<QTableWidgetItem*> list = ui.tableWidget->findItems(QString::number(Number, 10), Qt::MatchExactly);

	QList<QTableWidgetItem*> listOfAdd = ui.tableWidgetOfAdd->findItems(QString::number(Number, 10), Qt::MatchExactly);

	if (list.size() == 1) {

		int RowCont = ui.tableWidget->rowCount();

		permanent->setText("运行状态:正在运行  |  总计:" + QString::number(RowCont - 1));

		int Row = list.first()->row();

		if (listOfAdd.size() == 1) {

			int RowOfAdd = listOfAdd.first()->row();

			ui.tableWidgetOfAdd->removeRow(RowOfAdd);
		}
		ui.tableWidget->removeRow(Row);

		ui.statusBar->showMessage("用户下线", 3000);

	}


}

void SophonC::ExecPopMenu(QPoint pos) {


	QModelIndex index = ui.tableWidget->indexAt(pos);

	if (index.row() == -1) {
		return;
	}

	int cRow = ui.tableWidget->currentRow();

	QTableWidgetItem* cItem = ui.tableWidget->item(cRow, 0);

	if (linkerManager->GetLinkerByNumber(cItem->text().toInt())->isHideCapture) {
		hideCap->setText("停止后台抓包");
	}
	else {

		hideCap->setText("远程抓包(后台模式)");
		
	}

	

	popMenu->exec(QCursor::pos());
}

void SophonC::DoubleClickedToAdd(int row, int column) {

	int RowCont = ui.tableWidgetOfAdd->rowCount();

	QList<QTableWidgetItem*> listOfAdd = ui.tableWidgetOfAdd->findItems(ui.tableWidget->item(row, 0)->text(), Qt::MatchExactly);

	if (listOfAdd.size() != 0) {

		return;

	}

	ui.tableWidgetOfAdd->insertRow(RowCont);

	ui.tableWidgetOfAdd->setItem(RowCont, 0, ui.tableWidget->item(row, 0)->clone());

	ui.tableWidgetOfAdd->setItem(RowCont, 1, ui.tableWidget->item(row, 1)->clone());

	ui.tableWidgetOfAdd->setItem(RowCont, 2, ui.tableWidget->item(row, 2)->clone());

	ui.tableWidgetOfAdd->setItem(RowCont, 3, ui.tableWidget->item(row, 3)->clone());
}

void SophonC::DoubleClickedToDel(int row, int column) {

	ui.tableWidgetOfAdd->removeRow(row);

}

void SophonC::itemClickedToReflashInfo(QTableWidgetItem * QTWI) {

	int number = ui.tableWidget->item(QTWI->row(), 0)->text().toInt();

	Linker* linker = linkerManager->GetLinkerByNumber(number);

	currentLinker = linker;

	ui.labelOfHardware->setText("\n硬件详情:\n\n" +
		linker->cpu + "\n\n" +
		linker->memory + "\n\n" +
		linker->disk
	);
	ui.labelOfIp->setText(QString(linker->ip));
	ui.labelOfName->setText(linker->computerName);
	ui.labelOfNumber->setText(QString::number(linker->Number));
	ui.labelOfOs->setText(linker->os);
	ui.labelOfTime->setText(linker->onlineTime);

	ui.buttonOfRemotePath->setText("文件接收地址:" + linker->remotePath);



}

void SophonC::AddQueueClick() {

	if (ui.tableWidgetOfAdd->rowCount() == 0)

		return;

	if (ui.chooleFile->text()== QString("NULL"))
		return;

	if (fileSend != nullptr)

		return;

	fileSend = new FileSend(localFilePath,localFileName);

	QObject::connect(fileSend, SIGNAL(NewServerReady(Linker*)), this, SLOT(NewServerReady(Linker*)));

	QObject::connect(fileSend, SIGNAL(ServerListening(Linker*)), this, SLOT(ServerListening(Linker*)));

	QObject::connect(fileSend, SIGNAL(ServerSending(Linker*)), this, SLOT(ServerSending(Linker*)));

	QObject::connect(fileSend, SIGNAL(ServerFinish(Linker*)), this, SLOT(ServerFinish(Linker*)));

	int rowCount = ui.tableWidgetOfAdd->rowCount();

	QTableWidgetItem * Item;

	for (int i = 0; i < rowCount; i++) {

		ui.tableOfFileSend->insertRow(i);

		linkerManager->GetInstanceByNumber(ui.tableWidgetOfAdd->item(i, 0)->text().toInt())->Send(new SendInfo(CommandOpenDoucmentFuntion));
		
		Item =ui.tableWidgetOfAdd->item(i, 0)->clone();

		Item->setBackgroundColor(QColor(255, 0, 0));

		ui.tableOfFileSend->setItem(i,0,Item);

		Item = new QTableWidgetItem("未就绪");

		Item->setBackgroundColor(QColor(255, 0, 0));

		ui.tableOfFileSend->setItem(i, 1, Item);

		Item = new QTableWidgetItem(linkerManager->GetLinkerByNumber(ui.tableWidgetOfAdd->item(i, 0)->text().toInt())->remotePath);

		Item->setBackgroundColor(QColor(255, 0, 0));

		ui.tableOfFileSend->setItem(i, 2, Item);

	}
}

void SophonC::ChooseFileClick() {

	ChooseLocalFile* chooseLocaoFile = new ChooseLocalFile(&(this->localFilePath),&(this->localFileName), ui.chooleFile);

	chooseLocaoFile->show();
}

void SophonC::ClearQueueClick(){

	if (fileSend != nullptr) {

		delete fileSend;

		int sum= ui.tableOfFileSend->rowCount();

		while (sum--)
			ui.tableOfFileSend->removeRow(0);

		fileSend = nullptr;
	}
	return;
}

void SophonC::FileSendClick() {

	if (fileSend == nullptr) {
		return;
	}
	fileSend->Start();

}

void SophonC::NewServerReady(Linker * linker) {

}

void SophonC::ServerListening(Linker * linker){

	QList<QTableWidgetItem*> listOfSend = ui.tableOfFileSend->findItems(QString::number(linker->GetItsFather()), Qt::MatchExactly);

	if (listOfSend.size() == 1) {

		QTableWidgetItem* Item = listOfSend.at(0);

		ui.tableOfFileSend->item(Item->row(), 1)->setText("正在监听");

	}
}

void SophonC::ServerSending(Linker * linker){

	QList<QTableWidgetItem*> listOfSend = ui.tableOfFileSend->findItems(QString::number(linker->GetItsFather()), Qt::MatchExactly);

	if (listOfSend.size() == 1) {

		QTableWidgetItem* Item = listOfSend.at(0);

		ui.tableOfFileSend->item(Item->row(), 1)->setText("正在发送");

	}
}

void SophonC::ServerFinish(Linker * linker){

	QList<QTableWidgetItem*> listOfSend = ui.tableOfFileSend->findItems(QString::number(linker->GetItsFather()), Qt::MatchExactly);

	if (listOfSend.size() == 1) {

		QTableWidgetItem* Item = listOfSend.at(0);

		ui.tableOfFileSend->item(Item->row(), 1)->setText("已经完成");

		ui.tableOfFileSend->item(Item->row(), 0)->setBackgroundColor(QColor(0,255,0));
		ui.tableOfFileSend->item(Item->row(), 1)->setBackgroundColor(QColor(0, 255, 0));
		ui.tableOfFileSend->item(Item->row(), 2)->setBackgroundColor(QColor(0, 255, 0));

	}
}
