/********************************************************************************
** Form generated from reading UI file 'addressbox.ui'
**
** Created: Fri Jun 7 14:27:29 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRESSBOX_H
#define UI_ADDRESSBOX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddressBoxClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AddressBoxClass)
    {
        if (AddressBoxClass->objectName().isEmpty())
            AddressBoxClass->setObjectName(QString::fromUtf8("AddressBoxClass"));
        AddressBoxClass->resize(600, 400);
        menuBar = new QMenuBar(AddressBoxClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        AddressBoxClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AddressBoxClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        AddressBoxClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(AddressBoxClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        AddressBoxClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(AddressBoxClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        AddressBoxClass->setStatusBar(statusBar);

        retranslateUi(AddressBoxClass);

        QMetaObject::connectSlotsByName(AddressBoxClass);
    } // setupUi

    void retranslateUi(QMainWindow *AddressBoxClass)
    {
        AddressBoxClass->setWindowTitle(QApplication::translate("AddressBoxClass", "AddressBox", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddressBoxClass: public Ui_AddressBoxClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRESSBOX_H
