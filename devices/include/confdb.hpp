

#ifndef _CONF_DB_H_
#define _CONF_DB_H_

#include "utility.hpp"
#include "leveldb/db.h"
#include "conf.hpp"
#include "debug.hpp"

using namespace UtilityLib;

class ConfDB
{
public:
    ConfDB()
    {

    }
    ~ConfDB()
    {

    }

    s32 Open(astring & pPath);
public:

    BOOL GetDeviceData(u32 nId, VSCDeviceData &pData);
    BOOL UpdateDeviceData(u32 nId, VSCDeviceData &pData);

    BOOL GetLicense(astring &strLicense);
    BOOL SetLicense(astring &strLicense);

    s32 GetSysData(VSCConfData &pSysData);
    s32 UpdateSysData(VSCConfData &pSysData);

    s32 AddDevice(VSCDeviceData &pData, u32 nId);
    s32 DelDevice(u32 nId);

    s32 GetVmsData(VSCVmsData &pVmsData);
    s32 UpdateVmsData(VSCVmsData &pVmsData);

public:
    BOOL GetSystemConf(VSCConfData &pSys);
    BOOL GetVmsConf(VSCVmsData &pVms);

public:
    void Lock()
    {
        m_Lock.lock();
    }
    void UnLock()
    {
        m_Lock.unlock();
    }


private:
    fast_mutex m_Lock;

private:
    leveldb::DB* m_pDb;
    leveldb::Options m_Options;
};

typedef ConfDB* LPConfDB;


using namespace std;

inline BOOL SysConfDataDefault(VSCConfData &pConf)
{
    pConf.data.conf.DeviceNum = 0;
    for (s32 i = 0; i < CONF_MAP_MAX; i ++)
    {
        pConf.data.conf.DeviceMap[i] = CONF_MAP_INVALID_MIN;
    }

    return TRUE;
}

inline BOOL VmsConfDataDefault(VSCVmsData &pConf)
{
	memset(&pConf, 0, sizeof(VSCVmsData));

	for (s32 i = 0; i < CONF_VMS_NUM_MAX; i ++)
	{
	    	pConf.data.conf.vms[i].nId = i;
		pConf.data.conf.vms[i].Used = 0;
	}

    return TRUE;
}

inline s32 ConfDB::Open(astring & pPath)
{
    m_Options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(m_Options, pPath, &m_pDb);
    if (false == status.ok())
    {
        //cerr << "Unable to open/create test database "<< pPath << endl;
        //cerr << status.ToString() << endl;
        VDC_DEBUG( "Unable to open/create test database %s\n", pPath.c_str());

        return FALSE;
    }
    return TRUE;
}

inline BOOL ConfDB::GetSystemConf(VSCConfData &pSys)
{
    VSCConfSystemKey sSysKey;

    leveldb::Slice key((char *)&sSysKey, sizeof(sSysKey));


    leveldb::Iterator* it = m_pDb->NewIterator(leveldb::ReadOptions());

    it->Seek(key);
    leveldb::Slice sysValue;

    if (it->Valid())
    {
        sysValue = it->value();
    }

    if (sysValue.size() != sizeof(VSCConfData))
    {
        VDC_DEBUG( "System Config is not init\n");
        delete it;
        memset(&pSys, 0, sizeof(VSCConfData));
        SysConfDataDefault(pSys);
        UpdateSysData(pSys);
        astring strLicense = "no license";
        SetLicense(strLicense);//set the default license
        /* Call get system again */
        return TRUE;
    }

    memcpy(&pSys, sysValue.data(), sizeof(VSCConfData));

    // Check for any errors found during the scan
    assert(it->status().ok());
    delete it;

    return TRUE;

}

inline BOOL ConfDB::GetVmsConf(VSCVmsData &pVms)
{
    VSCConfVmsKey sVmsKey;

    leveldb::Slice key((char *)&sVmsKey, sizeof(sVmsKey));


    leveldb::Iterator* it = m_pDb->NewIterator(leveldb::ReadOptions());

    it->Seek(key);
    leveldb::Slice sysValue;

    if (it->Valid())
    {
        sysValue = it->value();
    }

    if (sysValue.size() != sizeof(VSCVmsData))
    {
        VDC_DEBUG( "VMS Config is not init\n");
        delete it;
        memset(&pVms, 0, sizeof(VSCVmsData));
        VmsConfDataDefault(pVms);
        UpdateVmsData(pVms);
        /* Call get system again */
        return TRUE;
    }

    memcpy(&pVms, sysValue.data(), sizeof(VSCVmsData));

    // Check for any errors found during the scan
    assert(it->status().ok());
    delete it;

    return TRUE;

}

