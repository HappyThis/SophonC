#include "MainFunction.h"



void MainFunction::SetItem(QTableWidgetItem * item)
{
	currentItem = item;
}

MainFunction::MainFunction(Linker * arg):BasisFunction(arg){

	SendInfo * SI = new SendInfo(TokenLogin);

	SI->GetInfo()->append((const char*)&(arg->Number), sizeof(int));

	SI->GetInfo()->append((const char*)arg->ip, sizeof(arg->ip));

	Send(SI);
}


MainFunction::~MainFunction(){

}

void MainFunction::ProcInfo(Token token, QByteArray data, Linker* linker) {

	switch (token){

	case TokenLogin: {
		break;
	}

	case TokenHeartBeat: {
		;
		break;
	}
	case CommandGetDir: {

		emit Proc(linker, data, CommandGetDir);
		break;
	}
	case CommandGetFiles: {

		emit Proc(linker, data, CommandGetFiles);
		break;
	}
	case CommandGetOnlineInfo: {

		currentItem->setText(QString(data));
		
		break;
	}
	default: {

		break;
	}
	}

}
