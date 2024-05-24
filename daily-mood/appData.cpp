#include "appData.h"
#include "todo.h"



appData::appData(std::vector<std::string> initialData) {
	for (std::string d : initialData) {
        this->addTodo(d);
	}
}

void appData::displayTodos(QWidget* todoScroll) {
    // Create a QVBoxLayout for the todoScroll widget
    QVBoxLayout* layout = new QVBoxLayout(todoScroll);
    // displaying todos and moods
    for (const Todo& todo : this->todos) {
        TodoCard* todoCard = new TodoCard(todo);

        layout->addWidget(todoCard);
    }

    // Set the layout to todoScroll
    todoScroll->setLayout(layout);
}

void appData::addTodo(std::string data) {
	this->todos.push_back(Todo(data));
};

void appData::addMood(std::string data) {
    //this->moods.push_back(Mood(data));
}

std::vector<Todo> appData::getTodos() { return this->todos; };