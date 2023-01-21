#include "CWeather.h"

CWeather::CWeather(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowFlag(Qt::FramelessWindowHint);
	
	InitView();
	InitConnect();
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
}

void CWeather::InitConnect()
{
	connect(m_ExitAct, &QAction::triggered, this, [=]() { 
		qApp->exit(0); 
		});
}

void CWeather::contextMenuEvent(QContextMenuEvent* event) {
	m_ExitMenu->exec(QCursor::pos());
	event->accept();
}