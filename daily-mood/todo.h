#ifndef TODO_H
#define TODO_H

#include <string>

namespace date {
    struct DATE {
        unsigned day;
        unsigned month;
        int year;
    };

    struct TIME {
        unsigned hour;
        unsigned minute;
    };

    const unsigned maxHour = 23;
    const unsigned maxMinute = 59;
}

class Todo {
private:
    date::DATE date;
    date::TIME time;
    std::string name;
    bool done;

public:
    // Constructors
    Todo(std::string s);
    Todo(unsigned day, unsigned month, int year, unsigned hour, unsigned minute, std::string name, bool done);

    // Setters
    void toggleDone();
    void setTime(unsigned hour, unsigned minute);

    // Getters
    std::string toString();
    std::string getDate();
    std::string getTime();
    std::string getName();
    bool getDone();
};

#endif // TODO_H