inline s32 ConfDB::UpdateSysData(VSCConfData &pSysData)
{
    VSCConfSystemKey sSysKey;

    leveldb::WriteOptions writeOptions;

    leveldb::Slice sysKey((char *)&sSysKey, sizeof(sSysKey));
    leveldb::Slice sysValue((char *)&pSysData, sizeof(VSCConfData));

    m_pDb->Put(writeOptions, sysKey, sysValue);

    return TRUE;
}

inline s32 ConfDB::GetSysData(VSCConfData &pSysData)
{
    GetSystemConf(pSysData);

    return TRUE;
}

inline BOOL ConfDB::UpdateDeviceData(u32 nId, VSCDeviceData &pData)
{
    VSCConfDeviceKey sChKey(nId);
    leveldb::WriteOptions writeOptions;

    leveldb::Slice chKey((char *)&sChKey, sizeof(sChKey));
    leveldb::Slice chValue((char *)&pData, sizeof(VSCDeviceData));
    m_pDb->Put(writeOptions, chKey, chValue);

    return TRUE;
}

inline BOOL ConfDB::GetDeviceData(u32 nId, VSCDeviceData &pData)
{
    VSCConfDeviceKey sChKey(nId);

    leveldb::Slice key((char *)&sChKey, sizeof(sChKey));


    leveldb::Iterator* it = m_pDb->NewIterator(leveldb::ReadOptions());

    it->Seek(key);
    leveldb::Slice sysValue;

    if (it->Valid())
    {
        sysValue = it->value();
    }

    if (sysValue.size() != sizeof(VSCDeviceData))
    {
        VDC_DEBUG( "Device Can not find !!!\n");

        delete it;
        return FALSE;
    }

    memcpy(&pData, sysValue.data(), sizeof(VSCDeviceData));

    // Check for any errors found during the scan
    assert(it->status().ok());
    delete it;

    return TRUE;
}


inline s32 ConfDB::GetVmsData(VSCVmsData &pVmsData)
{
	GetVmsConf(pVmsData);
	
	return TRUE;
}
inline s32 ConfDB::UpdateVmsData(VSCVmsData &pVmsData)
{
    VSCConfVmsKey sVmsKey;

    leveldb::WriteOptions writeOptions;

    leveldb::Slice sysKey((char *)&sVmsKey, sizeof(sVmsKey));
    leveldb::Slice sysValue((char *)&pVmsData, sizeof(VSCVmsData));

    m_pDb->Put(writeOptions, sysKey, sysValue);

    return TRUE;
}
    

inline   BOOL ConfDB::GetLicense(astring &strLicense)
{
	VSCConfLicenseKey sLicKey;
	

	leveldb::Slice key((char *)&sLicKey, sizeof(sLicKey));


	leveldb::Iterator* it = m_pDb->NewIterator(leveldb::ReadOptions());

	it->Seek(key);
	leveldb::Slice sysValue;

	if (it->Valid())
	{
		sysValue = it->value();
		strLicense = sysValue.ToString();
	}
	
	// Check for any errors found during the scan
	assert(it->status().ok());
	delete it;

	return TRUE;

}
inline   BOOL ConfDB::SetLicense(astring &strLicense)
{
	VSCConfLicenseKey sLic;
	leveldb::WriteOptions writeOptions;

	leveldb::Slice licKey((char *)&sLic, sizeof(sLic));
	leveldb::Slice licValue(strLicense);
	m_pDb->Put(writeOptions, licKey, licValue);
	return true;
    
}

inline s32 ConfDB::AddDevice(VSCDeviceData &pData, u32 nId)
{
    if (nId > CONF_MAP_MAX)
    {
        return FALSE;
    }
    VSCConfData SysData;
    GetSysData(SysData);

    SysData.data.conf.DeviceMap[nId] = nId;
    SysData.data.conf.DeviceNum ++;
    pData.data.conf.nId = nId;

    UpdateSysData(SysData);

    UpdateDeviceData(nId, pData);


    return TRUE;
}

inline s32 ConfDB::DelDevice(u32 nId)
{
    if (nId > CONF_MAP_MAX)
    {
        return FALSE;
    }

    VSCConfData SysData;
    GetSysData(SysData);

    SysData.data.conf.DeviceMap[nId] = CONF_MAP_INVALID_MIN;

    UpdateSysData(SysData);

    return TRUE;
}



#endif /* _CONF_DB_H_ */
