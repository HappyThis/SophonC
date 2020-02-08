#include "Linker.h"


Linker::Linker(UINT number):activeState(EXCELLENT),totSend(0),totPost(0),Number(number),Fnumber(number),isHideCapture(false){

	tempBufferOfRecv = new BYTE[MaxBufferLenth];

	in_Wsabuf.buf = (char*)tempBufferOfRecv;

	in_Wsabuf.len = MaxBufferLenth;

	socket = INVALID_SOCKET;

	instance = nullptr;

	recvTest = false;

	memset(Son, -1, sizeof(Son));

	packetCont = 0;

}
Linker::~Linker(){

	delete tempBufferOfRecv;

}

void Linker::SetItsFather(UINT Father){

	Fnumber=Father;

}

UINT Linker::GetItsFather(){

	return Fnumber;

}

void Linker::Clear()
{

	bufferOfRecv.clear();

	totSizeOfRecvedData = 0;

	recvTest = false;

	(void)activeState.fetchAndStoreOrdered(EXCELLENT);

	while (!sendQueue.empty()) {

		delete sendQueue.front();

		sendQueue.pop();

	}

	if (instance != nullptr) {

		instance = nullptr;
	}


	totSend = 0;

	for (BasisFunction *i : Son) {
		i = nullptr;
	}

	packetCont = 0;

	isHideCapture = false;
}
