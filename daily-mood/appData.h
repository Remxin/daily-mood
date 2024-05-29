#pragma once
#include "todo.h"
#include "mood.h"
#include "date.h"
#include "helpers.h"
#include <vector>
#include <string>
#include <qwidget.h>
#include "TodoCard.h"
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
	QVBoxLayout* layout;
	QCalendarWidget* calendar;

public:
	appData(std::vector<std::string> todoData, std::vector<std::string> moodData, std::string initialDate);
	// methods
	void displayTodos(QWidget* todoScroll);
	void displayTodos();
	void clearTodos();
	void sort();

	// setters
	void addTodo(std::string data);
	void addMood(std::string data);
	void setDate(std::string newDate);

	// getters
	std::vector<Todo> getTodos();
};

