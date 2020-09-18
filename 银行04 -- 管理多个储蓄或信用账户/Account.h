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
	// ���캯��(���� id)
	Account(string id) {};

	// get����
	string getId() { return id; }
	double getBalance() { return balance; }

	// �������(ԭ����������amount)
	void setBalance(double amount) { balance += amount; }

	virtual void record(Date date, double amount, string desc = "interest") = 0;
	virtual void deposit(Date date, double amount, string desc) = 0;
	virtual void withdraw(Date date, double amount, string desc) = 0;
	virtual void settle(const Date& date) = 0;
	void show();

	static double getTotal() { return total; }
};