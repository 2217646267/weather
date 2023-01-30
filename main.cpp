#include "CWeather.h"
#include <QtWidgets/QApplication>
#include <QFile>
#include <QTextCodec>
#include "loadfileqss.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LoadFileQss::setStyle("./skin/qss/Weather.qss");
	CWeather w;
	w.show(); 
	return a.exec();
}
