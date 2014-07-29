#ifndef _V_VIDEO_TYPE_H_
#define _V_VIDEO_TYPE_H_
#include "type.hpp"

typedef enum __VideoStreamType
{
	VIDEO_STREAM_VIDEO = 1,
	VIDEO_STREAM_AUDIO,
	VIDEO_STREAM_TEXT,
	VIDEO_STREAM_LAST
}VideoStreamType;

typedef enum __VideoFrameType
{
    VIDEO_FRM_NONE = 0,
    VIDEO_FRM_I = 1,
    VIDEO_FRM_P = 2,
    VIDEO_FRM_B = 3,
    VIDEO_FRM_LAST
} VideoFrameType;

typedef struct __VideoFrame
{
	VideoStreamType streamType;
 	VideoFrameType frameType;
 	u32 secs;       /* timestamp in seconds */
	u32 msecs;      /* timestamp in mseconds */
	u32 dataLen;
	u8   *dataBuf;
}VideoFrame;

#define MF_FILE_MAX_LENGTH 16 * 1024 * 1024

typedef enum
{
    MF_OK = 0,
    MF_WRTIE_REACH_END,
    MF_FRAME_TIME_ERROR,
    MF_LAST
} MFStatus;


typedef enum
{
    R_MANUAL = 1,
    R_ALARM,
    R_SCHED,
    R_ALL,
    R_LAST
} RecordingType;

enum RecordingMode {
   RECORDING_FULL_STOP = 1,
   RECORDING_FULL_LOOP
};

typedef struct __VdbRecordItem
{	
    s64 id;	
    s32 start;	
    s32 end;
} VdbRecordItem;

typedef struct __VdbDiskItem
{	
    s64 total;	
    s64 used;
} VdbDiskItem;

typedef std::map<int, VdbRecordItem> RecordItemMap;

typedef enum
{
    EVENT_TYPE_MOTION = 1,
    EVENT_TYPE_LAST
} VscEventType;

#endif /* _V_VIDEO_TYPE_H_ */
