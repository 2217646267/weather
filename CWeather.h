#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CWeather.h"
#include <QMenu>
#include <QAction>
#include <QMouseEvent>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QList>
#include "WeatherData.h"

class CWeather : public QMainWindow
{
	Q_OBJECT

public:
	CWeather(QWidget *parent = Q_NULLPTR);

private:
	Ui::CWeatherClass ui;

protected:
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void contextMenuEvent(QContextMenuEvent* event);
private slots:
	//接受天气信息
	void SlotRelied(QNetworkReply* m_NewReply);
private:
	void InitView();
	void InitConnect();
	//发送请求
	void SedWeatherRequest(const QString& strCityName);
	//解析json数据
	void parseJson(QByteArray &byteArray);
	void UpdataUI();
	void SlotSearch();
private:
	QMenu* m_ExitMenu = nullptr;
	QAction* m_ExitAct = nullptr;	
	QNetworkAccessManager* m_NetAccessManager = nullptr;
	QPoint m_nPoint;

	Today mToDay;
	//存放一周的数据 0昨天 1今天......
	Day mDay[6];

	//星期和周期
	QList<QLabel*> mWeekList;
	QList<QLabel*> mDateList;

	//天气和天气图标
	QList<QLabel*> mTypeList;
	QList<QLabel*> mTypeIconList;

	//天气污染指数
	QList<QLabel*> mAqiList;

	QList<QLabel*> mFxLis;
	QList<QLabel*> mFlLis;
	
	QMap<int, QString> pMapAqi;
	//<天气类型， 对应图标>
	QMap<QString, QString> mTypeMap;
};
