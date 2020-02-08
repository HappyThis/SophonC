#include "FileSend.h"

FileSend::FileSend(QString LocalFilePath, QString LocalFileName)
	: BasisFunction(),localFilePath(LocalFilePath),file(LocalFilePath),localFileName(LocalFileName),Port(1998)
{
	ui.setupUi(this);

	file.open(QIODevice::ReadOnly);

	fileData = file.readAll();

}

FileSend::~FileSend(){

	for (Linker* i : ServerList) {

		Send(i, new SendInfo(CommandCloseDoucmentFuntion));

	}
}

void FileSend::Start() {

	if (ServerList.size() == 0) {
		return;
	}
	else if (ServerList.size() == 1) {


		SendInfo* SIOfPath = new SendInfo(CommandNewFilePath);

		SIOfPath->GetInfo()->append(linkerManager->GetLinkerByNumber(ServerList.at(0)->GetItsFather())->remotePath+ localFileName);

		Send(ServerList.at(0), SIOfPath);

		SendInfo* SIOfData = new SendInfo(CommandNewFile);

		SIOfData->GetInfo()->append(fileData);

		Send(ServerList.at(0), SIOfData);

		Send(ServerList.at(0), new SendInfo(CommandReadyToListen));
		
	}
	else{
		SendInfo* SIOfPath0 = new SendInfo(CommandNewFilePath);

		SIOfPath0->GetInfo()->append(linkerManager->GetLinkerByNumber(ServerList.at(0)->GetItsFather())->remotePath + localFileName);

		Send(ServerList.at(0), SIOfPath0);

		SendInfo* SIOfData0 = new SendInfo(CommandNewFile);

		SIOfData0->GetInfo()->append(fileData);

		Send(ServerList.at(0), SIOfData0);

		SendInfo* SIOfPath1 = new SendInfo(CommandNewFilePath);

		SIOfPath1->GetInfo()->append(linkerManager->GetLinkerByNumber(ServerList.at(1)->GetItsFather())->remotePath + localFileName);

		Send(ServerList.at(1), SIOfPath1);

		SendInfo* SIOfData1 = new SendInfo(CommandNewFile);

		SIOfData1->GetInfo()->append(fileData);

		Send(ServerList.at(1), SIOfData1);

	}
}

void FileSend::ProcInfo(Token token, QByteArray data, Linker* linker) {

	switch (token) {

	case TokenFinish: {

		emit  ServerFinish(linker);

	    int pos= ServerList.indexOf(linker);

		int l = pos * 2 + 1;

		int r = pos * 2 + 2;

		if (l > ServerList.size()) {
			return;
		}

		Send(linker,new SendInfo(CommandReadyToListen));

		if (r < ServerList.size()) {

			SendInfo *SIL = new SendInfo(CommandFathersIp);
			SendInfo *SIFilePathL = new SendInfo(CommandNewFilePath);
			SIFilePathL->GetInfo()->append(linkerManager->GetLinkerByNumber(ServerList.at(l)->GetItsFather())->remotePath + localFileName);
			SIL->GetInfo()->append(linker->ip);
			SIL->GetInfo()->append((const char*)&Port, sizeof(UINT));

			Send(ServerList.at(l), SIL);
			Send(ServerList.at(l), SIFilePathL);

			SendInfo *SIR = new SendInfo(CommandFathersIp);
			SendInfo *SIFilePathR = new SendInfo(CommandNewFilePath);
			SIFilePathR->GetInfo()->append(linkerManager->GetLinkerByNumber(ServerList.at(r)->GetItsFather())->remotePath + localFileName);
			SIR->GetInfo()->append(linker->ip);
			SIR->GetInfo()->append((const char*)&Port, sizeof(UINT));
			Send(ServerList.at(r), SIR);
			Send(ServerList.at(r), SIFilePathR);

			Send(ServerList.at(l), new SendInfo(CommandReadyToConnect));
			Send(ServerList.at(r), new SendInfo(CommandReadyToConnect));
		}
		else if (l < ServerList.size()) {

			SendInfo *SIL = new SendInfo(CommandFathersIp);
			SendInfo *SIFilePathL = new SendInfo(CommandNewFilePath);
			SIFilePathL->GetInfo()->append(linkerManager->GetLinkerByNumber(ServerList.at(l)->GetItsFather())->remotePath + localFileName);
			SIL->GetInfo()->append(linker->ip);
			SIL->GetInfo()->append((const char*)&Port, sizeof(UINT));

			Send(ServerList.at(l), SIL);
			Send(ServerList.at(l), SIFilePathL);
			Send(ServerList.at(l), new SendInfo(CommandReadyToConnect));

		}
		break;
	}

	}
 }
