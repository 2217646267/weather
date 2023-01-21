#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CWeather.h"
#include <QMenu>
#include <QAction>
#include <QMouseEvent>

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
private:
	void InitView();
	void InitConnect();
private:
	QMenu* m_ExitMenu;
	QAction* m_ExitAct;
	QPoint m_nPoint;
};
