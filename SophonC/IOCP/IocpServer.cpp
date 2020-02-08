#include "IocpServer.h"


IocpServer* IocpServer::instance = nullptr;



IocpServer::IocpServer() {

}


IocpServer::~IocpServer()
{
}


IocpServer * IocpServer::GetInstance()
{
	if (instance == nullptr) {

		instance = new IocpServer;

	}
	return instance;
}

bool IocpServer::Start(UINT Port)
{

	Close();



	if (!data.Initialize(Port)) {

		qDebug() << "Initialize fail";
		return false;
	}


	SYSTEM_INFO systemInfo;

	GetSystemInfo(&systemInfo);

	for (int i = 0; i < systemInfo.dwNumberOfProcessors * 2 + 1; i++) {

		HANDLE TEMP = (HANDLE)_beginthreadex(NULL,
			0,
			ThreadOfWork,
			(PVOID)&data,
			0,
			NULL);
		if (TEMP != INVALID_HANDLE_VALUE) {
			listOfWorkThread.append(TEMP);
		}
		
		else {
			qDebug() << "Creat Work Thread Fail";
			return false;
		}
		data.workerCnt++;

	}


	checkThread = (HANDLE)_beginthreadex(NULL,
		0,
		ThreadOfCheck,
		(PVOID)&data,
		0,
		NULL);

	if (checkThread == INVALID_HANDLE_VALUE) {
		qDebug() << "Creat Check Thread Fail";

		return false;
	}

	listenThread = (HANDLE)_beginthreadex(NULL,
		0,
		ThreadOfListen,
		(PVOID)&data,
		0,
		NULL);

	if (listenThread == INVALID_HANDLE_VALUE) {
		qDebug() << "Creat Listen Thread Fail";
		return false;
	}
	return true;
}

void IocpServer::Close() {

	CloseListenAndCheckThread();

	/*while (data.workerCnt--) {


		OVERLAPPEDPLUS	*pOverlap = new OVERLAPPEDPLUS(LocalIoEndThread);

		PostQueuedCompletionStatus(data.completionPort, 0,NULL, &pOverlap->m_ol);
	}


	for (HANDLE T : listOfWorkThread) {

		WaitForSingleObject(T, INFINITE);

		CloseHandle(T);

		qDebug() << "wait it";
	}


	listOfWorkThread.clear();


	closesocket(data.listenSocket);

	CloseHandle(data.completionPort);

	WSACloseEvent(data.networkEvent);

	data.linkerManager->KickAllLinker();

	WSACleanup();

	DeleteCriticalSection(&data.Safer);*/
}

void IocpServer::CloseListenAndCheckThread(){

	if (!data.IsRunning()) {
		return;
	}

	data.runState = NOTRUNNING;


	WaitForSingleObject(listenThread, INFINITE);


	CloseHandle(listenThread);


	WaitForSingleObject(checkThread, INFINITE);


	CloseHandle(checkThread);

}

void IocpServer::StartListenAndCheckThread()
{
	if (data.IsRunning()) {
		return;
	}

	data.runState = RUNNING;

	checkThread = (HANDLE)_beginthreadex(NULL,
		0,
		ThreadOfCheck,
		(PVOID)&data,
		0,
		NULL);

	if (checkThread == INVALID_HANDLE_VALUE) {
		qDebug() << "Creat Check Thread Fail";

		return ;
	}

	listenThread = (HANDLE)_beginthreadex(NULL,
		0,
		ThreadOfListen,
		(PVOID)&data,
		0,
		NULL);

	if (listenThread == INVALID_HANDLE_VALUE) {
		qDebug() << "Creat Listen Thread Fail";
		return ;
	}
}

bool IocpServer::IsActive()
{
	return data.IsRunning();
}

