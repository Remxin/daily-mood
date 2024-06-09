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
#include <qpushbutton.h>

QT_BEGIN_NAMESPACE

class Ui_EventDialog: public QObject
{
    Q_OBJECT
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
        QDate currentDate = QDate::currentDate();
        dateEdit->setDate(currentDate);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        verticalLayout->addWidget(dateEdit);
        labelTime = new QLabel(EventDialog);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));
        verticalLayout->addWidget(labelTime);
        timeEdit = new QTimeEdit(EventDialog);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        QTime currentTime = QTime::currentTime();
        timeEdit->setTime(currentTime);
        verticalLayout->addWidget(timeEdit);
        buttonBox = new QDialogButtonBox(EventDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);
        verticalLayout->addWidget(buttonBox);

        retranslateUi(EventDialog);
        applyStyles();

        QMetaObject::connectSlotsByName(EventDialog);


        // Connect buttonBox to dialog's accept and reject slots
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, EventDialog, &QDialog::accept);
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, EventDialog, &QDialog::reject);

        QObject::connect(lineEditName, &QLineEdit::textChanged, this, &Ui_EventDialog::setButtonAvailability);
        QObject::connect(dateEdit, &QDateEdit::dateChanged, this, &Ui_EventDialog::setButtonAvailability);
        QObject::connect(timeEdit, &QTimeEdit::timeChanged, this, &Ui_EventDialog::setButtonAvailability);

        // Ustaw wstępny stan przycisku
        setButtonAvailability();
    } // setupUi

    void retranslateUi(QDialog* EventDialog)
    {
        EventDialog->setWindowTitle(QCoreApplication::translate("EventDialog", "EventDialog", nullptr));
        labelName->setText(QCoreApplication::translate("EventDialog", "Name", nullptr));
        labelDate->setText(QCoreApplication::translate("EventDialog", "Date", nullptr));
        labelTime->setText(QCoreApplication::translate("EventDialog", "Time", nullptr));
    } // retranslateUi

   

private slots:
    void setButtonAvailability()
    {
        QDialog* EventDialog = qobject_cast<QDialog*>(verticalLayout->parentWidget());
        if (EventDialog) {
            QPushButton* okButton = buttonBox->button(QDialogButtonBox::Ok);
            if (!lineEditName->text().isEmpty() && dateEdit->date().isValid() && timeEdit->time().isValid()) {
                okButton->setEnabled(true);
            }
            else {
                okButton->setEnabled(false);
            }
        }
    }

private:
    void applyStyles()
    {
        QString styleSheet = R"(
            QPushButton {
                background-color: #4CAF50;
                color: white;
                border: none;
                padding: 10px 24px;
                text-align: center;
                text-decoration: none;
                display: inline-block;
                font-size: 14px;
                margin: 4px 2px;
                cursor: pointer;
                border-radius: 12px;
            }

            QPushButton:disabled {
                background-color: #d4d4d4;
                color: #a0a0a0;
            }
        )";
        buttonBox->setStyleSheet(styleSheet);
    }

};

namespace Ui {
    class EventDialog : public Ui_EventDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTDIALOG_H
