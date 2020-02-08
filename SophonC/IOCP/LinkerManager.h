#pragma once

#include"Linker.h"

#include<QVector>

#include<QQueue>

#include<QMutex>

class LinkerManager:public QObject
{
	friend class IocpServer;

	Q_OBJECT

public:

	LinkerManager();

	~LinkerManager();

	/*Allcoate a New Linker*/

	Linker* AllocateNewLinker();

	void KickLinker(UINT aim);

	static LinkerManager* GetInstance();

	void KickAllLinker();


	void SetFatherAndInstanceByNumber(UINT father,Linker* son,BasisFunction* bf,int Function);

	BasisFunction* GetInstanceByNumber(UINT aim,int Function);

	BasisFunction* GetInstanceByNumber(UINT aim);

	Linker* GetLinkerByNumber(UINT aim);


private:

	static LinkerManager* instance;

	QVector<Linker*> onlineLinker;

	QQueue<Linker*>  offlineLinker;

	QMutex mutex;

signals:

	void DeleteServer(int Number);

};

