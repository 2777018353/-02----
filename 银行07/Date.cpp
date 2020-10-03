#include "Date.h"

int monthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

int Date::distance(Date date) const
{
	int days_count = 0;
	int m[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	// 日期在同一年
	if (date.year - year == 0)
	{
		// 如果是闰年
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			m[2] = 29;
		}
		// 日期不在同一月
		for (int i = month; i < date.month; i++)
		{
			if (i == month)
			{
				days_count = m[i] - day;
				continue;
			}
			days_count += m[i];
		}
		days_count += date.day;
		// 日期在同一月
		if (month == date.month)
		{
			return date.day - day;
		}
		return days_count;
	}
	else
	{
		for (int i = year; i < date.year; i++)
		{
			if (isLeapYear(i))
			{
				days_count += 366;
			}
			else
			{
				days_count += 365;
			}
		}
		if (isLeapYear(year))
		{
			m[2] = 29;
		}
		for (int i = 1; i < month; i++)
		{
			days_count -= m[i];
		}
		days_count -= day;
		if (isLeapYear(date.year))
		{
			m[2] = 29;
		}
		else
		{
			m[2] = 28;
		}
		for (int i = 1; i < date.month; i++)
		{
			days_count += m[i];
		}
		days_count += date.day;
		return days_count;
	}
}


int Date::getMaxDay() const
{
	if (month == 2 && isLeapYear(year))
	{
		return 29;
	}
	return monthDay[month];
}

bool Date::operator <(const Date& date)const
{
	if (this->year < date.year)
	{
		return true;
	}
	else if (this->year == date.year && this->month < date.month)
	{
		return true;
	}
	else if (this->year == date.year && this->month == date.month && this->day < date.day)
	{
		return true;
	}

	return false;
}

Date Date::read()
{
	int year, month, day;
	
	scanf_s("%d/%d/%d", &year, &month, &day);

	if (ifDate(Date(year, month, day)))
	{
		return Date(year, month, day);
	}
	else
	{
		return Date(-1, -1, -1);
	}
}

bool Date::ifDate(const Date& date)
{
	// 如果月份大于12 或者 天数大于该月天数
	if (date.year <= 0 || date.month > 12 || date.day > monthDay[date.month])
	{
		return false;
	}
	return true;
}