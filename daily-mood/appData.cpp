#include "appData.h"
#include "todo.h"



void appData::addTodo(std::string data) {
	this->todos.push_back(Todo(data));
};

std::vector<Todo> appData::getTodos() { return this->todos; };