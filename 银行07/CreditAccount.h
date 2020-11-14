#pragma once
#include "Account.h"
#include "Accumulator.h"
class CreditAccount :	  // 建立信用卡账户类
    public Account		  // 公共继承Account
{
private:
	Accumulator acc;      // 累积者
	double rate;          // 利息率(存钱(正余额)不会有利息。欠款(负余额)需要支付利息，且按日欠款计息，不考虑免息期。)
	double credit;        // 信用额度
	double fee;           // 年费(每年需要交一次年费(每年1月1日扣年费))

public:
	// 构造函数
	CreditAccount(Date date, string id, double credit, double rate, double fee) :acc(date), Account(id), credit(credit), rate(rate), fee(fee)
	{
		date.show();
		cout << "\t#" << getId() << " created" << endl;
	};

	// get 方法
	double getRate() { return rate; }
	double getCredit() { return credit; }
	double getFee() { return fee; }

	// 处理交易
	virtual void record(Date date, double amount, string desc = "interest");
	// 存入现金
	virtual void deposit(Date date, double amount, string desc);
	// 取出现金
	virtual bool withdraw(Date date, double amount, string desc);
	// 每月1日处理利息
	virtual void settle(const Date& date);
	// 格式化输出
	virtual void show();
	// 处理年费
	void settleFee(Date date);
	// 提醒还款
	virtual void RepaymentReminder();
};

