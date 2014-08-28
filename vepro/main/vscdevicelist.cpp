
#include "vscdevicelist.h"
#include "vscdeviceipc.h"
#include "factory.hpp"
#include "vscvms.h"

extern Factory *gFactory;

VSCDeviceList::VSCDeviceList(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    CameraTreeUpdated();
    DiskTreeUpdated();
    VmsTreeUpdated();

    SetupConnections();
    m_Timer = new QTimer(this);
    //connect(m_Timer,SIGNAL(timeout()),this,SLOT(UpdateOnline()));  
    //m_Timer->start(1000 * 3); 
    gFactory->RegDeviceChangeNotify((void *)this, 
				(FactoryDeviceChangeNotify)(VSCDeviceList::DeviceChangeCallbackFunc));
	

}

void VSCDeviceList::SetupConnections()
{
    connect(ui.pbSurveillance, SIGNAL(clicked()), this, SLOT(SurveillanceClick()));
    connect(ui.pbCamera, SIGNAL(clicked()), this, SLOT(CameraAddClick()));
    connect(ui.pbPlayback, SIGNAL(clicked()), this, SLOT(PlaybackClick()));
    connect(ui.pbSearch, SIGNAL(clicked()), this, SLOT(SearchClick()));
    connect(ui.pbRecorder, SIGNAL(clicked()), this, SLOT(RecorderClick()));
    connect(ui.pbSite, SIGNAL(clicked()), this, SLOT(SiteAddClick()));
	
    connect(ui.treeWidget, SIGNAL(CameraAddClicked()), this, SIGNAL(CameraAddClicked()));
    connect(ui.treeWidget, SIGNAL(CameraEditClicked(int)), this, SIGNAL(CameraEditClicked(int)));
    connect(ui.treeWidget, SIGNAL(CameraDeleteClicked(int)), this, SIGNAL(CameraDeleteClicked(int)));

    connect(ui.treeWidget, SIGNAL(SiteAddClicked()), this, SIGNAL(SiteAddClicked()));
    connect(ui.treeWidget, SIGNAL(SiteEditClicked(int)), this, SIGNAL(SiteEditClicked(int)));
    connect(ui.treeWidget, SIGNAL(SiteDeleteClicked(int)), this, SIGNAL(SiteDeleteClicked(int)));

	/*VSCZbIpc*/
	//connect(ui.treeWidget, SIGNAL(VSCZbIpcDeleteClicked(int)), this, SIGNAL(CameraDeleteClicked(int)));
	//connect(ui.treeWidget, SIGNAL(VSCZbIpcStopRecordClicked(int)), this, SIGNAL(RecorderClicked(int)));
	
    connect(ui.treeWidget, SIGNAL(DiskEditClicked()), this, SIGNAL(DiskEditClicked()));
    connect(ui.pbTrash, SIGNAL(CameraDeleted()), this, SLOT(CameraTreeUpdated()));
}



bool VSCDeviceList::DeviceChangeCallbackFunc(void* pData, FactoryDeviceChangeData change)
{
	if (pData)
	{
		VSCDeviceList * pDeviceList = (VSCDeviceList *)pData;
		pDeviceList->DeviceChangeCallbackFunc1(change);
	}
	return true;
}

bool VSCDeviceList::DeviceChangeCallbackFunc1(FactoryDeviceChangeData change)
{
	VDC_DEBUG( " %s Device Change Callback %d type %d\n", __FUNCTION__, change.id, change.type);
	switch (change.type)
	{
	    case FACTORY_DEVICE_DEL:
	    {
		 NotifyDelCamera(change.id);
	        break;
	    }
	    case FACTORY_DEVICE_ADD:
	    {
	        NotifyAddCamera(change.id);
	        break;
	    }
	    case FACTORY_DEVICE_OFFLINE:
	    {
	        NotifyCameraOnlineOffline(change.id, FALSE);
	        break;
	    }
	    case FACTORY_DEVICE_ONLINE:
	    {
	        NotifyCameraOnlineOffline(change.id, TRUE);
	        break;
	    }
	    case FACTORY_DEVICE_RECORDING_OFF:
	    {
	        NotifyCameraRecording(change.id, FALSE);
	        break;
	    }
	    case FACTORY_DEVICE_RECORDING_ON:
	    {
	        NotifyCameraRecording(change.id, TRUE);
	        break;
	    }
	    case FACTORY_VMS_ADD:
	    {
	        NotifyAddVms(change.id);
	        break;
	    }
	    case FACTORY_VMS_DEL:
	    {
	        NotifyDelVms(change.id);
	        break;
	    }
	    default:
	    {

	        break;
	    }
	}

	return true;
}

