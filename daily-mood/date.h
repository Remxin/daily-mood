#pragma once
#ifndef DATE_H
#define DATE_H

#include <string>

namespace date {
    // Declare constants as extern
    extern const unsigned maxDay;
    extern const unsigned maxMonth;
    extern const unsigned maxHour;
    extern const unsigned maxMinute;

    // Structures
    typedef struct {
        unsigned day;
        unsigned month;
        int year;
    } DATE;

    typedef struct {
        unsigned hour;
        unsigned minute;
    } TIME;

    // Function prototypes
    std::string getTodaysDateStr();
    std::string convertTo2Digits(unsigned num);
    unsigned long long toSeconds(unsigned hour, unsigned minute);
    unsigned long long toSeconds(unsigned day, unsigned month, int year);
}

#endif // DATE_H
