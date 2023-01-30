#include "CWeather.h"
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include "CWeatchTool.h"

CWeather::CWeather(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowFlag(Qt::FramelessWindowHint);
	
	InitView();
	InitConnect();
	//发送天气请求
	SedWeatherRequest("广州");

}

void CWeather::mousePressEvent(QMouseEvent* event)
{
	m_nPoint = event->globalPos() - this->pos();
}

void CWeather::mouseMoveEvent(QMouseEvent* event)
{
	this->move(event->globalPos() - m_nPoint);
}

void CWeather::InitView()
{
	// 右键菜单：退出程序
	m_ExitMenu = new QMenu(this);
	m_ExitAct = new QAction();
	m_ExitAct->setText(tr("Exit"));
	m_ExitAct->setIcon(QIcon("skin/close.png"));
	m_ExitMenu->addAction(m_ExitAct);

	m_NetAccessManager = new QNetworkAccessManager(this);

	//更新空气质量
	pMapAqi.insert(50, "优");
	pMapAqi.insert(100, "良好");
	pMapAqi.insert(150, "轻度");
	pMapAqi.insert(200, "中度");
	pMapAqi.insert(250, "重度");

	//更新天气图标
	mTypeMap.insert("暴雪", "skin/type/BaoXue.png");
	mTypeMap.insert("多云", "skin/type/DuoYun.png");
	mTypeMap.insert("阴", "skin/type/Yin.png");
	mTypeMap.insert("晴", "skin/type/Qing.png");

	mWeekList << ui.lblWeek0 << ui.lblWeek1 << ui.lblWeek2 << ui.lblWeek3 << ui.lblWeek4 << ui.lblWeek5;
	mDateList << ui.lblDate0 << ui.lblDate1 << ui.lblDate2 << ui.lblDate3 << ui.lblDate4 << ui.lblDate5;
	mTypeList << ui.lblType0 << ui.lblType1 << ui.lblType2 << ui.lblType3 << ui.lblType4 << ui.lblType5;
	mTypeIconList << ui.lblTypeIcon0 << ui.lblTypeIcon1 << ui.lblTypeIcon2 << ui.lblTypeIcon3 << ui.lblTypeIcon4 << ui.lblTypeIcon5;
	mAqiList << ui.lblQuality0 << ui.lblQuality1 << ui.lblQuality2 << ui.lblQuality3 << ui.lblQuality4 << ui.lblQuality5;

}
void CWeather::InitConnect()
{
	connect(m_ExitAct, &QAction::triggered, this, [=]() { 
		qApp->exit(0); 
		});
	connect(m_NetAccessManager, &QNetworkAccessManager::finished, this, &CWeather::SlotRelied);

	connect(ui.btnSearch, &QPushButton::clicked, this, &CWeather::SlotSearch);
}

void CWeather::contextMenuEvent(QContextMenuEvent* event) {
	m_ExitMenu->exec(QCursor::pos());
	event->accept();
}

void CWeather::SedWeatherRequest(const QString& strCityName)
{
	QString strCityCode = CWearherTool::GetCityCode(strCityName);

	if (strCityCode.isEmpty())
	{
		QMessageBox::warning(this, "天气", "请检查是否正确", QMessageBox::Ok);
		return;

	}
	QUrl url("http://t.weather.itboy.net/api/weather/city/" + strCityCode);
	m_NetAccessManager->get(QNetworkRequest(url));
}

void CWeather::parseJson(QByteArray& byteArray)
{
	QJsonParseError err;	
	QJsonDocument doc = QJsonDocument::fromJson(byteArray, &err);
	if (err.error != QJsonParseError::NoError)
	{
		//json错误
		return;
	}

	QJsonObject rootObj = doc.object();
	mToDay.strDate = rootObj.value("date").toString();
	mToDay.strCity = rootObj.value("cityInfo").toObject().value("city").toString();

	//1.解析昨天的数据
	QJsonObject ObjData = rootObj.value("data").toObject();
	QJsonObject ObjYesterDay = ObjData.value("yesterday").toObject();
	mDay[0].strWeek = ObjYesterDay.value("week").toString();
	mDay[0].strDate = ObjYesterDay.value("ymd").toString();
	mDay[0].strType = ObjYesterDay.value("type").toString();

	QString strWendu;
	strWendu = ObjYesterDay.value("high").toString().split(" ").at(1);
	mDay[0].nHigh = strWendu.left(strWendu.length() - 1).toInt();

	strWendu = ObjYesterDay.value("low").toString().split(" ").at(1);
	mDay[0].nLow = strWendu.left(strWendu.length() - 1).toInt();
	
	mDay[0].strFx = ObjYesterDay.value("fx").toString();
	mDay[0].strFl = ObjYesterDay.value("fl").toString();

	//污染指数
	mDay[0].nAqi = ObjYesterDay.value("aqi").toDouble();

	//2.解析forcast5天的
	QJsonArray ArrfFrecastDay = ObjData.value("forecast").toArray();

	for(int i = 0; i < 5; i++)
	{

		QJsonObject objForecast = ArrfFrecastDay[i].toObject();
		mDay[i + 1].strWeek = objForecast.value("week").toString();
		mDay[i + 1].strDate = objForecast.value("ymd").toString();
		mDay[i + 1].strType = objForecast.value("type").toString();

		QString strWendu;
		strWendu = objForecast.value("high").toString().split(" ").at(1);
		mDay[i + 1].nHigh = strWendu.left(strWendu.length() - 1).toInt();

		strWendu = objForecast.value("low").toString().split(" ").at(1);
		mDay[i + 1].nLow = strWendu.left(strWendu.length() - 1).toInt();

		mDay[i + 1].strFx = objForecast.value("fx").toString();
		mDay[i + 1].strFl = objForecast.value("fl").toString();

		//污染指数
		mDay[i + 1].nAqi = objForecast.value("aqi").toDouble();
	}
	
	//3.解析今天的数据
	mToDay.strGanmao = ObjData.value("ganmao").toString();
	QString strWenDu = ObjData.value("wendu").toString();
	mToDay.nWendu = strWenDu.toInt();
	mToDay.strShidu = ObjData.value("shidu").toString();
	mToDay.nPm25 = ObjData.value("pm25").toInt();
	mToDay.strQuelity = ObjData.value("quality").toString(); 

	mToDay.strType = mDay[1].strType;
	mToDay.strFx = mDay[1].strFx;
	mToDay.strFl = mDay[1].strFl;
	mToDay.nHigh = mDay[1].nHigh;
	mToDay.nLow = mDay[1].nLow;

	//更新UI
	UpdataUI();
}

