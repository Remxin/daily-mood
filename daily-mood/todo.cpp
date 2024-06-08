#include "todo.h"
#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <format>
#include <sstream>





Todo::Todo(std::string s) {
	try {
		std::vector<std::string> splited = helpers::split(s, '\t');
		if (splited.size() < 4) throw errors::WrongFileFormat();
		std::vector<std::string> date = helpers::split(splited[0], '/');
		if (date.size() < 3) throw errors::WrongDateFormat();
		std::vector<std::string> time = helpers::split(splited[2], ':');
		if (time.size() < 2) throw errors::WrongTimeFormat();
		this->date.day = std::stoi(date[0]);
		this->date.month = std::stoi(date[1]);
		this->date.year = std::stoi(date[2]);

		this->time.hour = std::stoi(time[0]);
		this->time.minute = std::stoi(time[1]);

		this->name = splited[1];
		this->done = std::stoi(splited[3]);
	}
	catch (errors::WrongFileFormat& err) {
		errors::display(QString::fromStdString(err.what()));
	}
	catch (errors::WrongDateFormat& err) {
		errors::display(QString::fromStdString(err.what()));
	}
	catch (errors::WrongTimeFormat& err) {
		errors::display(QString::fromStdString(err.what()));
	}

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
	ss << this->date.day << "/" << this->date.month << "/" << this->date.year << "\t" << this->name << "\t" << this->time.hour << ":" << this->time.hour << "\t" << (int)this->done;
	return ss.str();
}

void Todo::toggleDone() {
	if (this->done) this->done = false;
	else this->done = true;

}

void Todo::setTime(unsigned hour, unsigned minute) {
	if (hour > date::maxHour) throw "hour must be in range (0-23)";
	if (minute >> date::maxMinute) throw "minute must be in range (0-59)";

	this->time.hour = hour;
	this->time.minute = minute;
}

std::string Todo::getDate() {
	std::stringstream ss;
	ss << date::convertTo2Digits(this->date.day) << "/" << date::convertTo2Digits(this->date.month) << "/" << this->date.year;
	return ss.str();
}

std::string Todo::getTime() {
	std::stringstream ss;
	ss << date::convertTo2Digits(this->time.hour) << ":" << date::convertTo2Digits(this->time.minute);
	return ss.str();
}

std::string Todo::getName() { return this->name; };

bool Todo::getDone() { return this->done; };


date::DATE Todo::getDateObj() {
	return this->date;
}

unsigned Todo::getHour() { return this->time.hour; };
unsigned Todo::getMinute() { return this->time.minute; };

std::ostream& operator<<(std::ostream& os, Todo &todo) {
	os << todo.toString();
	return os;
}
