#include "vscsimpletl.h"
#include "debug.hpp"
#include <QPainter>
#include <QFont>
#include <QPaintEvent>

extern Factory *gFactory;
/* 60 s, and every 15s  */
VSCSimpleTl::VSCSimpleTl(QWidget *parent)
    : QWidget(parent), m_Enabled(FALSE),m_TimeLineMode(TIMELINE_MODE_FULL),
    m_TimelineLength(TIMELINE_LEN_5_MIN)
{
   int currentTime = time(NULL);
   /* Move the the before 2 min */
   currentTime = currentTime - 60 * 2;
   ui.setupUi(this);
   diffDays = GetTimeLineInSec();
   startTime = currentTime - diffDays/2;
   endTime = currentTime + diffDays/2;
   m_Timer = new QTimer(this);
   connect(m_Timer, SIGNAL(timeout()), this, SLOT(UpdateTime()));
   //m_Timer->start(1000);
   m_lastWidth = width();
 
}

BOOL VSCSimpleTl::SearchItems(RecordItemMap &map, u32 startTime, u32 endTime)
{
    gFactory->SearchItems(m_Id, startTime, endTime, 1, map);

    return TRUE;
}

BOOL VSCSimpleTl::GetDrawSearchItems(RecordItemMap &map, s32 nWidth, 
						u32 startTime, u32 endTime)
{
	RecordItemMap rawMap;
	VdbRecordItem lastItem;
	SearchItems(rawMap, startTime, endTime);
       RecordItemMap::iterator it;
	int i = 0;
       
       if (rawMap.size() <= 0)
       	{
             VDC_DEBUG( "%s  Search nothing\n",__FUNCTION__);   
             return TRUE;
       	}
	memset(&lastItem, 0, sizeof(lastItem));
	it = rawMap.begin();
	/* Merge items */
       for(; it!=rawMap.end(); ++it)
       {
            //VDC_DEBUG( "%s  id %d (%d, %d, %lld)\n",__FUNCTION__, 
           //            (*it).first, (*it).second.start, (*it).second.end, (*it).second.id);
            if (lastItem.start == 0)
            {
                lastItem.start = (*it).second.start;
                lastItem.end = (*it).second.end;
                continue;
            } 
	
	        if ((*it).second.start == lastItem.end)
            {
                lastItem.end = (*it).second.end;
            }else // ((*it).second.start != lastItem.end)
            {
                map[i] = lastItem;
		        i ++;
                lastItem.start = (*it).second.start;
                lastItem.end = (*it).second.end;
            }
        }
        map[i] = lastItem;
        i ++;
	
	it = map.begin();

       for(; it!=map.end(); ++it)
       {
            //VDC_DEBUG( "%s  id %d (%d, %d, %lld)\n",__FUNCTION__, 
            //           (*it).first, (*it).second.start, (*it).second.end, (*it).second.id);
	     if (it == map.begin())
	     {
                  if ((*it).second.start < startTime)
                  {
                       (*it).second.start = startTime;
                  }
                  if ((*it).second.end > endTime)
                  {
                       (*it).second.end = endTime;
                  }
	     }
	     if (it != map.end())
	     {
	           RecordItemMap::iterator last = it;
                  last ++;
                  if (last == map.end())
                  {
                       if ((*it).second.end > endTime)
                       {
                            (*it).second.end = endTime;
                       }
                  }
	     }
            //VDC_DEBUG( "%s  id %d (%d, %d, %lld)\n",__FUNCTION__, 
            //           (*it).first, (*it).second.start, (*it).second.end, (*it).second.id);
        }

        double ratio = (double)nWidth /(double)(endTime - startTime);
        //VDC_DEBUG( "%s  ratio %f endTime - startTime %d nWidth %d\n",__FUNCTION__, ratio, 
        //                    endTime - startTime, nWidth);
	it = map.begin();
       for(; it!=map.end(); ++it)
       {
            (*it).second.start = (double)((*it).second.start - startTime) * ratio;
	     (*it).second.end = (double)((*it).second.end - startTime) * ratio;
            //VDC_DEBUG( "%s  id %d (%d, %d)\n",__FUNCTION__, 
            //           (*it).first, (*it).second.start, (*it).second.end);
        }
	 return TRUE;
}

BOOL VSCSimpleTl::SetTimeLineLength(VscTimelineLength nLength)
{
    m_TimelineLength = nLength;
    int currentTime = startTime + diffDays/2;
    diffDays = GetTimeLineInSec();
    startTime = currentTime - diffDays/2;
    if (startTime < 0)
    {
    	startTime = 0;
    }
    
    endTime = currentTime + diffDays/2;
#if 0
    RecordItemMap map;
    SearchItems(map);
    RecordItemMap::iterator it = map.begin();
    for(; it!=map.end(); ++it)
    {
          VDC_DEBUG( "%s  id %d (%d, %d, %lld)\n",__FUNCTION__, 
                    (*it).first, (*it).second.start, (*it).second.end, (*it).second.id);
    }
#endif
    repaint();

    return TRUE;
}

