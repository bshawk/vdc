#include "videowidget.h"
#include "factory.hpp"
#include <QResizeEvent>
#include <QMimeData>
#include <QDrag>
#include <QAction>
#include <QDesktopWidget>
#include <QApplication>
#include <QDateTime>
#include <QTime>
#include <time.h>
#include <QStyleOption>
#include <QPainter>

//background-color:rgb(42, 43, 44)


VideoWidget::VideoWidget(QWidget *parent, Qt::WindowFlags flags)
    : QWidget(parent, flags)
{
    setMouseTracking(true);
	setStyleSheet(QStringLiteral("background-color:rgb(0, 0, 0)"));
    //QPalette pal = palette();
    //pal.setColor(QPalette::Background, QColor(0x00,0x00,0x00,0xff));
    //setPalette(pal);
	//setAttribute(Qt::WA_TranslucentBackground);
	m_isRunning = false;
}

VideoWidget::~VideoWidget()
{

}

void VideoWidget::mouseMoveEvent(QMouseEvent *e)
{
    //VDC_DEBUG( "%s mouseMoveEvent %p\n",__FUNCTION__, this);
    //if (e->pos().y() > height() - ui.videoControl->height()) {
        if (1) {
            //ui.videoControl->show();
        }
    //}
	emit videoMouseMove(e);
}
#if 1
void VideoWidget::paintEvent(QPaintEvent *)
{
	// if (m_isRunning == false)
	 {
		 QStyleOption opt;
		 opt.init(this);
		 QPainter p(this);
		 style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
	 }
}
#endif

void VideoWidget::resizeEvent( QResizeEvent * event )
{    
	VDC_DEBUG( "%s Resize\n",__FUNCTION__);   
	QWidget::resizeEvent(event);    
	emit videoResize();
}

