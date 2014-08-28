

#ifndef VSCDEVICELIST_H
#define VSCDEVICELIST_H

#include <QWidget>
#include "ui_vscdevicelist.h"
#include "factory.hpp"
#include "QTimer"
#include "vscrecorder.h"

#define VSC_DEVICE_INDEX_SITE 0
#define VSC_DEVICE_INDEX_RECORDER 1
#define VSC_DEVICE_INDEX_IPC 2
#define VSC_DEVICE_INDEX_VIEW 3
#define VSC_DEVICE_INDEX_DSIK 4
#define VSC_DEVICE_INDEX_V_IPC 5

class VSCDeviceList : public QWidget
{
    Q_OBJECT

public:
    //QSize sizeHint()
    //{
    //    return QSize(300, 300);
    //}

public:
    VSCDeviceList(QWidget *parent);
    ~VSCDeviceList();
public:
    void SetupConnections();
    static bool DeviceChangeCallbackFunc(void* pData, FactoryDeviceChangeData change);
    bool DeviceChangeCallbackFunc1(FactoryDeviceChangeData change);
    void NotifyAddCamera(int nId);
    void NotifyDelCamera(int nId);
    void NotifyCameraOnlineOffline(int nId, BOOL bOnline);
    void NotifyCameraRecording(int nId, BOOL bRecording);
    void NotifyAddVms(int nId);
    void NotifyDelVms(int nId);

public:
    void AddIPCamera(DeviceParam &pParam);
    void AddSite(VSCVmsDataItem &pParam);
    void AddVirtualIPC(VSCVmsDataItem &pParam);
    void AddDisk(astring strTitle);
    void RemoveAllCamera();
    BOOL GetRecorderMap(RecorderMap &pMap);
    void CameraTreeUpdated();

public slots:
    void SurveillanceClick();
    void CameraAddClick();
    void PlaybackClick();
    void SearchClick();
    void RecorderClick();

    void SiteAddClick();
    
    void DiskTreeUpdated();
    void UpdateOnline();
    void VmsTreeUpdated();

signals:
    void SurveillanceClicked();
    void PlaybackClicked();
    void SearchClicked();
    void RecorderClicked();
    
	/*ipc*/
	void CameraAddClicked();
    void CameraEditClicked(int nId);
    void CameraDeleteClicked(int nId);

    /* Site */
    void SiteAddClicked();
    void SiteEditClicked(int nId);
    void SiteDeleteClicked(int nId);
	
    void DiskEditClicked();

	//void VSCZbIpcDeleteClicked(int nId);
	//void VSCZbIpcStopRecordClicked(int nId);
private:
    Ui::VSCDeviceList ui;
private:
    QTimer *m_Timer;
    
};

#endif // VSCDEVICELIST_H