void VSCDeviceList::NotifyAddCamera(int nId)
{
	DeviceParam  pParam;
	if (gFactory->GetDeviceParamById(pParam, nId) == TRUE)
	{
		AddIPCamera(pParam);
	}
	return;
}

void VSCDeviceList::NotifyDelCamera(int nId)
{
	QTreeWidgetItem *qtreewidgetitem = ui.treeWidget->topLevelItem(VSC_DEVICE_INDEX_IPC);

	int cnt = qtreewidgetitem->childCount();
	//VDC_DEBUG( "%s cnt %d\n",__FUNCTION__, cnt);
	for (int i = 0; i < cnt; i ++)
	{
		QTreeWidgetItem * pChild = qtreewidgetitem->child(i);
		VSCDeviceIPC *pIPC = dynamic_cast<VSCDeviceIPC*>(pChild);
		if (pIPC && pIPC->GetDeviceId() == nId)
		{
			qtreewidgetitem->removeChild(pChild);
		}
	}
	return;
}

void VSCDeviceList::NotifyCameraOnlineOffline(int nId, BOOL bOnline)
{
	QTreeWidgetItem *qtreewidgetitem = ui.treeWidget->topLevelItem(VSC_DEVICE_INDEX_IPC);

	int cnt = qtreewidgetitem->childCount();
	//VDC_DEBUG( "%s cnt %d\n",__FUNCTION__, cnt);
	for (int i = 0; i < cnt; i ++)
	{
		QTreeWidgetItem * pChild = qtreewidgetitem->child(i);
		VSCDeviceIPC *pIPC = dynamic_cast<VSCDeviceIPC*>(pChild);
		if (pIPC && pIPC->GetDeviceId() == nId)
		{
		 	pIPC->UpdateOnline(bOnline);
		}
	}
	return;
}

void VSCDeviceList::NotifyCameraRecording(int nId, BOOL bRecording)
{
	QTreeWidgetItem *qtreewidgetitem = ui.treeWidget->topLevelItem(VSC_DEVICE_INDEX_IPC);

	int cnt = qtreewidgetitem->childCount();
	//VDC_DEBUG( "%s cnt %d\n",__FUNCTION__, cnt);
	for (int i = 0; i < cnt; i ++)
	{
		QTreeWidgetItem * pChild = qtreewidgetitem->child(i);
		VSCDeviceIPC *pIPC = dynamic_cast<VSCDeviceIPC*>(pChild);
		if (pIPC && pIPC->GetDeviceId() == nId)
		{
		 	pIPC->UpdateRecord(bRecording);
		}
	}
	return;
}

void VSCDeviceList::NotifyAddVms(int nId)
{
	VSCVmsDataItem  pParam;
	if (gFactory->GetVmsById(pParam, nId) == TRUE)
	{
		switch (pParam.nType)
		{
		    case VSC_VMS_SITE:
		    {
		        AddSite(pParam);
		        break;
		    }
		    case VSC_VMS_RECORDER:
		    {
		        
		        break;
		    }
		    default:
		    {

		        break;
		    }
		}
	}
	return;
}


void VSCDeviceList::NotifyDelVms(int nId)
{	
	/* Site */
	{
		QTreeWidgetItem *qtreewidgetitem = ui.treeWidget->topLevelItem(VSC_DEVICE_INDEX_SITE);

		int cnt = qtreewidgetitem->childCount();
		//VDC_DEBUG( "%s cnt %d\n",__FUNCTION__, cnt);
		for (int i = 0; i < cnt; i ++)
		{
			QTreeWidgetItem * pChild = qtreewidgetitem->child(i);
			VSCVms *pVms = dynamic_cast<VSCVms*>(pChild);
			if (pVms && pVms->GetDeviceId() == nId)
			{
				qtreewidgetitem->removeChild(pChild);
			}
		}
	}
	/* PG */
	{
		QTreeWidgetItem *qtreewidgetitem = ui.treeWidget->topLevelItem(VSC_DEVICE_INDEX_RECORDER);

		int cnt = qtreewidgetitem->childCount();
		//VDC_DEBUG( "%s cnt %d\n",__FUNCTION__, cnt);
		for (int i = 0; i < cnt; i ++)
		{
			QTreeWidgetItem * pChild = qtreewidgetitem->child(i);
			VSCVms *pVms = dynamic_cast<VSCVms*>(pChild);
			if (pVms && pVms->GetDeviceId() == nId)
			{
				qtreewidgetitem->removeChild(pChild);
			}
		}
	}
	return;
}

