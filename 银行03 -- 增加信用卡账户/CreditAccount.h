#pragma once
#include "Account.h"
#include "Accumulator.h"
class CreditAccount :
	public Account
{
private:
	Accumulator acc;      // 累积者
	double balance;       // 余额
	double rate;          // 利息率(存钱(正余额)不会有利息。欠款(负余额)需要支付利息，且按日欠款计息，不考虑免息期。)
	double credit;        // 信用额度
	double fee;           // 年费(每年需要交一次年费(每年1月1日扣年费))

public:
	CreditAccount(Date date, string id, double credit, double rate, double fee) :acc(date), Account(id), credit(credit), rate(rate), fee(fee)
	{
		balance = 0;
		date.show();
		cout << "\t#" << getId() << " created" << endl;
	};

	// get 方法
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

