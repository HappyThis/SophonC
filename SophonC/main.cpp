#include "SophonC.h"

#include <QtWidgets/QApplication>

#include<QFile>

#include <QLineSeries>

#include<QStyleFactory>


int main(int argc, char *argv[])
{

	QApplication a(argc, argv);


	qApp->setStyle(QStyleFactory::create("Fusion"));

	SophonC instance;

	instance.show();

	return a.exec();
}
