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

	int monthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

public:
	Date() :year(0), month(0), day(0) { totalDays = 0; };
	Date(int year, int month, int day) :year(year), month(month), day(day)
	{
		totalDays = 0;
	}

	// 重载 < 运算符
	bool operator < (const Date& date) const;

	// get 方法
	int getYear() const { return year; }
	int getMonth() const { return month; }
	int getDay() const { return day; }
	int getMaxDay() const;

	// 判断是否是闰年
	static bool isLeapYear(int year) {return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);}
	// 格式化输出
	void show() const { cout << year << '-' << month << '-' << day; }
	// 计算与目标日期之间的天数
	int distance(Date date) const;
	// 读入日期并初始化
	static Date read();
};

