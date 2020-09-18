#pragma once
#include "Date.h"
#include <math.h>
extern double total;

class Account
{
private:
	string id;			  // �˻�
	double balance;		  // ���(����)

public:
	// ���캯��(���� id)
	Account(string id) :id(id) { balance = 0; };

	string getId() { return id; }
	double getBalance() { return balance; }
	void setBalance(double amount) { balance += amount; }
	static double getTotal() { return total; }
	void show();
};

