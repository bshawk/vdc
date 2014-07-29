#include "vschddedit.h"
#include "hdddevice.hpp"
#include "debug.hpp"
#include "vschddone.h"
#include "factory.hpp"

extern Factory *gFactory;

VSCHddEdit::VSCHddEdit(QWidget *parent)
    : QWidget(parent)
{
   m_SelectedDisk = 0;
   m_TotalDisks = 0;
   int i = 0;
   s8 DiskTitle[1024];
   ui.setupUi(this);
   QStringList hdd = m_Device.GetDeviceList();
   QString text;
   foreach( text, hdd)
   {
       if (i >= VSC_SUPPORTED_DISKS)
       {
          break;
       }
       astring strHdd = text.toStdString();
	VDC_DEBUG( "%s strHdd %s \n",__FUNCTION__, strHdd.c_str());
	s64 totalSize = m_Device.GetTotalDiskSpace(strHdd);
       s64 leftSize = m_Device.GetavailableDiskSpace(strHdd);
	VDC_DEBUG( "%s Total %lld G Left %lld G \n",__FUNCTION__, totalSize, leftSize);  
	VDC_DEBUG( "%s Type %d \n",__FUNCTION__,  m_Device.GetHddType(strHdd));
	if (m_Device.GetHddType(strHdd) == HddInternalDrive)
	{
	    /* Add to UI */
           m_Disks[i] = new VSCHddOne(true, i, strHdd, totalSize, 
                                     leftSize, this);
           ui.verticalLayout->addWidget(m_Disks[i] );
           if (i == 0)
           {
               m_Disks[i]->diskSetChecked(true);
           }
           m_TotalDisks ++;
           connect(m_Disks[i], SIGNAL(diskSelectedUpdated(int)), this, SLOT(masterDiskSelected(int)));  
           i ++;
  #if 0
	    sprintf(DiskTitle, "%s Disk 01 Total %lldG Left %lldG", strHdd.c_str(), 
	                                     totalSize, leftSize);
	    ui.label->setText(DiskTitle);
	    QLabel* w1 = new QLabel("a");
           //w1->setStyleSheet("QLabel { background-color : green; color : blue; }");
           QSizePolicy policy1 = w1->sizePolicy();
           policy1.setHorizontalStretch(1);
           w1->setSizePolicy(policy1);
		   
           QLabel* w2 = new QLabel("b");
           //w2->setStyleSheet("QLabel { background-color : white; color : black; }");
           QSizePolicy policy2 = w2->sizePolicy();
           policy2.setHorizontalStretch(1);
           w2->setSizePolicy(policy2);
           //layout->setSpacing(0);
           //ui.horizontalLayout_6->addWidget(w1);
           //ui.horizontalLayout_6->addWidget(w2);
      #endif
           
	}
   }

   connect( this->ui.applyButton, SIGNAL( clicked() ), this, SLOT(applyConfig()));
}

void VSCHddEdit::masterDiskSelected(int id)
{
    for (int i = 0; i <m_TotalDisks; i ++ )
    {
        m_Disks[i]->diskSetChecked(false);
    }
    m_Disks[id]->diskSetChecked(true);
    m_SelectedDisk = id;
}

BOOL VSCHddEdit::GetDiskPath(astring &strPath)
{
    m_Disks[m_SelectedDisk]->getStrHdd(strPath);
    return TRUE;
}
s32 VSCHddEdit::GetDiskSize()
{
    s64 diskSize = 0;
    m_Disks[m_SelectedDisk]->getNewUsed(diskSize);
    
    s32 size = diskSize / 1024;

    return size;
}


void VSCHddEdit::applyConfig()
{
	bool bUpdate = false;
	for (int i = 0; i < m_TotalDisks; i ++)
	{
		if (m_Disks[i]->isChecked() == false)
		{
			continue;
		}
#ifdef WIN32
	       astring strPath = "C:\\";
#else
		astring strPath = "ve/";//TODO get the hdd from hdd
#endif
		s64 size = 1;
	       m_Disks[i]->getNewUsed(size);
		size = size / 1024;
	       m_Disks[i]->getStrHdd(strPath);
		gFactory->AddHDD(strPath, size);
		bUpdate = true;
	}
	if (bUpdate == true)
	{
		emit DiskTreeUpdated();
	}

	return;

}


