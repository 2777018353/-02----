#pragma once
#include "Date.h"
class Accumulator
{
private:
	Date lastDate;			   // �ϴθ�������
	double value;			   // ���(���˻���ÿ�θ���ʱ��ȡ)
	double accumulation;	   // ����ÿ���ۼ�


public:
	// ���캯�� ���� Date
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

