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
}