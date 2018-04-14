#pragma once
#ifndef Date_h
#define Date_h
#include <iostream>
#include <string>
using namespace std;
class Date1
{
	friend ostream &operator<<(ostream &, const Date1 &);
public:
	Date1(int m1 = 1, int d1 = 1, int y1 = 1900);
	void setDate1(int, int, int);
	bool leapYear1() const;
	bool endOfMonth1() const;
	int getMonth1() const
	{
		return month1;
	}
	int getDay1() const
	{
		return day1;
	}
	int getYear1() const
	{
		return year1;
	}
	string getMonthString1() const;
	void operator+=(int);
	Date1& operator=(Date1 other1);
private:
	int month1;
	int day1;
	int year1;
	static const int days1[];
	static const string monthName1[];
	void helpIncrement1();
};
#endif
