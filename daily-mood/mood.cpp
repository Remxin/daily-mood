#include "mood.h"



Mood::Mood(unsigned day, unsigned month, int year, unsigned rating, std::string description) {
	if (day > date::maxDay) throw "day must be in range (0-31)";
	if (month > date::maxMonth) throw "month must be in range (1-12)";
	if (rating < 1 || rating > 5) throw "rating must be in range (1-5)";

	this->date.day = day;
	this->date.month = month;
	this->date.year = year;
	this->rating = rating;
	this->description = description;
}

Mood::Mood(std::string data) {
	std::vector<std::string> splited = helpers::split(data, '\t');
	std::vector<std::string> date = helpers::split(splited[0], '/');

	this->date.day = std::stoi(date[0]);
	this->date.month = std::stoi(date[1]);
	this->date.year = std::stoi(date[2]);

	this->rating = std::stoi(splited[1]);
	this->description = splited[2];

}

void Mood::setRating(unsigned rating) {
	if (rating < 1 || rating > 5) throw "rating must be in range (1-5)";
	this->rating = rating;
}

std::string Mood::toString() {
	std::stringstream ss;
	ss << this->date.day << "/" << this->date.month << "/" << this->date.year << "\t" << this->rating << "\t" << this->description;
	return ss.str();
}

std::string Mood::getDate() {
	std::stringstream ss;
	ss << this->date.day << "/" << this->date.month << "/" << this->date.year;
	return ss.str();
}

unsigned Mood::getRating() { return this->rating; };
std::string Mood::getDescription() { return this->description; };


date::DATE Mood::getDateObj() { return this->date; };

void Mood::updateRank(unsigned rating, std::string description) {
	this->rating = rating;
	this->description = description;
}

