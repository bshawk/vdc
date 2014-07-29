#ifndef VSC_SIMPLE_TL_H
#define VSC_SIMPLE_TL_H

/* Simple timeline */

#include <QDialog>
#include <QTimer>
#include "ui_vscsimpletl.h"
#include "utility.hpp"
#include "videotype.hpp"
#include "factory.hpp"

typedef enum __VscTimelineMode
{
    TIMELINE_MODE_SIMPLE = 0,
    TIMELINE_MODE_FULL = 1,
    TIMELINE_MODE_LAST
} VscTimelineMode;

typedef enum __VscTimelineLength
{
    TIMELINE_LEN_1_MIN = 0,
    TIMELINE_LEN_5_MIN ,
    TIMELINE_LEN_30_MIN ,
    TIMELINE_LEN_2_HOUR ,
    TIMELINE_LEN_1_DAY ,
    TIMELINE_LEN_7_DAY ,
    TIMELINE_LEN_14_DAY,
    TIMELINE_LEN_LAST
} VscTimelineLength;

typedef std::map<int, astring> TimeLineMap;

class VSCSimpleTl : public QWidget
{
    Q_OBJECT

public:
    VSCSimpleTl(QWidget *parent = 0);
    ~VSCSimpleTl(){}
public:
    Q_INVOKABLE void SetStartTime(int sTime);
    void SetEnabled(BOOL enable)
    {
        m_Enabled = enable;
        repaint();
    }
    void SetId(s32 nId)
    {
        m_Id = nId;
    }
public slots:
    void UpdateTime();

signals:
    void TimeLineChange(int nStatus);
    void SeekToTime(int seekTime);
public:
    int GetTimeLineInSec();
    BOOL SetTimeLineLength(VscTimelineLength nLength);
    BOOL GetTimeLineMap(int w, TimeLineMap &map);
    std::string GetTimeLineTimeString(int time);
    BOOL SearchItems(RecordItemMap &map, u32 startTime, u32 endTime);
    BOOL GetDrawSearchItems(RecordItemMap &map, s32 nWidth, u32 startTime, u32 endTime);

protected:
    virtual void paintEvent(QPaintEvent *);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void mouseMoveEvent(QMouseEvent *);

public:
    Ui::VSCSimpleTl ui;
private:
	int startTime;
	int endTime;
	int movingReference;
    int diffDays;
    bool moving;
    int mouseX;
    int lastX;
	double dayLength;
	QTimer *m_Timer;
	BOOL m_Enabled;
	VscTimelineMode m_TimeLineMode;
	int m_lastWidth;
	VscTimelineLength m_TimelineLength;
	s32 m_Id;
};

#endif // VSC_SIMPLE_TL_H