void VSCDeviceList::VmsTreeUpdated()
{
	/* Delete all the site */
	{
		QTreeWidgetItem *qtreewidgetitem = ui.treeWidget->topLevelItem(VSC_DEVICE_INDEX_SITE);

		qDeleteAll(qtreewidgetitem->takeChildren());
	}
	/* Delete all the site */
	{
		QTreeWidgetItem *qtreewidgetitem = ui.treeWidget->topLevelItem(VSC_DEVICE_INDEX_RECORDER);

		qDeleteAll(qtreewidgetitem->takeChildren());
	}

	VSCVmsData pData;
	gFactory->GetVms(pData);
	for (s32 i = 1; i < CONF_VMS_NUM_MAX; i ++)
	{
	    	if (pData.data.conf.vms[i].Used == 1)
	    	{
		        switch (pData.data.conf.vms[i].nType)
		        {
		            case VSC_VMS_SITE:
		            {
		                AddSite(pData.data.conf.vms[i]);
		                break;
		            }
		            case VSC_VMS_RECORDER:
		            {
		                
		                break;
		            }
		            case VSC_VMS_VIRTUL_IPC:
		            {
		                AddVirtualIPC(pData.data.conf.vms[i]);
		                break;
		            }
		            default:
		            {

		                break;
		            }
		        }
	    	}else
	    	{
	    		continue;
	    	}
	}	
}

void VSCDeviceList::DiskTreeUpdated()
{
	/* Delete all the disk */
	QTreeWidgetItem *qtreewidgetitem = ui.treeWidget->topLevelItem(VSC_DEVICE_INDEX_DSIK);

	qDeleteAll(qtreewidgetitem->takeChildren());

	VDBDiskMap pMap;
	gFactory->GetDiskMap(pMap);


	VDBDiskMap::iterator it = pMap.begin();

	for(; it!=pMap.end(); ++it)
	{
		astring strName = (*it).first;
		VdbDiskItem pParam = (*it).second;
		s8 DiskTitle[1024];
		memset(DiskTitle, 0, sizeof(DiskTitle));
		sprintf(DiskTitle, "  %lld%%",   (pParam.used * 100)/pParam.total);
		strName = strName + DiskTitle;
		AddDisk(strName);
	}

	ui.treeWidget->topLevelItem(VSC_DEVICE_INDEX_DSIK)->setExpanded(true);

	
}

void VSCDeviceList::CameraTreeUpdated()
{
    RemoveAllCamera();
    DeviceParamMap pMap;
    gFactory->GetDeviceParamMap(pMap);


    DeviceParamMap::iterator it = pMap.begin();

    for(; it!=pMap.end(); ++it)
    {
        u32 nId = (*it).first;
        DeviceParam pParam = (*it).second;
        switch (pParam.m_Conf.data.conf.nType)
        {
            case VSC_DEVICE_CAM:
            {
                AddIPCamera(pParam);
                break;
            }
            default:
            {

                break;
            }
        }

    }

    ui.treeWidget->topLevelItem(VSC_DEVICE_INDEX_IPC)->setExpanded(true);
}


void VSCDeviceList::AddDisk(astring strTitle)
{
    QTreeWidgetItem *qtreewidgetitem = ui.treeWidget->topLevelItem(VSC_DEVICE_INDEX_DSIK);
    QIcon icon1;
    icon1.addFile(QStringLiteral(":/device/resources/harddisk.png"), QSize(), QIcon::Normal, QIcon::Off);
    //icon1.addFile(QStringLiteral(":/device/resources/camera-record.png"), QSize(), QIcon::Normal, QIcon::Off);

    QTreeWidgetItem *qtreewidgetitemChild = new QTreeWidgetItem(qtreewidgetitem);

    qtreewidgetitemChild->setIcon(0, icon1);

    qtreewidgetitemChild->setText(0, QApplication::translate("Disk",  strTitle.c_str(), 0));

    qtreewidgetitem->setExpanded(true);
}

void VSCDeviceList::AddIPCamera(DeviceParam &pParam)//添加IPC
{
    QTreeWidgetItem *qtreewidgetitem = ui.treeWidget->topLevelItem(VSC_DEVICE_INDEX_IPC);
    QIcon icon1;
    icon1.addFile(QStringLiteral(":/device/resources/dome.png"), QSize(), QIcon::Normal, QIcon::Off);
    //icon1.addFile(QStringLiteral(":/device/resources/camera-record.png"), QSize(), QIcon::Normal, QIcon::Off);

    QTreeWidgetItem *qtreewidgetitemChild = new VSCDeviceIPC(qtreewidgetitem, pParam);

    qtreewidgetitemChild->setIcon(0, icon1);

    qtreewidgetitemChild->setText(0, QApplication::translate("",
            pParam.m_Conf.data.conf.Name, 0));

    qtreewidgetitem->setExpanded(true);
    VSCDeviceIPC *pIPC = dynamic_cast<VSCDeviceIPC*>(qtreewidgetitemChild);
    if (pParam.m_Conf.data.conf.Recording == 1)
    {
		pIPC->UpdateRecord(TRUE);
    }else
    {
    	pIPC->UpdateRecord(FALSE);
    }
}


