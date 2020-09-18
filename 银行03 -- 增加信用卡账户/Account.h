#pragma once
#include "Date.h"
#include <math.h>
extern double total;

class Account
{
private:
	string id;			  // 账户
	double balance;		  // 余额(本金)

public:
	// 构造函数(参数 id)
	Account(string id) :id(id) { balance = 0; };

	string getId() { return id; }
	double getBalance() { return balance; }
	void setBalance(double amount) { balance += amount; }
	static double getTotal() { return total; }
	void show();
};

