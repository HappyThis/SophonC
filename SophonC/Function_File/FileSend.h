#pragma once

#include <QWidget>

#include "ui_FileSend.h"

#include "../BasisFunction/BasisFunction.h"

#include<QFile>

#include<QBytearray>

class FileSend : public BasisFunction
{
	Q_OBJECT

public:

	FileSend(QString LocalFilePath,QString LocalFileName);

	~FileSend();

	void Start();

private:

	Ui::FileSend ui;

	QString localFilePath,localFileName;

	QFile file;

	QByteArray fileData;

	UINT Port;

protected slots:

	virtual void ProcInfo(Token token, QByteArray data, Linker* linker);

signals:

	void NewServerReady(Linker* linker);

	void ServerListening(Linker* linker);

	void ServerSending(Linker* linker);

	void ServerFinish(Linker* linker);
};
