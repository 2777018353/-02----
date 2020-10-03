#include "Accumulator.h"

// ÿ�ε���ʱ����������ۼƽ��
// ���� date: ��������
// ���� �ۼƽ��
double Accumulator::accumulate(const Date& date)
{
	return accumulation + value * lastDate.distance(date);
}

// �����ۼƽ���ȡ
// ���� date: ��������
// ���� �ۼƽ��
double Accumulator::getAccumulation(const Date& date)
{
	accumulation = accumulate(date);
	lastDate = date;
	return accumulation;
}

// �����ۼƽ��(�·ѻ���Ѹ���֮�����)
void Accumulator::reset()
{
	accumulation = 0;
}