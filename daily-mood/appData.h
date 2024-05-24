#pragma once
#include "todo.h"
#include "mood.h"
#include <vector>
#include <string>

class appData
{
private:
	std::vector<Todo> todos;
	std::vector<mood> moods;
public:
	// setters
	void addTodo(std::string data);
	void addMood(std::string data);

	// getters
	std::vector<Todo> getTodos();
};

