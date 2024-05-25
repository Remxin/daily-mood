#pragma once

#ifndef MOOD_H
#define MOOD_H
#include "date.h"
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

#endif

