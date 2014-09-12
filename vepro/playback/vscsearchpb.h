#ifndef VSC_SEARCH_PB_H
#define VSC_SEARCH_PB_H

#include <QWidget>
#include "ui_vscsearchpb.h"
#include "utility.hpp"
#include "factory.hpp"
#include "vscvwidget.h"
#include "vsclicense.h"
#include "vscversion.h"
#include "vvideowrapper.hpp"
#include "vscdevicelist.h"
#include <QTableWidgetItem>

class VSCRecordItem : QTableWidgetItem 
{
public:
    VSCRecordItem(QWidget *parent, astring url, int startTime, int endTime);
    ~VSCRecordItem();
public:
	astring m_url;
	int m_startTime;
	int m_endTime;
};

class VSCSearchPb : public QWidget
{
    Q_OBJECT

public:
    VSCSearchPb(QWidget *parent);
    ~VSCSearchPb();
public:
    void mouseDoubleClickEvent(QMouseEvent *e);
    void createContentMenu();
    void setupDefaultValue();
    void updateParamValue(QLineEdit *ld, s8 * pParam);
    void removeAll();
	void dragEnterEvent(QDragEnterEvent *event);
	void dropEvent(QDropEvent *event);
	void fakeTest();
	
public slots:
	void PlaySelected(QTableWidgetItem * item );
	void SearchAction();

public:
    void SetupConnections();

	
public:
    Ui::VSCSearchPb ui;
private:
	VVideoWrapper *m_video;
    QWidget *m_pParent;
    QVBoxLayout* m_Layout;
};



#endif // VSC_SEARCH_PB_H
