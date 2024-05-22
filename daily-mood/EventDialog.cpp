#include "EventDialog.h"

EventDialog::EventDialog(QWidget* parent) :
    QDialog(parent)
{
    ui.setupUi(this);
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
