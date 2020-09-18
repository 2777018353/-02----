#pragma once
#include <iostream>
using namespace std;
class Date
{
private:
	int year;
	int month;
	int day;
	int totalDays;
public:
	Date() :year(0), month(0), day(0) {};
	Date(int year, int month, int day);

	// get 方法
	int getYear() const { return year; }
	int getMonth() const { return month; }
	int getDay() const { return day; }
	int getMaxDay() const { return totalDays; }	

	// 判断是否是闰年
	static bool isLeapYear(int year) {return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);}
	// 格式化输出
	void show() const { cout << year << '-' << month << '-' << day; }
	// 计算与目标日期之间的天数
	int distance(Date date) const;

};

