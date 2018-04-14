#include <iostream>
#include "Date.h"
#include <string>

const int Date1::days1[] =
{
	0, 31, 28,
	31, 30, 31,
	30, 31, 31,
	30, 31, 30, 31
};

const string Date1::monthName1[] =
{ "", "January", "February", "March",
"April", "May", "June", "July",
"August", "September",
"October", "November", "December"
};

Date1::Date1(int m1, int d1, int y1)
{
	setDate1(m1, d1, y1);
}

void Date1::setDate1(int mm1, int dd1, int yy1)
{
	month1 = (mm1 >= 1 && mm1 <= 12) ? mm1 : 1;
	year1 = (yy1 >= 1900 && yy1 <= 2100) ? yy1 : 1900;

	if (month1 == 2 && leapYear1())
		day1 = (dd1 >= 1 && dd1 <= 29) ? dd1 : 1;
	else
		day1 = (dd1 >= 1 && dd1 <= days1[month1]) ? dd1 : 1;
}

void Date1::operator+=(int additionalDays1)
{
	for (int i1 = 0; i1 < additionalDays1; i1++)
		helpIncrement1();
}

bool Date1::leapYear1() const
{
	if (year1 % 400 == 0 || (year1 % 100 != 0 && year1 % 4 == 0))
		return true;
	else
		return false;
}

bool Date1::endOfMonth1() const
{
	if (month1 == 2 && leapYear1())
		return (day1 == 29);
	else
		return (day1 == days1[month1]);
}

void Date1::helpIncrement1()
{
	if (!endOfMonth1())
	{
		day1++;
	}
	else if (month1 < 12)
	{
		day1 = 1;
		++month1;
	}
	else
	{
		day1 = 1;
		month1 = 1;
		++year1;
	}
}

Date1& Date1::operator=(Date1 other1)
{
	day1 = other1.day1;
	month1 = other1.month1;
	year1 = other1.year1;
	return *this;
}

ostream &operator<<(ostream &output1, const Date1 &d1)
{
	output1 << d1.monthName1[d1.month1] << ' ' << d1.day1 << ", " << d1.year1;
	return output1;
}

string Date1::getMonthString1() const
{
	return monthName1[month1];
}
