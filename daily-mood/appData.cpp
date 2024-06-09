#include "appData.h"
#include "todo.h"

appData::appData(std::vector<std::string> todoData, std::vector<std::string> moodData, std::string initialDate, QWidget* todoScroll) {
    for (std::string d : todoData) {
        this->addTodo(d);
    }

    for (std::string m : moodData) {
        this->addMood(m);
    }

    this->todoScroll = todoScroll;
    this->todoLayout = new QVBoxLayout(todoScroll);

    std::vector<std::string> dateParts = helpers::split(initialDate, '/');
    this->date.day = std::stoi(dateParts[0]);
    this->date.month = std::stoi(dateParts[1]);
    this->date.year = std::stoi(dateParts[2]);
}

void appData::displayTodos() {
    for (Todo& td : this->todos) {
        date::DATE tdDate = td.getDateObj();
        if (this->date.day != tdDate.day || this->date.month != tdDate.month || this->date.year != tdDate.year) continue;
        TodoCard* todoCard = new TodoCard(td);
        this->todoLayout->addWidget(todoCard);
    }
    this->todoScroll->setLayout(this->todoLayout);
}

void appData::displayMood(QVBoxLayout* moodScroll) {
    this->moodLayout = moodScroll;
    this->displayMood();
}

void appData::displayMood() {
    QLayoutItem* item;
    while ((item = this->moodLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    for (Mood& mood : this->moods) {
        date::DATE tdDate = mood.getDateObj();
        if (this->date.day != tdDate.day || this->date.month != tdDate.month || this->date.year != tdDate.year) continue;
        MoodCard* moodCard = new MoodCard(mood);
        this->moodLayout->addWidget(moodCard);
    }
}

void appData::clearTodos() {
    QLayoutItem* item;
    while ((item = this->todoLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
}

void appData::addTodo(std::string data) {
    this->todos.push_back(Todo(data));
}

void appData::addMood(std::string data) {
    this->moods.push_back(Mood(data));
}

void appData::addMood(std::string date, int rating, std::string description) {
    std::vector<std::string> dateParts = helpers::split(date, '/');
    int moodDay = std::stoi(dateParts[0]);
    int moodMonth = std::stoi(dateParts[1]);
    int moodYear = std::stoi(dateParts[2]);

    Mood* foundMood = this->findMood(moodDay, moodMonth, moodYear);
    if (foundMood) {
        foundMood->updateRank(rating, description);
        return;
    }

    this->addMood(date + "\t" + std::to_string(rating) + "\t" + description);
}

void appData::setDate(std::string newDate) {
    std::vector<std::string> date = helpers::split(newDate, '/');
    this->date.day = std::stoi(date[0]);
    this->date.month = std::stoi(date[1]);
    this->date.year = std::stoi(date[2]);
}

std::vector<Todo> appData::getTodos() { return this->todos; }
std::vector<Mood> appData::getMoods() { return this->moods; }

void appData::sort() {
    helpers::todoQuicksort(this->todos, 0, this->todos.size() - 1);
}

Mood* appData::findMood(unsigned day, unsigned month, unsigned year) {
    for (Mood& m : this->moods) {
        date::DATE d = m.getDateObj();
        if (d.day == day && d.month == month && d.year == year) return &m;
    }
    return nullptr;
}
