#pragma once
#include "Date.h"
class Accumulator
{
private:
	Date lastDate;			   // 上次更新日期
	double value;			   // 余额(从账户中每次更新时获取)
	double accumulation;	   // 余额的每日累加


public:
	// 构造函数 参数 Date
	Accumulator(Date date) :lastDate(date)
	{
		value = 0;
		accumulation = 0;
	}
	double accumulate(const Date& date);
	double getAccumulation(const Date& date);
	Date getLastDate() { return lastDate; }
	void setValue(double amount) { value = amount; }
	void reset();
};

