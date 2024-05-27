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
#include "helpers.h"

class fileReader {
private:
    std::vector<std::string> data;
    //std::fstream file;

public:
    // Constructor
    fileReader(const std::string& filename);

    // Destructor
    ~fileReader();

    // methods
    void addTodoRecord(const std::string record);
    void writeTodos(const std::vector<Todo> todos);
    // Getter
    std::vector<std::string> getData();
};

#endif // FILEREADER_H
