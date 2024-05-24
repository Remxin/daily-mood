#include "fileReader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>



fileReader::fileReader(const std::string& filename) {
    file.open(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
    }
    else {
        std::string line;
        while (std::getline(file, line)) {
            data.push_back(line);
        }
    }
}

fileReader::~fileReader() {
    if (file.is_open()) {
        file.close();
    }
}

std::vector<std::string> fileReader::getData() { return this->data; };