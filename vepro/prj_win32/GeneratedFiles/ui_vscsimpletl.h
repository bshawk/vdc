/********************************************************************************
** Form generated from reading UI file 'vscsimpletl.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VSCSIMPLETL_H
#define UI_VSCSIMPLETL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VSCSimpleTl
{
public:

    void setupUi(QWidget *VSCSimpleTl)
    {
        if (VSCSimpleTl->objectName().isEmpty())
            VSCSimpleTl->setObjectName(QStringLiteral("VSCSimpleTl"));
        VSCSimpleTl->resize(567, 60);
        VSCSimpleTl->setMinimumSize(QSize(0, 45));
        VSCSimpleTl->setMaximumSize(QSize(16777215, 60));
        VSCSimpleTl->setStyleSheet(QStringLiteral("background-color: rgb( 100,100,100);"));

        retranslateUi(VSCSimpleTl);

        QMetaObject::connectSlotsByName(VSCSimpleTl);
    } // setupUi

    void retranslateUi(QWidget *VSCSimpleTl)
    {
        VSCSimpleTl->setWindowTitle(QApplication::translate("VSCSimpleTl", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class VSCSimpleTl: public Ui_VSCSimpleTl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VSCSIMPLETL_H
