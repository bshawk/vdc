//------------------------------------------------------------------------------
// File: factory.hpp
//
// Desc: Device factory - Manage IP Camera.
//
// Copyright (c) 2014-2018 vdceye. All rights reserved.
//------------------------------------------------------------------------------

#ifndef __VSC_FACTORY_H_
#define __VSC_FACTORY_H_
#include "confdb.hpp"
#include "device.hpp"
#include "vdb.hpp"
#include "vplay.hpp"
#include "sysdb.hpp"
#include <QThread>
#include <qdebug.h>

typedef enum
{
    FACTORY_DEVICE_ADD = 1,
    FACTORY_DEVICE_DEL,
    FACTORY_DEVICE_ONLINE,
    FACTORY_DEVICE_OFFLINE,
    FACTORY_DEVICE_RECORDING_ON,
    FACTORY_DEVICE_RECORDING_OFF,
    FACTORY_VMS_ADD,
    FACTORY_VMS_DEL,
    FACTORY_DEVICE_LAST
} FactoryDeviceChangeType;



class FactoryDeviceChangeData
{
public:
	FactoryDeviceChangeType type;
	int id;
};

typedef BOOL (*FactoryDeviceChangeNotify)(void* pParam, 
		FactoryDeviceChangeData data);

typedef std::list<LPDevice> DeviceList;
typedef std::list<DeviceParam> DeviceParamList;
typedef std::map<int, LPDevice> DeviceMap;
typedef std::map<int, DeviceParam> DeviceParamMap;
typedef std::map<void *, FactoryDeviceChangeNotify> DeviceChangeNofityMap;
#define FACTORY_DEVICE_ID_MAX 4096




/* Fatory is Qthread for callback in Qt GUI */
class Factory: public QThread
{
    Q_OBJECT
public:
    Factory();
    ~Factory();
public:
    BOOL Init();
    s32 InitAddDevice(DeviceParam & pParam, u32 nIndex);
public:
	BOOL RegDeviceChangeNotify(void * pData, FactoryDeviceChangeNotify callback)
	{
		Lock();
		m_DeviceChange[pData] = callback;
		UnLock();
		return TRUE;
	}
	BOOL CallDeviceChange(FactoryDeviceChangeData data)
	{
	        DeviceChangeNofityMap::iterator it = m_DeviceChange.begin(); 
	        for(; it!=m_DeviceChange.end(); ++it)
	        {
			if ((*it).second)
			{
				(*it).second((*it).first, data);
			}
	        }	
		 return TRUE;
	}
public:
	BOOL GetLicense(astring &strLicense, astring &strHostId, int &ch, int &type)
	{
		VPlay::GetLicenseInfo(strHostId, ch, type);
		return m_Conf.GetLicense(strLicense);
	}
	BOOL SetLicense(astring &strLicense)
	{
		VPlay::SetLicense(strLicense);
		return m_Conf.SetLicense(strLicense);
	}
	BOOL InitLicense()
	{
		astring strLicense;
		m_Conf.GetLicense(strLicense);
		VPlay::SetLicense(strLicense);
		return TRUE;
	}

public:
	/* UI can use this for display device tree */
	BOOL GetDeviceParamMap(DeviceParamMap &pMap);

