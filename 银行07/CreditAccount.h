#pragma once
#include "Account.h"
#include "Accumulator.h"
class CreditAccount :
    public Account
{
private:
	Accumulator acc;      // �ۻ���
	double rate;          // ��Ϣ��(��Ǯ(�����)��������Ϣ��Ƿ��(�����)��Ҫ֧����Ϣ���Ұ���Ƿ���Ϣ����������Ϣ�ڡ�)
	double credit;        // ���ö��
	double fee;           // ���(ÿ����Ҫ��һ�����(ÿ��1��1�տ����))

public:
	CreditAccount(Date date, string id, double credit, double rate, double fee) :acc(date), Account(id), credit(credit), rate(rate), fee(fee)
	{
		date.show();
		cout << "\t#" << getId() << " created" << endl;
	};

	// get ����
	double getRate() { return rate; }
	double getCredit() { return credit; }
	double getFee() { return fee; }

	virtual void record(Date date, double amount, string desc = "interest");
	virtual void deposit(Date date, double amount, string desc);
	virtual bool withdraw(Date date, double amount, string desc);
	virtual void settle(const Date& date);
	virtual void show();
	void settleFee(Date date);
	virtual void RepaymentReminder();
};

