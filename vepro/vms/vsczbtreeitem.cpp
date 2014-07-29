
#include "vsczbtreeitem.h"
#include "factory.hpp"
#include "QColor"

extern Factory *gFactory;

VSCZbTreeItemNVR::VSCZbTreeItemNVR(QTreeWidgetItem *parent)
    : QTreeWidgetItem(parent)
{

}

void VSCZbTreeItemNVR::mousePressEvent(QMouseEvent *event)
{
	//VDC_DEBUG( "%s \n",__FUNCTION__);
}

VSCZbTreeItemIPC::VSCZbTreeItemIPC(QTreeWidgetItem *parent)
    : QTreeWidgetItem(parent)
{

}

void VSCZbTreeItemIPC::mousePressEvent(QMouseEvent *event)
{
	//VDC_DEBUG( "%s \n",__FUNCTION__);
}



