/********************************************************************************
** Form generated from reading UI file 'vscdevicelist.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VSCDEVICELIST_H
#define UI_VSCDEVICELIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "vscdevicetrash.h"
#include "vscdevicetree.h"

QT_BEGIN_NAMESPACE

class Ui_VSCDeviceList
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pbSite;
    QPushButton *pbRecorder;
    QPushButton *pbCamera;
    QPushButton *pbSurveillance;
    QPushButton *pbSearch;
    QPushButton *pbPlayback;
    VSCDeviceTrash *pbTrash;
    QSpacerItem *verticalSpacer;
    VSCDeviceTree *treeWidget;

    void setupUi(QWidget *VSCDeviceList)
    {
        if (VSCDeviceList->objectName().isEmpty())
            VSCDeviceList->setObjectName(QStringLiteral("VSCDeviceList"));
        VSCDeviceList->resize(280, 584);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VSCDeviceList->sizePolicy().hasHeightForWidth());
        VSCDeviceList->setSizePolicy(sizePolicy);
        VSCDeviceList->setMinimumSize(QSize(280, 0));
        VSCDeviceList->setMaximumSize(QSize(400, 16777215));
        VSCDeviceList->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(VSCDeviceList);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pbSite = new QPushButton(VSCDeviceList);
        pbSite->setObjectName(QStringLiteral("pbSite"));
        pbSite->setMinimumSize(QSize(40, 40));
        pbSite->setMaximumSize(QSize(40, 40));
        QIcon icon;
        icon.addFile(QStringLiteral(":/action/resources/site.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbSite->setIcon(icon);
        pbSite->setIconSize(QSize(40, 40));

        verticalLayout->addWidget(pbSite);

        pbRecorder = new QPushButton(VSCDeviceList);
        pbRecorder->setObjectName(QStringLiteral("pbRecorder"));
        pbRecorder->setMinimumSize(QSize(40, 40));
        pbRecorder->setMaximumSize(QSize(40, 40));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/device/resources/computer.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbRecorder->setIcon(icon1);
        pbRecorder->setIconSize(QSize(36, 36));

        verticalLayout->addWidget(pbRecorder);

        pbCamera = new QPushButton(VSCDeviceList);
        pbCamera->setObjectName(QStringLiteral("pbCamera"));
        pbCamera->setMinimumSize(QSize(40, 40));
        pbCamera->setMaximumSize(QSize(40, 40));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/device/resources/camera.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbCamera->setIcon(icon2);
        pbCamera->setIconSize(QSize(40, 40));

        verticalLayout->addWidget(pbCamera);

        pbSurveillance = new QPushButton(VSCDeviceList);
        pbSurveillance->setObjectName(QStringLiteral("pbSurveillance"));
        pbSurveillance->setMinimumSize(QSize(40, 40));
        pbSurveillance->setMaximumSize(QSize(40, 40));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/action/resources/surveillance.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbSurveillance->setIcon(icon3);
        pbSurveillance->setIconSize(QSize(40, 40));

        verticalLayout->addWidget(pbSurveillance);

        pbSearch = new QPushButton(VSCDeviceList);
        pbSearch->setObjectName(QStringLiteral("pbSearch"));
        pbSearch->setMinimumSize(QSize(40, 40));
        pbSearch->setMaximumSize(QSize(40, 40));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/action/resources/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbSearch->setIcon(icon4);
        pbSearch->setIconSize(QSize(36, 36));

        verticalLayout->addWidget(pbSearch);

        pbPlayback = new QPushButton(VSCDeviceList);
        pbPlayback->setObjectName(QStringLiteral("pbPlayback"));
        pbPlayback->setMinimumSize(QSize(40, 40));
        pbPlayback->setMaximumSize(QSize(40, 40));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/action/resources/videosearch.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbPlayback->setIcon(icon5);
        pbPlayback->setIconSize(QSize(40, 40));

        verticalLayout->addWidget(pbPlayback);

        pbTrash = new VSCDeviceTrash(VSCDeviceList);
        pbTrash->setObjectName(QStringLiteral("pbTrash"));
        pbTrash->setMinimumSize(QSize(40, 40));
        pbTrash->setMaximumSize(QSize(40, 40));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/action/resources/user-trash-2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbTrash->setIcon(icon6);
        pbTrash->setIconSize(QSize(40, 40));

        verticalLayout->addWidget(pbTrash);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        treeWidget = new VSCDeviceTree(VSCDeviceList);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/device/resources/view.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/device/resources/harddisk.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem->setIcon(0, icon);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsTristate);
        __qtreewidgetitem1->setIcon(0, icon1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem2->setIcon(0, icon2);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem3->setIcon(0, icon7);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem4->setIcon(0, icon8);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setIconSize(QSize(20, 20));
        treeWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
        treeWidget->setIndentation(30);
        treeWidget->setRootIsDecorated(true);
        treeWidget->setUniformRowHeights(false);
        treeWidget->setItemsExpandable(true);
        treeWidget->setAnimated(true);
        treeWidget->setWordWrap(false);
        treeWidget->setHeaderHidden(true);
        treeWidget->setExpandsOnDoubleClick(true);
        treeWidget->setColumnCount(1);
        treeWidget->header()->setCascadingSectionResizes(true);
        treeWidget->header()->setProperty("showSortIndicator", QVariant(true));

        horizontalLayout->addWidget(treeWidget);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(VSCDeviceList);

        QMetaObject::connectSlotsByName(VSCDeviceList);
    } // setupUi

    void retranslateUi(QWidget *VSCDeviceList)
    {
        VSCDeviceList->setWindowTitle(QString());
        pbSite->setText(QString());
        pbRecorder->setText(QString());
#ifndef QT_NO_TOOLTIP
        pbCamera->setToolTip(QApplication::translate("VSCDeviceList", "Add IP Camera", 0));
#endif // QT_NO_TOOLTIP
        pbCamera->setText(QString());
#ifndef QT_NO_TOOLTIP
        pbSurveillance->setToolTip(QApplication::translate("VSCDeviceList", "Add View", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pbSurveillance->setStatusTip(QApplication::translate("VSCDeviceList", "2", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pbSurveillance->setWhatsThis(QApplication::translate("VSCDeviceList", "3", 0));
#endif // QT_NO_WHATSTHIS
        pbSurveillance->setText(QString());
#ifndef QT_NO_TOOLTIP
        pbSearch->setToolTip(QApplication::translate("VSCDeviceList", "Search IP Camera", 0));
#endif // QT_NO_TOOLTIP
        pbSearch->setText(QString());
#ifndef QT_NO_TOOLTIP
        pbPlayback->setToolTip(QApplication::translate("VSCDeviceList", "Playback ", 0));
#endif // QT_NO_TOOLTIP
        pbPlayback->setText(QString());
#ifndef QT_NO_TOOLTIP
        pbTrash->setToolTip(QApplication::translate("VSCDeviceList", "Drop IP Camera to Here", 0));
#endif // QT_NO_TOOLTIP
        pbTrash->setText(QString());
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("VSCDeviceList", "VS Cloud", 0));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("VSCDeviceList", "Sites", 0));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QApplication::translate("VSCDeviceList", "Recorders", 0));
        QTreeWidgetItem *___qtreewidgetitem3 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem3->setText(0, QApplication::translate("VSCDeviceList", "IP Cameras", 0));
        QTreeWidgetItem *___qtreewidgetitem4 = treeWidget->topLevelItem(3);
        ___qtreewidgetitem4->setText(0, QApplication::translate("VSCDeviceList", "Views", 0));
        QTreeWidgetItem *___qtreewidgetitem5 = treeWidget->topLevelItem(4);
        ___qtreewidgetitem5->setText(0, QApplication::translate("VSCDeviceList", "Disks", 0));
        treeWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class VSCDeviceList: public Ui_VSCDeviceList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VSCDEVICELIST_H
