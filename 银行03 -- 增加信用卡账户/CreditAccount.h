#pragma once
#include "Account.h"
#include "Accumulator.h"
class CreditAccount :
	public Account
{
private:
	Accumulator acc;      // �ۻ���
	double balance;       // ���
	double rate;          // ��Ϣ��(��Ǯ(�����)��������Ϣ��Ƿ��(�����)��Ҫ֧����Ϣ���Ұ���Ƿ���Ϣ����������Ϣ�ڡ�)
	double credit;        // ���ö��
	double fee;           // ���(ÿ����Ҫ��һ�����(ÿ��1��1�տ����))

public:
	CreditAccount(Date date, string id, double credit, double rate, double fee) :acc(date), Account(id), credit(credit), rate(rate), fee(fee)
	{
		balance = 0;
		date.show();
		cout << "\t#" << getId() << " created" << endl;
	};

	// get ����
	double getRate() { return rate; }
	double getCredit() { return credit; }
	double getFee() { return fee; }

	void record(Date date, double amount, string desc = "interest");
	void deposit(Date date, double amount, string desc);
	void withdraw(Date date, double amount, string desc);
	void settle(Date date);
	void settleFee(Date date);
	void show();
};

