/********************************************************************************
** Form generated from reading UI file 'vscvwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VSCVWIDGET_H
#define UI_VSCVWIDGET_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "videowidget.h"
#include "vscsimpletl.h"

QT_BEGIN_NAMESPACE

class Ui_VSCVWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *labelName;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelRecording;
    VideoWidget *video;
    QWidget *videoControl;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *timelineZoom;
    VSCSimpleTl *widgetTimeline;
    QPushButton *pbPause;
    QPushButton *pbPlay;
    QPushButton *pbInstantpb;
    QPushButton *pbRecord;

    void setupUi(QWidget *VSCVWidget)
    {
        if (VSCVWidget->objectName().isEmpty())
            VSCVWidget->setObjectName(QStringLiteral("VSCVWidget"));
        VSCVWidget->resize(623, 358);
        VSCVWidget->setStyleSheet(QStringLiteral("background-color: rgb( 100,100,100);"));
        verticalLayout_2 = new QVBoxLayout(VSCVWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(VSCVWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setContextMenuPolicy(Qt::DefaultContextMenu);
        widget_3->setAutoFillBackground(false);
        widget_3->setStyleSheet(QStringLiteral("background-color: rgb( 100,100,100);"));
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        widget = new QWidget(widget_3);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 20));
        widget->setMaximumSize(QSize(16777215, 20));
        widget->setStyleSheet(QStringLiteral("background-color:rgb(0, 0, 0)"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        labelName = new QLabel(widget);
        labelName->setObjectName(QStringLiteral("labelName"));
        labelName->setStyleSheet(QLatin1String("color : rgb(247, 247, 247);\n"
"font: 8pt \"Arial\";"));

        horizontalLayout->addWidget(labelName);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        labelRecording = new QLabel(widget);
        labelRecording->setObjectName(QStringLiteral("labelRecording"));
        labelRecording->setStyleSheet(QLatin1String("color : red;\n"
"font: 8pt \"Arial\";"));

        horizontalLayout->addWidget(labelRecording);


        verticalLayout->addWidget(widget);

        video = new VideoWidget(widget_3);
        video->setObjectName(QStringLiteral("video"));
        video->setAutoFillBackground(false);
        video->setStyleSheet(QStringLiteral("background-color:rgb(0, 0, 0)"));

        verticalLayout->addWidget(video);

        videoControl = new QWidget(widget_3);
        videoControl->setObjectName(QStringLiteral("videoControl"));
        videoControl->setMinimumSize(QSize(0, 25));
        videoControl->setMaximumSize(QSize(16777215, 25));
        videoControl->setStyleSheet(QStringLiteral("background-color:rgb(42, 43, 44)"));
        horizontalLayout_2 = new QHBoxLayout(videoControl);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        timelineZoom = new QComboBox(videoControl);
        timelineZoom->setObjectName(QStringLiteral("timelineZoom"));
        timelineZoom->setMinimumSize(QSize(75, 0));
        timelineZoom->setMaximumSize(QSize(75, 16777215));
        timelineZoom->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 10pt \"Arial\";"));

        horizontalLayout_2->addWidget(timelineZoom);

        widgetTimeline = new VSCSimpleTl(videoControl);
        widgetTimeline->setObjectName(QStringLiteral("widgetTimeline"));
        widgetTimeline->setMinimumSize(QSize(0, 0));

        horizontalLayout_2->addWidget(widgetTimeline);

        pbPause = new QPushButton(videoControl);
        pbPause->setObjectName(QStringLiteral("pbPause"));
        pbPause->setMinimumSize(QSize(19, 19));
        pbPause->setMaximumSize(QSize(19, 19));
        QIcon icon;
        icon.addFile(QStringLiteral(":/pb/resources/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbPause->setIcon(icon);
        pbPause->setIconSize(QSize(17, 17));

        horizontalLayout_2->addWidget(pbPause);

        pbPlay = new QPushButton(videoControl);
        pbPlay->setObjectName(QStringLiteral("pbPlay"));
        pbPlay->setMinimumSize(QSize(19, 19));
        pbPlay->setMaximumSize(QSize(19, 19));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/pb/resources/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbPlay->setIcon(icon1);
        pbPlay->setIconSize(QSize(17, 17));

        horizontalLayout_2->addWidget(pbPlay);

        pbInstantpb = new QPushButton(videoControl);
        pbInstantpb->setObjectName(QStringLiteral("pbInstantpb"));
        pbInstantpb->setMinimumSize(QSize(25, 19));
        pbInstantpb->setMaximumSize(QSize(25, 19));
        pbInstantpb->setLayoutDirection(Qt::RightToLeft);
        pbInstantpb->setStyleSheet(QLatin1String("background-color:rgb(80, 80, 80);\n"
"color : rgb(247, 247, 247);\n"
"font: 75 6pt \"Arial\";"));
        pbInstantpb->setLocale(QLocale(QLocale::Colognian, QLocale::Germany));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/pb/resources/instantpb.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pbInstantpb->setIcon(icon2);
        pbInstantpb->setIconSize(QSize(25, 19));

        horizontalLayout_2->addWidget(pbInstantpb);

        pbRecord = new QPushButton(videoControl);
        pbRecord->setObjectName(QStringLiteral("pbRecord"));
        pbRecord->setMinimumSize(QSize(25, 19));
        pbRecord->setMaximumSize(QSize(25, 19));
        pbRecord->setStyleSheet(QLatin1String("background-color:rgb(80, 80, 80);\n"
"color : rgb(247, 247, 247);\n"
"font: 75 6pt \"Arial\";"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/pb/resources/record.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pbRecord->setIcon(icon3);
        pbRecord->setIconSize(QSize(25, 19));

        horizontalLayout_2->addWidget(pbRecord);


        verticalLayout->addWidget(videoControl);

        widget->raise();
        videoControl->raise();
        video->raise();

        verticalLayout_2->addWidget(widget_3);


        retranslateUi(VSCVWidget);

        QMetaObject::connectSlotsByName(VSCVWidget);
    } // setupUi

    void retranslateUi(QWidget *VSCVWidget)
    {
        VSCVWidget->setWindowTitle(QApplication::translate("VSCVWidget", "Form", 0));
        labelName->setText(QString());
        labelRecording->setText(QString());
        timelineZoom->clear();
        timelineZoom->insertItems(0, QStringList()
         << QApplication::translate("VSCVWidget", "1   min", 0)
         << QApplication::translate("VSCVWidget", "5   min", 0)
         << QApplication::translate("VSCVWidget", "30 min", 0)
         << QApplication::translate("VSCVWidget", "2   hour", 0)
         << QApplication::translate("VSCVWidget", "1   day", 0)
         << QApplication::translate("VSCVWidget", "1   week", 0)
         << QApplication::translate("VSCVWidget", "2   week", 0)
        );
        pbPause->setText(QString());
        pbPlay->setText(QString());
        pbInstantpb->setText(QString());
        pbRecord->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VSCVWidget: public Ui_VSCVWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VSCVWIDGET_H