int VSCSimpleTl::GetTimeLineInSec()
{
    int length = 300;
     switch (m_TimelineLength)
     {
        case TIMELINE_LEN_1_MIN:    
            length = 60;
            break;
        case TIMELINE_LEN_5_MIN:   
            length = 60 * 5;
            break; 
        case TIMELINE_LEN_30_MIN:   
            length = 60 * 30;
            break; 
        case TIMELINE_LEN_2_HOUR:   
            length = 2 * 60 * 60;
            break; 
        case TIMELINE_LEN_1_DAY:   
            length = 24 * 60 * 60;
            break;  
        case TIMELINE_LEN_7_DAY:   
            length = 7 * 24 * 60 * 60;
            break;  
        case TIMELINE_LEN_14_DAY:   
            length = 14 * 24 * 60 * 60;
            break;                
        default:
            break;
     }

     return length;
}

std::string VSCSimpleTl::GetTimeLineTimeString(int time)
{
    time_t     now = time;
    struct tm  tstruct;
    char       buf[512];
    tstruct = *localtime(&now);
  
     switch (m_TimelineLength)
     {
        case TIMELINE_LEN_1_MIN:
        case TIMELINE_LEN_5_MIN:
            strftime(buf, sizeof(buf), "%X", &tstruct);
            break;
        case TIMELINE_LEN_30_MIN:   
        case TIMELINE_LEN_2_HOUR:   
            strftime(buf, sizeof(buf), "%m-%d %H:%M", &tstruct);
            break; 
        case TIMELINE_LEN_1_DAY:   
        case TIMELINE_LEN_7_DAY:   
        case TIMELINE_LEN_14_DAY:   
            strftime(buf, sizeof(buf), "%m-%d %H", &tstruct);
            break;                
        default:
            break;
     }

     return buf;
}

BOOL VSCSimpleTl::GetTimeLineMap(int w, TimeLineMap &map)
{
    int num = 0;
    int step = 0;
    char buff[128];
    int i = 0;
    int j = 0;
    int point  = 0;
    int pointStart = 0;
    
     switch (m_TimelineLength)
     {
        case TIMELINE_LEN_1_MIN:    
            num = 6;//every 10s
            step = 10;
            break;
        case TIMELINE_LEN_5_MIN:   
            num = 10;//every 30s
            step = 30;
            break; 
        case TIMELINE_LEN_30_MIN:
            num = 6;//ervery 5 min
            step = 5 * 60;
            break; 
        case TIMELINE_LEN_2_HOUR:   
            num = 4;//every 30 min
            step = 30 * 60;
            break; 
        case TIMELINE_LEN_1_DAY:
            num = 6;//every 4 hour
            step =  60 * 60 * 4;
            break;  
        case TIMELINE_LEN_7_DAY:   
            num = 7;//every 24 hour
            step = 60 * 60 * 24;
            break;  
        case TIMELINE_LEN_14_DAY:   
            num = 7;//every 48 hour
            step = 60 * 60 * 48;
            break;                
        default:
            break;
     }
     int eachStep = w/num;
     int start = (startTime/step)* step + step;
     //VDC_DEBUG( "%s  (%d, %d), new start %d\n",__FUNCTION__, 
     //               startTime, endTime, start);
     
     pointStart = ((double)(start - startTime) /(double)step) * (double)eachStep;
     //VDC_DEBUG( "%s  pointStart %d\n",__FUNCTION__, pointStart);
     
     for (i = start, j = 0, point = pointStart; i < endTime; i = i + step,  j ++, 
        point = point + eachStep)
     {
 #if 0
         if (j%2 == 0)
         {
            map[point] = GetTimeLineTimeString(i);
         }else
         {
            map[point] =  "small";
         }
  #else
         map[point] = GetTimeLineTimeString(i);
  #endif
         //VDC_DEBUG( "%s  map (%d, %s)\n",__FUNCTION__,  point, map[point].c_str());
     }

     return TRUE;

     
}

void VSCSimpleTl::UpdateTime()
{
    SetStartTime(startTime + 1);
}

Q_INVOKABLE void VSCSimpleTl::SetStartTime(int sTime)
{
   startTime = sTime - diffDays/2;
    if (startTime < 0)
    {
    	startTime = 0;
    }
   endTime = sTime + diffDays/2;
   repaint();
}

