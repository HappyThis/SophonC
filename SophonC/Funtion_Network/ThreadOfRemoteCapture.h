#pragma once

#include <QObject>

#include"Header.h"

#include<QDebug>

#include"RemoteCaptureUint.h"

#include<QFile>

class ThreadOfRemoteCapture : public QObject
{
	Q_OBJECT

public:
	ThreadOfRemoteCapture();

	~ThreadOfRemoteCapture();

	void Stop();

private slots:

	void StartCap(QString ip);

private:

	QAtomicInteger<int> activeState;

	void ip4tos(u_long in, char* addressV4);

	void ip6tos(struct sockaddr *sockaddr, char *addressV6, int addrlen);

	void AnalyzeEth(const u_char* pkt);

	void AnalyzeArp(const u_char* pkt);

	void AnalyzeIpV6(const u_char* pkt);

	void AnalyzeIpV4(const u_char* pkt);

	void AnalyzeTcp(const u_char* pkt);

	void AnalyzeUdp(const u_char* pkt);

	RemoteCaptureUint* RCU;

signals:

	void NewPacket(RemoteCaptureUint RCU);
};