	s32 AddDevice(DeviceParam & pParam);
	s32 GetDeviceParamById(DeviceParam & pParam, s32 nIndex);
	BOOL GetDeviceRtspUrl(astring & strUrl, s32 nIndex);
	s32 GetDeviceParamByIdTryLock(DeviceParam & pParam, s32 nIndex);
	BOOL DelDevice(s32 nIndex);
	BOOL AttachPlayer(s32 nIndex, HWND hWnd, int w, int h);
	BOOL UpdateWidget(s32 nIndex, HWND hWnd, int w, int h);
	BOOL DetachPlayer(s32 nIndex, HWND hWnd);
	BOOL DrawPtzDirection(s32 nIndex, HWND hWnd, int x1, int y1, int x2,  int y2);
	BOOL ClearPtzDirection(s32 nIndex, HWND hWnd);
	BOOL PtzAction(s32 nIndex, FPtzAction action, float speed);
	BOOL ShowAlarm(s32 nIndex, HWND hWnd);
public:
	BOOL GetVms(VSCVmsData &pData);
	s32 AddVms(VSCVmsDataItem &pParam);
	BOOL DelVms(s32 Id);
	BOOL GetVmsById(VSCVmsDataItem &pParam, int nId);

public:
    BOOL StartDevice(s32 nIndex);
    BOOL StopDevice(s32 nIndex);
    
public:
    BOOL StartRecord(s32 nIndex);
    BOOL StopRecord(s32 nIndex);
public:
    BOOL GetRecordStatus(s32 nIndex, BOOL &bStatus);

public:
    NotificationQueue * GetRawDataQueue(s32 nIndex);
    BOOL ReleaseRawDataQueue(s32 nIndex, NotificationQueue * pQueue);
    NotificationQueue * GetDataQueue(s32 nIndex);
    BOOL GetDataQueue(s32 nIndex, NotificationQueue * pQueue);
    BOOL RegDataCallback(s32 nIndex, DeviceDataCallbackFunctionPtr pCallback, void * pParam);
    BOOL UnRegDataCallback(s32 nIndex, void * pParam);
    BOOL GetDeviceOnline(s32 nIndex, BOOL &bStatus);
    BOOL GetUrl(s32 nIndex, std::string &url);
    BOOL SetSystemPath(astring &strPath);
    BOOL AddHDD(astring &strPath, s32 nSize);
    BOOL DelHDD(astring &strPath, s32 nSize);
    BOOL GetDiskMap(VDBDiskMap &pMap);
    BOOL SearchItems(s32 deviceId, u32 startTime, u32 endTime, u32 recordType, 
    				RecordItemMap &map);
    BOOL SearchAItem(s32 deviceId, u32 Time, VdbRecordItem &pItem);
    BOOL SearchNextItem(s32 deviceId, s64 LastId, VdbRecordItem &pItem);
    BOOL RequestAMFRead(VdbRecordItem &pItem, astring & strPath);
    BOOL FinishedAMFRead(VdbRecordItem &pItem, astring & strPath);
public:
    void Lock(){m_Lock.lock();}
    bool TryLock(){return m_Lock.try_lock();}
    void UnLock(){m_Lock.unlock();}

public:
    s32 GetDeviceID(void);
    BOOL ReleaseDeviceID(s32 nID);
    BOOL LockDeviceID(s32 nID);
public:
    static void Run(void * pParam);
    void run();

private:
    DeviceMap m_DeviceMap;
    DeviceParamMap m_DeviceParamMap;
    fast_mutex m_Lock;
    tthread::thread *m_pThread;

private:
   DeviceChangeNofityMap m_DeviceChange;

private:
    VDB *m_pVdb;

private:
    s8 m_strDeviceMap[FACTORY_DEVICE_ID_MAX];
    ConfDB m_Conf;
    SysDB m_SysPath;
};

typedef Factory* LPFactory;

inline void OnvifLog(char * str)
{
    VDC_DEBUG( "%s\n", str);
    return;
}


inline Factory::Factory()
{
#ifdef WIN32
    astring strSysPath = "C:\\videodb\\system";
#else
    astring strSysPath = "ve/videodb/system/";
#endif
    m_SysPath.Open(strSysPath);
}

inline Factory::~Factory()
{

}

inline BOOL Factory::SetSystemPath(astring &strPath)
{
    return m_SysPath.SetSystemPath(strPath);
}