static const std::string Time2StringTime(time_t nTime) {
    time_t     now = nTime;
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://www.cplusplus.com/reference/clibrary/ctime/strftime/
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%X", &tstruct);

    return buf;
}
static const std::string Time2StringDate(time_t nTime) {
    time_t     now = nTime;
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://www.cplusplus.com/reference/clibrary/ctime/strftime/
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%m-%d %X", &tstruct);

    return buf;
}

void VSCSimpleTl::paintEvent(QPaintEvent *event)
{
    const int mWidth = width();
    const int mHeight = height();
    //VDC_DEBUG( "%s mWidth %d mHeight %d\n",__FUNCTION__, mWidth, mHeight);
    if (m_Enabled == FALSE)
    {
        return ;
    }
    if (abs(mWidth - m_lastWidth) > 110)
    {
        if (mWidth < 600)
        {
            m_TimeLineMode = TIMELINE_MODE_SIMPLE;
        }else
        {
            m_TimeLineMode = TIMELINE_MODE_FULL;
        }
        m_lastWidth = mWidth;
    }
    emit TimeLineChange((int)m_TimeLineMode);
    char buff[128];
    QPainter painter(this);
    QFont font("sans");
    font.setPointSize(7);
    painter.setFont(font);
    astring strTime;
    TimeLineMap map;
    RecordItemMap itemMap;

    //VDC_DEBUG( "%s mWidth %d mHeight %d\n",__FUNCTION__, mWidth, mHeight);
    
    //painter.setRenderHint(QPainter::Antialiasing, true);


    /* --------------------- */
    painter.setPen(QPen(Qt::white, 3));
    painter.drawLine(0, mHeight - 13, mWidth, mHeight - 13);
    
    //painter.setPen(Qt::green);
    //painter.drawLine(20, mHeight - 13, 35, mHeight - 13);
    double widthInTime = mWidth/diffDays;
    double drawPoint;
	
    painter.setPen(QPen(Qt::white, 1));
    GetTimeLineMap(mWidth, map);
    TimeLineMap::iterator it = map.begin();
    for(; it!=map.end(); ++it)
    {
        if ((*it).second == "small")
        {
             painter.drawLine((int)(*it).first, 7, (int)(*it).first, mHeight/2);
        }else
        {
                 painter.drawLine((*it).first, 3, (*it).first , mHeight/2);
                 if (m_TimeLineMode == TIMELINE_MODE_FULL)
                 {
                      painter.drawText((int)(*it).first + 1, 9, (*it).second.c_str());
                 }            
        }
    }
    painter.setPen(QPen(Qt::red, 1));
    painter.drawLine(mWidth/2, mHeight/2 - 10, mWidth/2, mHeight/2 + 10);
    strTime = Time2StringDate(startTime + diffDays/2);
    sprintf(buff, "%s", strTime.c_str());
    painter.setPen(Qt::white);
    painter.drawText(mWidth/2, mHeight/2 + 10 , buff);

    GetDrawSearchItems(itemMap, mWidth, startTime, endTime);
    RecordItemMap::iterator it1 = itemMap.begin();
    /* Draw the record */
    painter.setPen(QPen(Qt::green, 3));
    for(; it1!=itemMap.end(); ++it1)
    {
       //VDC_DEBUG( "%s  id %d (%d, %d)\n",__FUNCTION__, 
       //           (*it1).first, (*it1).second.start, (*it1).second.end);
       painter.drawLine((*it1).second.start, mHeight - 13, (*it1).second.end, mHeight - 13);
       painter.drawLine((*it1).second.start, mHeight - 14, (*it1).second.end, mHeight - 14);
    }
		
    //painter.setPen(QColor(64,64,64));
    //painter.drawLine(20, mHeight - 40, 20, mHeight - 30);
    //painter.drawText(QRect(0, height()-30, 40, 30), Qt::AlignCenter, beginDate.toString(tr("MMM, d\nyyyy")));
	event->accept();
}

void VSCSimpleTl::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        moving = true;
        movingReference = startTime;
        dayLength = ((double)diffDays)/(width()-2);
        mouseX = event->x();
		//VDC_DEBUG( "%s mousePressEvent mouseX %d\n",__FUNCTION__, mouseX);
    }
    event->accept();
}

void VSCSimpleTl::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        moving = false;
    event->accept();
}

void VSCSimpleTl::mouseMoveEvent(QMouseEvent *event)
{
    if(!moving)
    {
        event->accept();
        return;
    }
    lastX = event->x();
    startTime = movingReference + (qRound(dayLength*(mouseX - lastX)));
    if (startTime < 0)
    {
    	startTime = 0;
    }
    endTime = startTime + diffDays;
    //emit periodChanged(beginDate, endDate);
    emit SeekToTime(startTime + diffDays/2);
    repaint();
}

