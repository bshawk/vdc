#ifndef __VSC_VMS_H__
#define __VSC_VMS_H__

#include <QWidget>
#include <QTimer>
#include <QTreeWidgetItem>
#include "factory.hpp"
#include "vscrecorder.h"
#include <QObject>

class VSCVms : public QObject , public QTreeWidgetItem //��̳У�qobject�����ڼ̳е���ĵ�һ��
{
	Q_OBJECT;

public:
	void mousePressEvent(QMouseEvent *event);

public:
    VSCVms(QTreeWidgetItem *parent, VSCVmsDataItem &pParam);
    ~VSCVms();
	
public:
	u32 GetDeviceId()
	{
	    return m_Param.nId;
	}
	virtual BOOL GetRecorderMap(RecorderMap & pMap){return FALSE;}
	virtual BOOL Refresh(){return FALSE;}


private:
	VSCVmsDataItem m_Param;
	QTreeWidgetItem *m_pParent;

};

class VSCVmsPg : public VSCVms
{
public:
	void mousePressEvent(QMouseEvent *event);

public:
    VSCVmsPg(QTreeWidgetItem *parent, VSCVmsDataItem &pParam);
    ~VSCVmsPg();
public:
	virtual BOOL Refresh(){return FALSE;}


private:

};

class VSCVmsZb : public VSCVms
{
public:
	void mousePressEvent(QMouseEvent *event);

public:
    VSCVmsZb(QTreeWidgetItem *parent, VSCVmsDataItem &pParam);
    ~VSCVmsZb();
public:
	/* Reconnect site to refresh the data */
	virtual BOOL Refresh();
	virtual BOOL GetRecorderMap(RecorderMap & pMap);
	void printIPCList(const QJsonObject& json);//
	void printNVRList(const QJsonObject& json);//	

private:
	BOOL VSCVmsZb::ShowRefresh();
	RecorderMap mMap;
	QString mIp;
};

#endif // __VSC_VMS_H__
