#pragma once
#include <iostream>
class Date
{
private:
	int year;		  // ��
	int month;		  // ��
	int day;		  // ��

public:
	Date() :year(0), month(0), day(0) {}
	int getYear() { return year; }
	Date(int year, int month, int day) :year(year), month(month), day(day) {}
	void  show();
	friend int  CalcDays(Date& d1, Date& d2);
};

bool isLeap(int date);