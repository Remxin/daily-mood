#pragma once
#ifndef HELPERS_H
#define HELPERS_H


#include <string>
#include <vector>
#include "todo.h"
class Todo;


namespace helpers {
    std::vector<std::string> split(const std::string& str, char delimiter);
    void todoSwap(Todo& a, Todo& b);
    int todoPartition(std::vector<Todo>& arr, int low, int high);
    void todoQuicksort(std::vector<Todo>& arr, int low, int high);
}

#endif // HELPERS_H
