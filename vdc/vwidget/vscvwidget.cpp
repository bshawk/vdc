#include "vscvwidget.h"
#include "factory.hpp"
#include "ffmpeg_scale.hpp"
#include <QResizeEvent>
#include <QMimeData>
#include <QDrag>
#include <QAction>
#include <QDesktopWidget>
#include <QApplication>
#include <QDateTime>
#include <QTime>
#include <time.h>

//background-color:rgb(42, 43, 44)

extern Factory *gFactory;
#define ENABLE_OSD_SDL_TTF 0

VSCVWidget::VSCVWidget(s32 nId, QWidget *parent, Qt::WindowFlags flags)
    : QWidget(parent, flags)
{
     
    m_pStarted = FALSE;
    m_nId = nId;
    m_nPlayId = 0;
    m_pRenderBuffer = NULL;
    m_bDeviceDeleted = FALSE;
    m_bFocus = FALSE;
    m_lastMoveTime = 0;
    m_pipe = NULL;
    
    this->setAcceptDrops(true);

    m_pStop = new QAction(QIcon(tr("images/open.ico")), tr("STOP"), this);
    connect(m_pStop, SIGNAL(triggered()), this, SLOT(stopAction()));
    m_pStop->setEnabled(false);

    m_pFloating = new QAction(QIcon(tr("images/open.ico")), tr("FLOAT"), this);
    connect(m_pFloating, SIGNAL(triggered()), this, SIGNAL(ShowFloatingClicked()));

    m_pTabbed = new QAction(QIcon(tr("images/open.ico")), tr("TABBED"), this);
    connect(m_pTabbed, SIGNAL(triggered()), this, SIGNAL(ShowTabbedClicked()));

    m_pDisplay1 = new QAction(QIcon(tr(":/action/resources/display.png")), tr("DISPLAY1"), this);
    connect(m_pDisplay1, SIGNAL(triggered()), this, SLOT(showDisplay1()));

    m_pDisplay2 = new QAction(QIcon(tr(":/action/resources/display.png")), tr("DISPLAY2"), this);
    connect(m_pDisplay2, SIGNAL(triggered()), this, SLOT(showDisplay2()));

    m_pDisplay3 = new QAction(QIcon(tr(":/action/resources/display.png")), tr("DISPLAY3"), this);
    connect(m_pDisplay3, SIGNAL(triggered()), this, SLOT(showDisplay3()));

    m_pDisplay4 = new QAction(QIcon(tr(":/action/resources/display.png")), tr("DISPLAY4"), this);
    connect(m_pDisplay4, SIGNAL(triggered()), this, SLOT(showDisplay4()));
    createContentMenu();
    ui.setupUi(this);
    ui.videoControl->setVisible(false);
    m_videoWindow = (guintptr)ui.video->winId();
    setMouseTracking(true);

    connect(ui.video, SIGNAL(videoMouseMove(QMouseEvent *)), this, SLOT(videoMouseMove(QMouseEvent *)));
    m_Timer = new QTimer(this);
    connect(m_Timer,SIGNAL(timeout()),this,SLOT(UpdateVideoControl()));  
    m_Timer->start(800); 
}

VSCVWidget::~VSCVWidget()
{
    VDC_DEBUG( "%s ~VSCVWidget id %d\n",__FUNCTION__,
            m_nId);
    StopPlay();
    if (m_pStarted != TRUE)
    {
        m_pStarted = TRUE;
    }
}

void VSCVWidget::UpdateVideoControl()
{
   time_t current = time(NULL);
    //VDC_DEBUG( "UpdateVideoControl %d , m_lastMoveTime %d ", 
//		m_nId, m_lastMoveTime);
    //VDC_DEBUG( "current time %d\n",  current);
    if (current - m_lastMoveTime > 1)
    {
        if (m_bFocus == FALSE){
            ui.videoControl->hide();
	     m_bFocus = FALSE;
        }
	 
    }
}

