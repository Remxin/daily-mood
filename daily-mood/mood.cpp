#include "mood.h"
#include "date.cpp"

#include <string>
#include <sstream>

class Mood {
private:
	date::DATE date;
	unsigned rating;
	std::string description;

public:
	Mood(unsigned day, unsigned month, int year, unsigned rating, std::string description);
	void setRating(unsigned rating);

	// getters
	std::string toString();
	std::string getDate();
	unsigned getRating();
	std::string getDescription();

};

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

