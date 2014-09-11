#ifndef QT_VSC_V_WIDGET_H
#define QT_VSC_V_WIDGET_H

#include <QWidget>

#define NOMINMAX
#define NOMINMAX 
//#include <inttypes.h>



#include "tinythread.h"
#include "fast_mutex.h"
#include "utility.hpp"
#include "ui_vscvwidget.h"
//#include "mpipeline.hpp"
#include "debug.hpp"
#include "device.hpp"
#include <QTimer>
#include "vscpbthread.h"
using  namespace tthread;

class FFmpegScale;

typedef enum
{
    RENDER_QT = 1,
    RENDER_TRAN,
    RENDER_D3D,
    RENDER_LAST
} VideoRenderType;

#define  VWIDGET_ID_OFFSET 60000

class VSCVWidget : public QWidget
{
    Q_OBJECT

public:
    VSCVWidget(s32 nId, QWidget *parent = 0, Qt::WindowFlags flags = 0);
    ~VSCVWidget();
    void mouseDoubleClickEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void wheelEvent ( QWheelEvent * event );
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    Qt::DropActions supportedDropActions () const
    {
            return Qt::MoveAction;
    }
    void dropEvent(QDropEvent *event);
    void createContentMenu();
    void setId(s32 nId)
    {
        m_nId = nId;
    }
    void SetVideoFocus(BOOL bFocus);
    virtual bool eventFilter(QObject *obj, QEvent *event)
    {
        if (event->type() == QEvent::MouseMove && obj == ui.videoControl)
        {
            VDC_DEBUG( "%s mouseMoveEvent %p\n",__FUNCTION__, this);
        }
	 return false;
    }
    BOOL SetVideoUpdate(BOOL update);
    BOOL SetVideoUpdateNoPaint(BOOL update);
    BOOL ChangeLayout();
    void DeviceEvent(int deviceId, VscEventType type);
    void PtzAction(int x1, int y1, int x2, int y2);
    void PtzActionStop();

private slots:
    void stopAction();
    void showDisplay1();
    void showDisplay2();
    void showDisplay3();
    void showDisplay4();
    void videoMouseMove(QMouseEvent *e);
    void UpdateVideoControl();
    void instantPbClick();
    void TimeLineChanged(int nStatus );
    void InstantPbPause();
    void InstantPbPlay();
    void TimeLineLengthChanged(int index);
    void SetRenderD3D();
    void videoResizeEvent();
    void PTZEnable();

signals:
    void ShowDisplayClicked(int nId);
    void ShowFloatingClicked();
    void ShowTabbedClicked();
    void ShowControlPanelClicked();
    void ShowFocusClicked(int nId);
    void Layout1Clicked(int nId);
    void VideoSwitchWith(int nSrcId, int nDstId);


public:
    BOOL StartPlay(std::string strUrl);
    BOOL StopPlay();
    BOOL StartPlayLive(std::string strUrl);
    BOOL StopPlayLive();
    void LivePlayControlUI();
    void InstantPbControlUI();
    void InstantPbControlUISimple();
    void StopPlayUI();
    BOOL DeviceDeleted(u32 nId);
    BOOL SetPlayId(u32 nPlayId);
    static void DeviceDeletedCallback(u32 nId, void * pParam);
    

/* Thread */
private:
    tthread::thread *m_videoThread;
    HWND m_videoWindow;
    //mediaPipeline *m_pipe;
    tthread::fast_mutex m_Mutex;
    BOOL m_bFocus;
    s32 m_nId;
    u32 m_nPlayId;
    s32 m_w;
    s32 m_h;
    unsigned char *m_pRenderBuffer;
    BOOL m_pStarted;
    BOOL m_bDeviceDeleted;
    QAction *m_pStop;
    QAction *m_pRecord;
    QAction *m_pPTZ;
    QAction *m_pDisplay1;
    QAction *m_pDisplay2;
    QAction *m_pDisplay3;
    QAction *m_pDisplay4;

    QAction *m_pFloating;
    QAction *m_pTabbed;
    QAction *m_pControlEnable;


    /* TTF Font */
    int m_nFontSize;
    int m_lastTime;
    BOOL m_InstantPbMode;
	
private:
    QTimer *m_Timer;
    time_t m_lastMoveTime;
    VSCPbThread *m_pbThread;

public:
    Ui::VSCVWidget ui;
/* Playback  */
private:
    VPlay m_vPlay;;   
    BOOL m_autoUpdate;
private:
    VideoRenderType m_Render;
    BOOL m_DragStart;
    s32 m_lastDragX;
    s32 m_lastWidth;
    s32 m_lastHeight;

	BOOL m_PtzStart;
	s32 m_lastPtzX;
	s32 m_lastPtzY;
	BOOL m_PtzEnable;
	struct timeval m_lastPtz;
	struct timeval m_lastPtzZoom;
	
    
};

#endif // QT_VSC_V_WIDGET_H
