#pragma once
#include "Date.h"
class Accumulator	// �����ۼ�����
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
	// �����ۼӽ��
	double accumulate(const Date& date);
	// ���²���ȡ�ۼƽ��
	double getAccumulation(const Date& date);
	// ��ȡ�ϴθ�������
	Date getLastDate() { return lastDate; }
	// �趨���
	void setValue(double amount) { value = amount; }
	// �����ۼƽ��(�·ѻ���Ѹ���֮�����)
	void reset();
};

