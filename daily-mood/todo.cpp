#include "todo.h"
#include <iostream>
#include <string>
#include <vector>
#include <format>
#include <sstream>

#include "helpers.cpp"
#include "date.cpp"




class Todo {
private:
	date::DATE date;
	date::TIME time;
	std::string name;
	bool done;

public:
	Todo(std::string s);
	Todo(unsigned day, unsigned month, int year, unsigned hour, unsigned minute, std::string name, bool done);
	std::string toString();
	void toggleDone();
	void changeTime(unsigned hour, unsigned minute);
	
};

Todo::Todo(std::string s) {
	std::vector<std::string> splited = helpers::split(s, ' ');
	
	std::vector<std::string> date = helpers::split(splited[0], '/');
	std::vector<std::string> time = helpers::split(splited[2], ':');
	this->date.day = std::stoi(date[0]);
	this->date.month = std::stoi(date[1]);
	this->date.year = std::stoi(date[2]);

	this->time.hour = std::stoi(time[0]);
	this->time.minute = std::stoi(time[1]);

	this->name = splited[1];
	this->done = std::stoi(splited[3]);

}



Todo::Todo(unsigned day, unsigned month, int year, unsigned hour, unsigned minute, std::string name, bool done) {
	date::DATE date;
	date.day = day;
	date.month = month;
	date.year = year;
	this->date = date;

	date::TIME time;
	time.hour = hour;
	time.minute = minute;
	this->time = time;

	this->name = name;
	this->done = done;
}

std::string Todo::toString() {
	std::stringstream ss;
	ss << this->date.day << "/" << this->date.month << "/" << this->date.year << "\t" << this->name << "\t" << this->time.hour << ":" << this->time.hour << "\t" << this->done;
	return ss.str();
}

void Todo::toggleDone() {
	if (this->done) this->done = false;
	this->done = true;
}

void Todo::changeTime(unsigned hour, unsigned minute) {
	if (hour > date::maxHour) throw "hour must be in range (0-23)";
	if (minute >> date::maxMinute) throw "minute must be in range (0-59)";

	this->time.hour = hour;
	this->time.minute = minute;
}