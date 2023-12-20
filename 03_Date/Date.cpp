#include "Date.h"

void Date::setDate(const int& day, const int& month, const int& year)
{
	this->year = year;
	setmonth(month);
	setday(day);
}

void Date::displayDate() const
{
	cout << (day < 10 ? "0" : "") << day << ".";
	cout << (month < 10 ? "0" : "") << month << ".";
	cout <<  year;
}

void Date::incrementDate()
{
	this->day++;
	if (this->day > maxDay()) {
		this->day = 1;
		this->month++;
	}
	if (this->month > 12) {
		this->month = 1;
		this->year++;
	}
}

void Date::decrementDate()
{
	this->day--;
	if (this->day == 0) {
		this->month--;
		if (this->month == 0) {
			this->year--;
			this->month = 12;
		}
		this->day = maxDay();
	}
	
	
}

void Date::setmonth(const int& month)
{
	if (month < 0 || month > 12) {
		cout << "Error month" << endl;
		this->month = 1;
	}
	else
	{
		this->month = month;
	}
}

void Date::setday(const int& day)
{
	if (day < 0 || day > maxDay()) {
		cout << "Error day" << endl;
		this->day = 1;
	}
	else {
		this->day = day;
	}
}

int Date::maxDay() const
{
	switch (this->month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		return (this->year % 4 == 0 && this->year % 100 != 0 || this->year % 400 == 0 ? 29 : 28);
	}
}
