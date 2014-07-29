#include "vscvwidget.h"
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
#include "QMimeData"
#include "QPainter"
#include "QPixmap"
#include "vscpbthread.h"


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
    m_InstantPbMode = FALSE;
    m_pbThread = NULL;
    m_autoUpdate = TRUE;
    m_Render = RENDER_QT;
    m_DragStart = FALSE;
    m_PtzStart = FALSE;
    m_PtzEnable = FALSE;
    gettimeofday(&m_lastPtz, NULL);
    
    this->setAcceptDrops(true);

    m_pStop = new QAction(QIcon(tr(":/action/resources/stop.png")), tr("Stop"), this);
    connect(m_pStop, SIGNAL(triggered()), this, SLOT(stopAction()));
    m_pStop->setEnabled(false);

    m_pFloating = new QAction(QIcon(tr(":/action/resources/float.png")), tr("Float"), this);
    connect(m_pFloating, SIGNAL(triggered()), this, SIGNAL(ShowFloatingClicked()));

    
    m_pPTZ = new QAction(QIcon(tr(":/device/resources/dome.png")), tr("PTZ"), this);
    connect(m_pPTZ, SIGNAL(triggered()), this, SLOT(PTZEnable()));        

    m_pRecord = new QAction(QIcon(tr("images/open.ico")), tr("RECORD"), this);
    //connect(m_pFloating, SIGNAL(triggered()), this, SIGNAL(ShowFloatingClicked()));

    m_pTabbed = new QAction(QIcon(tr(":/action/resources/tabbed.png")), tr("Tabbed"), this);
    connect(m_pTabbed, SIGNAL(triggered()), this, SIGNAL(ShowTabbedClicked()));

   m_pControlEnable = new QAction(QIcon(tr(":/action/resources/control_panel.png")), tr("Control Panel"), this);
    connect(m_pControlEnable, SIGNAL(triggered()), this, SIGNAL(ShowControlPanelClicked()));

    m_pDisplay1 = new QAction(QIcon(tr(":/action/resources/display.png")), tr("DISPLAY 1"), this);
    connect(m_pDisplay1, SIGNAL(triggered()), this, SLOT(showDisplay1()));

    m_pDisplay2 = new QAction(QIcon(tr(":/action/resources/display.png")), tr("DISPLAY 2"), this);
    connect(m_pDisplay2, SIGNAL(triggered()), this, SLOT(showDisplay2()));

    m_pDisplay3 = new QAction(QIcon(tr(":/action/resources/display.png")), tr("DISPLAY 3"), this);
    connect(m_pDisplay3, SIGNAL(triggered()), this, SLOT(showDisplay3()));

    m_pDisplay4 = new QAction(QIcon(tr(":/action/resources/display.png")), tr("DISPLAY 4"), this);
    connect(m_pDisplay4, SIGNAL(triggered()), this, SLOT(showDisplay4()));


   
    createContentMenu();
    ui.setupUi(this);
    ui.videoControl->setVisible(false);
    //ui.widgetTimeline->hide();
    /* Hide all the control button */
    
    StopPlayUI();
    
    //ui.videoControl->setMaximumHeight(20);
    m_videoWindow = (HWND)ui.video->winId();
    setMouseTracking(true);

    connect(ui.video, SIGNAL(videoMouseMove(QMouseEvent *)), this, SLOT(videoMouseMove(QMouseEvent *)));
    connect(ui.video, SIGNAL(videoResize()), this, SLOT(videoResizeEvent()));

    connect(ui.pbInstantpb, SIGNAL( clicked() ), this, SLOT(instantPbClick()));
    connect(ui.widgetTimeline, SIGNAL( TimeLineChange(int) ), this, SLOT(TimeLineChanged(int)));
    ui.widgetTimeline->SetEnabled(FALSE);

    connect(ui.pbPause, SIGNAL( clicked() ), this, SLOT(InstantPbPause()));
    connect(ui.pbPlay, SIGNAL( clicked() ), this, SLOT(InstantPbPlay()));
    connect(ui.timelineZoom, SIGNAL( currentIndexChanged (int) ), 
        this, SLOT(TimeLineLengthChanged(int)));
    ui.timelineZoom->setCurrentIndex (TIMELINE_LEN_5_MIN);


    m_Timer = new QTimer(this);
    connect(m_Timer,SIGNAL(timeout()),this,SLOT(UpdateVideoControl()));  
    m_Timer->start(500); 
    m_lastWidth = ui.video->width();
    m_lastHeight = ui.video->height();
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