UINT IocpServer::ThreadOfCheck(PVOID arg)
{
	qDebug() << "Check Start";

	IocpServer::IocpData *pThis = reinterpret_cast<IocpServer::IocpData *>(arg);

	LinkerManager *linkerManager = LinkerManager::GetInstance();

	UINT onlineLinkerNumber = linkerManager->onlineLinker.size();

	while (pThis->IsRunning())
	{

		linkerManager->mutex.lock();

		for (UINT i = 0; i < onlineLinkerNumber; i++)
		{

			Linker* Temp = linkerManager->onlineLinker.at(i);

			if (Temp->GetItsFather() != Temp->Number) {

				continue;

			}

			if (Temp->activeState.testAndSetOrdered(NULL,NULL)){

				continue;

			}
			if (Temp->activeState.testAndSetOrdered(POOR,POOR)){

				qDebug() << "SYSTEM KCIKED NUMBER "<<Temp->Number;

				linkerManager->KickLinker(Temp->Number);
			}
			else{
				(void)Temp->activeState.deref();
			}
		}
		onlineLinkerNumber = onlineLinkerNumber = linkerManager->onlineLinker.size();

		linkerManager->mutex.unlock();

		Sleep(CHECK_RATE);
	}
	qDebug() << "Close Checker Thread";

	return 0;
}

UINT IocpServer::ThreadOfListen(PVOID arg) {


	qDebug() << "Listren Start";

	IocpServer::IocpData *pThis = reinterpret_cast<IocpServer::IocpData *>(arg);

	WSANETWORKEVENTS events;


	while (pThis->IsRunning())
	{

		DWORD dwRet;
		dwRet = WSAWaitForMultipleEvents(1,
			&pThis->networkEvent,
			FALSE,
			100,
			FALSE);
		if (dwRet == WSA_WAIT_TIMEOUT)
			continue;
		int nRet = WSAEnumNetworkEvents(pThis->listenSocket,

			pThis->networkEvent,

			&events);

		if (nRet == SOCKET_ERROR)
		{
			qDebug() << "Listen Fail 1" << WSAGetLastError();
			break;
		}
		if (events.lNetworkEvents & FD_ACCEPT)
		{
			if (events.iErrorCode[FD_ACCEPT_BIT] == 0)
				pThis->OnAccept();
			else
			{
				qDebug() << "Listen Fail 2" << WSAGetLastError();
				break;
			}

		}
	}
	qDebug() << "Listen End!";

	return 0;
}

UINT IocpServer::ThreadOfWork(PVOID arg)
{
	IocpServer::IocpData *pThis = reinterpret_cast<IocpServer::IocpData *>(arg);

	LinkerManager *linkerManager = LinkerManager::GetInstance();

	HANDLE hCompletionPort = pThis->completionPort;

	DWORD dwIoSize;

	LPOVERLAPPED lpOverlapped;

	Linker* pLinkerContext;

	OVERLAPPEDPLUS*	pOverlapPlus;


	while (true){

		pOverlapPlus = NULL;

		pLinkerContext = NULL;

		BOOL bIORet = GetQueuedCompletionStatus(
			hCompletionPort,
			&dwIoSize,
			(PULONG_PTR)&pLinkerContext,
			&lpOverlapped, INFINITE);


		pOverlapPlus = CONTAINING_RECORD(lpOverlapped, OVERLAPPEDPLUS, m_ol);

		if (bIORet){
			switch (pOverlapPlus->m_ioType) {

			case LocalIoRead: {

				pThis->DealWithReceivedData(pLinkerContext, dwIoSize);
				break;
			}
			case LocalIoWrite: {

				pThis->DealWithSendData(pLinkerContext, dwIoSize);

				break;
			}
			case LocalIoEndThread: {


				delete pOverlapPlus;

				return 0;
			}
			default: {
				qDebug() << "NO This Token";
			}
			}
			delete pOverlapPlus;
		}

		else{

			qDebug() << "Kick By WorkThread";

			linkerManager->KickLinker(pLinkerContext->Number);

		}
	}
	qDebug() << "Work Thread END!";

	return 0;
}

