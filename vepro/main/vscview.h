#ifndef VSCVIEW_H
#define VSCVIEW_H

#include <QWidget>
#include "ui_vscview.h"
#include "utility.hpp"
#include "debug.hpp"
#include "vscvwidget.h"
#include "vscvideowall.h"
#include "QTabWidget"
#include "vscplaycontrol.h"

class VSCView : public QWidget
{
    Q_OBJECT

public:
    VSCView(QWidget *parent, QTabWidget &pTabbed);
    ~VSCView();
public:
    void mouseDoubleClickEvent(QMouseEvent *e);
    void createContentMenu();
public:
    void SetupConnections();
	
public slots:
    void floatingClicked();
    void TabbedClicked();
    void ControlPanelClicked();
    void ShowDisplayClicked(int nId);
    void ShowFocusClicked(int nId);
    void ShowPlayControl();
    void ShowLayout1Clicked(int nId);
    void mouseMoveEvent(QMouseEvent *e)
    	{
    	    VDC_DEBUG( "%s mouseMoveEvent \n",__FUNCTION__);
    	}
    void SetLayoutMode4x4()
    {
        m_pTabbed.setTabIcon(m_pTabbed.indexOf(this), 
		QIcon(tr(":/view/resources/4x4.png")));
    }
    void SetLayoutMode3x3()
    {
        m_pTabbed.setTabIcon(m_pTabbed.indexOf(this), 
		QIcon(tr(":/view/resources/3x3.png")));
    }
    void SetLayoutMode2x2()
    {
        m_pTabbed.setTabIcon(m_pTabbed.indexOf(this), 
		QIcon(tr(":/view/resources/2x2.png")));
    }
    void SetLayoutMode6()
    {
        m_pTabbed.setTabIcon(m_pTabbed.indexOf(this), 
		QIcon(tr(":/view/resources/6.png")));
    }
    void SetLayoutMode12p1()
    {
        m_pTabbed.setTabIcon(m_pTabbed.indexOf(this), 
		QIcon(tr(":/view/resources/12+1.png")));
    }
    void SetLayoutMode1()
    {
        m_pTabbed.setTabIcon(m_pTabbed.indexOf(this), 
		QIcon(tr(":/view/resources/1x1.png")));
    }
    void SetLayoutMode5x5()
    {
        m_pTabbed.setTabIcon(m_pTabbed.indexOf(this), 
		QIcon(tr(":/view/resources/5x5.png")));
    }
    void SetLayoutMode6x6()
    {
        m_pTabbed.setTabIcon(m_pTabbed.indexOf(this), 
		QIcon(tr(":/view/resources/6x6.png")));
    }
    void DeviceEvent(int deviceId, int type)
    {
    	m_pVideo->DeviceEvent(deviceId, (VscEventType)type);
    }
	
public:
    Ui::VSCView ui;
private:
    QWidget *m_pParent;
    QAction *m_pFloating;
    QAction *m_pUnFloating;
    BOOL m_bFloated;
    int m_currentFocus;
    VSCVideoWall * m_pVideo;
    VSCPlayControl * m_pPlayControl;
    BOOL m_bPlayControl;
    QTabWidget &m_pTabbed;

 	/* Control Panel  */
	BOOL m_bControlEnable;
    
};

#endif // VSCVIEW_H
