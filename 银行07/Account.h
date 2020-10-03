#pragma once
#include "Date.h"
#include "RuntimeError.h"
#include <string>
#include <math.h>
#include <map>

extern double total;

class Account
{
private:
	string id;
	double balance;

public:
	// ���캯��(���� id)
	Account(string id) :id(id) { balance = 0; };

	// ��̬��Ա, key: ��Ŀ������ value: ��Ŀ����ϸ����
	// static multimap<Date, AccountRecord> recordMap;

	// get����
	string getId() { return id; }
	double getBalance() { return balance; }

	// �������(ԭ����������amount)
	void setBalance(double amount) { balance += amount; }

	// ��ָ��ʱ����ڲ�ѯ
	static void query(Date start, Date end);

	virtual void record(Date date, double amount, string desc = "interest") = 0;
	virtual void deposit(Date date, double amount, string desc) = 0;
	virtual bool withdraw(Date date, double amount, string desc) = 0;
	virtual void settle(const Date& date) = 0;
	virtual void show();

	static double getTotal() { return total; }
};

class AccountRecord				// ��Ŀ��¼
{
private:
	Date date;					// ����
	Account* account;			// �˻�
	double amount;				// �����ȡ���Ľ��
	double balance;				// ���
	std::string desc;			// ����

public:
	AccountRecord(Date date, Account* account, double amount, double balance, std::string desc);

	void show();
};

extern multimap<Date, AccountRecord> recordMap;