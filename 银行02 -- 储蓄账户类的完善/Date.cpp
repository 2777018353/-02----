#include "Date.h"
void Date::show()
{
	std::cout << year << '-' << month << '-' << day;
}

int CalcDays(Date& d1, Date& d2)
{
	int days_count = 0;
	int m[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	// 日期在同一年
	if (d2.year - d1.year == 0)
	{
		// 如果是闰年
		if ((d1.year % 4 == 0 && d1.year % 100 != 0) || (d1.year % 400 == 0))
		{
			m[2] = 29;
		}
		// 日期不在同一月
		for (int i = d1.month; i < d2.month; i++)
		{
			if (i == d1.month)
			{
				days_count = m[i] - d1.day;
				continue;
			}
			days_count += m[i];
		}
		days_count += d2.day;
		// 日期在同一月
		if (d1.month == d2.month)
		{
			return d2.day - d1.day;
		}
		return days_count;
	}
	else
	{
		for (int i = d1.year; i < d2.year; i++)
		{
			if (isLeap(i))
			{
				days_count += 366;
			}
			else
			{
				days_count += 365;
			}
		}
		if (isLeap(d1.year))
		{
			m[2] = 29;
		}
		for (int i = 1; i < d1.month; i++)
		{
			days_count -= m[i];
		}
		days_count -= d1.day;
		if (isLeap(d2.year))
		{
			m[2] = 29;
		}
		else
		{
			m[2] = 28;
		}
		for (int i = 1; i < d2.month; i++)
		{
			days_count += m[i];
		}
		days_count += d2.day;
		return days_count;
	}
}

bool isLeap(int date)
{
	return (date % 4 == 0 && date % 100 != 0 || date % 400 == 0);
}