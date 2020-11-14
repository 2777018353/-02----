#pragma once
#include "Date.h"
#include "RuntimeError.h"
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>

extern double total;

class Account // 建立账户类
{
private:
	string id;			// 用户id
	double balance;		// 账户余额

public:
	// 构造函数(参数 id)
	Account(string id) :id(id) { balance = 0; };

	// 静态成员, key: 账目的日期 value: 账目的详细内容
	// static multimap<Date, AccountRecord> recordMap;

	// get方法
	string getId() { return id; }
	double getBalance() { return balance; }

	// 更新余额(原来的余额加上amount)
	void setBalance(double amount) { balance += amount; }

	// 在指定时间段内查询
	static void QuaryByDate(Date start, Date end);
	// 在指定时间段内按金额大小查询
	static void QueryByAmount(Date start, Date end);

	// 虚函数
	virtual void record(Date date, double amount, string desc = "interest") = 0;
	virtual void deposit(Date date, double amount, string desc) = 0;
	virtual bool withdraw(Date date, double amount, string desc) = 0;
	virtual void settle(const Date& date) = 0;
	virtual void show();
	virtual void RepaymentReminder() = 0;

	// 获取所有账户总金额
	static double getTotal() { return total; }
};

class AccountRecord				// 建立账目记录类
{
public:
	Date date;					// 日期
	Account* account;			// 账户
	double amount;				// 存入或取出的金额
	double balance;				// 余额
	std::string desc;			// 描述

public:
	// 构造函数
	AccountRecord(Date date, Account* account, double amount, double balance, std::string desc);

	// get方法
	Account* getAccount() { return account; }
	Date getDate() { return date; }
	double getAmount() { return amount; }

	// 格式化输出
	void show();
};

extern multimap<Date, AccountRecord> recordMap;