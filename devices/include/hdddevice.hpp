#ifndef _HDD_H_
#define _HDD_H_

#include "utility.hpp"
#include "leveldb/db.h"
#include "conf.hpp"
#include "debug.hpp"
#include <qstorageinfo.h>
#include <QtCore/QFileInfoList>
#include <QtCore/QDir>

using namespace UtilityLib;

/* This is same with QStorageInfo define */
enum HddDriveType {
	HddUnknownDrive = 0,
	HddInternalDrive,
	HddRemovableDrive,
	HddRemoteDrive,
	HddCdromDrive,
	HddRamDrive
};

class HddDevice
{
public:
    HddDevice()
    {

    }
    ~HddDevice()
    {

    }

public:
    QStringList GetDeviceList();
    s64 GetTotalDiskSpace(astring &strDevice);
    s64 GetavailableDiskSpace(astring &strDevice);
    HddDriveType GetHddType(astring &strDevice);

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
	QStorageInfo m_Info;
};

typedef HddDevice* LPHddDevice;


using namespace std;

inline QStringList HddDevice::GetDeviceList()
{
	return m_Info.allLogicalDrives();
}

/* Total size is in M */
inline s64 HddDevice::GetTotalDiskSpace(astring &strDevice)
{
	return m_Info.totalDiskSpace(strDevice.c_str()) / (1024 * 1024);
}

/* Total size is in M */
inline s64 HddDevice::GetavailableDiskSpace(astring &strDevice)
{
	return m_Info.availableDiskSpace(strDevice.c_str()) / (1024 * 1024);
}
inline HddDriveType HddDevice::GetHddType(astring &strDevice)
{
	return (HddDriveType)(m_Info.driveType(strDevice.c_str()));
}



#endif /* _HDD_H_ */
