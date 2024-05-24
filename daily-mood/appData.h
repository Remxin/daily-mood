#pragma once
#include "todo.h"
#include "mood.h"
#include <vector>
#include <string>
#include <qwidget.h>
#include "TodoCard.h"
#include <QtWidgets/QApplication>
#include <qboxlayout.h>

class appData
{
private:
	std::vector<Todo> todos;
	std::vector<Mood> moods;
public:
	appData(std::vector<std::string> initialData);
	// methods
	void displayTodos(QWidget* todoScroll);

	// setters
	void addTodo(std::string data);
	void addMood(std::string data);

	// getters
	std::vector<Todo> getTodos();
};

