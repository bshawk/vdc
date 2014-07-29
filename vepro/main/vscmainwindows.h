
#ifndef VSCMAINWINDOWS_H
#define VSCMAINWINDOWS_H

#include <QtWidgets/QMainWindow>
#include "ui_vscmainwindows.h"
#include "vevent.hpp"
#include "vscdockwidget.h"

class VSCDeviceList;
class VSCToolBar;
class VSCMainWindows : public QMainWindow
{
    Q_OBJECT

public:
    void SetupToolBar();
    void SetupMenuBar();
    void CreateActions();
    void CreateDockWindows();
    void SetupConnections();


public slots:
    void AddSurveillance();
    void AddCamera();
    void AddPlayback();
    void AddRecorder();
    
    void Search();
    void Setting();
    void EditCamera(int nId);
    void DeleteCamera(int nId);
    void MainCloseTab(int index);
    void about();
    void SetFullScreen();
    void AddEvent();
    void EditDisk();

    /* Site */
    void AddSite();
    void EditSite(int nId);
    void DeleteSite(int nId);

signals:
    void CameraDeleted();
public:
    VSCMainWindows(QWidget *parent = 0);
    ~VSCMainWindows();
private:
    QTabWidget * m_pMainArea;

private:
    QAction *pActSurveillance;
    QAction *pActSearch;



    QAction *pActDeviceList;
    QAction *pActDeviceAdd;
    QAction *pActDeviceDel;
    QAction *pActDeviceConf;
    QAction *aboutAct;
    QAction *aboutQtAct;

private:
    VSCDeviceList * m_pDeviceList;
    VSCToolBar * m_pToolBar;
    VEventThread * m_pEventThread;

private:
    Ui::VSCMainWindowsClass ui;
};

#endif // VSCMAINWINDOWS_H
