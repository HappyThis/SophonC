#include "BasisFunction.h"




BasisFunction::BasisFunction(Linker * arg){

	ServerList.push_back(arg);

	QObject::connect(this, SIGNAL(NewInfo(Token,QByteArray,Linker*)), this, SLOT(ProcInfo(Token, QByteArray,Linker*)));

	setAttribute(Qt::WA_DeleteOnClose);

	setAttribute(Qt::WA_QuitOnClose,false);

	linkerManager = LinkerManager::GetInstance();

}

BasisFunction::BasisFunction() {

	QObject::connect(this, SIGNAL(NewInfo(Token, QByteArray, Linker*)), this, SLOT(ProcInfo(Token, QByteArray, Linker*)));

	setAttribute(Qt::WA_DeleteOnClose);

	setAttribute(Qt::WA_QuitOnClose,false);
	linkerManager = LinkerManager::GetInstance();
}

void BasisFunction::AddNewServer(Linker* linker){

	ServerList.push_back(linker);

}


BasisFunction::~BasisFunction(){
}

void BasisFunction::Send(SendInfo *Info){


	linkerManager = LinkerManager::GetInstance();

	int ulFlags = 0;

	Info->info->prepend((const char*)&Info->token, sizeof(Info->token));

	*(Info->info) = qCompress(*Info->info);

	UINT lenth = Info->info->length() + sizeof(UINT);

	Info->info->prepend((const char*)&lenth, sizeof(lenth));


	ServerList[0]->sendQueue.push(Info);


	if (ServerList[0]->sendQueue.size() == 1) {

		ServerList[0]->totPost = Info->info->length();

		OVERLAPPEDPLUS * pOverlap = new OVERLAPPEDPLUS(LocalIoWrite);

		ServerList[0]->out_Wsabuf.len = Info->info->length();

		ServerList[0]->out_Wsabuf.buf = Info->info->data();

		int nRetVal = WSASend(ServerList[0]->socket,
			&ServerList[0]->out_Wsabuf,

			1,

			&ServerList[0]->out_Wsabuf.len,

			ulFlags,

			&pOverlap->m_ol,

			NULL
		);

		if (nRetVal == SOCKET_ERROR && WSAGetLastError() != WSA_IO_PENDING) {

			qDebug() << "Send Error!";

			linkerManager->KickLinker(ServerList[0]->Number);
		}
	}
}

void BasisFunction::Send(Linker *SLinker, SendInfo * Info){

	linkerManager = LinkerManager::GetInstance();

	int ulFlags = 0;

	Info->info->prepend((const char*)&Info->token, sizeof(Info->token));

	*(Info->info) = qCompress(*Info->info);

	UINT lenth = Info->info->length() + sizeof(UINT);

	Info->info->prepend((const char*)&lenth, sizeof(lenth));


	SLinker->sendQueue.push(Info);


	if (SLinker->sendQueue.size() == 1) {

		SLinker->totPost = Info->info->length();

		OVERLAPPEDPLUS * pOverlap = new OVERLAPPEDPLUS(LocalIoWrite);

		SLinker->out_Wsabuf.len = Info->info->length();

		SLinker->out_Wsabuf.buf = Info->info->data();

		int nRetVal = WSASend(SLinker->socket,
			&SLinker->out_Wsabuf,

			1,

			&SLinker->out_Wsabuf.len,

			ulFlags,

			&pOverlap->m_ol,

			NULL
		);
		if (nRetVal == SOCKET_ERROR && WSAGetLastError() != WSA_IO_PENDING) {

			qDebug() << "Send Error!";

			linkerManager->KickLinker(SLinker->Number);
		}
	}

}
