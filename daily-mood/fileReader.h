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
    std::vector<std::string> todoData;
    std::vector<std::string> moodData;
    //std::fstream file;

public:
    // Constructor
    fileReader();

    // Destructor
    ~fileReader();

    // methods
    void addTodoRecord(const std::string record);
    void writeTodos(const std::vector<Todo> todos);
    void addMoodRecord(const std::string record);

    // Getter
    std::vector<std::string> getTodoData();
    std::vector<std::string> getMoodData();
};

#endif // FILEREADER_H
