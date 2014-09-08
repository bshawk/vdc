#ifndef _V_VIDEO_TYPE_H_
#define _V_VIDEO_TYPE_H_
#include "type.hpp"

typedef enum __VideoStreamType
{
	VIDEO_STREAM_VIDEO = 1,
	VIDEO_STREAM_AUDIO,
	VIDEO_STREAM_INFO,
	VIDEO_STREAM_TEXT,
	VIDEO_STREAM_LAST
}VideoStreamType;

typedef enum __CodecType
{
        CODEC_H264 = 1,
        CODEC_H265,
        CODEC_MPEG4,
        CODEC_MJPEG,
        CODEC_PCMA,
        CODEC_PCMU, 
        CODEC_LAST
}CodecType;

typedef enum __VideoFrameType
{
    VIDEO_FRM_NONE = 0,
    VIDEO_FRM_I = 1,
    VIDEO_FRM_P = 2,
    VIDEO_FRM_B = 3,
    VIDEO_FRM_INFO = 4,
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

typedef struct __InfoFrame
{
        CodecType video;
        u32 vWidth;
        u32 vHeight;
        u32 vFps;
        CodecType audio;
        u32 aRate;
        u32 aBitrate;
        u32 aChannels;
        u32 aBitspersample;
        u32 padding1;
        u32 padding2;
        u32 padding3;
        u32 padding4;
        u32 padding5;
        u32 padding6;
        u32 padding7;
        u32 padding8;
}InfoFrame;


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
