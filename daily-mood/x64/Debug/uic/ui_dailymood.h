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
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dailymoodClass
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QCalendarWidget *calendarWidget;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *addTodoButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QScrollArea *todosScroll;
    QWidget *scrollAreaWidgetContents;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *dailymoodClass)
    {
        if (dailymoodClass->objectName().isEmpty())
            dailymoodClass->setObjectName("dailymoodClass");
        dailymoodClass->resize(608, 646);
        centralWidget = new QWidget(dailymoodClass);
        centralWidget->setObjectName("centralWidget");
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(-1, -1, 451, 361));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        calendarWidget = new QCalendarWidget(gridLayoutWidget);
        calendarWidget->setObjectName("calendarWidget");

        gridLayout->addWidget(calendarWidget, 1, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(450, 19, 170, 341));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        addTodoButton = new QPushButton(verticalLayoutWidget);
        addTodoButton->setObjectName("addTodoButton");

        verticalLayout->addWidget(addTodoButton);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);

        todosScroll = new QScrollArea(centralWidget);
        todosScroll->setObjectName("todosScroll");
        todosScroll->setGeometry(QRect(-1, 359, 611, 231));
        todosScroll->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 609, 229));
        todosScroll->setWidget(scrollAreaWidgetContents);
        dailymoodClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(dailymoodClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 608, 21));
        dailymoodClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(dailymoodClass);
        mainToolBar->setObjectName("mainToolBar");
        dailymoodClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(dailymoodClass);
        statusBar->setObjectName("statusBar");
        dailymoodClass->setStatusBar(statusBar);

        retranslateUi(dailymoodClass);

        QMetaObject::connectSlotsByName(dailymoodClass);
    } // setupUi

    void retranslateUi(QMainWindow *dailymoodClass)
    {
        dailymoodClass->setWindowTitle(QCoreApplication::translate("dailymoodClass", "dailymood", nullptr));
        label->setText(QCoreApplication::translate("dailymoodClass", "TODOS", nullptr));
        addTodoButton->setText(QCoreApplication::translate("dailymoodClass", "ADD TODO", nullptr));
        pushButton_3->setText(QCoreApplication::translate("dailymoodClass", "UPDATE MOOD", nullptr));
        pushButton_2->setText(QCoreApplication::translate("dailymoodClass", "VIEW MOOD GRAPH", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dailymoodClass: public Ui_dailymoodClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAILYMOOD_H
