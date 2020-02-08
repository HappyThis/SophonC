#pragma once

#include "./BasisFunction/BasisFunction.h"

#include<qtablewidget.h>

class MainFunction :
	public BasisFunction
{
	Q_OBJECT

		friend class IocpServer;

public:

	void SetItem(QTableWidgetItem*);

	MainFunction(Linker * arg);

	~MainFunction();

	QTableWidgetItem* currentItem;


protected slots:

	virtual void ProcInfo(Token token, QByteArray data, Linker* linker);


signals:

	void Proc(Linker*, QByteArray, Token);

};

