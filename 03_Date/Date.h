#pragma once
#include <iostream>
using namespace std;
class Date
{
public:
	Date():Date(1,1,2000)
	{

	}
	Date(const int& day, const int& month, const int& year)
	{
		setDate(day, month, year);
	}
	void setDate(const int& day, const int& month, const int& year);
	void displayDate() const;
	void incrementDate();
	void decrementDate();
	void setmonth(const int& month);
	void setday(const int& day);
private:
	int day, month, year;
	int maxDay()const;
};

