#include "Accumulator.h"

// 每次调用时计算至今的累计金额
// 参数 date: 更新日期
// 返回 累计金额
double Accumulator::accumulate(const Date& date)
{
	return accumulation + value * lastDate.distance(date);
}

// 更新累计金额并获取
// 参数 date: 更新日期
// 返回 累计金额
double Accumulator::getAccumulation(const Date& date)
{
	accumulation = accumulate(date);
	lastDate = date;
	return accumulation;
}

// 重置累计金额(月费或年费更新之后调用)
void Accumulator::reset()
{
	accumulation = 0;
}