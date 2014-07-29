#ifndef VSC_HDD_EDIT_H
#define VSC_HDD_EDIT_H

#include <QWidget>
#include "ui_vschddedit.h"
#include "utility.hpp"
#include <QTimer>
#include "hdddevice.hpp"
#include "vschddone.h"

#define VSC_SUPPORTED_DISKS 4

class VSCHddEdit : public QWidget
{
    Q_OBJECT

public:
    VSCHddEdit(QWidget *parent = 0);
    ~VSCHddEdit(){}
public:
    BOOL GetDiskPath(astring &strPath);
    s32 GetDiskSize();
public slots:   
  void masterDiskSelected(int id);  
  void applyConfig();
 
signals:
    void DiskTreeUpdated();
	
public:
    Ui::VSCHddEdit ui;
	
private:
    HddDevice m_Device;
    VSCHddOne *  m_Disks[VSC_SUPPORTED_DISKS];
    s32 m_TotalDisks;
    s32 m_SelectedDisk;

    
};

#endif // VSC_HDD_DEVICE_H
