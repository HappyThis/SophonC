#pragma once


#include<QObject>

#include<QDebug>

#include<QStack>

#include"LinkerManager.h"

#include"Process.h"

#include"MSTcpIP.h"

#include"../Funtion_Network/NetworkServer.h"

#include"../BasisFunction/MainFunction.h"


#pragma comment(lib,"WS2_32.lib")


#define RUNNING 1

#define NOTRUNNING 0


#define CHECK_RATE 2500

#define sizeOfPacketHead (sizeof(UINT))


class IocpServer :public QObject
{ 
    Q_OBJECT

public:

	IocpServer();

	~IocpServer();

	static IocpServer* GetInstance();


	bool Start(UINT Port=1997);

	void Close();

	void CloseListenAndCheckThread();

	void StartListenAndCheckThread();

	bool IsActive();


private:

	static IocpServer * instance;


	class IocpData : public QObject
	{
	public:

		IocpData();

		~IocpData();

		bool  Initialize(UINT PORT);

		bool AssociateSocketWithCompletionPort(SOCKET clientSocket, HANDLE completionPort, ULONG_PTR pClient);

		void OnAccept();

		void PostRecv(Linker * pLinker);

		bool IsRunning();

		void DealWithReceivedData(Linker *pLinkerContext, UINT dwIosize);

		void DealWithSendData(Linker *pLinkerContext, UINT dwIosize);

		void AnalyzeAndProcess(Linker *aim);

		HANDLE completionPort;

		UINT workerCnt;

		WSAEVENT	networkEvent;

		SOCKET listenSocket;

		UINT serialNumber;

		UINT runState;

		CRITICAL_SECTION Safer;

		IocpServer *parent;

		LinkerManager* linkerManager;
	}

	data;

	static UINT WINAPI ThreadOfCheck(PVOID arg);

	static UINT WINAPI ThreadOfListen(PVOID arg);

	static UINT WINAPI ThreadOfWork(PVOID arg);

	HANDLE listenThread;

	HANDLE checkThread;

	QList<HANDLE> listOfWorkThread;


	/*Initialize the signal of the function instance*/

	signals:

		void CreateInstance(Token, QByteArray,Linker *);
		
};

