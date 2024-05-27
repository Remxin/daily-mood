#include "helpers.h"
#include "date.h"
#include "todo.h"


namespace helpers {
    std::vector<std::string> split(const std::string& str, char delimiter) {
        std::vector<std::string> tokens;
        size_t start = 0;
        size_t end = str.find(delimiter);

        while (end != std::string::npos) {
            tokens.push_back(str.substr(start, end - start));
            start = end + 1;
            end = str.find(delimiter, start);
        }

        tokens.push_back(str.substr(start));
        return tokens;
    }
    void todoSwap(Todo& a, Todo& b) {
        Todo temp = a;
        a = b;
        b = temp;
    }

    int todoPartition(std::vector<Todo>& arr, int low, int high) {
        unsigned pivot = date::toSeconds(arr[high].getHour(), arr[high].getMinute());
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            Todo curr = arr[j];
            if (date::toSeconds(curr.getHour(), curr.getMinute())<pivot) {
                i++;
                todoSwap(arr[i], arr[j]);
            }
        }
        todoSwap(arr[i + 1], arr[high]);
        return i + 1;
    }

    void todoQuicksort(std::vector<Todo>& arr, int low, int high) {
        if (low < high) {
            int pi = todoPartition(arr, low, high);
            todoQuicksort(arr, low, pi - 1);
            todoQuicksort(arr, pi + 1, high);
        }
    }


}