void CWeather::UpdataUI()
{
	//更新日期和城市
	ui.lblDate->setText(QDateTime::fromString(mToDay.strDate, "yyyyMMdd").toString("yyyy/MM/dd") + " " + mDay[1].strWeek);
	ui.lblCity->setText(mToDay.strCity);

	ui.lblTypeIcon->setPixmap(mTypeMap[mToDay.strType]);	
	ui.lblTemp->setText(QString::number(mToDay.nWendu));	
	ui.lblLowHigh->setText(QString::number(mToDay.nLow) + "~" + QString::number(mToDay.nHigh));

	ui.lblGanMao->setText("感冒指数:" + mToDay.strGanmao);
	ui.lblWindFx->setText(mToDay.strFx);
	ui.lblWindFl->setText(mToDay.strFl);

	ui.lblPM25->setText(QString::number(mToDay.nPm25));

	ui.lblShiDu->setText(mToDay.strShidu);
	ui.lblQuality->setText(mToDay.strQuelity);

	for (int i = 0; i < 6; i++)
	{
		//更新时间和日期
		mWeekList[i]->setText(("星期") + mDay[i].strWeek.right(1));
		ui.lblWeek0->setText("昨天");
		ui.lblWeek1->setText("今天");
		ui.lblWeek2->setText("昨天");

		QStringList ymdList = mDay[i].strDate.split("-");
		mDateList[i]->setText(ymdList[1] + "/" + ymdList[2]);
		//更新天气类型	
		mTypeList[i]->setText(mDay[i].strType);
		mTypeIconList[i]->setPixmap(mTypeMap[mDay[i].strType]);
		
		int nCurrentNumber = mDay[i].nAqi;

		QMapIterator<int, QString> iterator(pMapAqi);
		while (iterator.hasNext()) {
			iterator.next();

			if (nCurrentNumber <= iterator.key())
			{
				mAqiList[i]->setText(iterator.value());		
				if (iterator.value().compare("优") == 0)
				{
					mAqiList[i]->setStyleSheet("background-color: rgb(121, 184, 0);");
				}
				else if (iterator.value().compare("良好") == 0)
				{
					mAqiList[i]->setStyleSheet("background-color: rgb(255, 187, 23);");
				}
				else if (iterator.value().compare("轻度") == 0)
				{
					mAqiList[i]->setStyleSheet("background-color: rgb(255, 87, 97);");
				}
				else if (iterator.value().compare("中度") == 0)
				{
					mAqiList[i]->setStyleSheet("background-color: rgb(255, 17, 27);");
				}
				else if (iterator.value().compare("重度") == 0)
				{
					mAqiList[i]->setStyleSheet("background-color: rgb(170, 0, 0);");
				}
				qDebug() << iterator.value();
				break;
			}
			else
			{
				//大于250，属于严重
				mAqiList[i]->setText(iterator.value());
				mAqiList[i]->setStyleSheet("background-color: rgb(110, 0, 0);");
			}
		}
	}	

}

void CWeather::SlotRelied(QNetworkReply* m_NewReply)
{
	int nStatusCode = m_NewReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

	if (nStatusCode != 200 || m_NewReply->error() != QNetworkReply::NoError)
	{
		QMessageBox::warning(this, "天气", "请求数据失败", QMessageBox::Ok);
	}
	else
	{
		QByteArray ByteArray = m_NewReply->readAll();
		parseJson(ByteArray);
	}
	m_NewReply->deleteLater();
}

void CWeather::SlotSearch()
{
	if (ui.leCity->text().isEmpty())
	{
		return;
	}
	SedWeatherRequest(ui.leCity->text());
	ui.leCity->text().clear();

}