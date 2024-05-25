#pragma once
#ifndef FILEREADER_H
#define FILEREADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "EventDialog.h"  
#include <QtWidgets/QMainWindow>
#include "ui_dailymood.h"

class fileReader {
private:
    std::vector<std::string> data;
    std::ifstream file;

public:
    // Constructor
    fileReader(const std::string& filename);

    // Destructor
    ~fileReader();

    void addTodoRecord(const std::string record);
    // Getter
    std::vector<std::string> getData();
};

#endif // FILEREADER_H
