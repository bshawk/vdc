
#include "vscdevicetree.h"
#include <QMimeData>
#include <QDrag>
#include "factory.hpp"
#include "vscdeviceipc.h"
#include <QPainter>
#include "vscdevicelist.h"
#include "vsczbtreeitem.h"

extern Factory *gFactory;


VSCDeviceTree::VSCDeviceTree(QWidget *parent)
    : QTreeWidget(parent)
{
    createActions();
}

void VSCDeviceTree::createActions()
{
	/*Ipc*/
    pActAddCamera = new QAction(tr("&New"), this);
    pActAddCamera->setIcon(QIcon(":/action/resources/new.png"));
    pActEditCamera = new QAction(tr("&Edit"), this);
    pActEditCamera->setIcon(QIcon(":/action/resources/edit.png"));
    pActDeleteCamera = new QAction(tr("&Delete"), this);
    pActDeleteCamera->setIcon(QIcon(":/action/resources/user-trash-2.png"));
    pActRecord= new QAction(tr("&Start Recording"), this);
    pActRecord->setIcon(QIcon(":/action/resources/recordstart.png"));
    pActStopRecord = new QAction(tr("&Stop Recording"), this);
    pActStopRecord->setIcon(QIcon(":/action/resources/recordstop.png"));

	/*disk*/
    pActDiskEdit = new QAction(tr("&Edit"), this);
    pActDiskEdit->setIcon(QIcon(":/action/resources/edit.png"));

    /* Site */
    pActEditSite = new QAction(tr("&Edit"), this);
    pActEditSite->setIcon(QIcon(":/action/resources/edit.png"));
    pActAddSite = new QAction(tr("&New"), this);
    pActAddSite->setIcon(QIcon(":/action/resources/new.png"));
    pActRefreshSite = new QAction(tr("&Refresh"), this);
    pActRefreshSite->setIcon(QIcon(":/action/resources/refresh.png"));
    pActDelSite = new QAction(tr("&Delete"), this);
    pActDelSite->setIcon(QIcon(":/action/resources/user-trash-2.png"));
	
	/*VSCZbIpc*/
	pActDelVSCZbIpc = new QAction(tr("&Delete"), this);//hjy
    pActDelVSCZbIpc->setIcon(QIcon(":/action/resources/user-trash-2.png"));
    pActRecordVSCZbIpc= new QAction(tr("&Start Recording"), this);
    pActRecordVSCZbIpc->setIcon(QIcon(":/action/resources/recordstart.png"));
    pActStopRecordVSCZbIpc = new QAction(tr("&Stop Recording"), this);
    pActStopRecordVSCZbIpc->setIcon(QIcon(":/action/resources/recordstop.png"));

    SetupConnections();
    pPopMenu = new QMenu(this);
    //pPopMenu->addAction(pActAddCamera);
    //pPopMenu->addAction(pActEditCamera);
    //pPopMenu->addAction(pActDeleteCamera);
}

void VSCDeviceTree::SetupConnections()
{
    connect(pActAddCamera, SIGNAL(triggered()), this, SLOT(CameraAddClick()));
    connect(pActEditCamera, SIGNAL(triggered()), this, SLOT(CameraEditClick()));
    connect(pActDeleteCamera, SIGNAL(triggered()), this, SLOT(CameraDeleteClick()));
    connect(pActRecord, SIGNAL(triggered()), this, SLOT(CameraRecordClick()));
    connect(pActStopRecord, SIGNAL(triggered()), this, SLOT(CameraStopRecordClick()));

    connect(pActDiskEdit, SIGNAL(triggered()), this, SIGNAL(DiskEditClicked()));

    connect(pActAddSite, SIGNAL(triggered()), this, SLOT(SiteAddClick()));
    connect(pActEditSite, SIGNAL(triggered()), this, SLOT(SiteEditClick()));
    connect(pActDelSite, SIGNAL(triggered()), this, SLOT(SiteDeleteClick()));
    connect(pActRefreshSite, SIGNAL(triggered()), this, SLOT(SiteRefreshClick()));

	connect(pActDelVSCZbIpc, SIGNAL(triggered()), this, SLOT(VSCZbIpcDeleteClick()));//
	connect(pActRecordVSCZbIpc, SIGNAL(triggered()), this, SLOT(VSCZbIpcRecordClick()));
	connect(pActStopRecordVSCZbIpc, SIGNAL(triggered()), this, SLOT(VSCZbIpcStopRecordClick()));
}

