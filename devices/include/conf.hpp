
 
#ifndef _CONF_H_
#define _CONF_H_

#include "utility.hpp"

#define VE_VERSION "V2014-0821"
#define VE_INFO "VdcEye Manager"

#ifdef WIN32
#define VE_NVR_CLIENT 
#else
#define VE_NVR
#endif

/* NVR Client feature */
#ifdef VE_NVR_CLIENT
#define VE_RECORDER_MGR_CLIENT_SUPPORT 
#endif

/* NVR feature */
#ifdef VE_NVR
#define VE_RECORDER_MGR_SERVER_SUPPORT
#endif

#define CONF_NAME_MAX 128
/* support Camera num */
#define CONF_MAP_MAX 4096
#define CONF_USER_PASSWORD_MAX 1024
#define CONF_PATH_MAX 1024
/* 0xFF FFFF to 0xFFFF FFFF is for status for the map */
#define CONF_MAP_INVALID_MIN 0xFFFFFF
#define CONF_KEY_STR_MAX 16

/* Support VMS(site, recorder) num */
#define CONF_VMS_NUM_MAX 128

#define VSC_CONF_KEY "ConfVSCSystem"
#define VSC_CONF_LIC_KEY "ConfVSCLicense"
#define VSC_CONF_CHANNEL_KEY "ConfVSCDevice"
#define VSC_CONF_VMS_KEY "ConfVSCVms"
#define VSC_CONF_PARAM_MAX 1024
#define VSC_CONF_PARAM_S_MAX 128

typedef enum
{
    VSC_DEVICE_CAM = 1,
    VSC_DEVICE_RECORDER,

    VSC_DEVICE_LAST
} VSCDeviceType;

/* Device Type */
typedef enum
{
    VSC_SUB_DEVICE_USB_CAM = 1,
    VSC_SUB_DEVICE_FILE,
    VSC_SUB_DEVICE_RTSP,
    VSC_SUB_DEVICE_ONVIF,
    VSC_SUB_DEVICE_ONVIF_RECODER,

    VSC_SUB_DEVICE_LAST
} VSCDeviceSubType;

typedef enum
{
    VSC_VMS_RECORDER = 1,
    VSC_VMS_SITE,
    VSC_VMS_VIRTUL_IPC,
    
    VSC_VMS_LAST
} VSCVmsType;

typedef enum
{
    VSC_SUB_VMS_PG = 1,
    VSC_SUB_VMS_ZB,
    VSC_SUB_VIRTUL_IPC,
    
    VSC_SUB_VMS_LAST
} VSCVmsSubType;

#pragma pack(push,  1 )
typedef struct __VSCConfSystemKey {
    s8 Key[CONF_KEY_STR_MAX];
    __VSCConfSystemKey()
    {
        memset(Key, 0, CONF_KEY_STR_MAX);
        strcpy(Key, VSC_CONF_KEY);
    }
}VSCConfSystemKey;

typedef struct __VSCConfLicenseKey {
    s8 Key[CONF_KEY_STR_MAX];
    __VSCConfLicenseKey()
    {
        memset(Key, 0, CONF_KEY_STR_MAX);
        strcpy(Key, VSC_CONF_LIC_KEY);
    }
}VSCConfLicenseKey;

typedef struct __VSCConfDeviceKey {
    u32 nId;
    s8 Key[CONF_KEY_STR_MAX];
    __VSCConfDeviceKey(u32 id)
    {
        memset(Key, 0, CONF_KEY_STR_MAX);
        strcpy(Key, VSC_CONF_CHANNEL_KEY);
        nId = id;
    }
}VSCConfDeviceKey;

typedef struct __VSCConfVmsKey {
    s8 Key[CONF_KEY_STR_MAX];
    __VSCConfVmsKey()
    {
        memset(Key, 0, CONF_KEY_STR_MAX);
        strcpy(Key, VSC_CONF_VMS_KEY);
    }
}VSCConfVmsKey;


typedef struct __VSCConfData__ {
    u32 DeviceMap[CONF_MAP_MAX];
    u32 Language;
    u32 DeviceNum;
}VSCConfData__;

typedef struct __VSCConfData {
    union {
        VSCConfData__ conf;
        u8 whole[1024 * 128];
    } data;
}VSCConfData;

typedef struct __VSCDeviceData__ {
	u32 nId;
	VSCDeviceType nType;
	VSCDeviceSubType nSubType;

	s8 Name[CONF_NAME_MAX];
	s8 Param[VSC_CONF_PARAM_MAX];

	s8 IP[VSC_CONF_PARAM_MAX];
	s8 Port[VSC_CONF_PARAM_MAX];
	s8 User[VSC_CONF_PARAM_MAX];
	s8 Password[VSC_CONF_PARAM_MAX];

	/* Camera Param */
	s8 RtspLocation[VSC_CONF_PARAM_MAX];
	s8 FileLocation[VSC_CONF_PARAM_MAX];
	s8 OnvifAddress[VSC_CONF_PARAM_MAX];
	s8 CameraIndex[VSC_CONF_PARAM_MAX];/* This is For USB Camera */

	u32 UseProfileToken;/* 1 stand for use, 0 stand for do not use */
	s8 OnvifProfileToken[VSC_CONF_PARAM_MAX];

	/* Recording */
	u32 Recording;/* 1 stand for recording, 0 stand for do record */
	u32 GroupId;
}VSCDeviceData__;

typedef struct __VSCVmsDataItem__ {
	u32 nId;
	VSCVmsType nType;
	VSCVmsSubType nSubType;

	s8 Name[CONF_NAME_MAX];
	s8 Param[VSC_CONF_PARAM_MAX];

	s8 IP[VSC_CONF_PARAM_MAX];
	s8 Port[VSC_CONF_PARAM_MAX];
	s8 User[VSC_CONF_PARAM_MAX];
	s8 Password[VSC_CONF_PARAM_MAX];

	s8 OnvifAddress[VSC_CONF_PARAM_MAX];
	u32 GroupId;
	u32 Used;/* 1 stand for used, 0 stand for not used */
}VSCVmsDataItem;

inline void VSCVmsDataItemDefault(VSCVmsDataItem &item)
{
    sprintf(item.Name, "Site");

    strcpy(item.IP, "192.168.0.1");
    strcpy(item.Port, "80");
    strcpy(item.User, "admin");
    strcpy(item.Password, "admin");
    item.Used = 0;
    item.nId = 0;
    item.GroupId = 0;
}

typedef struct __VSCVmsData__ {
	VSCVmsDataItem vms[CONF_VMS_NUM_MAX];
}VSCVmsData__;

typedef struct __VSCDeviceData {
    union {
        VSCDeviceData__ conf;
        u8 whole[1024 * 128];
    } data;
}VSCDeviceData;

typedef struct __VSCVmsData {
    union {
        VSCVmsData__ conf;
        u8 whole[1024 * 128];
    } data;
}VSCVmsData;

#pragma pack(pop)

#endif /* _CONF_H_ */
