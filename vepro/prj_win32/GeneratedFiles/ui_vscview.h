/********************************************************************************
** Form generated from reading UI file 'vscview.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VSCVIEW_H
#define UI_VSCVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VSCView
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QWidget *widgetControl;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton1;
    QPushButton *pushButton2x2;
    QPushButton *pushButton3x3;
    QPushButton *pushButton6;
    QPushButton *pushButton4x4;
    QPushButton *pushButton12p1;
    QPushButton *pushButton5x5;
    QPushButton *pushButton6x6;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *VSCView)
    {
        if (VSCView->objectName().isEmpty())
            VSCView->setObjectName(QStringLiteral("VSCView"));
        VSCView->resize(524, 371);
        QIcon icon;
        icon.addFile(QStringLiteral(":/logo/resources/vscsmall.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        VSCView->setWindowIcon(icon);
        gridLayout = new QGridLayout(VSCView);
        gridLayout->setSpacing(1);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(1, 1, 1, 1);
        widget = new QWidget(VSCView);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setAutoFillBackground(true);
        widget->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(widget, 0, 0, 1, 1);

        widgetControl = new QWidget(VSCView);
        widgetControl->setObjectName(QStringLiteral("widgetControl"));
        verticalLayout = new QVBoxLayout(widgetControl);
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton1 = new QPushButton(widgetControl);
        pushButton1->setObjectName(QStringLiteral("pushButton1"));
        pushButton1->setMinimumSize(QSize(25, 25));
        pushButton1->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/view/resources/1x1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton1->setIcon(icon1);
        pushButton1->setIconSize(QSize(25, 25));

        verticalLayout->addWidget(pushButton1);

        pushButton2x2 = new QPushButton(widgetControl);
        pushButton2x2->setObjectName(QStringLiteral("pushButton2x2"));
        pushButton2x2->setMinimumSize(QSize(25, 25));
        pushButton2x2->setMaximumSize(QSize(30, 30));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/view/resources/2x2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton2x2->setIcon(icon2);
        pushButton2x2->setIconSize(QSize(25, 25));

        verticalLayout->addWidget(pushButton2x2);

        pushButton3x3 = new QPushButton(widgetControl);
        pushButton3x3->setObjectName(QStringLiteral("pushButton3x3"));
        pushButton3x3->setMinimumSize(QSize(25, 25));
        pushButton3x3->setMaximumSize(QSize(30, 30));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/view/resources/3x3.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton3x3->setIcon(icon3);
        pushButton3x3->setIconSize(QSize(25, 25));

        verticalLayout->addWidget(pushButton3x3);

        pushButton6 = new QPushButton(widgetControl);
        pushButton6->setObjectName(QStringLiteral("pushButton6"));
        pushButton6->setMinimumSize(QSize(25, 25));
        pushButton6->setMaximumSize(QSize(30, 30));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/view/resources/6.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton6->setIcon(icon4);
        pushButton6->setIconSize(QSize(25, 25));

        verticalLayout->addWidget(pushButton6);

        pushButton4x4 = new QPushButton(widgetControl);
        pushButton4x4->setObjectName(QStringLiteral("pushButton4x4"));
        pushButton4x4->setMinimumSize(QSize(25, 25));
        pushButton4x4->setMaximumSize(QSize(30, 30));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/view/resources/4x4.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton4x4->setIcon(icon5);
        pushButton4x4->setIconSize(QSize(25, 25));

        verticalLayout->addWidget(pushButton4x4);

        pushButton12p1 = new QPushButton(widgetControl);
        pushButton12p1->setObjectName(QStringLiteral("pushButton12p1"));
        pushButton12p1->setMaximumSize(QSize(30, 30));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/view/resources/12+1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton12p1->setIcon(icon6);
        pushButton12p1->setIconSize(QSize(25, 25));

        verticalLayout->addWidget(pushButton12p1);

        pushButton5x5 = new QPushButton(widgetControl);
        pushButton5x5->setObjectName(QStringLiteral("pushButton5x5"));
        pushButton5x5->setMaximumSize(QSize(30, 30));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/view/resources/5x5.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton5x5->setIcon(icon7);
        pushButton5x5->setIconSize(QSize(25, 25));

        verticalLayout->addWidget(pushButton5x5);

        pushButton6x6 = new QPushButton(widgetControl);
        pushButton6x6->setObjectName(QStringLiteral("pushButton6x6"));
        pushButton6x6->setMaximumSize(QSize(30, 30));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/view/resources/6x6.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton6x6->setIcon(icon8);
        pushButton6x6->setIconSize(QSize(25, 25));

        verticalLayout->addWidget(pushButton6x6);

        verticalSpacer = new QSpacerItem(20, 118, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addWidget(widgetControl, 0, 1, 1, 1);


        retranslateUi(VSCView);

        QMetaObject::connectSlotsByName(VSCView);
    } // setupUi

    void retranslateUi(QWidget *VSCView)
    {
        VSCView->setWindowTitle(QApplication::translate("VSCView", "View", 0));
        pushButton1->setText(QString());
        pushButton2x2->setText(QString());
        pushButton3x3->setText(QString());
        pushButton6->setText(QString());
        pushButton4x4->setText(QString());
        pushButton12p1->setText(QString());
        pushButton5x5->setText(QString());
        pushButton6x6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VSCView: public Ui_VSCView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VSCVIEW_H
