/********************************************************************************
** Form generated from reading UI file 'EventDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTDIALOG_H
#define UI_EVENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EventDialog
{
public:
    QVBoxLayout* verticalLayout;
    QLabel* labelName;
    QLineEdit* lineEditName;
    QLabel* labelDate;
    QDateEdit* dateEdit;
    QLabel* labelTime;
    QTimeEdit* timeEdit;
    QDialogButtonBox* buttonBox;

    void setupUi(QDialog* EventDialog)
    {
        if (EventDialog->objectName().isEmpty())
            EventDialog->setObjectName(QString::fromUtf8("EventDialog"));
        EventDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(EventDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelName = new QLabel(EventDialog);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        verticalLayout->addWidget(labelName);
        lineEditName = new QLineEdit(EventDialog);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));
        verticalLayout->addWidget(lineEditName);
        labelDate = new QLabel(EventDialog);
        labelDate->setObjectName(QString::fromUtf8("labelDate"));
        verticalLayout->addWidget(labelDate);
        dateEdit = new QDateEdit(EventDialog);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        verticalLayout->addWidget(dateEdit);
        labelTime = new QLabel(EventDialog);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));
        verticalLayout->addWidget(labelTime);
        timeEdit = new QTimeEdit(EventDialog);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        verticalLayout->addWidget(timeEdit);
        buttonBox = new QDialogButtonBox(EventDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);
        verticalLayout->addWidget(buttonBox);

        retranslateUi(EventDialog);

        QMetaObject::connectSlotsByName(EventDialog);

        // Connect buttonBox to dialog's accept and reject slots
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, EventDialog, &QDialog::accept);
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, EventDialog, &QDialog::reject);
    } // setupUi

    void retranslateUi(QDialog* EventDialog)
    {
        EventDialog->setWindowTitle(QCoreApplication::translate("EventDialog", "EventDialog", nullptr));
        labelName->setText(QCoreApplication::translate("EventDialog", "Name", nullptr));
        labelDate->setText(QCoreApplication::translate("EventDialog", "Date", nullptr));
        labelTime->setText(QCoreApplication::translate("EventDialog", "Time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EventDialog : public Ui_EventDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTDIALOG_H
