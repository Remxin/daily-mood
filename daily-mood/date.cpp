#include "date.h"
#include <chrono>

namespace date {
	const unsigned maxDay = 31;
	const unsigned maxMonth = 12;
	const unsigned maxHour = 23;
	const unsigned maxMinute = 59;


	std::string getTodaysDateStr() {
		auto now = std::chrono::system_clock::now();
		std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
		std::tm localTime;
		localtime_s(&localTime, &currentTime);
		//std::tm localTime = *std::localtime(&currentTime);

		DATE retDate;
		retDate.year = localTime.tm_year + 1900;
		retDate.month = localTime.tm_mon + 1;
		retDate.day = localTime.tm_mday;

		return std::to_string(localTime.tm_year + 1900) + std::to_string(localTime.tm_mon + 1) + std::to_string(localTime.tm_mday);
	}

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