IocpServer::IocpData::IocpData() {

	runState = NOTRUNNING;

	parent = (IocpServer*)((char*)this - offsetof(IocpServer, data));

	linkerManager = LinkerManager::GetInstance();

	workerCnt = 0;

}

IocpServer::IocpData::~IocpData()
{
}

bool IocpServer::IocpData::Initialize(UINT PORT) {

	try {

		runState=RUNNING;

		workerCnt = 0;

		InitializeCriticalSection(&Safer);

		WSADATA wsaData;

		WSAStartup(MAKEWORD(2, 2), &wsaData);

		listenSocket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);

		if (listenSocket == INVALID_SOCKET) {
			throw false;
		}

		SOCKADDR_IN		saServer;

		saServer.sin_port = htons(PORT);

		saServer.sin_family = AF_INET;

		saServer.sin_addr.s_addr = INADDR_ANY;

		int nRet = bind(listenSocket,
			(LPSOCKADDR)&saServer,
			sizeof(struct sockaddr));


		if (nRet == SOCKET_ERROR) {

			throw false;

		}

		networkEvent = WSACreateEvent();
		if (networkEvent == WSA_INVALID_EVENT) {
			throw false;
		}

		nRet = WSAEventSelect(listenSocket,
			networkEvent,
			FD_ACCEPT);

		if (nRet == SOCKET_ERROR) {
			throw false;
		}

		nRet = listen(listenSocket, SOMAXCONN);
		if (nRet == SOCKET_ERROR) {
			throw false;
		}

		completionPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);

		if (completionPort == NULL) {
			throw false;
		}

	}
	catch (...) {

		qDebug() << "Initialize Fail";
		return false;
	}

	qDebug() << "Initialize Successful! Port: " << PORT;

	return true;
}

void IocpServer::IocpData::PostRecv(Linker * pLinker) {

	OVERLAPPEDPLUS * pOverlap = new OVERLAPPEDPLUS(LocalIoRead);

	DWORD			dwNumberOfBytesRecvd;

	DWORD FLAG = 0;

	int nRetVal = WSARecv(pLinker->socket,
		&pLinker->in_Wsabuf,
		1,
		&dwNumberOfBytesRecvd,
		&FLAG,
		&pOverlap->m_ol,
		NULL);

	if (nRetVal == SOCKET_ERROR && WSAGetLastError() != WSA_IO_PENDING)
	{
		qDebug() << "Kick By PostRecv";

		linkerManager->KickLinker(pLinker->Number);
	}


}

bool IocpServer::IocpData::AssociateSocketWithCompletionPort(SOCKET clientSocket, HANDLE completionPort, ULONG_PTR pClient) {

	HANDLE h = CreateIoCompletionPort((HANDLE)clientSocket, completionPort, pClient, 0);

	return h == completionPort;
}

void IocpServer::IocpData::OnAccept() {

	SOCKADDR_IN	SockAddr;

	SOCKET		LinkerSocket;

	Linker* newLinker =linkerManager->AllocateNewLinker();

	int nLen = sizeof(SOCKADDR_IN);

	LinkerSocket = accept(listenSocket,
		(LPSOCKADDR)&SockAddr,
		&nLen);

	newLinker->socket = LinkerSocket;

	if (LinkerSocket == INVALID_SOCKET) {

		qDebug() << "ACCEPT failed! : " << WSAGetLastError();

		linkerManager->KickLinker(newLinker->Number);

		return;
	}
	if (!AssociateSocketWithCompletionPort(LinkerSocket, completionPort, (ULONG_PTR)newLinker)){

		qDebug() << "Associate Socket With CompletionPort Failed!";

		linkerManager->KickLinker(newLinker->Number);

		return;
	}


	strcpy(newLinker->ip, inet_ntoa(SockAddr.sin_addr));

	PostRecv(newLinker);
}


bool IocpServer::IocpData::IsRunning() {

	return runState == RUNNING;
}


