#pragma once

#include <QMap>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QString>
#include <QTextCodec>

//城市名称转换城市编码
class CWearherTool
{
private:

	// <城市名， 城市编码>
	static QMap<QString, QString> CityMap;

	static void InitMap()
	{
		//读取文件
		QString strFilePlah = "CityInfo/citycode.json";
		QFile File(strFilePlah);
		if (File.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			QByteArray JsonArray = File.readAll();
			File.close();

			QJsonParseError err;
			QJsonDocument doc = QJsonDocument::fromJson(JsonArray, &err);
			if(err.error != QJsonParseError::NoError)
			{ 
				return;
			}
			if (!doc.isArray())
			{
				return;
			}
			QJsonArray CityArray = doc.array();
			for (int i = 0; i < CityArray.size(); i++)
			{
				QString strCity = CityArray[i].toObject().value("city_name").toString();
				QString strCode = CityArray[i].toObject().value("city_code").toString();

				CityMap.insert(strCity, strCode);
			}

		}
	}

public:
	static QString GetCityCode(QString strCityName)
	{	
		
		if (CityMap.isEmpty())
		{
			InitMap();
		}
	
		QMap<QString, QString>::iterator it = CityMap.find(strCityName);
		// 北京/北京市
		if (it == CityMap.end())
		{
			
			if (strCityName.indexOf("市") != -1)
			{
				//it = CityMap.find(strCityName + "市");
			   QString strCity = strCityName.remove(strCityName.length() -1, strCityName.length());
				it = CityMap.find(strCity);
			}

			
		}

		if (it != CityMap.end())
		{
			return it.value();
		}
		
		return "";

	}
};

QMap<QString, QString> CWearherTool::CityMap = {};
