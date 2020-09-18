#pragma once
#include "Date.h"
#include <string>
#include <math.h>
extern double total;
class Account
{
private:
	string id;
	double balance;
	
public:
	// 构造函数(参数 id)
	Account(string id) {};

	// get方法
	string getId() { return id; }
	double getBalance() { return balance; }

	// 更新余额(原来的余额加上amount)
	void setBalance(double amount) { balance += amount; }

	virtual void record(Date date, double amount, string desc = "interest") = 0;
	virtual void deposit(Date date, double amount, string desc) = 0;
	virtual void withdraw(Date date, double amount, string desc) = 0;
	virtual void settle(const Date& date) = 0;
	void show();

	static double getTotal() { return total; }
};