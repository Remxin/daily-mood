#include "appData.h"
#include "todo.h"



void appData::addTodo(std::string data) {
	Todo newTodo = Todo(data);
	this->todos.push_back(newTodo);
};