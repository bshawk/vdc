
#include "vscdeviceipc.h"
#include "factory.hpp"
#include "QColor"

extern Factory *gFactory;

VSCDeviceIPC::VSCDeviceIPC(QTreeWidgetItem *parent, DeviceParam &pParam)
    : QTreeWidgetItem(parent)
{
	m_Param = pParam;
    UpdateOnline(FALSE);
	UpdateRecord(FALSE);
}

void VSCDeviceIPC::mousePressEvent(QMouseEvent *event)
{
	//VDC_DEBUG( "%s \n",__FUNCTION__);
}


void VSCDeviceIPC::UpdateOnline(BOOL bonline)
{
	if (bonline == TRUE)
	{
	    this->setTextColor(0, QColor(0, 170, 0));
	      //this->setTextColor(0, QColor(205, 0, 0));
	      //this->setTextColor(0, QColor(255, 0, 0));
	      //VDC_DEBUG( "%s Set to Green %d\n",__FUNCTION__, m_Param.m_Conf.data.conf.nId);
	}else
	{
	    this->setTextColor(0, QColor(194, 194, 194));
	      //VDC_DEBUG( "%s Set to black %d\n",__FUNCTION__, m_Param.m_Conf.data.conf.nId);
	}
}

void VSCDeviceIPC::UpdateRecord(BOOL bRecording)
{
            if (bRecording == TRUE)
            {
                QIcon icon1;
                //icon1.addFile(QStringLiteral(":/device/resources/camera-record.png"), QSize(), QIcon::Normal, QIcon::Off);
                icon1.addFile(QStringLiteral(":/device/resources/dome-record.png"), QSize(), QIcon::Normal, QIcon::Off);

                setIcon(0, icon1);
            }else
            {
                QIcon icon1;
                icon1.addFile(QStringLiteral(":/device/resources/dome.png"), QSize(), QIcon::Normal, QIcon::Off);
                setIcon(0, icon1);		
            }
}

VSCDeviceIPC::~VSCDeviceIPC()
{

}
