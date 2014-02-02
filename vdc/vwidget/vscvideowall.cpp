
#include "vscvideowall.h"
#include "vscvwidget.h"
#include "factory.hpp"
#include <QLineEdit>
#include <QAction>

VSCVideoWall::VSCVideoWall(QWidget *parent)
: m_bFloated(FALSE), QWidget(parent)
{
    //setMinimumWidth(800);
    //setMinimumHeight(600);
    m_VideoWallMode = LAYOUT_MODE_2X2;
    m_LastVideoWallMode = LAYOUT_MODE_2X2;
    for (int i = 0; i < VIDEO_WALL_WIDGET_MAX; i ++)
    {
        m_VideoMap[i] = new VSCVWidget(i, this);
        connect(m_VideoMap[i], SIGNAL(ShowDisplayClicked(int)), this,
                SIGNAL(ShowDisplayClicked(int)));
        connect(m_VideoMap[i], SIGNAL(ShowFloatingClicked()), this,
                SIGNAL(ShowFloatingClicked()));
        connect(m_VideoMap[i], SIGNAL(ShowTabbedClicked()), this,
                SIGNAL(ShowTabbedClicked()));
        connect(m_VideoMap[i], SIGNAL(ShowFocusClicked(int)), this,
                SIGNAL(ShowFocusClicked(int)));
        connect(m_VideoMap[i], SIGNAL(Layout1Clicked(int)), this,
                SIGNAL(Layout1Clicked(int)));
    }

    m_pLayout = new QGridLayout;
    m_pLayout->setSpacing(0);
    m_pLayout->setMargin(0);
    m_pLayout->setVerticalSpacing(0);
    m_pLayout->setHorizontalSpacing(0);
#if 0
#if 0
    for (int i = 0; i < 3; i ++)
    {
        for (int j = 0; j < 3; j ++)
        {
            m_pLayout->addWidget(m_VideoMap[i * 3 + j], i, j);
            //m_pLayout->addWidget(new QLineEdit(), i, j);
            m_VideoMap[i]->show();
        }
    }
#else
    m_pLayout->addWidget(m_VideoMap[0], 0, 0, 2, 2);
    m_pLayout->addWidget(m_VideoMap[1], 0, 2);
    m_pLayout->addWidget(m_VideoMap[2], 1, 2);
    m_pLayout->addWidget(m_VideoMap[3], 2, 0);
    m_pLayout->addWidget(m_VideoMap[4], 2, 1);
    m_pLayout->addWidget(m_VideoMap[5], 2, 2);
#endif
#endif

    
    setLayout(m_pLayout);

    for (int i = 0; i < 1; i ++)
    {
        //m_VideoMap[i] = new VSCVideoWidget;
        //m_VideoMap[i]->showMaximized();
    }
#if 0
    m_pFloating = new QAction(QIcon(tr("images/open.ico")), tr("Floating"), this);
    m_pUnFloating = new QAction(QIcon(tr("images/open.ico")), tr("UnFloating"), this);
    //connect(m_pFloating, SIGNAL(triggered()), this, SLOT(floatingAction()));
    //connect(m_pUnFloating, SIGNAL(triggered()), this, SLOT(unFloatingAction()));
    createContentMenu();
#endif
    UpdateVideoWallLayout();
    //setMouseTracking(true);
}

VSCVideoWall::~VSCVideoWall()
{
    VDC_DEBUG( "%s ~VSCVideoWall\n",__FUNCTION__);
}

void SetVideoFocus(int nId, BOOL on)
{

}

