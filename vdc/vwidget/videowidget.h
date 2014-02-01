#ifndef __VIDEO_WIDGET_H
#define __VIDEO_WIDGET_H

#include <QWidget>

#define NOMINMAX
#define NOMINMAX 
//#include <inttypes.h>


#include "tinythread.h"
#include "fast_mutex.h"
#include "utility.hpp"
#include "mpipeline.hpp"
using  namespace tthread;


class VideoWidget : public QWidget
{
    Q_OBJECT

public:
    VideoWidget(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    ~VideoWidget();


public:
    void mouseMoveEvent(QMouseEvent *e);    
	void paintEvent(QPaintEvent *);
	void setRunning(bool isRunning)
	{
		m_isRunning = isRunning;
		return;
	}
	
	
signals:
    void videoMouseMove(QMouseEvent *e);

private:
	bool m_isRunning;
};

#endif // __VIDEO_WIDGET_H