void IocpServer::IocpData::DealWithReceivedData(Linker * pLinkerContext, UINT dwIosize)
{
	if (dwIosize == 0) {

		qDebug() << "Kick By DealWithRecvData" << pLinkerContext->Number;

		linkerManager->KickLinker(pLinkerContext->Number);

		return;
	}

	(void)pLinkerContext->activeState.fetchAndStoreOrdered(EXCELLENT);

	pLinkerContext->bufferOfRecv.append((const char*)pLinkerContext->tempBufferOfRecv, dwIosize);


	while (pLinkerContext->recvTest || (pLinkerContext->bufferOfRecv.getBufferSize() >= sizeOfPacketHead))
	{
		if (!pLinkerContext->recvTest)
		{

			pLinkerContext->bufferOfRecv.read(&pLinkerContext->bufferOfComplete, sizeOfPacketHead);




			CopyMemory(&pLinkerContext->totSizeOfRecvedData, pLinkerContext->bufferOfComplete.data(), sizeOfPacketHead);



			pLinkerContext->totSizeOfRecvedData -= sizeOfPacketHead;



			pLinkerContext->recvTest = true;


		}

		if (pLinkerContext->bufferOfRecv.getBufferSize() >= pLinkerContext->totSizeOfRecvedData)
		{

			pLinkerContext->recvTest = false;



			pLinkerContext->bufferOfRecv.read(&pLinkerContext->bufferOfComplete, pLinkerContext->totSizeOfRecvedData);


			pLinkerContext->bufferOfComplete = qUncompress(pLinkerContext->bufferOfComplete);


			CopyMemory(&pLinkerContext->Token, pLinkerContext->bufferOfComplete.data(), sizeof(Token));



			pLinkerContext->bufferOfComplete.remove(0, sizeof(Token));

			AnalyzeAndProcess(pLinkerContext);

		}
		else
		{
			qDebug() << "Continue Recv......";
			break;
		}
	}

	PostRecv(pLinkerContext);
}

void IocpServer::IocpData::DealWithSendData(Linker * pLinkerContext, UINT dwIosize)
{


	pLinkerContext->totSend += dwIosize;


	if (pLinkerContext->totSend == pLinkerContext->totPost)
	{

		delete pLinkerContext->sendQueue.front();

		EnterCriticalSection(&Safer);

		pLinkerContext->sendQueue.pop();

		LeaveCriticalSection(&Safer);


		pLinkerContext->totSend = 0;


		if (!pLinkerContext->sendQueue.empty()) {

			pLinkerContext->totPost = pLinkerContext->sendQueue.front()->info->length();
		}
		else {
			return;
		}
	}


	UINT ulFlags = 0;

	OVERLAPPEDPLUS * pOverlap = new OVERLAPPEDPLUS(LocalIoWrite);

	pLinkerContext->out_Wsabuf.len = pLinkerContext->totPost - pLinkerContext->totSend;

	pLinkerContext->out_Wsabuf.buf = pLinkerContext->sendQueue.front()->info->data() + pLinkerContext->totSend;


	int nRetVal = WSASend(pLinkerContext->socket,
		&pLinkerContext->out_Wsabuf,
		1,
		&pLinkerContext->out_Wsabuf.len,
		ulFlags,
		&pOverlap->m_ol,
		NULL);


	if (nRetVal == SOCKET_ERROR && WSAGetLastError() != WSA_IO_PENDING){

		qDebug() << "Kick By Send Function";

		linkerManager->KickLinker(pLinkerContext->Number);

	}
}

void IocpServer::IocpData::AnalyzeAndProcess(Linker * aim) {

	/*If the instance already exists, then send the corresponding signal*/

	if (aim->instance != nullptr) {

		emit aim->instance->NewInfo(aim->Token, aim->bufferOfComplete,aim);

		return;
	}

	/*If the instance does not exist, the IOCP notifies the GUI to initialize the corresponding instance.*/

	emit parent->CreateInstance(aim->Token, aim->bufferOfComplete,aim);


}