inline BOOL Factory::Init()
{

    s32 i = 0;

    for (i = 0; i < FACTORY_DEVICE_ID_MAX; i ++)
    {
        m_strDeviceMap[i] = 'n';
    }


    astring strPath;
    if (m_SysPath.GetSystemPath(strPath) == FALSE)
    {
        return FALSE;
        //strPath = "C:\\video";//TODO get the path from user
    }
    printf("Sys path %s\n", strPath.c_str());
#ifdef WIN32
    astring strPathConf = strPath + "videodb\\config";
#else
    astring strPathConf = strPath + "videodb/config";
#endif
    m_Conf.Open(strPathConf);

    astring strPathDb = strPath + "videodb";
    m_pVdb = new VDB(strPathDb);
    VSCConfData sysData;
    m_Conf.GetSysData(sysData);
    for (s32 i = 1; i < CONF_MAP_MAX; i ++)
    {
        if (sysData.data.conf.DeviceMap[i] != CONF_MAP_INVALID_MIN )
        {
            VDC_DEBUG( "%s Init %d\n",__FUNCTION__, i);
            VSCDeviceData Data;
            m_Conf.GetDeviceData(i, Data);
            DeviceParam mParam(Data);
            LockDeviceID(Data.data.conf.nId);
            InitAddDevice(mParam, Data.data.conf.nId);
            VDC_DEBUG( "%s Id %d\n",__FUNCTION__, Data.data.conf.nId);
        }
    }
    InitLicense();
       //m_pThread = new thread(Factory::Run, (void *)this);
       //start();
	return TRUE;
}

inline BOOL Factory::AddHDD(astring &strPath, s32 nSize)
{
    astring strPathHdd = strPath + "videodb";
    return m_pVdb->AddHdd(strPathHdd, nSize);
}

inline BOOL Factory::GetDiskMap(VDBDiskMap &pMap)
{
	return m_pVdb->GetDiskMap(pMap);
}

inline BOOL Factory::SearchItems(s32 deviceId, u32 startTime, u32 endTime, u32 recordType, 
				RecordItemMap &map)
{
    return m_pVdb->SearchItems(deviceId, startTime, endTime, recordType, 
                        map);
}
inline BOOL Factory::SearchAItem(s32 deviceId, u32 Time, VdbRecordItem &pItem)
{
    return m_pVdb->SearchAItem(deviceId, Time, pItem);
}
inline BOOL Factory::SearchNextItem(s32 deviceId, s64 LastId, VdbRecordItem &pItem)
{
    return m_pVdb->SearchNextItem(deviceId, LastId, pItem);
}
inline BOOL Factory::RequestAMFRead(VdbRecordItem &pItem, astring & strPath)
{
    return m_pVdb->RequestAMFRead(pItem, strPath);
}
inline BOOL Factory::FinishedAMFRead(VdbRecordItem &pItem, astring & strPath)
{
    return m_pVdb->FinishedAMFRead(pItem, strPath);
}

inline BOOL Factory::GetDeviceParamMap(DeviceParamMap &pMap)
{
    pMap = m_DeviceParamMap;

    return TRUE;
}

inline s32 Factory::InitAddDevice(DeviceParam & pParam, u32 nIndex)
{
    if (pParam.m_Conf.data.conf.nType == VSC_DEVICE_CAM)
    {
    	m_DeviceMap[nIndex] = new Device(*m_pVdb, pParam);
    }else
    {
    	m_DeviceMap[nIndex] = NULL;
    }
    m_DeviceParamMap[nIndex] = pParam;

    return TRUE;
}

inline NotificationQueue * Factory::GetRawDataQueue(s32 nIndex)
{
    NotificationQueue * pQueue = NULL;
    Lock();
    if (m_DeviceMap[nIndex] != NULL)
    {
        pQueue = m_DeviceMap[nIndex]->GetRawDataQueue();
    }

    UnLock();

    return pQueue;
}

inline BOOL Factory::ReleaseRawDataQueue(s32 nIndex, NotificationQueue * pQueue)
{
    Lock();
    if (m_DeviceMap[nIndex] != NULL)
    {
        m_DeviceMap[nIndex]->ReleaseRawDataQueue(pQueue);
    }

    UnLock();

    return TRUE;
}
inline NotificationQueue * Factory::GetDataQueue(s32 nIndex)
{
    return NULL;
}