void VSCDeviceList::AddSite(VSCVmsDataItem &pParam)//添加site
{
    QTreeWidgetItem *qtreewidgetitem = ui.treeWidget->topLevelItem(VSC_DEVICE_INDEX_SITE);//所有的
    QIcon icon1;
    icon1.addFile(QStringLiteral(":/action/resources/site.png"), QSize(), QIcon::Normal, QIcon::Off);
    //icon1.addFile(QStringLiteral(":/device/resources/camera-record.png"), QSize(), QIcon::Normal, QIcon::Off);

    QTreeWidgetItem *qtreewidgetitemChild = new VSCVmsZb(qtreewidgetitem, pParam);

    qtreewidgetitemChild->setIcon(0, icon1);

    qtreewidgetitemChild->setText(0, QApplication::translate("Site",
            pParam.Name, 0));

    qtreewidgetitem->setExpanded(true);
}

void VSCDeviceList::AddVirtualIPC(VSCVmsDataItem &pParam)//添加site
{
    QTreeWidgetItem *qtreewidgetitem = ui.treeWidget->topLevelItem(VSC_DEVICE_INDEX_V_IPC);//所有的
    QIcon icon1;
    icon1.addFile(QStringLiteral(":/action/resources/dome.png"), QSize(), QIcon::Normal, QIcon::Off);
    //icon1.addFile(QStringLiteral(":/device/resources/camera-record.png"), QSize(), QIcon::Normal, QIcon::Off);

    QTreeWidgetItem *qtreewidgetitemChild = new VSCVmsVirtualIPC(qtreewidgetitem, pParam);

    qtreewidgetitemChild->setIcon(0, icon1);

    qtreewidgetitemChild->setText(0, QApplication::translate("Camera",
            pParam.Name, 0));

    qtreewidgetitem->setExpanded(true);
}


void VSCDeviceList::UpdateOnline()
{

}

BOOL VSCDeviceList::GetRecorderMap(RecorderMap &pMap)
{
	//TODO get all the recorder from VSC_DEVICE_INDEX_SITE

	/* Site */
	{
		QTreeWidgetItem *qtreewidgetitem = ui.treeWidget->topLevelItem(VSC_DEVICE_INDEX_SITE);

		int cnt = qtreewidgetitem->childCount();
		//VDC_DEBUG( "%s cnt %d\n",__FUNCTION__, cnt);
		for (int i = 0; i < cnt; i ++)
		{
			QTreeWidgetItem * pChild = qtreewidgetitem->child(i);
			VSCVms *pVms = dynamic_cast<VSCVms*>(pChild);
			
				pVms->GetRecorderMap(pMap);

		}
	}
	/*//fake
	VSCRecorder zb1(0, "192.168.12.12", VSC_SUB_VMS_ZB);
	VSCRecorder zb2(0, "192.168.12.32", VSC_SUB_VMS_ZB);
	VSCRecorder zb3(0, "192.168.12.33", VSC_SUB_VMS_ZB);
	pMap.insert( std::map<int, VSCRecorder>::value_type(0, zb1) );
	pMap.insert( std::map<int, VSCRecorder>::value_type(1, zb2) );
	pMap.insert( std::map<int, VSCRecorder>::value_type(2, zb3) );
	//pMap.insert( std::map<int, VSCRecorder>::value_type(3, zb3) );*/
	return TRUE;
}

void VSCDeviceList::RemoveAllCamera()
{
    QTreeWidgetItem *qtreewidgetitem = ui.treeWidget->topLevelItem(VSC_DEVICE_INDEX_IPC);

    qDeleteAll(qtreewidgetitem->takeChildren());
#if 0
    int cnt = qtreewidgetitem->childCount();
    VDC_DEBUG( "%s cnt %d\n",__FUNCTION__, cnt);
    for (int i = 0; i < cnt; i ++)
    {
        VDC_DEBUG( "%s cnt %d\n",__FUNCTION__, i);
        QTreeWidgetItem * pChild = qtreewidgetitem->child(i);
        delete pChild;
    }
#endif
}

VSCDeviceList::~VSCDeviceList()
{
	m_Timer->stop();
	delete m_Timer;
}

void VSCDeviceList::SurveillanceClick()
{
    emit SurveillanceClicked();
    return;
}

void VSCDeviceList::CameraAddClick()
{
    emit CameraAddClicked();
    return;
}

void VSCDeviceList::PlaybackClick()
{
    emit PlaybackClicked();
    return;
}

void VSCDeviceList::SearchClick()
{
    emit SearchClicked();
    return;
}

void VSCDeviceList::RecorderClick()
{
    emit RecorderClicked();
    return;
}

void VSCDeviceList::SiteAddClick()
{
    emit SiteAddClicked();
    return;
}
