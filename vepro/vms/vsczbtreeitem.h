#ifndef __VSC_ZB_TREE_ITEM_H__
#define __VSC_ZB_TREE_ITEM_H__

#include <QWidget>
#include <QTimer>
#include <QTreeWidgetItem>
#include "factory.hpp"

class VSCZbTreeItemNVR : public QTreeWidgetItem
{
public:
	void mousePressEvent(QMouseEvent *event);
	void DeleteIPC(){}//TODO
public:
    VSCZbTreeItemNVR(QTreeWidgetItem *parent);
    ~VSCZbTreeItemNVR(){}

};

class VSCZbTreeItemIPC : public QTreeWidgetItem
{
public:
	void mousePressEvent(QMouseEvent *event);

public:
    VSCZbTreeItemIPC(QTreeWidgetItem *parent);
    ~VSCZbTreeItemIPC(){}

};


#endif // __VSC_VMS_H__