inline BOOL Factory::GetDataQueue(s32 nIndex, NotificationQueue * pQueue)
{
    return TRUE;
}

inline BOOL Factory::RegDataCallback(s32 nIndex, DeviceDataCallbackFunctionPtr pCallback,
        void * pParam)
{
    Lock();
    if (m_DeviceMap[nIndex] != NULL)
    {
        UnLock();
        return m_DeviceMap[nIndex]->RegDataCallback(pCallback, pParam);
    }

    UnLock();

    return TRUE;
}

inline BOOL Factory::GetDeviceOnline(s32 nIndex, BOOL &bStatus)
{
    if (TryLock() == false)
    {
        return FALSE;
    }

    if (m_DeviceMap[nIndex] != NULL)
    {
        bStatus =  m_DeviceMap[nIndex]->GetDeviceOnline();
    }

    UnLock();

    return TRUE;
}

inline   BOOL Factory::GetUrl(s32 nIndex, std::string &url)
{
    BOOL ret = FALSE;

    if (m_DeviceMap[nIndex] != NULL)
    {
        ret =  m_DeviceMap[nIndex]->GetUrl(url);
    }

    UnLock();

    return ret;
}

inline BOOL Factory::UnRegDataCallback(s32 nIndex, void * pParam)
{
    Lock();
    if (m_DeviceMap[nIndex] != NULL)
    {
        UnLock();
        return m_DeviceMap[nIndex]->UnRegDataCallback(pParam);
    }

    UnLock();

    return TRUE;
}


inline BOOL Factory::StartDevice(s32 nIndex)
{
    Lock();
    if (m_DeviceMap[nIndex] != NULL)
    {
        m_DeviceMap[nIndex]->Start();
    }
    UnLock();

	return TRUE;
}

inline BOOL Factory::AttachPlayer(s32 nIndex, HWND hWnd, int w, int h)
{
    Lock();
    if (m_DeviceMap[nIndex] != NULL)
    {
        m_DeviceMap[nIndex]->AttachPlayer(hWnd, w, h);
    }
    UnLock();

	return TRUE;
}

inline BOOL Factory::UpdateWidget(s32 nIndex, HWND hWnd, int w, int h)
{
    Lock();
    if (m_DeviceMap[nIndex] != NULL)
    {
        m_DeviceMap[nIndex]->UpdateWidget(hWnd, w, h);
    }
    UnLock();

	return TRUE;
}

inline BOOL Factory::DetachPlayer(s32 nIndex, HWND hWnd)
{
    Lock();
    if (m_DeviceMap[nIndex] != NULL)
    {
        m_DeviceMap[nIndex]->DetachPlayer(hWnd);
    }
    UnLock();

	return TRUE;
}

inline BOOL Factory::DrawPtzDirection(s32 nIndex, HWND hWnd, int x1, int y1, int x2,  int y2)
{
    Lock();
    if (m_DeviceMap[nIndex] != NULL)
    {
        m_DeviceMap[nIndex]->DrawPtzDirection(hWnd, x1, y1, x2, y2);
    }
    UnLock();

	return TRUE;
}

inline BOOL Factory::ShowAlarm(s32 nIndex, HWND hWnd)
{
    Lock();
    if (m_DeviceMap[nIndex] != NULL)
    {
        m_DeviceMap[nIndex]->ShowAlarm(hWnd);
    }
    UnLock();

	return TRUE;
}

inline BOOL Factory::ClearPtzDirection(s32 nIndex, HWND hWnd)
{
    Lock();
    if (m_DeviceMap[nIndex] != NULL)
    {
        m_DeviceMap[nIndex]->ClearPtzDirection(hWnd);
    }
    UnLock();

	return TRUE;
}

