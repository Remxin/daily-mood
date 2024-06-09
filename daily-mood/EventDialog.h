#pragma once

#include <QDialog>
#include "ui_eventdialog.h"  

class EventDialog : public QDialog {
    Q_OBJECT

public:
    explicit EventDialog(QWidget* parent = nullptr);
    ~EventDialog();

    QString getName() const;
    QDate getDate() const;
    QTime getTime() const;

private:
    Ui::EventDialog ui;

    void applyStyleSheet();  
};
