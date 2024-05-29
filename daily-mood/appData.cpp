#include "appData.h"
#include "todo.h"



appData::appData(std::vector<std::string> todoData, std::vector<std::string> moodData, std::string initialDate) {
	for (std::string d : todoData) {
        this->addTodo(d);
	}

    for (std::string d : moodData) {
        this->addMood(d);
    }


    QVBoxLayout* layout = new QVBoxLayout(this->todoScroll);
    this->layout = layout;
}

void appData::displayTodos(QWidget* todoScroll) {
    this->todoScroll = todoScroll;
    this->displayTodos();
}

void appData::displayTodos() {
    // Create a QVBoxLayout for the todoScroll widget
    
    // displaying todos and moods
    for (Todo &td : this->todos) {
        date::DATE tdDate = td.getDateObj();
        if (this->date.day != tdDate.day || this->date.month != tdDate.month || this->date.year != tdDate.year) continue;
        TodoCard* todoCard = new TodoCard(td);
        this->layout->addWidget(todoCard);
    }

    // Set the layout to todoScroll
    this->todoScroll->setLayout(this->layout);
}

void appData::clearTodos() {
    QLayoutItem* item;
    while ((item = this->layout->takeAt(0)) != nullptr) {
        delete item->widget(); // delete the widget
        delete item; // delete the layout item
    }
}

void appData::addTodo(std::string data) {
	this->todos.push_back(Todo(data));
};

void appData::addMood(std::string data) {
    this->moods.push_back(Mood(data));
}

void appData::setDate(std::string newDate) {
    std::vector<std::string> date = helpers::split(newDate, '/');
    this->date.day = std::stoi(date[0]);
    this->date.month = std::stoi(date[1]);
    this->date.year = std::stoi(date[2]);
}

std::vector<Todo> appData::getTodos() { return this->todos; };

void appData::sort() {
    helpers::todoQuicksort(this->todos, 0, this->todos.size() - 1);
}