inline BOOL Factory::PtzAction(s32 nIndex, FPtzAction action, float speed)
{
	Lock();
	if (m_DeviceMap[nIndex] != NULL)
	{
	    m_DeviceMap[nIndex]->PtzAction(action, speed);
	}
	UnLock();

	return TRUE;
}

inline BOOL Factory::StopDevice(s32 nIndex)
{
    Lock();

    UnLock();

	return TRUE;
}

inline BOOL Factory::GetRecordStatus(s32 nIndex,BOOL &nStatus)
{
    DeviceParam pParam;
    if (nIndex <=0 || nIndex >= FACTORY_DEVICE_ID_MAX)
    {
        return FALSE;
    }
    if (GetDeviceParamByIdTryLock(pParam, nIndex) == FALSE)
    {
        return FALSE;
    }
    if (pParam.m_Conf.data.conf.Recording == 1)
    {
        nStatus = TRUE;
    }else
    {
        nStatus = FALSE;
    }
    return TRUE;
}

inline BOOL Factory::StartRecord(s32 nIndex)
{
    DeviceParam pParam;
    FactoryDeviceChangeData change;
    if (nIndex <=0 || nIndex >= FACTORY_DEVICE_ID_MAX)
    {
        return FALSE;
    }
    GetDeviceParamById(pParam, nIndex);
    if (pParam.m_Conf.data.conf.Recording == 1)
    {
        return TRUE;
    }

    Lock();
    pParam.m_Conf.data.conf.Recording = 1;
    m_Conf.UpdateDeviceData(nIndex, pParam.m_Conf);
    m_DeviceParamMap[nIndex] = pParam;
    if (m_DeviceMap[nIndex] != NULL)
    {
        m_DeviceMap[nIndex]->SetRecord(TRUE);
        m_DeviceMap[nIndex]->StartRecord();
    }
    UnLock();
    change.id = nIndex;
    change.type = FACTORY_DEVICE_RECORDING_ON;
    CallDeviceChange(change);
    return TRUE;
}
inline BOOL Factory::StopRecord(s32 nIndex)
{
    DeviceParam pParam;
    FactoryDeviceChangeData change;
    if (nIndex <=0 || nIndex >= FACTORY_DEVICE_ID_MAX)
    {
        return FALSE;
    }
    GetDeviceParamById(pParam, nIndex);
    if (pParam.m_Conf.data.conf.Recording == 0)
    {
        return TRUE;
    }

    Lock();
    pParam.m_Conf.data.conf.Recording = 0;
    m_DeviceParamMap[nIndex] = pParam;
    m_Conf.UpdateDeviceData(nIndex, pParam.m_Conf);
    if (m_DeviceMap[nIndex] != NULL)
    {
        m_DeviceMap[nIndex]->SetRecord(FALSE);
        m_DeviceMap[nIndex]->StopRecord();
    }
    UnLock();
    change.id = nIndex;
    change.type = FACTORY_DEVICE_RECORDING_OFF;
    CallDeviceChange(change);
    return TRUE;
}

inline s32 Factory::AddDevice(DeviceParam & pParam)
{
    s32 nId = GetDeviceID();
    FactoryDeviceChangeData change;

    VDC_DEBUG( "%s GetDeviceID %d\n",__FUNCTION__, nId);

    Lock();
    pParam.m_Conf.data.conf.nId = nId;
    m_DeviceParamMap[nId] = pParam;

    m_Conf.AddDevice(pParam.m_Conf, nId);
    if (pParam.m_Conf.data.conf.nType == VSC_DEVICE_CAM)
    {
    	m_DeviceMap[nId] = new Device(*m_pVdb, pParam);
    }else
    {
	m_DeviceMap[nId] = NULL;
    }
    VDC_DEBUG( "%s  Line %d\n",__FUNCTION__, __LINE__);
    UnLock();
    VDC_DEBUG( "%s  Line %d\n",__FUNCTION__, __LINE__);
    change.id = nId;
    change.type = FACTORY_DEVICE_ADD;
    CallDeviceChange(change);
    VDC_DEBUG( "%s  Line %d\n",__FUNCTION__, __LINE__);
	
    return nId;
}

