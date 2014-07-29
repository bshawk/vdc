#include "vscpbthread.h"
#include "debug.hpp"

extern Factory *gFactory;
VSCPbThread::VSCPbThread(u32 id, u32 PlayTime, VSCSimpleTl &Timeline, 
    HWND videoWindow, VideoWidget &pVideo, VPlay &pVPlay)
:m_Timeline(Timeline), m_videoWindow(videoWindow), m_DeviceId(id), m_Playtime(PlayTime), 
m_Quit(FALSE), m_pbSession(NULL), m_pVPlay(pVPlay), 
m_pVideo(pVideo)
{
    connect(&Timeline, SIGNAL( SeekToTime(int)), this, SLOT(SeekToTime(int)));
    m_pbFrame.dataBuf = (u8 *)malloc(1024 * 1024);
    m_Playing = FALSE;
    m_nLastSec = 0;
    m_pVPlay.Init(FALSE, "fake", "fake", "fake");
    connect(&m_pVideo, SIGNAL(videoResize()), this, SLOT(videoResizeEvent()));
    m_pVPlay.AttachWidget(m_videoWindow, pVideo.width(), pVideo.height());
}

void VSCPbThread::videoResizeEvent()
{
	m_pVPlay.UpdateWidget(m_videoWindow, m_pVideo.width(), m_pVideo.height());
}

void VSCPbThread::SeekToTime(int seekTime)
{
    astring strPath;
    s32 waiting = 0;
    Lock();
    //VDC_DEBUG( "%s Seekto %d\n",__FUNCTION__, seekTime);   
    if (m_pbSession)
    {
        if (m_pbSession->SeekToTime(seekTime) == FALSE)
        {
             if (gFactory->SearchAItem(m_DeviceId, seekTime, m_recordItem) == TRUE)
             {
                 delete m_pbSession;
                 m_pbSession = NULL;
                 gFactory->FinishedAMFRead(m_recordItem, strPath);
                  if (gFactory->RequestAMFRead(m_recordItem, strPath) == FALSE)
                  {
                            UnLock();
                            return;
                  }
                 m_pbSession = new PlaybackSession(m_DeviceId, strPath);
                 m_pbSession->SeekToTime(seekTime);
              }else
              {
                 delete m_pbSession;
                 m_pbSession = NULL; 
                 UnLock();
                 return;
              }
         }
        m_Playing = FALSE;
        emit ChangedToPause();
        FeedAFrame(m_pbFrame, waiting);
        //If no in the file, just another search
    }else
    {
         if (gFactory->SearchAItem(m_DeviceId, seekTime, m_recordItem) == TRUE)
         {
             delete m_pbSession;
             m_pbSession = NULL;
             gFactory->FinishedAMFRead(m_recordItem, strPath);
              if (gFactory->RequestAMFRead(m_recordItem, strPath) == FALSE)
              {
                        UnLock();
                        return;
              }
             m_pbSession = new PlaybackSession(m_DeviceId, strPath);
             m_pbSession->SeekToTime(seekTime);
          }
    }
    UnLock();
}

BOOL VSCPbThread::FeedAFrame(VideoFrame &pbFrame, s32 &waiting)
{
    s32 nDataType;
    astring strPath;
    s32 nLastSec = 0;
    u32 nKeyFrame = 0;
    if (m_pbSession)
    {
             //VDC_DEBUG( "%s Playback %d\n",__FUNCTION__, i ++);   
             if (m_pbSession->GetAFrame(pbFrame, waiting) == MF_WRTIE_REACH_END)
             {
                 delete m_pbSession;
                 m_pbSession = NULL;
                 gFactory->FinishedAMFRead(m_recordItem, strPath);
                 if (gFactory->SearchNextItem(m_DeviceId, m_recordItem.id, m_recordItem) == FALSE)
                 {
                     return TRUE;
                 }
                  if (gFactory->RequestAMFRead(m_recordItem, strPath) == FALSE)
                  {
                      return TRUE;
                  }
                 m_pbSession = new PlaybackSession(m_DeviceId, strPath);
                
                 return TRUE;
             }
             //VDC_DEBUG("Read Size %d stream %d frame %d (%d, %d)\n", pbFrame.dataLen,      
		//	 	pbFrame.streamType, pbFrame.frameType, pbFrame.secs, pbFrame.msecs);
            if (pbFrame.secs != m_nLastSec)
            {
         	     QMetaObject::invokeMethod(&m_Timeline,"SetStartTime"
                                  ,Q_ARG(int, pbFrame.secs));
                m_nLastSec = pbFrame.secs;
            }
            m_pVPlay.PutRawData(pbFrame);
            emit GetANewFrame();
            
    }
    return TRUE;
}

void VSCPbThread::run()
{
        s32 nDataType;
        astring strPath;
        s32 nLastSec = 0;

        m_Playing = TRUE;
        s32 waiting = 0;
        u32 nKeyFrame = 0;
        if (gFactory->SearchAItem(m_DeviceId, m_Playtime, m_recordItem) == TRUE)
        {
               if (gFactory->RequestAMFRead(m_recordItem, strPath) == TRUE)
              {
                  m_pbSession = new PlaybackSession(m_DeviceId, strPath);
              }
        }
        
        int i = 0;
        while(! m_Quit)
         {
        
              while (! m_Quit && m_pbSession && m_Playing == TRUE)
              {
                  Lock();
                  FeedAFrame(m_pbFrame, waiting);
                  UnLock();
#ifdef WIN32
                  Sleep(waiting);    
              }
              Sleep(100);  
#else
                  usleep(waiting * 1000);    
              }
              usleep(100 * 1000);  
#endif
        }

        int a = 1;
}