void VSCDeviceTree::contextMenuEvent(QContextMenuEvent * event)
{
    QTreeWidgetItem *item = NULL;
#if 0
    QPoint point = QCursor::pos();
    point = mapFromGlobal(point);
    item = this->itemAt(point);
    //pActAddCamera->setEnabled (false);
    //pActEditCamera->setEnabled (false);
    //pActDeleteCamera->setEnabled (false);
#endif
    item = currentItem();//获取当前被点击的节点
    pPopMenu->removeAction(pActAddCamera);
    pPopMenu->removeAction(pActEditCamera);
    pPopMenu->removeAction(pActDeleteCamera);
    pPopMenu->removeAction(pActRecord);
    pPopMenu->removeAction(pActStopRecord);

    pPopMenu->removeAction(pActDiskEdit);

    /* VMS */
    pPopMenu->removeAction(pActEditSite);
    pPopMenu->removeAction(pActAddSite);
    pPopMenu->removeAction(pActDelSite);
    pPopMenu->removeAction(pActRefreshSite);

	pPopMenu->removeAction(pActDelVSCZbIpc);
    pPopMenu->removeAction(pActRecordVSCZbIpc);
    pPopMenu->removeAction(pActStopRecordVSCZbIpc);

    if(item != NULL)
    {
        VSCDeviceIPC *pIpc = dynamic_cast<VSCDeviceIPC * >(item);
        if (pIpc)//指向IP camera里面的项
        {
            pPopMenu->addAction(pActEditCamera);
            pPopMenu->addAction(pActDeleteCamera);
            pPopMenu->addAction(pActRecord);
            pPopMenu->addAction(pActStopRecord);
        }

        VSCVmsZb *pVms = dynamic_cast<VSCVmsZb * >(item);
        if (pVms)//指向site
        {
            pPopMenu->addAction(pActRefreshSite);
            pPopMenu->addAction(pActEditSite);
			pPopMenu->addAction(pActDelSite);
        }

		VSCZbTreeItemIPC *pVSCZbIpc = dynamic_cast<VSCZbTreeItemIPC * >(item);
        if (pVSCZbIpc)//指向NUR的ipc
        {
            pPopMenu->addAction(pActDelVSCZbIpc);
            pPopMenu->addAction(pActRecordVSCZbIpc);
            pPopMenu->addAction(pActStopRecordVSCZbIpc);	
         }

        /* This is Top level Camera Item */
        if (item == topLevelItem(VSC_DEVICE_INDEX_IPC))
        {
            pPopMenu->addAction(pActAddCamera);
        }
        if (item == topLevelItem(VSC_DEVICE_INDEX_DSIK))
        {
            pPopMenu->addAction(pActDiskEdit);
        }
        if (item == topLevelItem(VSC_DEVICE_INDEX_SITE))
        {
            pPopMenu->addAction(pActAddSite);
        }
    }
    pPopMenu->exec(QCursor::pos());//菜单出现的位置为当前鼠标的位置
    event->accept();
}

