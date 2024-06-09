#include "EventDialog.h"

EventDialog::EventDialog(QWidget* parent) :
    QDialog(parent)
{
    ui.setupUi(this);
    setWindowTitle("Add Todo"); 

    
    applyStyleSheet();
}

EventDialog::~EventDialog() {}

QString EventDialog::getName() const {
    return ui.lineEditName->text();
}

QDate EventDialog::getDate() const {
    return ui.dateEdit->date();
}

QTime EventDialog::getTime() const {
    return ui.timeEdit->time();
}

void EventDialog::applyStyleSheet() {
    QString styleSheet = R"(
        
        QWidget {
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            font-size: 14px;
            background-color: #FAF3E0;  /* Lekki kremowy kolor */
            color: #333333;
        }

        
        QDialog {
            background-color: #FFF8DC;  /* Lekki kremowy kolor dla QDialog */
        }

        
        QPushButton {
            background-color: #4CAF50;
            border: none;
            color: white;
            padding: 10px 24px;
            text-align: center;
            text-decoration: none;
            display: inline-block;
            font-size: 14px;
            margin: 4px 2px;
            cursor: pointer;
            border-radius: 12px;
        }

        QPushButton:hover {
            background-color: #45a049;
        }
          
        QLineEdit {
            border: 1px solid #d4d4d4;
            border-radius: 4px;
            padding: 5px;
            background-color: #ffffff;
        }

        
        QDateEdit, QTimeEdit {
            border: 1px solid #d4d4d4;
            border-radius: 4px;
            padding: 5px;
            background-color: #ffffff;
        }

        
        QLabel {
            color: #333333;
        }
        
    )";

    this->setStyleSheet(styleSheet);
}