void VSCVideoWall::createContentMenu()
{
    //this->addAction(m_pFloating);
    //this->addAction(m_pUnFloating);
    //this->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void VSCVideoWall::ClearVideoLayout()
{
    VDC_DEBUG( "%s Layout count before clearing it: %d\n",__FUNCTION__,
            m_pLayout->count());

    int count = m_pLayout->count();
    int colums = m_pLayout->columnCount();
    int rows = m_pLayout->rowCount();

    int i=0;
    for(int j=0; j<rows; j++)
    {
        for(int k=0; k<colums && i<count; k++)
        {
            i++;
            VDC_DEBUG( "%s Removing item at: %d %d\n",__FUNCTION__,
                    j, k);
            QLayoutItem* item = m_pLayout->itemAtPosition(j, k);

            if (!item) continue;

            if (item->widget()) {
                m_pLayout->removeWidget(item->widget());
            } else {
                m_pLayout->removeItem(item);
            }
        }
    }
    VDC_DEBUG( "%s Layout count after clearing it: %d\n",__FUNCTION__,
            m_pLayout->count());
}


void VSCVideoWall::SetupVideoLayout4x4()
{
    m_pLayout->addWidget(m_VideoMap[0], 0, 0);
    m_pLayout->addWidget(m_VideoMap[1], 0, 1);
    m_pLayout->addWidget(m_VideoMap[2], 0, 2);
    m_pLayout->addWidget(m_VideoMap[3], 0, 3);

    m_pLayout->addWidget(m_VideoMap[4], 1, 0);
    m_pLayout->addWidget(m_VideoMap[5], 1, 1);
    m_pLayout->addWidget(m_VideoMap[6], 1, 2);
    m_pLayout->addWidget(m_VideoMap[7], 1, 3);

    m_pLayout->addWidget(m_VideoMap[8], 2, 0);
    m_pLayout->addWidget(m_VideoMap[9], 2, 1);
    m_pLayout->addWidget(m_VideoMap[10], 2, 2);
    m_pLayout->addWidget(m_VideoMap[11], 2, 3);

    m_pLayout->addWidget(m_VideoMap[12], 3, 0);
    m_pLayout->addWidget(m_VideoMap[13], 3, 1);
    m_pLayout->addWidget(m_VideoMap[14], 3, 2);
    m_pLayout->addWidget(m_VideoMap[15], 3, 3);
}

void VSCVideoWall::SetupVideoLayout2x2()
{
    m_pLayout->addWidget(m_VideoMap[0], 0, 0);
    m_pLayout->addWidget(m_VideoMap[1], 0, 1);

    m_pLayout->addWidget(m_VideoMap[2], 1, 0);
    m_pLayout->addWidget(m_VideoMap[3], 1, 1);
}

void VSCVideoWall::SetupVideoLayout3x3()
{
    m_pLayout->addWidget(m_VideoMap[0], 0, 0);
    m_pLayout->addWidget(m_VideoMap[1], 0, 1);
    m_pLayout->addWidget(m_VideoMap[2], 0, 2);


    m_pLayout->addWidget(m_VideoMap[3], 1, 0);
    m_pLayout->addWidget(m_VideoMap[4], 1, 1);
    m_pLayout->addWidget(m_VideoMap[5], 1, 2);

    m_pLayout->addWidget(m_VideoMap[6], 2, 0);
    m_pLayout->addWidget(m_VideoMap[7], 2, 1);
    m_pLayout->addWidget(m_VideoMap[8], 2, 2);
}

void VSCVideoWall::SetupVideoLayout1()
{
    m_pLayout->addWidget(m_VideoMap[0], 0, 0);
}
void VSCVideoWall::SetupVideoLayout12p1()
{
    m_pLayout->addWidget(m_VideoMap[0], 0, 0);
    m_pLayout->addWidget(m_VideoMap[1], 0, 1);
    m_pLayout->addWidget(m_VideoMap[2], 0, 2);
    m_pLayout->addWidget(m_VideoMap[3], 0, 3);

    m_pLayout->addWidget(m_VideoMap[4], 1, 0);
    m_pLayout->addWidget(m_VideoMap[5], 1, 1, 2, 2);
    m_pLayout->addWidget(m_VideoMap[6], 1, 3);

    m_pLayout->addWidget(m_VideoMap[7], 2, 0);
    m_pLayout->addWidget(m_VideoMap[8], 2, 3);

    m_pLayout->addWidget(m_VideoMap[9], 3, 0);
    m_pLayout->addWidget(m_VideoMap[10], 3, 1);
    m_pLayout->addWidget(m_VideoMap[11], 3, 2);
    m_pLayout->addWidget(m_VideoMap[12], 3, 3);
}
void VSCVideoWall::SetupVideoLayout6()
{
    m_pLayout->addWidget(m_VideoMap[0], 0, 0, 2, 2);
    m_pLayout->addWidget(m_VideoMap[1], 0, 2);
    m_pLayout->addWidget(m_VideoMap[2], 1, 2);
    m_pLayout->addWidget(m_VideoMap[3], 2, 0);
    m_pLayout->addWidget(m_VideoMap[4], 2, 1);
    m_pLayout->addWidget(m_VideoMap[5], 2, 2);
}

void VSCVideoWall::SetupVideoLayout5x5()
{
    s32 w, h;
    int i = 0;
    for (w = 0; w < 5 ; w ++)
    {
        for (h = 0; h < 5; h ++)
        {
            m_pLayout->addWidget(m_VideoMap[i++], w, h);
	         VDC_DEBUG( "%s 5x5 w %d h %d\n",__FUNCTION__, w, h);
        }
    }
}
void VSCVideoWall::SetupVideoLayout6x6()
{
    s32 w, h;
    int i = 0;
    for (w = 0; w < 6 ; w ++)
    {
        for (h = 0; h < 6; h ++)
        {
            m_pLayout->addWidget(m_VideoMap[i++], w, h);
        }
    }
}
void VSCVideoWall::SetupVideoLayout8x8()
{
    s32 w, h;
    int i = 0;
    for (w = 0; w < 8 ; w ++)
    {
        for (h = 0; h < 8; h ++)
        {
            m_pLayout->addWidget(m_VideoMap[i++], w, h);
        }
    }
}

void VSCVideoWall::SetLayoutMode(VideoWallLayoutMode nMode)
{
    if (nMode != m_VideoWallMode)
    {
        m_VideoWallMode = nMode;
        UpdateVideoWallLayout();
    }

    return;
}

void VSCVideoWall::SetLayout1Mode(int nId)
{
    if (m_VideoWallMode == LAYOUT_MODE_ONE)
    {
        SetLayoutMode(m_LastVideoWallMode);
	 m_LastVideoWallMode = LAYOUT_MODE_2X2;
    }else
    {
        m_LastVideoWallMode = m_VideoWallMode;
        m_VideoWallMode = LAYOUT_MODE_ONE;
        StopVideoBeforeSetLayout();
        ClearVideoLayout();
        m_pLayout->addWidget(m_VideoMap[nId], 0, 0);
        m_VideoMap[nId]->show();
    }
}

void VSCVideoWall::StopVideoBeforeSetLayout()
{
    int videoCnt = 0;
    switch(m_VideoWallMode)
    {
        case LAYOUT_MODE_2X2:
            videoCnt = 4;
            break;
        case LAYOUT_MODE_3X3:
            videoCnt = 9;
            break;
        case LAYOUT_MODE_4X4:
            videoCnt = 16;
            break;
        case LAYOUT_MODE_1:
            videoCnt = 1;
            break;
        case LAYOUT_MODE_6:
            videoCnt = 6;
            break;
        case LAYOUT_MODE_12p1:
            videoCnt = 13;
            break;
        case LAYOUT_MODE_5x5:
            videoCnt = 25;
            break;
        case LAYOUT_MODE_6x6:
            videoCnt = 36;
            break;
        case LAYOUT_MODE_8x8:
            videoCnt = 64;
            break;
        case LAYOUT_MODE_ONE:
            videoCnt = 1;
            break;
        default:
            break;
    }
    for (int i = videoCnt; i < VIDEO_WALL_WIDGET_MAX; i ++)
    {
        //m_VideoMap[i]->StopPlay();
        m_VideoMap[i]->hide();
    }
    for (int i = 0; i < videoCnt; i ++)
    {
        m_VideoMap[i]->show();
    }

}

void VSCVideoWall::UpdateVideoWallLayout()
{
    StopVideoBeforeSetLayout();
    ClearVideoLayout();
    switch(m_VideoWallMode)
    {
        case LAYOUT_MODE_2X2:
            SetupVideoLayout2x2();
            break;
        case LAYOUT_MODE_3X3:
            SetupVideoLayout3x3();
            break;
        case LAYOUT_MODE_4X4:
            SetupVideoLayout4x4();
            break;
        case LAYOUT_MODE_1:
            SetupVideoLayout1();
            break;
        case LAYOUT_MODE_6:
            SetupVideoLayout6();
            break;
        case LAYOUT_MODE_12p1:
            SetupVideoLayout12p1();
            break;
        case LAYOUT_MODE_5x5:
            SetupVideoLayout5x5();
            break;
        case LAYOUT_MODE_6x6:
            SetupVideoLayout6x6();
            break;
        case LAYOUT_MODE_8x8:
            SetupVideoLayout8x8();
            break;
        default:
            break;
    }

    return;
}

void VSCVideoWall::SetVideoFocus(int nId, BOOL on)
{
    if (nId > VIDEO_WALL_WIDGET_MAX || nId < 0)
    {
        return;
    }
    m_VideoMap[nId]->SetVideoFocus(on);
}

void VSCVideoWall::floatingAction()
{
    if (m_bFloated == TRUE)
    {
        return;
    }
    m_pParent = parentWidget();
    setParent(NULL);
    showMaximized();
    m_bFloated = TRUE;
}

void VSCVideoWall::unFloatingAction()
{
    if (m_bFloated == FALSE)
    {
        return;
    }
    showFullScreen();
    setParent(m_pParent);
    resize(m_pParent->width(), m_pParent->height());
    showFullScreen();
    m_bFloated = FALSE;
}

void VSCVideoWall::mouseDoubleClickEvent(QMouseEvent *e)
{
    VDC_DEBUG( "%s mouseDoubleClickEvent\n",__FUNCTION__);
    QWidget::mouseDoubleClickEvent(e);
#if 0
    if(isFullScreen()) {
        //setParent(m_pParent);
        //resize(m_pParent->width(), m_pParent->height());
        //showMaximized();
        this->setWindowState(Qt::WindowMaximized);
    } else {
        //m_pParent = parentWidget();
        //setParent(NULL);
        //showFullScreen();
        this->setWindowState(Qt::WindowFullScreen);
    }
#endif
}

bool VSCVideoWall::Start()
{
    char url[1024];
    //m_Cap->open("VSCvideo.avi");
    for (int i = 0; i < 3; i ++)
    {
        //m_VideoMap[i]->show();
        //sprintf(url, "%s%d", "rtsp://192.168.0.1/channel/stream", i + 1);
        sprintf(url, "%s", "VSCvideo.avi");
        m_VideoMap[i]->StartPlay(url);
    }
    
    return true;

}

bool VSCVideoWall::Stop()
{
    return true;
}
