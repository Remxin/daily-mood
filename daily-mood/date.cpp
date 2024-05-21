namespace date {
	unsigned maxDay = 31;
	unsigned maxMonth = 12;
	unsigned maxHour = 23;
	unsigned maxMinute = 59;

	typedef struct {
		unsigned day;
		unsigned month;
		int year;
	} DATE;

	typedef struct {
		unsigned hour;
		unsigned minute;
	} TIME;

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