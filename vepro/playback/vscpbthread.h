#ifndef VSC_PB_THREAD_H
#define VSC_PB_THREAD_H

#include <QDialog>
#include <QTimer>
#include "utility.hpp"
#include <QThread>
#include "vscsimpletl.h"
#include "factory.hpp"
#include "vplay.hpp"
#include "videowidget.h"

class VSCPbThread : public QThread
{
    Q_OBJECT

public:
    VSCPbThread(u32 id, u32 PlayTime, VSCSimpleTl &Timeline, HWND videoWindow,
		VideoWidget &pVideo, VPlay &pVPlay);
    ~VSCPbThread()
    {
        disconnect(&m_Timeline, SIGNAL( SeekToTime(int)), this, SLOT(SeekToTime(int)));
        m_pVPlay.DetachWidget(m_videoWindow);
        
        if (m_pbFrame.dataBuf)
        {
            delete m_pbFrame.dataBuf;
        }
        if (m_pbSession  != NULL)
        {
            delete m_pbSession;
        }
    }
public:
	void run();
public slots:
    void SeekToTime(int seekTime);
    void videoResizeEvent();
signals:
    void ChangedToPause();
    void GetANewFrame();
public:
	void setQuit()
	{
	    m_Quit = TRUE;
           return;
	}
public:
	BOOL SetPlaying(BOOL bPlaying)
       {
           m_Playing =   bPlaying;
           return TRUE;
       }
public:
    void Lock(){m_Lock.lock();}
    bool TryLock(){return m_Lock.try_lock();}
    void UnLock(){m_Lock.unlock();}
public:
    BOOL FeedAFrame(VideoFrame &pbFrame, s32 &waiting);
private:
	VSCSimpleTl &m_Timeline;
	VideoWidget &m_pVideo;
	HWND m_videoWindow;
 	VPlay &m_pVPlay;
	u32 m_DeviceId;
	u32 m_Playtime;
	BOOL m_Quit;
	PlaybackSession *m_pbSession;
	VideoFrame m_pbFrame;
	fast_mutex m_Lock;
	BOOL m_Playing;
	VdbRecordItem m_recordItem;
	s32 m_nLastSec;

};

#endif // VSC_PB_THREAD_H
