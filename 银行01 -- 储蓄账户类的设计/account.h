#pragma once
#include <iostream>
#include <cmath>
class SavingsAccount //建立储蓄账户类
{
private:
	int id;				//账号
	double balance;		//余额
	double rate;		//存款的年利率
	int lastDate;		//上次变更余额的时期
	double accumulation;	//余额按日累加之和
	//获得到指定日期为止的存款金额按日累积值①
	void record(int date, double amount);
	//计算利息 ②
	double accumulate(int date) const {
		return accumulation + balance * (date - lastDate);
	} 
public:
	//构造函数
	SavingsAccount(int date, int id, double rate); 
	// 获得账户id
	int getId() const { return id; }
	// 获得账户余额
	double getBalance() const { return balance; }
	// 获得存款的年利率
	double getRate() const { return rate; }
	//存入现金
	void deposit(int date, double amount); 
	//取出现金
	void withdraw(int date, double amount); 
	//结算利息，每年1月1日调用一次该函数
	void settle(int date); 
	//显示账户信息
	void show() const; 
};

