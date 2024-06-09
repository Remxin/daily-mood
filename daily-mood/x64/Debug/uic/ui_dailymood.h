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
#include <QtWidgets/QHBoxLayout>
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
    QHBoxLayout *horizontalLayout_3;
    QPushButton *updateMoodBtn;
    QPushButton *addTodoButton;
    QScrollArea *todosScroll;
    QWidget *scrollAreaWidgetContents;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *moodScroll;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *dailymoodClass)
    {
        if (dailymoodClass->objectName().isEmpty())
            dailymoodClass->setObjectName("dailymoodClass");
        dailymoodClass->resize(609, 646);
        centralWidget = new QWidget(dailymoodClass);
        centralWidget->setObjectName("centralWidget");
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 611, 361));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        calendarWidget = new QCalendarWidget(gridLayoutWidget);
        calendarWidget->setObjectName("calendarWidget");

        gridLayout->addWidget(calendarWidget, 6, 0, 1, 3);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 1, 3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");

        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        updateMoodBtn = new QPushButton(gridLayoutWidget);
        updateMoodBtn->setObjectName("updateMoodBtn");

        gridLayout->addWidget(updateMoodBtn, 2, 2, 1, 1);

        addTodoButton = new QPushButton(gridLayoutWidget);
        addTodoButton->setObjectName("addTodoButton");

        gridLayout->addWidget(addTodoButton, 2, 0, 1, 1);

        todosScroll = new QScrollArea(centralWidget);
        todosScroll->setObjectName("todosScroll");
        todosScroll->setGeometry(QRect(0, 360, 431, 231));
        todosScroll->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 429, 229));
        todosScroll->setWidget(scrollAreaWidgetContents);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(430, 360, 181, 191));
        moodScroll = new QVBoxLayout(verticalLayoutWidget);
        moodScroll->setSpacing(6);
        moodScroll->setContentsMargins(11, 11, 11, 11);
        moodScroll->setObjectName("moodScroll");
        moodScroll->setContentsMargins(0, 0, 0, 0);
        dailymoodClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(dailymoodClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 609, 21));
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
        updateMoodBtn->setText(QCoreApplication::translate("dailymoodClass", "UPDATE MOOD", nullptr));
        addTodoButton->setText(QCoreApplication::translate("dailymoodClass", "ADD TODO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dailymoodClass: public Ui_dailymoodClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAILYMOOD_H