void VSCDeviceTree::mousePressEvent(QMouseEvent *event)
{
	VDC_DEBUG( "%s \n",__FUNCTION__);
	// Get current selection
	QTreeWidgetItem *selectedItem = currentItem();
	
    if (event->buttons() & Qt::RightButton)
    {
        return;
    }
	// If the selected Item exists
	if (selectedItem)
	{
		VSCDeviceIPC *pIpc = dynamic_cast<VSCDeviceIPC * >(selectedItem);
	    //VSCDeviceIPC *pIpc = (VSCDeviceIPC * )(selectedItem);
        // Create data
		if (pIpc)
		{
		    u32 nId = pIpc->GetDeviceId();
		    VDC_DEBUG( "%s id %d\n",__FUNCTION__, nId);
			QMimeData *mimeData = new QMimeData();
			mimeData->setText(QString::number(nId));
			
			// Create drag
			QPixmap pixmap(":/device/resources/camera1.png");
			QPainter painter(&pixmap);

			QDrag *drag = new QDrag(this);
			drag->setMimeData(mimeData);
			drag->setPixmap(pixmap);
                      drag->setHotSpot(QPoint(drag->pixmap().width()/2,
                             drag->pixmap().height()/2));
			drag->exec();
			QTreeWidget::mousePressEvent(event);
			return ;
		}
		VSCZbTreeItemIPC *pSiteIpc = dynamic_cast<VSCZbTreeItemIPC * >(selectedItem);
	    //VSCDeviceIPC *pIpc = (VSCDeviceIPC * )(selectedItem);
        // Create data
		if (pSiteIpc)
		{
			VSCQMimeDataIPC *pMimeIpc = new VSCQMimeDataIPC();
			
			// Create drag
			QPixmap pixmap(":/device/resources/camera1.png");
			QPainter painter(&pixmap);

			QDrag *drag = new QDrag(this);
			drag->setMimeData(pMimeIpc);
			drag->setPixmap(pixmap);
                      drag->setHotSpot(QPoint(drag->pixmap().width()/2,
                             drag->pixmap().height()/2));
			drag->exec();
			QTreeWidget::mousePressEvent(event);
			return ;
		}

	}
	
	QTreeWidget::mousePressEvent(event);
}

void VSCDeviceTree::CameraAddClick()
{
    VDC_DEBUG( "%s \n",__FUNCTION__);
    emit CameraAddClicked();
    return;
}

void VSCDeviceTree::CameraEditClick()
{
    QTreeWidgetItem *item = NULL;
    item = currentItem();

    VDC_DEBUG( "%s \n",__FUNCTION__);
    if(item != NULL)
    {
        VSCDeviceIPC *pIpc = dynamic_cast<VSCDeviceIPC * >(item);
        if (pIpc)
        {
            VDC_DEBUG( "%s \n",__FUNCTION__);
            u32 nId = pIpc->GetDeviceId();
            emit CameraEditClicked(nId);
        }
    }

    return;
}

void VSCDeviceTree::CameraDeleteClick()
{
    QTreeWidgetItem *item = NULL;
    item = currentItem();

    VDC_DEBUG( "%s \n",__FUNCTION__);
    if(item != NULL)
    {
        VSCDeviceIPC *pIpc = dynamic_cast<VSCDeviceIPC * >(item);
        if (pIpc)
        {
            VDC_DEBUG( "%s \n",__FUNCTION__);
            u32 nId = pIpc->GetDeviceId();
            emit CameraDeleteClicked(nId);
        }
    }

    return;
}

void VSCDeviceTree::CameraRecordClick()
{
    QTreeWidgetItem *item = NULL;
    item = currentItem();

    VDC_DEBUG( "%s Record\n",__FUNCTION__);
    if(item != NULL)
    {
        VSCDeviceIPC *pIpc = dynamic_cast<VSCDeviceIPC * >(item);
        if (pIpc)
        {
            VDC_DEBUG( "%s Record\n",__FUNCTION__);
            u32 nId = pIpc->GetDeviceId();
            gFactory->StartRecord(nId);
        }
    }

    return;
}


void VSCDeviceTree::CameraStopRecordClick()
{
    QTreeWidgetItem *item = NULL;
    item = currentItem();

    VDC_DEBUG( "%s Stop Record\n",__FUNCTION__);
    if(item != NULL)
    {
        VSCDeviceIPC *pIpc = dynamic_cast<VSCDeviceIPC * >(item);
        if (pIpc)
        {
            VDC_DEBUG( "%s Stop Record\n",__FUNCTION__);
            u32 nId = pIpc->GetDeviceId();
            gFactory->StopRecord(nId);
        }
    }

    return;
}

void VSCDeviceTree::SiteAddClick()
{
    VDC_DEBUG( "%s \n",__FUNCTION__);
    emit SiteAddClicked();
    return;
}

