#pragma once


#ifndef ERRORS_H
#define ERRORS_H

#include <exception>
#include <string>
#include <qstring.h>
#include <QMessageBox>

class QString;

namespace errors {

    class WrongFileFormat : public std::exception {
    public:
        virtual const char* what() throw() {
            return "Wrong file format - data parts should be separated by \\t ";
        }
    };

    class WrongDateFormat : public std::exception {
    public:
        virtual const char* what() throw() {
            return "Wrong date format - date parts should be separated by /";
        }
    };

    class WrongTimeFormat : public std::exception {
    public:
        virtual const char* what() throw() {
            return "Wrong time format - time parts should be separated by :";
        }
    };

    void display(QString msg);
}


#endif