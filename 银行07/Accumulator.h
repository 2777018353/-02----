#pragma once
#include "Date.h"
class Accumulator	// 建立累加器类
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
	// 按日累加金额
	double accumulate(const Date& date);
	// 更新并获取累计金额
	double getAccumulation(const Date& date);
	// 获取上次更新日期
	Date getLastDate() { return lastDate; }
	// 设定余额
	void setValue(double amount) { value = amount; }
	// 重置累计金额(月费或年费更新之后调用)
	void reset();
};

