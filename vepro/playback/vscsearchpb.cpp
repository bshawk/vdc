#include "vscsearchpb.h"
#include "vscvwidget.h"
#include "vsczbtreeitem.h"
#include "QMimeData"
#include <QDrag>

static std::string PbSearchTime2String(time_t nTime) {
    time_t     now = nTime;
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://www.cplusplus.com/reference/clibrary/ctime/strftime/
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%X", &tstruct);

    return buf;
}



extern Factory *gFactory;

VSCRecordItem::VSCRecordItem(QWidget *parent, astring url, int startTime, int endTime)
:m_url(url), m_startTime(startTime), m_endTime(endTime)
{
	std::string strText = PbSearchTime2String(startTime) + " ---> " + PbSearchTime2String(endTime);
	setFlags(this->flags() ^ Qt::ItemIsEditable);
	setText(strText.c_str());
}

VSCRecordItem::~VSCRecordItem()
{
}


VSCSearchPb::VSCSearchPb(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	SetupConnections();
	m_Layout = new QVBoxLayout();
	
	m_Layout->setMargin(0);
	m_video = VVideoWrapper::CreateObject(this);
	m_Layout->addWidget(m_video);
	ui.videowidget->setLayout(m_Layout);
	
	ui.tableWidget->setColumnWidth(0, 220);
	this->setAcceptDrops(true);
}

VSCSearchPb::~VSCSearchPb()
{
	delete m_Layout;
}

void VSCSearchPb::SearchAction()
{
	fakeTest();
}

void VSCSearchPb::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
    QWidget::dragEnterEvent(event);
}
void VSCSearchPb::dropEvent(QDropEvent *event)
{
		QMimeData * pMime = (QMimeData *)event->mimeData();
        VSCQMimeDataIPC *myData =
             dynamic_cast<VSCQMimeDataIPC * > (pMime);
     if (myData) 
	 {
		//Get the data of the IPC and belongs NVR, then call the search api to search the current day
		fakeTest();
         
     }
}

void VSCSearchPb::fakeTest()
{
	ui.tableWidget->setRowCount(0);//delete all the item
	
	QDate currentDate = QDate::currentDate();//Get the date
	ui.date->setDate(currentDate);
	
	QDate getDate = ui.date->date();
	
	int year;
	int month;
	int day;
	getDate.getDate(&year, &month, &day);
	
	int i = 100;
	while (i-- > 0){
		//Add one record
		{
			int insertRow = ui.tableWidget->rowCount();
			ui.tableWidget->insertRow(insertRow);
			VSCRecordItem *pitem = new VSCRecordItem(this, "rtsp://admin:admin@192.168.1.11:554/Streaming/Channels/1?transportmode=unicast&profile=Profile_1", i, i+1);
			ui.tableWidget->setItem(insertRow, 0, (QTableWidgetItem *)pitem);
				//use rtsp url replace the file path
		}
		//Add two record
		{
			int insertRow = ui.tableWidget->rowCount();
			ui.tableWidget->insertRow(insertRow);
			VSCRecordItem *pitem = new VSCRecordItem(this, "rtsp://admin:admin@192.168.1.11:554/Streaming/Channels/1?transportmode=unicast&profile=Profile_1", i, i+1);
			ui.tableWidget->setItem(insertRow, 0, (QTableWidgetItem *)pitem);
			//use rtsp url replace the file path
		}
	}
	
}

void VSCSearchPb::PlaySelected(QTableWidgetItem * item)
{
	//VSCRecordItem *pItem = dynamic_cast<VSCRecordItem * >(item);
	VSCRecordItem *pItem = (VSCRecordItem * )(item);
	if (pItem)
	{
		m_video->Play(pItem->m_url, pItem->m_startTime, pItem->m_endTime);
	}
}

void VSCSearchPb::SetupConnections()
{
	connect(ui.tableWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem *)), 
				this, SLOT(PlaySelected(QTableWidgetItem *)));
	connect(ui.search, SIGNAL(clicked()), this, SLOT(SearchAction()));
}


void VSCSearchPb::setupDefaultValue()
{
}

void VSCSearchPb::updateParamValue(QLineEdit *ld, s8 * pParam)
{
}

void VSCSearchPb::mouseDoubleClickEvent(QMouseEvent *e)
{

}

void VSCSearchPb::createContentMenu()
{

}

