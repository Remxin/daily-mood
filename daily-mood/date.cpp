#include "date.h"

namespace date {
	const unsigned maxDay = 31;
	const unsigned maxMonth = 12;
	const unsigned maxHour = 23;
	const unsigned maxMinute = 59;


	std::string convertTo2Digits(unsigned num) {
		if (num < 10) return "0" + std::to_string(num);
		return std::to_string(num);
	}

	unsigned long long toSeconds(unsigned hour, unsigned minute) {
		return minute * 60 + hour * 60 * 60;
	}

	unsigned long long toSeconds(unsigned day, unsigned month, int year) {
		day = day * 60 * 60 * 24;
		month = month * day;
		year = year * month;

		return year + month + day;
	}
}