void VSCVWidget::SetRenderD3D()
{

}

void VSCVWidget::TimeLineLengthChanged(int index)
{
    VDC_DEBUG( "%s  index Changed %d\n",__FUNCTION__,
            index);
    ui.widgetTimeline->SetTimeLineLength((VscTimelineLength)index);
}


void VSCVWidget::InstantPbPause()
{
    if (m_pbThread)
    {
        m_pbThread->SetPlaying(FALSE);
    }
    ui.pbPause->hide();
    ui.pbPlay->show();
}
void VSCVWidget::InstantPbPlay()
{
    if (m_pbThread)
    {
        m_pbThread->SetPlaying(TRUE);
    }
    ui.pbPause->show();
    ui.pbPlay->hide();
    
}

void VSCVWidget::LivePlayControlUI()
{
    ui.pbInstantpb->show();
    //ui.pbRecord->show();
    ui.timelineZoom->hide();
    ui.pbPause->hide();
    ui.pbPlay->hide();
}
void VSCVWidget::InstantPbControlUI()
{
    ui.pbInstantpb->show();
    //ui.pbRecord->show();
    ui.timelineZoom->show();
    //ui.pbPause->show();
    //ui.pbPlay->show();
}

void VSCVWidget::InstantPbControlUISimple()
{
    //ui.pbInstantpb->hide();
    ui.pbRecord->hide();
    ui.timelineZoom->hide();
}
void VSCVWidget::StopPlayUI()
{
    ui.timelineZoom->hide();
    ui.pbPause->hide();
    ui.pbPlay->hide();
    ui.pbInstantpb->hide();
    ui.pbRecord->hide();
}

void VSCVWidget::DeviceEvent(int deviceId, VscEventType type)
{
    if (m_pStarted == false || m_InstantPbMode == true)
        return;
    if (deviceId != m_nPlayId)
	return;
    VDC_DEBUG( "%s  Device Event %d\n",__FUNCTION__,
            m_nPlayId);
    gFactory->ShowAlarm(m_nPlayId, m_videoWindow);	
    return;
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
    if (m_pStarted == FALSE && m_InstantPbMode == FALSE)
        return;
    
    BOOL bRecording = FALSE;
 #if 0
    if (gFactory->GetRecordStatus(m_nPlayId, bRecording) == TRUE)
    {
         if (bRecording == TRUE)
         {
             ui.pbRecord->setIcon(QIcon(":/pb/resources/recordclick.jpg"));
             ui.labelRecording->setText("Recording");
         }else
         {
             ui.pbRecord->setIcon(QIcon(":/pb/resources/record.jpg"));
             ui.labelRecording->setText("");
         }
    }

    BOOL bonline = FALSE;
    if (m_InstantPbMode != TRUE)
    {
        if (gFactory->GetDeviceOnline(m_nPlayId, bonline) == TRUE)
        {
            if (bonline != TRUE )
            {
            	    //SetVideoUpdate(true);
            }else
            {
            	    //SetVideoUpdate(false);
            }
        }
    }else
    {
         s32 nWidth = ui.video->width();
         s32 nHeight = ui.video->height();

         VDC_DEBUG( "current width %d nWidth last %d\n",  nWidth, m_lastWidth);
         if ((nWidth != m_lastWidth ) && m_autoUpdate == FALSE)
         {
             ChangeLayout();
         }
         m_lastWidth = nWidth;
         m_lastHeight = nHeight;
    }
   #endif
}



BOOL VSCVWidget::SetVideoUpdateNoPaint(BOOL update)
{
    ui.video->setUpdatesEnabled(update);

    m_autoUpdate = update;
    return TRUE;
}

BOOL VSCVWidget::SetVideoUpdate(BOOL update)
{
    ui.video->setUpdatesEnabled(update);
    if (update == TRUE)
        repaint();

    m_autoUpdate = update;
    return TRUE;
}

BOOL VSCVWidget::ChangeLayout()
{
    if (m_autoUpdate == FALSE)
    {
        //SetVideoUpdate(TRUE);
        //SetVideoUpdate(FALSE);
    }

    return TRUE;
}

