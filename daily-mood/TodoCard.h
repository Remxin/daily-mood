#pragma once
#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>
#include <QtWidgets/QApplication>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "todo.h"
#include <QScrollArea>

class TodoCard : public QWidget {
    Q_OBJECT

public:
    explicit TodoCard(QObject* parent, Todo todo);

private slots:
    void onButtonClicked();

private:
    QLabel* label;
    QPushButton* button;
};

#endif // CUSTOMWIDGET_H
