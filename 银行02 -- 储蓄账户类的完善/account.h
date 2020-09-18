#pragma once
#include <string>
#include <math.h>
#include "Date.h"
using namespace std;
class SavingsAccount
{
private:
	string id;				//�˻� 
	double balance;			//���
	double rate;			//������
	Date lastDate;			//�ϴθ���ʱ��
	double accumulation;	//�����ۼ�
	// ÿ���һ�α���
	double accumulate(Date& date)
	{
		return accumulation + balance * CalcDays(lastDate, date);
	}
	// ����һ��
	void record(Date date, double amount, string operation);
	void record(Date date, double amount);

public:
	SavingsAccount(Date date, string id, double rate);

	// get ����
	// ����˻�id
	string getId() const { return id; }
	// ����˻����
	double getBalance() const { return balance; }
	// ��ô���������
	double getRate() const { return rate; }

	// �����ֽ�
	void deposit(Date date, double amount, string operation);
	// ȡ���ֽ�
	void withdraw(Date date, double amount, string operation);
	// ����
	void settle(Date date);
	// ��ʽ�����
	void show();
	// �����˻��ܽ��
	static double getTotal();
};

static double total = 0;