void VSCVWidget::dragEnterEvent(QDragEnterEvent *event)
{
    VDC_DEBUG( "%s Event %s id %d\n",__FUNCTION__,
            event->mimeData()->text().toLatin1().data(),
            m_nId);
    event->acceptProposedAction();
    QWidget::dragEnterEvent(event);
}
void VSCVWidget::dropEvent(QDropEvent *event)
{
    VDC_DEBUG( "%s Enter in dropEvent id %d\n",__FUNCTION__, m_nId);
    if (m_pStarted == TRUE)
    {
        return;
    }

    m_nPlayId = atoi(event->mimeData()->text().toLatin1().data());
    StopPlay();
    StartPlay("fake");

    VDC_DEBUG( "%s Enter in dropEvent Play %d\n",__FUNCTION__, m_nPlayId);
}

void VSCVWidget::stopAction()
{
    StopPlay();
}

void VSCVWidget::showDisplay1()
{
    emit ShowDisplayClicked(0);
}
void VSCVWidget::showDisplay2()
{
    emit ShowDisplayClicked(1);
}
void VSCVWidget::showDisplay3()
{
    emit ShowDisplayClicked(2);
}

void VSCVWidget::showDisplay4()
{
    emit ShowDisplayClicked(3);
}

BOOL VSCVWidget::SetPlayId(u32 nPlayId)
{
    m_nPlayId = nPlayId;
    VDC_DEBUG( "%s Set Player ID %d\n",__FUNCTION__, m_nPlayId);
    return true;
}

BOOL VSCVWidget::StartPlay(std::string strUrl)
{
    m_pStarted = TRUE;
    m_bDeviceDeleted = FALSE;
    DeviceParam param;
    gFactory->GetDeviceParamById(param, m_nPlayId);
    ui.labelName->setText(param.m_Conf.data.conf.Name);
    m_videoThread = new tthread::thread(VSCVWidget::Run, (void *)this);
    m_pStop->setEnabled(true);
    ui.video->setRunning(true);
    return TRUE;
}

void VSCVWidget::createContentMenu()
{
    QDesktopWidget *desktop = QApplication::desktop();
    this->addAction(m_pStop);
    this->addAction(m_pFloating);
    this->addAction(m_pTabbed);

    int screenCnt = desktop->screenCount();
    if (screenCnt == 1)
    {
        this->addAction(m_pDisplay1);
    }else if (screenCnt == 2)
    {
        this->addAction(m_pDisplay1);
        this->addAction(m_pDisplay2);
    }else if (screenCnt == 3)
    {
        this->addAction(m_pDisplay1);
        this->addAction(m_pDisplay2);
        this->addAction(m_pDisplay3);
    }else if (screenCnt == 4)
    {
        this->addAction(m_pDisplay1);
        this->addAction(m_pDisplay2);
        this->addAction(m_pDisplay3);
        this->addAction(m_pDisplay4);
    }else
    {
        this->addAction(m_pDisplay1);
        this->addAction(m_pDisplay2);
        this->addAction(m_pDisplay3);
        this->addAction(m_pDisplay4);
    }

    this->setContextMenuPolicy(Qt::ActionsContextMenu);
}


BOOL VSCVWidget::StopPlay()
{
    if (m_pStarted == true)
    {
        VDC_DEBUG( "%s StopPlay begin\n",__FUNCTION__);
        m_pStarted = false;
        m_bDeviceDeleted = false;
        m_pStop->setEnabled(false);
        if (m_pipe)
	    m_pipe->stop();
	m_videoThread->join();
	ui.video->setRunning(false);
	ui.labelName->setText("");
    }
    VDC_DEBUG( "%s StopPlay End\n",__FUNCTION__);
    return TRUE;
}

BOOL VSCVWidget::DeviceDeleted(u32 nId)
{
    if (m_pStarted == true)
    {
        VDC_DEBUG( "%s DeviceDeleted begin\n",__FUNCTION__);
        m_pStarted = false;
        m_bDeviceDeleted = TRUE;

        VDC_DEBUG( "%s DeviceDeleted end\n",__FUNCTION__);
        m_pStop->setEnabled(false);
    }

    return TRUE;
}

