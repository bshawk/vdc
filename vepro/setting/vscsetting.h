#ifndef VSC_SETTING_H
#define VSC_SETTING_H

#include <QWidget>
#include "ui_vscsetting.h"
#include "utility.hpp"
#include "factory.hpp"
#include "vscvwidget.h"
#include "vsclicense.h"
#include "vscversion.h"
#include "vscrecorderconf.h"
#include "vscdevicelist.h"

#define VSC_SETTING_INDEX_SYSTEM 0
#define VSC_SETTING_INDEX_MEDIA 1
#define VSC_SETTING_INDEX_STORAGE 2

class VSCSetting : public QWidget
{
    Q_OBJECT

public:
    VSCSetting(QWidget *parent, VSCDeviceList &pDeviceList);
    ~VSCSetting();
public:
    void mouseDoubleClickEvent(QMouseEvent *e);
    void createContentMenu();
    void setupDefaultValue();
    void updateParamValue(QLineEdit *ld, s8 * pParam);
    void removeAll();
	
private slots:

    void radioButtonClicked();
    void applyConfig();
    void treeClicked(QTreeWidgetItem *item, int column);
signals:
    void RecorderTreeUpdated();

public:
    void SetupConnections();

	
public:
    Ui::VSCSetting ui;
private:
    QWidget *m_pParent;
    VSCLicense *m_License;
    VSCVersion *m_Version;
    VSCRecorderConf *m_RecorderConf;
    QVBoxLayout* m_Layout;
    VSCDeviceList &m_DeviceList;
};

#endif // VSC_SETTING_H