inline BOOL Factory::DelDevice(s32 nIndex)
{
    FactoryDeviceChangeData change;
    VDC_DEBUG( "%s DelDevice %d\n",__FUNCTION__, nIndex);
    if (nIndex <=0 || nIndex >= FACTORY_DEVICE_ID_MAX)
    {
        return FALSE;
    }

    //TODO check is this device can be delete or not
    Lock();
    VDC_DEBUG( "%s Cleanup Begin\n",__FUNCTION__);
    m_DeviceMap[nIndex]->Cleanup();
    VDC_DEBUG( "%s Cleanup End\n",__FUNCTION__);
    delete m_DeviceMap[nIndex];
    m_DeviceParamMap.erase(nIndex);
    m_DeviceMap.erase(nIndex);
    m_Conf.DelDevice(nIndex);
    ReleaseDeviceID(nIndex);
    UnLock();
	
    change.id = nIndex;
    change.type = FACTORY_DEVICE_DEL;
    CallDeviceChange(change);
    return TRUE;
}

inline BOOL Factory::GetVms(VSCVmsData &pData)
{
	Lock();
	m_Conf.GetVmsData(pData);
	UnLock();
	return TRUE;
}

inline BOOL Factory::GetVmsById(VSCVmsDataItem &pParam, int nId)
{
	VSCVmsData VmsData;
	int id = -1;
	Lock();
	m_Conf.GetVmsData(VmsData);
	if (nId < CONF_VMS_NUM_MAX && nId > 0)
	{
		if (VmsData.data.conf.vms[nId].Used == 1)
		{
			memcpy(&pParam, &(VmsData.data.conf.vms[nId]), sizeof(VSCVmsDataItem));
		}
	}else
	{
		UnLock();
		return FALSE;
	}
	return TRUE;
	
}

inline s32 Factory::AddVms(VSCVmsDataItem &pParam)
{
	VSCVmsData VmsData;
	FactoryDeviceChangeData change;
	int id = -1;
	Lock();
	m_Conf.GetVmsData(VmsData);
	/* Just use 1 to CONF_VMS_NUM_MAX */
	for (s32 i = 1; i < CONF_VMS_NUM_MAX; i ++)
	{
	    	if (VmsData.data.conf.vms[i].Used == 1)
	    	{
	    		continue;
	    	}else
	    	{
	    		memcpy(&(VmsData.data.conf.vms[i]), &pParam, sizeof(VSCVmsDataItem));
			VmsData.data.conf.vms[i].Used = 1;
			VmsData.data.conf.vms[i].nId = i;
			id = i;
			break;
	    	}
	}	
	m_Conf.UpdateVmsData(VmsData);
	UnLock();
	change.id = id;
	change.type = FACTORY_VMS_ADD;
	CallDeviceChange(change);
	return id;
}
inline BOOL Factory::DelVms(s32 Id)
{
	VSCVmsData VmsData;
	FactoryDeviceChangeData change;
	Lock();
	m_Conf.GetVmsData(VmsData);
	if (Id < CONF_VMS_NUM_MAX && Id > 0)
	{
		VmsData.data.conf.vms[Id].Used = 0;
	}else
	{
		UnLock();
		return FALSE;
	}
	
	m_Conf.UpdateVmsData(VmsData);
	UnLock();
	change.id = Id;
	change.type = FACTORY_VMS_DEL;
	CallDeviceChange(change);
	return TRUE;
}

inline BOOL Factory::GetDeviceRtspUrl(astring & strUrl, s32 nIndex)
{
	BOOL ret = FALSE;
	Lock();
	if (m_DeviceMap[nIndex] != NULL)
	{
	    ret = m_DeviceMap[nIndex]->GetDeviceRtspUrl(strUrl);
	}
	UnLock();

	return ret;
}

