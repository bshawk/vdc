/********************************************************************************
** Form generated from reading UI file 'vschddedit.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VSCHDDEDIT_H
#define UI_VSCHDDEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VSCHddEdit
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *applyButton;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *VSCHddEdit)
    {
        if (VSCHddEdit->objectName().isEmpty())
            VSCHddEdit->setObjectName(QStringLiteral("VSCHddEdit"));
        VSCHddEdit->resize(591, 369);
        QIcon icon;
        icon.addFile(QStringLiteral(":/logo/resources/vscsmall.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        VSCHddEdit->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(VSCHddEdit);
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(20, 35, 50, 100);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(30);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        applyButton = new QPushButton(VSCHddEdit);
        applyButton->setObjectName(QStringLiteral("applyButton"));

        hboxLayout->addWidget(applyButton);

        cancelButton = new QPushButton(VSCHddEdit);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        hboxLayout->addWidget(cancelButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(hboxLayout);


        retranslateUi(VSCHddEdit);
        QObject::connect(applyButton, SIGNAL(clicked()), VSCHddEdit, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), VSCHddEdit, SLOT(reject()));

        QMetaObject::connectSlotsByName(VSCHddEdit);
    } // setupUi

    void retranslateUi(QWidget *VSCHddEdit)
    {
        VSCHddEdit->setWindowTitle(QApplication::translate("VSCHddEdit", "Master Hard Disk Selecting", 0));
        applyButton->setText(QApplication::translate("VSCHddEdit", "Apply", 0));
        cancelButton->setText(QApplication::translate("VSCHddEdit", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class VSCHddEdit: public Ui_VSCHddEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VSCHDDEDIT_H
