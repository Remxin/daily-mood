#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_dailymood.h"
#include "EventDialog.h"  


#include "TodoCard.h"
#include "appData.h"
#include "todo.h"
#include "fileReader.h"
#include "helpers.h"

class dailymood : public QMainWindow
{
    Q_OBJECT

public:
    dailymood(QWidget* parent = nullptr);
    ~dailymood();

private:
    Ui::dailymoodClass ui;
    fileReader* freader;
    appData *applicationData;
 
    void updateTodoCards(const QString& selectedDateString);


private slots:
    void addBtnClicked();
    void openEventDialog();
    void onDateChanged();
};