void VSCVWidget::TimeLineChanged(int nStatus )
{
    VscTimelineMode TimeLineMode = (VscTimelineMode)nStatus ;
    if (TimeLineMode ==  TIMELINE_MODE_SIMPLE)
    {
        InstantPbControlUISimple();
    }else /* TIMELINE_MODE_FULL */ 
    {
        InstantPbControlUI();
    }
}

void VSCVWidget::instantPbClick()
{
    if (m_InstantPbMode == TRUE)
    {
        ui.pbInstantpb->setIcon(QIcon(":/pb/resources/instantpb.jpg"));
        m_InstantPbMode = FALSE;
        //ui.widgetTimeline->hide();
        //ui.videoControl->setMaximumHeight(20);
        ui.widgetTimeline->SetEnabled(FALSE);
        m_pbThread->setQuit();
        m_pbThread->wait();
        StartPlayLive("fake");
        InstantPbPause();
        LivePlayControlUI();
        disconnect(m_pbThread, SIGNAL(ChangedToPause() ), this, 
                                        SLOT(InstantPbPause()));
        disconnect(m_pbThread, SIGNAL(GetANewFrame() ), this, 
                                        SLOT(SetRenderD3D()));
        delete m_pbThread;
        m_pbThread = NULL;
        
    }else
    {
        StopPlayLive();
        ui.pbInstantpb->setIcon(QIcon(":/pb/resources/instantpbclick.jpg"));
        m_InstantPbMode = TRUE;

        ui.widgetTimeline->SetEnabled(TRUE);
        ui.widgetTimeline->SetId(m_nPlayId);
        SetVideoUpdate(false);

        InstantPbControlUI();
        //ui.videoControl->setMaximumHeight(45);
        m_pbThread = new VSCPbThread(m_nPlayId, time(NULL) - 5 * 60, 
            *ui.widgetTimeline, m_videoWindow, *ui.video, m_vPlay);
#if 1        
    connect(m_pbThread, SIGNAL(ChangedToPause() ), this, 
                                        SLOT(InstantPbPause()));
    connect(m_pbThread, SIGNAL(GetANewFrame() ), this, 
                                        SLOT(SetRenderD3D()));
#endif
        m_pbThread->start();
        InstantPbPlay();
            
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

    s32 nPlayId = atoi(event->mimeData()->text().toLatin1().data());
    if (nPlayId < VWIDGET_ID_OFFSET)
    {
       if (m_pStarted == TRUE)
       {
            return;
       }
       m_nPlayId = nPlayId;
        StopPlay();
        StartPlay("fake");
        return;
    }
    

    VDC_DEBUG( "%s Enter in dropEvent Play %d\n",__FUNCTION__, nPlayId);

    nPlayId = nPlayId - VWIDGET_ID_OFFSET;

    if (nPlayId == m_nId)
    {
        VDC_DEBUG( "%s Enter in dropEvent Same with me %d\n", 
            __FUNCTION__, nPlayId);
        return;
    }
    emit VideoSwitchWith(m_nId, nPlayId);
    VDC_DEBUG( "%s Enter in dropEvent  me %d switch with %d\n", 
            __FUNCTION__, m_nId, nPlayId);
}

void VSCVWidget::stopAction()
{
    StopPlay();
}

void VSCVWidget::PTZEnable()
{
    if (m_PtzEnable == FALSE)
    {
    	m_PtzEnable = TRUE;
    }else
    {
    	m_PtzEnable = FALSE;
    }
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

BOOL VSCVWidget::StartPlayLive(std::string strUrl)
{
    m_pStarted = TRUE;
    m_bDeviceDeleted = FALSE;
    DeviceParam param;
    gFactory->GetDeviceParamById(param, m_nPlayId);
    
    ui.labelName->setText(param.m_Conf.data.conf.Name);

    SetVideoUpdate(false);
    gFactory->AttachPlayer(m_nPlayId, m_videoWindow, ui.video->width(), 
								ui.video->height());
    m_pStop->setEnabled(true);
    ui.video->setRunning(true);
    return TRUE;
}

void VSCVWidget::videoResizeEvent()
{    
	VDC_DEBUG( "%s Resize %d\n",__FUNCTION__, m_nPlayId);   
	if (m_pStarted == TRUE)
	{
    		gFactory->UpdateWidget(m_nPlayId, m_videoWindow, ui.video->width(), 
								ui.video->height());		
	}
}

BOOL VSCVWidget::StartPlay(std::string strUrl)
{
    ui.pbInstantpb->show();
    StartPlayLive(strUrl);
    return TRUE;
}

BOOL VSCVWidget::StopPlay()
{
    if (m_InstantPbMode == FALSE)
    {
        StopPlayLive();
    }else
    {
        ui.pbInstantpb->setIcon(QIcon(":/pb/resources/instantpb.jpg"));
        m_InstantPbMode = FALSE;
        //ui.widgetTimeline->hide();
        //ui.videoControl->setMaximumHeight(20);
        ui.widgetTimeline->SetEnabled(FALSE);
        m_pbThread->setQuit();
        m_pbThread->wait();
        SetVideoUpdate(true);
        disconnect(m_pbThread, SIGNAL(ChangedToPause() ), this, 
                                        SLOT(InstantPbPause()));
        delete m_pbThread;
        m_pbThread = NULL;
    }
    StopPlayUI();
    ui.pbRecord->setIcon(QIcon(":/pb/resources/record.jpg"));
    ui.labelRecording->setText("");
    ui.labelName->setText("");
    m_pStop->setEnabled(false);

    return TRUE;
}

void VSCVWidget::createContentMenu()
{
    QDesktopWidget *desktop = QApplication::desktop();
    this->addAction(m_pStop);
    this->addAction(m_pPTZ);
    this->addAction(m_pFloating);
    this->addAction(m_pTabbed);
    this->addAction(m_pControlEnable);
    //this->addAction(m_pRecord);
    //this->addAction(m_pPlayback);

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


BOOL VSCVWidget::StopPlayLive()
{
    if (m_pStarted == true)
    {
        VDC_DEBUG( "%s StopPlay begin\n",__FUNCTION__);
        m_pStarted = false;
        m_bDeviceDeleted = false;
        gFactory->DetachPlayer(m_nPlayId, m_videoWindow);
        
	ui.video->setRunning(false);
	//ui.labelName->setText("");
	SetVideoUpdate(true);
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
	 ui.widget_3->setStyleSheet(QStringLiteral("background-color:rgb(100, 100, 100)"));
	 //VDC_DEBUG( "%s SetVideoFocus %d false\n",__FUNCTION__, m_nId);
	 m_bFocus = bFocus;
    }else if (bFocus == TRUE && m_bFocus == FALSE)
    {
        ui.videoControl->show();
	 ui.widget_3->setStyleSheet(QStringLiteral("background-color:rgb(85, 255, 0)"));
	 //VDC_DEBUG( "%s SetVideoFocus %d true\n",__FUNCTION__, m_nId);
	 m_bFocus = bFocus;
    }
    videoResizeEvent();
    
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
    if (m_pStarted == TRUE || m_InstantPbMode == TRUE)
    {
    	 if (m_PtzStart == FALSE)
    	 {
    	 	//if (abs(e->x() - width()/2) < 20 && abs(e->y() - height()/2) < 20)
    	 	if (m_PtzEnable == TRUE)
    	 	{
            		VDC_DEBUG( "%s mousePressEvent %d PTZ Start\n",__FUNCTION__, m_nId);
			m_PtzStart = TRUE;
			m_lastPtzX = e->x();
			m_lastPtzY = e->y();
			return;
    	 	}
    	 }
        if (m_DragStart == FALSE)
        {
            m_lastDragX = e->x();
            VDC_DEBUG( "%s mousePressEvent %d start x %d\n",__FUNCTION__, m_nId, m_lastDragX);
            m_DragStart = TRUE;
            return;
        }
    }

}

void VSCVWidget::mouseReleaseEvent(QMouseEvent *event)
{
    VDC_DEBUG( "%s id %d Release \n",__FUNCTION__, m_nId);
    if(event->button() == Qt::LeftButton)
    {
        m_DragStart = false;
	if (m_PtzStart == TRUE)
	{
		if (m_pStarted == TRUE)
		{
	    		gFactory->ClearPtzDirection(m_nPlayId, m_videoWindow);	
			PtzActionStop();
		}	
		m_PtzStart = FALSE;
	}
    }
    event->accept();
}

void VSCVWidget::PtzActionStop()
{
	gFactory->PtzAction(m_nPlayId, F_PTZ_STOP, 0.0);
}

void VSCVWidget::PtzAction(int x1, int y1, int x2, int y2)
{
	struct timeval current;
	gettimeofday(&current, NULL);
	if (current.tv_sec == m_lastPtz.tv_sec)
	{
		if (current.tv_usec - m_lastPtz.tv_usec < 900000)
		{
			return;
		}
	}
	if (current.tv_sec -  m_lastPtz.tv_sec == 1)
	{
		if (current.tv_usec + 1000000 - m_lastPtz.tv_usec < 900000)
		{
			return;
		}		
	}
	gettimeofday(&m_lastPtz, NULL);

	FPtzAction action;
	int diffx = abs(x1 - x2);
	int diffy = abs(y1 - y2);
	if (diffx - diffy >= 0)
	{
		if (x1 - x2 > 0)
		{
			gFactory->PtzAction(m_nPlayId, F_PTZ_LEFT, ((float)diffx / (float)x1));
		}else
		{
			gFactory->PtzAction(m_nPlayId, F_PTZ_RIGHT, ((float)diffx / (float)x1));
		}
	}else
	{
		if (y1 - y2 > 0)
		{
			gFactory->PtzAction(m_nPlayId, F_PTZ_UP, ((float)diffy / (float)y1));
		}else
		{
			gFactory->PtzAction(m_nPlayId, F_PTZ_DOWN, ((float)diffy / (float)y1));
		}	
	}
}

void VSCVWidget::videoMouseMove(QMouseEvent *e)
{
    VDC_DEBUG( "%s mouseMoveEvent %d\n",__FUNCTION__, m_nId);
    //if (e->pos().y() > height() - ui.videoControl->height()) {
        if (1) {
            //ui.videoControl->show();
            emit ShowFocusClicked(m_nId);
	     m_lastMoveTime = time(NULL);
        }
    if (m_pStarted == TRUE || m_InstantPbMode == TRUE)
    {
        if (m_DragStart == TRUE)
        {
           VDC_DEBUG( "%s mouseMoveEvent %d event x %d\n",__FUNCTION__, m_nId, e->x());
           if (abs(e->x() - m_lastDragX) < 5)
           {
               return;
           }
        }else if (m_PtzStart == TRUE)
        {
		if (abs(e->x() - m_lastPtzX) < 10 || abs(e->y() - m_lastPtzY) < 10 )
		{
		   return;
		}
		gFactory->DrawPtzDirection(m_nPlayId, m_videoWindow, 
			width()/2, height()/2, e->x(), e->y());
		PtzAction(width()/2, height()/2, e->x(), e->y());
		m_lastPtzX = e->x();
		m_lastPtzY = e->y();
		return;
        }
        else
        {
            return;
        }
        u32 nId = m_nId;
        m_DragStart = FALSE;
        VDC_DEBUG( "%s id %d\n",__FUNCTION__, nId);
    	QMimeData *mimeData = new QMimeData();
    	mimeData->setText(QString::number(nId + VWIDGET_ID_OFFSET));
    	
    	// Create drag
    	QPixmap pixmap(":/device/resources/camera1.png");
    	QPainter painter(&pixmap);
    
    	QDrag *drag = new QDrag(this);
    	drag->setMimeData(mimeData);
    	drag->setPixmap(pixmap);
                  drag->setHotSpot(QPoint(drag->pixmap().width()/2,
                         drag->pixmap().height()/2));
    	drag->exec();
        
    }
}

void VSCVWidget::mouseDoubleClickEvent(QMouseEvent *e)
{
    VDC_DEBUG( "%s mouseDoubleClickEvent %d\n",__FUNCTION__, m_nId);
    QWidget::mouseDoubleClickEvent(e);
    m_DragStart = false;
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


void VSCVWidget::wheelEvent ( QWheelEvent * event )
{
	VDC_DEBUG( "%s wheelEvent %d %d\n",__FUNCTION__, m_nId, event->delta());
	//scale+=(event->delta()/120); //or use any other step for zooming 
}


