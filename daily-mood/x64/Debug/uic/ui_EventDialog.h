/********************************************************************************
** Form generated from reading UI file 'EventDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTDIALOG_H
#define UI_EVENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLineEdit *lineEdit;
    QDateEdit *dateEdit;
    QTimeEdit *timeEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *okButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(400, 300);
        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(70, 30, 271, 41));
        dateEdit = new QDateEdit(Dialog);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(70, 120, 141, 41));
        timeEdit = new QTimeEdit(Dialog);
        timeEdit->setObjectName("timeEdit");
        timeEdit->setGeometry(QRect(70, 210, 141, 24));
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 0, 41, 20));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        label->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label_2 = new QLabel(Dialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 90, 49, 16));
        label_2->setFont(font);
        label_3 = new QLabel(Dialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 180, 49, 16));
        label_3->setFont(font);
        okButton = new QPushButton(Dialog);
        okButton->setObjectName("okButton");
        okButton->setGeometry(QRect(120, 250, 80, 24));
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(230, 250, 80, 24));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Title", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Date", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "Time", nullptr));
        okButton->setText(QCoreApplication::translate("Dialog", "ADD", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dialog", "EXIT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTDIALOG_H
