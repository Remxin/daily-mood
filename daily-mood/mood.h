#pragma once

#ifndef MOOD_H
#define MOOD_H
#include "date.h"
#include "helpers.h"
#include <string>
#include <sstream>
#include "errors.h"



class Mood {
private:
	date::DATE date;
	unsigned rating;
	std::string description;

public:
	Mood(unsigned day, unsigned month, int year, unsigned rating, std::string description);
	Mood(std::string data);
	void setRating(unsigned rating);

	// getters
	std::string toString();
	std::string getDate();
	unsigned getRating();
	std::string getDescription();
	date::DATE getDateObj();

	// setters
	void updateRank(unsigned rating, std::string description);

};

#endif

