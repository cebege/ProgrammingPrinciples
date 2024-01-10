#include <iostream>

using namespace std;

enum class Day
{
	MONDAY = 1, START_OF_WEEK = MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY, END_OF_WEEK = SUNDAY // from 0 to 6
};

Day operator++(Day& d)
{
	return d = (d == Day::END_OF_WEEK) ? Day::MONDAY : static_cast<Day>(static_cast <int>(d) + 1);
	// if the day is the end of the week, this will return Monday, if not, it will review the day of the week;
	// it will cast the day into a number, add one, and cast it back to a day for the return function.
}

ostream& operator << (ostream& left, const Day& right)
{
	switch (right)
	{
	case Day::MONDAY:
		left << "Monday";
		break;
	case Day::TUESDAY:
		left << "Tuesday";
		break;
	case Day::WEDNESDAY:
		left << "Wednesday";
		break;
	case Day::THURSDAY:
		left << "Thursday";
		break;
	case Day::FRIDAY:
		left << "Friday";
		break;
	case Day::SATURDAY:
		left << "Saturday";
	case Day::SUNDAY:
		left << "Sunday";
		break;
	default:
		left << "Invalid";
		break;
	}
	return left;
}

int main() {

	Day today = Day::FRIDAY;

	if (today < Day::SATURDAY)
		cout << "It is a weekday." << endl;

	++today;
	
	if (today > Day::FRIDAY)
		cout << "It is the weekend." << endl;

	++today;

	cout << today << endl;

	++today;

	cout << today << endl;

	return 0;
}

