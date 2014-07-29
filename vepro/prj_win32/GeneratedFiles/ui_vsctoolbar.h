/********************************************************************************
** Form generated from reading UI file 'vsctoolbar.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VSCTOOLBAR_H
#define UI_VSCTOOLBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VSCToolBar
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbSetting;
    QPushButton *pbAlarm;
    QSpacerItem *horizontalSpacer;
    QLabel *time;
    QPushButton *pbFullScreen;
    QPushButton *pbAbout;

    void setupUi(QWidget *VSCToolBar)
    {
        if (VSCToolBar->objectName().isEmpty())
            VSCToolBar->setObjectName(QStringLiteral("VSCToolBar"));
        VSCToolBar->resize(500, 29);
        VSCToolBar->setMaximumSize(QSize(100000, 60));
        QIcon icon;
        icon.addFile(QStringLiteral(":/logo/resources/vscsmall.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        VSCToolBar->setWindowIcon(icon);
        VSCToolBar->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(VSCToolBar);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(9);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pbSetting = new QPushButton(VSCToolBar);
        pbSetting->setObjectName(QStringLiteral("pbSetting"));
        pbSetting->setMinimumSize(QSize(27, 27));
        pbSetting->setMaximumSize(QSize(27, 27));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/action/resources/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbSetting->setIcon(icon1);
        pbSetting->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(pbSetting);

        pbAlarm = new QPushButton(VSCToolBar);
        pbAlarm->setObjectName(QStringLiteral("pbAlarm"));
        pbAlarm->setEnabled(true);
        pbAlarm->setMinimumSize(QSize(25, 25));
        pbAlarm->setMaximumSize(QSize(25, 25));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/action/resources/alarm.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pbAlarm->setIcon(icon2);
        pbAlarm->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(pbAlarm);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        time = new QLabel(VSCToolBar);
        time->setObjectName(QStringLiteral("time"));

        horizontalLayout->addWidget(time);

        pbFullScreen = new QPushButton(VSCToolBar);
        pbFullScreen->setObjectName(QStringLiteral("pbFullScreen"));
        pbFullScreen->setMinimumSize(QSize(25, 25));
        pbFullScreen->setMaximumSize(QSize(25, 25));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/action/resources/view-fullscreen.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbFullScreen->setIcon(icon3);
        pbFullScreen->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(pbFullScreen);

        pbAbout = new QPushButton(VSCToolBar);
        pbAbout->setObjectName(QStringLiteral("pbAbout"));
        pbAbout->setMinimumSize(QSize(25, 25));
        pbAbout->setMaximumSize(QSize(25, 25));
        pbAbout->setIcon(icon);
        pbAbout->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(pbAbout);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(VSCToolBar);

        QMetaObject::connectSlotsByName(VSCToolBar);
    } // setupUi

    void retranslateUi(QWidget *VSCToolBar)
    {
        VSCToolBar->setWindowTitle(QApplication::translate("VSCToolBar", "VSC", 0));
#ifndef QT_NO_TOOLTIP
        pbSetting->setToolTip(QApplication::translate("VSCToolBar", "<html><head/><body><p>TODO next version</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pbSetting->setText(QString());
#ifndef QT_NO_TOOLTIP
        pbAlarm->setToolTip(QApplication::translate("VSCToolBar", "<html><head/><body><p>TODO next version </p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pbAlarm->setText(QString());
        time->setText(QApplication::translate("VSCToolBar", "2014-03-08 14:11:00", 0));
#ifndef QT_NO_TOOLTIP
        pbFullScreen->setToolTip(QApplication::translate("VSCToolBar", "<html><head/><body><p>FullScreen</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pbFullScreen->setText(QString());
#ifndef QT_NO_TOOLTIP
        pbAbout->setToolTip(QApplication::translate("VSCToolBar", "<html><head/><body><p>About</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pbAbout->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VSCToolBar: public Ui_VSCToolBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VSCTOOLBAR_H
