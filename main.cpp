#include "CWeather.h"
#include <QtWidgets/QApplication>
#include <QFile>
#include "loadfileqss.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LoadFileQss::setStyle("./qss/Weather.qss");
	CWeather w;
	w.show(); 
	return a.exec();
}
