#pragma once

#pragma execution_character_set("utf-8")

#include"../IOCP/RingBuffer.h"

#include"../IOCP/Token.h"

#include"../IOCP/LinkerManager.h"

#include<QWidget>

#include<QVector>

class BasisFunction : public QWidget
{
	Q_OBJECT

friend class IocpServer;

public:

	BasisFunction(Linker* arg);

	BasisFunction();

	virtual ~BasisFunction();

	void Send(SendInfo* info);

	void Send(Linker *SLinker, SendInfo* info);

	void AddNewServer(Linker* linker);

protected:

	QVector<Linker *> ServerList;

	LinkerManager *linkerManager;


protected slots:

	virtual void ProcInfo(Token token, QByteArray data,Linker* linker) = 0;


signals:

	void NewInfo(Token, QByteArray,Linker*);

};

