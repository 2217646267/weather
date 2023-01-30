#pragma once
#include <QString>

class Today
{
public:
	Today()
	{
		strDate = "2022-10-20";
		strCity = "广州";
		strGanmao = "感冒指数";
		nWendu = -99;
		strShidu = "0%";
		strQuelity = "暂无数据";
		strType = "多云";
		strFx = "风向";
		strFl = "风力";
		nHigh = 30;
		nLow = 18;
	}
	QString strDate;
	QString strCity;
	QString strGanmao;
	int nWendu;
	QString strShidu;
	int nPm25;
	QString strQuelity;
	QString strType;
	QString strFx;
	QString strFl;
	int nHigh;
	int nLow;
};


class Day
{
public:
	Day()
	{
		strDate = "2022-10-20";
		strWeek = "周五";
		strType = "多云";
		nHigh = 0;
		nLow = 0;
		strFx = "多云";
		strFl = "多云";
		nAqi = 0;
	}
	QString strDate;
	QString strWeek;
	QString strType;
	int nHigh;
	int nLow;
	QString strFx;
	QString strFl;		
	double nAqi;
};

