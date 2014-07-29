

#ifndef VSCDEVICE_TREE_H
#define VSCDEVICE_TREE_H

#include <QWidget>
#include <QTreeWidget>
#include <QAction>
#include <QMenu>
#include <QContextMenuEvent>

#include "factory.hpp"
#include "vscvms.h"

class VSCDeviceTree : public QTreeWidget
{
    Q_OBJECT
public:
    VSCDeviceTree(QWidget *parent = 0);
public:
	void mousePressEvent(QMouseEvent *event);
	void contextMenuEvent(QContextMenuEvent * event);
	void createActions();
	void SetupConnections();

public slots:
    void CameraAddClick();
    void CameraEditClick();
    void CameraDeleteClick();
    void CameraRecordClick();
    void CameraStopRecordClick();
	
    void SiteAddClick();
    void SiteEditClick();
    void SiteDeleteClick();
    void SiteRefreshClick();

signals:
    void CameraAddClicked();
    void CameraEditClicked(int nId);
    void CameraDeleteClicked(int nId);
    void SiteAddClicked();
    void SiteEditClicked(int nId);
    void SiteDeleteClicked(int nId);
    void DiskEditClicked();

private:
	QAction *pActDeleteCamera;
	QAction *pActAddCamera;
	QAction *pActEditCamera;
	QAction *pActRecord;
	QAction *pActStopRecord;
	QAction *pActDiskEdit;
	
	QAction *pActEditSite;
	QAction *pActAddSite;
	QAction *pActRefreshSite;
	QAction *pActDelSite;
	
	QMenu *pPopMenu;
	
    //~VSCDeviceTree();

};

#endif // VSCDEVICE_TREE_H