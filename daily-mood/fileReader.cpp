#include "fileReader.h"
#include "todo.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>



fileReader::fileReader(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
    }
    else {
        std::string line;
        while (std::getline(file, line)) {
            data.push_back(line);
        }
    }
    file.close();
}

fileReader::~fileReader() {
  /*  if (file.is_open()) {
        file.close();
    }*/
}

std::vector<std::string> fileReader::getData() { return this->data; };

void fileReader::writeTodos(const std::vector<Todo> todos) {
    std::ofstream wfile("data.txt");
    if (!wfile.is_open()) return;
    for (Todo todo : todos) {
        wfile << todo.toString() << std::endl;
    }
    wfile.close();
}

void fileReader::addTodoRecord(const std::string record) {
}