void VSCDeviceTree::SiteEditClick()
{
    QTreeWidgetItem *item = NULL;
    item = currentItem();

    VDC_DEBUG( "%s \n",__FUNCTION__);
    if(item != NULL)
    {
        VSCVmsZb *pVms = dynamic_cast<VSCVmsZb * >(item);
        if (pVms)
        {
            VDC_DEBUG( "%s \n",__FUNCTION__);
            u32 nId = pVms->GetDeviceId();
            emit SiteEditClicked(nId);
        }
    }

    return;
}

void VSCDeviceTree::SiteDeleteClick()
{
    QTreeWidgetItem *item = NULL;
    item = currentItem();

    VDC_DEBUG( "%s \n",__FUNCTION__);
    if(item != NULL)
    {
        VSCVmsZb *pVms = dynamic_cast<VSCVmsZb * >(item);
        if (pVms)
        {
            VDC_DEBUG( "%s \n",__FUNCTION__);
            u32 nId = pVms->GetDeviceId();
            emit SiteDeleteClicked(nId);
        }
    }

    return;
}

void VSCDeviceTree::SiteRefreshClick()
{
    QTreeWidgetItem *item = NULL;
    item = currentItem();

    VDC_DEBUG( "%s \n",__FUNCTION__);
    if(item != NULL)
    {
        VSCVmsZb *pVms = dynamic_cast<VSCVmsZb * >(item);
        if (pVms)
        {
            VDC_DEBUG( "%s \n",__FUNCTION__);
            pVms->Refresh();
        }
    }

    return;
}


void VSCDeviceTree::VSCZbIpcDeleteClick()
{
	QTreeWidgetItem* child = currentItem();
	QTreeWidgetItem* parent = currentItem()->parent();
	VSCZbTreeItemIPC *pVSCZbIpc = dynamic_cast<VSCZbTreeItemIPC * >(child);
	u32 nId = pVSCZbIpc->GetDeviceId();
	pVSCZbIpc->DeleteTreeItemIPC();
	if(parent) 
	{
		parent->removeChild(child);
	}
	emit VSCZbIpcDeleteClicked(nId);

    return;
}

void VSCDeviceTree::VSCZbIpcRecordClick()//nur的IPC的startrecordclick
{
	QTreeWidgetItem *item = NULL;
    item = currentItem();

    VDC_DEBUG( "%s \n",__FUNCTION__);
    if(item != NULL)
    {
        VSCZbTreeItemIPC *pVSCZbIpc = dynamic_cast<VSCZbTreeItemIPC * >(item);
        if (pVSCZbIpc)
        {
            VDC_DEBUG( "%s \n",__FUNCTION__);
            u32 nId = pVSCZbIpc->GetDeviceId();
			//qDebug() << QString("hahahaa2: %1").arg(pVSCZbIpc->GetDeviceId());
			gFactory->StartRecord(nId);
			//TODO  VSCZbIPCRecord()?
			//if(pVSCZbIpc->GetDeviceParam().m_Conf.data.conf.Recording==1)
				pVSCZbIpc->VSCZbIPCUpdateRecord(true);
        }
    }

	return;
}

void VSCDeviceTree::VSCZbIpcStopRecordClick()
{
	QTreeWidgetItem *item = NULL;
    item = currentItem();

    VDC_DEBUG( "%s \n",__FUNCTION__);
    if(item != NULL)
    {
        VSCZbTreeItemIPC *pVSCZbIpc = dynamic_cast<VSCZbTreeItemIPC * >(item);
        if (pVSCZbIpc)
        {
            VDC_DEBUG( "%s \n",__FUNCTION__);
            u32 nId = pVSCZbIpc->GetDeviceId();
            gFactory->StartRecord(nId);
			//TODO VSCZbIPCRecord()?
			//if(pVSCZbIpc->GetDeviceParam().m_Conf.data.conf.Recording==0)
				pVSCZbIpc->VSCZbIPCUpdateRecord(false);
        }
		
    }
	
    return;
}