void VSCVWidget::DeviceDeletedCallback(u32 nId, void * pParam)
{
    VSCVWidget *pWidget = NULL;

    if (pParam == NULL)
    {
        return;
    }

    pWidget = (VSCVWidget *)pParam;
    pWidget->DeviceDeleted(nId);
    return;
}


void VSCVWidget::SetVideoFocus(BOOL bFocus)
{

    if (bFocus == FALSE && m_bFocus == TRUE)
    {
        ui.videoControl->hide();
	 setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));
	 VDC_DEBUG( "%s SetVideoFocus %d false\n",__FUNCTION__, m_nId);
	 m_bFocus = bFocus;
    }else if (bFocus == TRUE && m_bFocus == FALSE)
    {
        ui.videoControl->show();
	 setStyleSheet(QStringLiteral("background-color:rgb(85, 255, 0)"));
	 VDC_DEBUG( "%s SetVideoFocus %d true\n",__FUNCTION__, m_nId);
	 m_bFocus = bFocus;
    }
    
}

void VSCVWidget::mousePressEvent(QMouseEvent *e)
{
    VDC_DEBUG( "%s mousePressEvent %d\n",__FUNCTION__, m_nId);
    QWidget::mousePressEvent(e);
    Qt::MouseButtons mouseButtons = e->buttons();
    if( mouseButtons != Qt::LeftButton )
    {
        return;
    }

    emit ShowFocusClicked(m_nId);

}
void VSCVWidget::mouseMoveEvent(QMouseEvent *e)
{
    //VDC_DEBUG( "%s mouseMoveEvent %d\n",__FUNCTION__, m_nId);
    //if (e->pos().y() > height() - ui.videoControl->height()) {
        if (1) {
            //ui.videoControl->show();
        }
    emit ShowFocusClicked(m_nId);
    //}
}

void VSCVWidget::videoMouseMove(QMouseEvent *e)
{
    //VDC_DEBUG( "%s mouseMoveEvent %d\n",__FUNCTION__, m_nId);
    //if (e->pos().y() > height() - ui.videoControl->height()) {
        if (1) {
            //ui.videoControl->show();
            emit ShowFocusClicked(m_nId);
	     m_lastMoveTime = time(NULL);
        }
}

void VSCVWidget::mouseDoubleClickEvent(QMouseEvent *e)
{
    VDC_DEBUG( "%s mouseDoubleClickEvent %d\n",__FUNCTION__, m_nId);
    QWidget::mouseDoubleClickEvent(e);
#if 0
    if(isFullScreen()) {
        this->setWindowState(Qt::WindowMaximized);
    } else {
        //setParent(NULL);
        //showFullScreen();
        this->setWindowState(Qt::WindowFullScreen);
    }
#endif
    emit Layout1Clicked(m_nId);
    //ui.videoControl->setVisible(false);
    //setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));
}

void VSCVWidget::Run(void * pParam)
{
    VSCVWidget *pQtSdl2 = NULL;
    if (pParam == NULL)
    {
        return;
    }
    pQtSdl2 = (VSCVWidget *)pParam;
    //Sleep(3000);

    pQtSdl2->Run1();
}

void VSCVWidget::Run1()
{

    NotificationQueue *pCmd = NULL;
    cmn_cmd cmd;
    int pitch;
    void * pixels = NULL;
    std::string url;
    gFactory->GetUrl(m_nPlayId, url);
    gFactory->RegDeleteCallback(m_nPlayId, VSCVWidget::DeviceDeletedCallback, (void *)this);
    m_pipe = new mediaPipeline(url);
    m_pipe->addWindows(m_videoWindow);
    m_pipe->run();
    delete m_pipe;
    m_pipe = NULL;
 
    return ;
}


