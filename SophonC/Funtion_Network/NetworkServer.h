#pragma once

#include "../BasisFunction/BasisFunction.h"

#include<stdio.h>

#include<QDebug>

#include<QDir>

#include"../Funtion_Network/IpContainerUnit.h"

#include "ui_NetworkServer.h"

#include"../Funtion_Network/CustomSlice.h"

#include<QVBoxLayout>

class NetworkServer : public BasisFunction
{
	Q_OBJECT

		friend class IocpServer;

public:
	NetworkServer(Linker * arg);

	~NetworkServer();

protected slots:

	virtual void ProcInfo(Token token, QByteArray data, Linker* linker);

private:

	QString Distinguish(int Number);

	IpContainerUnit tempOfRecv;

	QByteArray tempOfArray;

	unsigned int Protocol[MaxProtocol];

	Ui::NetworkServer ui;

	QPieSeries *seriesOfProtocol;

	QChart *chartOfProtocol;

	QBarSet *ipConter;

	QBarSeries *seriesOfIp;

	QBarCategoryAxis *axis;

	QChart *chartOfIp;

	QLineSeries *seriesOfIo;

	QValueAxis *axisX;

	QLogValueAxis *axisY;

	QChart *chartOfIo;

	QTableWidget *table;

private slots:

	void GetNewInfo(int index);
};