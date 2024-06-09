#include "fileReader.h"
#include "todo.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string TODOFILENAME = "todo.txt";
std::string MOODFILENAME = "mood.txt";

fileReader::fileReader() {
    // for todos
    std::ifstream file(TODOFILENAME);
    if (!file.is_open()) {
        QMessageBox::warning(0, "Warning", "Cannot open todos file");
        std::cerr << "Failed to open the file." << std::endl;
    }
    else {
        std::string line;
        while (std::getline(file, line)) {
            todoData.push_back(line);
        }
    }
    file.close();

    // for mood
    std::ifstream mfile(MOODFILENAME);
    if (!mfile.is_open()) {
        QMessageBox::warning(0, "Warning", "Cannot open mood file");
    }
    else {
        std::string line;
        while (std::getline(mfile, line)) {
            moodData.push_back(line);
        }
    }
    file.close();
}

fileReader::~fileReader() {
}

std::vector<std::string> fileReader::getTodoData() { return this->todoData; };
std::vector<std::string> fileReader::getMoodData() { return this->moodData; };

void fileReader::writeTodos(const std::vector<Todo> todos) {
    std::ofstream wfile(TODOFILENAME);
    if (!wfile.is_open()) return;
    for (Todo todo : todos) {
        wfile << todo.toString() << std::endl;
    }
    wfile.close();
}

void fileReader::writeMoods(const std::vector<Mood> moods) {
    std::ofstream wfile(MOODFILENAME);
    if (!wfile.is_open()) return;
    for (Mood mood : moods) {
        wfile << mood.toString() << std::endl;
    }
    wfile.close();
}

void fileReader::addTodoRecord(const std::string record) {
}
