#include "LinkerManager.h"

LinkerManager* LinkerManager::instance = nullptr;

/*
QVector<Linker*> LinkerManager::onlineLinker;

QQueue<Linker*>   LinkerManager::offlineLinker;

QMutex LinkerManager::mutex;
*/

LinkerManager::LinkerManager() {

}


LinkerManager::~LinkerManager() {

}

Linker * LinkerManager::AllocateNewLinker() {

	mutex.lock();

	/*Can be reused*/

	if (offlineLinker.size() > 0) {

		qDebug() << "-------------Test_Start---------------";

		Linker* tempOfOfflineLinker = offlineLinker.front();

		offlineLinker.pop_front();

		tempOfOfflineLinker->Clear();

		qDebug() << "-------------Test_End---------------";

		mutex.unlock();

		

		return tempOfOfflineLinker;

	}

	/*Can't be reused*/

	onlineLinker.append(new Linker(onlineLinker.size()));

	mutex.unlock();


	return onlineLinker.last();
}


void LinkerManager::KickLinker(UINT aim) {


	Sleep(0);

	Linker* ReadyToKickLinker = onlineLinker.at(aim);

	if (ReadyToKickLinker->activeState.testAndSetOrdered(NULL,NULL)) {

		return;

	}
	(void)ReadyToKickLinker->activeState.fetchAndStoreOrdered(NULL);


	/*Move it to the offline queue*/

	offlineLinker.push_back(ReadyToKickLinker);

	/*Emit a kick-off signal to the GUI*/


	/*Close its socket*/

	linger lig;

	lig.l_onoff = 1;

	lig.l_linger = 0;

	setsockopt(ReadyToKickLinker->socket, SOL_SOCKET, SO_LINGER, (char *)&lig, sizeof(linger));

	closesocket(ReadyToKickLinker->socket);

	ReadyToKickLinker->socket = INVALID_SOCKET;

	if (ReadyToKickLinker->Fnumber == ReadyToKickLinker->Number) {

		emit DeleteServer(ReadyToKickLinker->Number);

	}


}

LinkerManager * LinkerManager::GetInstance()
{
	if (instance == nullptr) {

		return instance = new LinkerManager();
	}
	return instance;
}

void LinkerManager::KickAllLinker() {

	mutex.lock();

	for (Linker* linker : onlineLinker) {

		if (linker->activeState.testAndSetOrdered(NULL, NULL))

			continue;

		KickLinker(linker->Number);

		//delete linker;

	}

	onlineLinker.clear();

	for (Linker* linker : offlineLinker) {

		delete linker;
	}

	offlineLinker.clear();

	mutex.unlock();

}

void LinkerManager::SetFatherAndInstanceByNumber(UINT father, Linker * son, BasisFunction * bf, int Function) {

	mutex.lock();

	son->SetItsFather(father);

	son->instance = bf;

	son->Fnumber = father;

	onlineLinker.at(father)->Son[Function] = bf;

	mutex.unlock();
}

BasisFunction* LinkerManager::GetInstanceByNumber(UINT aim, int Function) {

	
	return onlineLinker.at(aim)->Son[Function];
}

BasisFunction * LinkerManager::GetInstanceByNumber(UINT aim) {


	return onlineLinker.at(aim)->instance;

}

Linker * LinkerManager::GetLinkerByNumber(UINT aim)
{
	return onlineLinker.at(aim);
}