inline s32 Factory::GetDeviceParamById(DeviceParam & pParam, s32 nIndex)
{
    //VDC_DEBUG( "%s GetDeviceParamById %d\n",__FUNCTION__, nIndex);
    if (nIndex <=0 || nIndex >= FACTORY_DEVICE_ID_MAX)
    {
        return FALSE;
    }

    Lock();
    pParam = m_DeviceParamMap[nIndex];
    UnLock();

    return TRUE;
}

inline s32 Factory::GetDeviceParamByIdTryLock(DeviceParam & pParam, s32 nIndex)
{
    //VDC_DEBUG( "%s GetDeviceParamById %d\n",__FUNCTION__, nIndex);
    if (nIndex <=0 || nIndex >= FACTORY_DEVICE_ID_MAX)
    {
        return FALSE;
    }

#if 1
    if (TryLock() == false)
    {
        return FALSE;
    }
#else
    Lock();
#endif
    pParam = m_DeviceParamMap[nIndex];
    UnLock();

    return TRUE;
}

inline s32 Factory::GetDeviceID(void)
{
    s32 id  = -1;
    s32 i = -1;

    Lock();
    for (i = 1; i < FACTORY_DEVICE_ID_MAX; i ++)
    {
        if (m_strDeviceMap[i] == 'n')
        {
            id = i;
            m_strDeviceMap[i] = 'y';
            UnLock();
            return id;
        }
    }

    UnLock();
    return id;
}

inline BOOL Factory::ReleaseDeviceID(s32 nID)
{
    if (nID <=0 || nID >= FACTORY_DEVICE_ID_MAX)
    {
        return FALSE;
    }
    Lock();
    m_strDeviceMap[nID] = 'n';
    UnLock();

    return TRUE;
}

inline BOOL Factory::LockDeviceID(s32 nID)
{
    if (nID <=0 || nID >= FACTORY_DEVICE_ID_MAX)
    {
        return FALSE;
    }
    Lock();
    m_strDeviceMap[nID] = 'y';
    UnLock();

    return TRUE;
}

inline void Factory::Run(void * pParam)
{
    int dummy = errno;
    LPFactory pThread = (LPFactory)pParam;

    if (pThread)
    {
        //pThread->Run1();
    }
}

inline void Factory::run()
{
    int lastIdx = 0;
    while (1)
    {

        Lock();
        DeviceMap::iterator it = m_DeviceMap.begin(); 
        for(; it!=m_DeviceMap.end(); ++it)
        {
            s32 nIndex = (*it).first;
            DeviceMap::iterator next = it;
	     next ++;
	     VDC_DEBUG( "%s run CheckDevice %d   1\n",__FUNCTION__, nIndex);
	     
	     if (lastIdx +1 > nIndex  && next != m_DeviceMap.end())
	     {
			continue;
	     }
            if (next == m_DeviceMap.end())
            {
            	  lastIdx = 0; 
            }else
            {
            	 lastIdx = nIndex;
            }
	    VDC_DEBUG( "%s run CheckDevice %d   2\n",__FUNCTION__, nIndex);
	     if (m_DeviceMap[nIndex])
	     {
	        FactoryDeviceChangeData change;
		 change.id = nIndex;
		switch (m_DeviceMap[nIndex]->CheckDevice())
		{
		    case DEV_OFF2ON:
		    {
		        change.type = FACTORY_DEVICE_ONLINE;
			 CallDeviceChange(change);
		        break;
		    }
		    case DEV_ON2OFF:
		    {
		        change.type = FACTORY_DEVICE_OFFLINE;
			 CallDeviceChange(change);
		        break;
		    }
		    default:
		    {

		        break;
		    }
		}
	     }
	     break;
        }   
        UnLock();
#ifdef WIN32
        Sleep(1000 * 2);
#else
	sleep(2);
#endif
    }
}




#endif // __VSC_FACTORY_H_
