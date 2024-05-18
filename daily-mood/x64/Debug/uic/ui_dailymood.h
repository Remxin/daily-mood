/********************************************************************************
** Form generated from reading UI file 'dailymood.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAILYMOOD_H
#define UI_DAILYMOOD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dailymoodClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *dailymoodClass)
    {
        if (dailymoodClass->objectName().isEmpty())
            dailymoodClass->setObjectName("dailymoodClass");
        dailymoodClass->resize(600, 400);
        menuBar = new QMenuBar(dailymoodClass);
        menuBar->setObjectName("menuBar");
        dailymoodClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(dailymoodClass);
        mainToolBar->setObjectName("mainToolBar");
        dailymoodClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(dailymoodClass);
        centralWidget->setObjectName("centralWidget");
        dailymoodClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(dailymoodClass);
        statusBar->setObjectName("statusBar");
        dailymoodClass->setStatusBar(statusBar);

        retranslateUi(dailymoodClass);

        QMetaObject::connectSlotsByName(dailymoodClass);
    } // setupUi

    void retranslateUi(QMainWindow *dailymoodClass)
    {
        dailymoodClass->setWindowTitle(QCoreApplication::translate("dailymoodClass", "dailymood", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dailymoodClass: public Ui_dailymoodClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAILYMOOD_H
