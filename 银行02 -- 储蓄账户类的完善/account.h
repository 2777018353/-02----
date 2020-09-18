#pragma once
#include <string>
#include <math.h>
#include "Date.h"
using namespace std;
class SavingsAccount
{
private:
	string id;				//账户 
	double balance;			//余额
	double rate;			//年利率
	Date lastDate;			//上次更新时间
	double accumulation;	//余额的累计
	// 每天加一次本金
	double accumulate(Date& date)
	{
		return accumulation + balance * CalcDays(lastDate, date);
	}
	// 更新一波
	void record(Date date, double amount, string operation);
	void record(Date date, double amount);

public:
	SavingsAccount(Date date, string id, double rate);

	// get 方法
	// 获得账户id
	string getId() const { return id; }
	// 获得账户余额
	double getBalance() const { return balance; }
	// 获得存款的年利率
	double getRate() const { return rate; }

	// 存入现金
	void deposit(Date date, double amount, string operation);
	// 取出现金
	void withdraw(Date date, double amount, string operation);
	// 结算
	void settle(Date date);
	// 格式化输出
	void show();
	// 所有账户总金额
	static double getTotal();
};

static double total = 0;

