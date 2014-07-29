#ifndef VSC_TOOL_BAR_H
#define VSC_TOOL_BAR_H

#include <QWidget>
#include "ui_vsctoolbar.h"
#include "utility.hpp"
#include <QTimer>

class VSCToolBar : public QWidget
{
    Q_OBJECT

public:
    VSCToolBar(QWidget *parent = 0);
    ~VSCToolBar(){}
	
public slots:
    void showcurrentTime();
	void showAlarm();
    void NewAlarm();
public:
    Ui::VSCToolBar ui;
	
private:
	QTimer *m_Timer;
	QTimer *m_TimerAlarm;
	bool m_alarm;
	int m_alarmCnt;
    
};

#endif // VSC_TOOL_BAR_H
