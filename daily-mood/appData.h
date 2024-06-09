#pragma once
#include "todo.h"
#include "mood.h"
#include "date.h"
#include "helpers.h"
#include <vector>
#include <string>
#include <qwidget.h>
#include "TodoCard.h"
#include "MoodCard.h"
#include <QtWidgets/QApplication>
#include <qboxlayout.h>
#include <QCalendarWidget>

class appData
{
private:
    std::vector<Todo> todos;
    std::vector<Mood> moods;
    date::DATE date;
    QWidget* todoScroll;
    QVBoxLayout* todoLayout;
    QVBoxLayout* moodLayout;
    QCalendarWidget* calendar;

    Mood* findMood(unsigned day, unsigned month, unsigned year);

public:
    appData(std::vector<std::string> todoData, std::vector<std::string> moodData, std::string initialDate, QWidget* todoScroll);

    void displayTodos();
    void displayMood(QVBoxLayout* moodScroll);
    void displayMood();
    void clearTodos();
    void sort();

    void addTodo(std::string data);
    void addMood(std::string data);
    void addMood(std::string date, int rating, std::string description);
    void setDate(std::string newDate);

    std::vector<Todo> getTodos();
    std::vector<Mood> getMoods();
};
