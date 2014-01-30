#ifndef QT_VSC_V_WIDGET_H
#define QT_VSC_V_WIDGET_H

#include <QWidget>

#define NOMINMAX
#define NOMINMAX 
//#include <inttypes.h>

#include "SDL.h"
#include "SDL_ttf.h"
#undef main

#include "tinythread.h"
#include "fast_mutex.h"
#include "utility.hpp"
#include "ui_vscvwidget.h"
#include "mpipeline.hpp"
#include "debug.hpp"
#include <QTimer>
using  namespace tthread;

class FFmpegScale;

class VSCVWidget : public QWidget
{
    Q_OBJECT

public:
    VSCVWidget(s32 nId, QWidget *parent = 0, Qt::WindowFlags flags = 0);
    ~VSCVWidget();
    void mouseDoubleClickEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void mouseMoveEvent(QMouseEvent *e);
    void createContentMenu();
    void SetVideoFocus(BOOL bFocus);
    virtual bool eventFilter(QObject *obj, QEvent *event)
    {
        if (event->type() == QEvent::MouseMove && obj == ui.videoControl)
        {
            VDC_DEBUG( "%s mouseMoveEvent %p\n",__FUNCTION__, this);
        }
	 return false;
    }

private slots:
    void stopAction();
    void showDisplay1();
    void showDisplay2();
    void showDisplay3();
    void showDisplay4();
    void videoMouseMove(QMouseEvent *e);
    void UpdateVideoControl();

signals:
    void ShowDisplayClicked(int nId);
    void ShowFloatingClicked();
    void ShowTabbedClicked();
    void ShowFocusClicked(int nId);

public:
    static void Run(void * pParam);
    void Run1();


public:
    BOOL StartPlay(std::string strUrl);
    BOOL StopPlay();
    BOOL DeviceDeleted(u32 nId);
    BOOL SetPlayId(u32 nPlayId);
    static void DeviceDeletedCallback(u32 nId, void * pParam);
    

/* Thread */
private:
    tthread::thread *m_videoThread;
    guintptr m_videoWindow;
    mediaPipeline *m_pipe;
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
    QAction *m_pDisplay1;
    QAction *m_pDisplay2;
    QAction *m_pDisplay3;
    QAction *m_pDisplay4;

    QAction *m_pFloating;
    QAction *m_pTabbed;


	/* SDL2 */
    SDL_Window *m_SdlWin;
    SDL_Renderer *m_SdlRender;
    SDL_Texture *m_pTex;
    /* TTF Font */
	int m_nFontSize;
    TTF_Font *m_pFont;
    SDL_Texture *m_pCaption;
    SDL_Texture *m_pTime;
    SDL_Rect m_captionRect;
    SDL_Rect m_timeRect;
    int m_lastTime;
	
private:
    QTimer *m_Timer;
    time_t m_lastMoveTime;

public:
    Ui::VSCVWidget ui;
    
};

#endif // QT_VSC_V_WIDGET_H
