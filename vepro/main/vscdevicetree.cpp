
#include "vscdevicetree.h"
#include <QMimeData>
#include <QDrag>
#include "factory.hpp"
#include "vscdeviceipc.h"
#include <QPainter>
#include "vscdevicelist.h"

extern Factory *gFactory;


VSCDeviceTree::VSCDeviceTree(QWidget *parent)
    : QTreeWidget(parent)
{
    createActions();
}

void VSCDeviceTree::createActions()
{
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
    item = currentItem();
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
    if(item != NULL)
    {
        VSCDeviceIPC *pIpc = dynamic_cast<VSCDeviceIPC * >(item);
        if (pIpc)
        {
            pPopMenu->addAction(pActEditCamera);
            pPopMenu->addAction(pActDeleteCamera);
            pPopMenu->addAction(pActRecord);
            pPopMenu->addAction(pActStopRecord);
        }
        VSCVmsZb *pVms = dynamic_cast<VSCVmsZb * >(item);
        if (pVms)
        {
            pPopMenu->addAction(pActRefreshSite);
            pPopMenu->addAction(pActEditSite);
	     pPopMenu->addAction(pActDelSite);
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


