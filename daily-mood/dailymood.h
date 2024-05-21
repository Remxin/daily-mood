#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_dailymood.h"
#include "EventDialog.h"  

class dailymood : public QMainWindow
{
    Q_OBJECT

public:
    dailymood(QWidget* parent = nullptr);
    ~dailymood();

private:
    Ui::dailymoodClass ui;

private slots:
    void addBtnClicked();
    void openEventDialog();
};
