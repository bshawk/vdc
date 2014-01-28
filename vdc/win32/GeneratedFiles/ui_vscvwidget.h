/********************************************************************************
** Form generated from reading UI file 'vscvwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VSCVWIDGET_H
#define UI_VSCVWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "videowidget.h"

QT_BEGIN_NAMESPACE

class Ui_VSCVWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    VideoWidget *video;
    QWidget *videoControl;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_2;

    void setupUi(QWidget *VSCVWidget)
    {
        if (VSCVWidget->objectName().isEmpty())
            VSCVWidget->setObjectName(QStringLiteral("VSCVWidget"));
        VSCVWidget->resize(580, 358);
        VSCVWidget->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));
        verticalLayout_2 = new QVBoxLayout(VSCVWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(VSCVWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setAutoFillBackground(true);
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
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("color : rgb(247, 247, 247);\n"
"font: 75 9pt \"Arial\";"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("color : red;\n"
"font: 75 9pt \"Arial\";"));

        horizontalLayout->addWidget(label_2);


        verticalLayout->addWidget(widget);

        video = new VideoWidget(widget_3);
        video->setObjectName(QStringLiteral("video"));
        video->setAutoFillBackground(false);
        video->setStyleSheet(QStringLiteral("background-color:rgb(0, 0, 0)"));

        verticalLayout->addWidget(video);

        videoControl = new QWidget(widget_3);
        videoControl->setObjectName(QStringLiteral("videoControl"));
        videoControl->setMinimumSize(QSize(0, 30));
        videoControl->setMaximumSize(QSize(16777215, 30));
        videoControl->setStyleSheet(QStringLiteral("background-color:rgb(42, 43, 44)"));
        horizontalLayout_2 = new QHBoxLayout(videoControl);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(videoControl);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMaximumSize(QSize(70, 16777215));
        pushButton->setStyleSheet(QLatin1String("background-color:rgb(80, 80, 80);\n"
"color : rgb(247, 247, 247);\n"
"font: 75 9pt \"Arial\";"));

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButton_2 = new QPushButton(videoControl);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(50, 0));
        pushButton_2->setMaximumSize(QSize(50, 16777215));
        pushButton_2->setStyleSheet(QLatin1String("background-color:rgb(80, 80, 80);\n"
"color : rgb(247, 247, 247);\n"
"font: 75 9pt \"Arial\";"));

        horizontalLayout_2->addWidget(pushButton_2);


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
        label->setText(QApplication::translate("VSCVWidget", "Camera", 0));
        label_2->setText(QApplication::translate("VSCVWidget", "Recording", 0));
        pushButton->setText(QApplication::translate("VSCVWidget", "Playback", 0));
        pushButton_2->setText(QApplication::translate("VSCVWidget", "Zoom", 0));
    } // retranslateUi

};

namespace Ui {
    class VSCVWidget: public Ui_VSCVWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VSCVWIDGET_H
