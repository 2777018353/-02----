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
	Date() :year(0), month(0), day(0) { totalDays = 0; };
	Date(int year, int month, int day) :year(year), month(month), day(day)
	{
		totalDays = 0;
	}

	// ���� < �����
	bool operator < (const Date& date) const;

	// get ����
	int getYear() const { return year; }
	int getMonth() const { return month; }
	int getDay() const { return day; }
	int getMaxDay() const;

	// ��������Ƿ���ȷ
	static bool ifDate(const Date& date);
	// �ж��Ƿ�������
	static bool isLeapYear(int year) {return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);}
	// ��ʽ�����
	void show() const { cout << year << '-' << month << '-' << day; }
	// ������Ŀ������֮�������
	int distance(Date date) const;
	// �������ڲ���ʼ��
	static Date read();
};

