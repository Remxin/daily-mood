#include "fileReader.h"
#include "todo.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>



fileReader::fileReader(const std::string& filename) {
    this->file.open(filename);
    if (!this->file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
    }
    else {
        std::string line;
        while (std::getline(this->file, line)) {
            data.push_back(line);
        }
    }
}

fileReader::~fileReader() {
    if (this->file.is_open()) {
        this->file.close();
    }
}

std::vector<std::string> fileReader::getData() { return this->data; };

void fileReader::writeTodos(const std::vector<Todo> todos) {
    if (!this->file.is_open()) return;
    for (Todo todo : todos) {
        this->file << todo << std::endl;
    }
}

void fileReader::addTodoRecord(const std::string record) {
}