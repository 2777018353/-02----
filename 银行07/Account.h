#pragma once
#include "Date.h"
#include "RuntimeError.h"
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>

extern double total;

class Account // �����˻���
{
private:
	string id;			// �û�id
	double balance;		// �˻����

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
	static void QuaryByDate(Date start, Date end);
	// ��ָ��ʱ����ڰ�����С��ѯ
	static void QueryByAmount(Date start, Date end);

	// �麯��
	virtual void record(Date date, double amount, string desc = "interest") = 0;
	virtual void deposit(Date date, double amount, string desc) = 0;
	virtual bool withdraw(Date date, double amount, string desc) = 0;
	virtual void settle(const Date& date) = 0;
	virtual void show();
	virtual void RepaymentReminder() = 0;

	// ��ȡ�����˻��ܽ��
	static double getTotal() { return total; }
};

class AccountRecord				// ������Ŀ��¼��
{
public:
	Date date;					// ����
	Account* account;			// �˻�
	double amount;				// �����ȡ���Ľ��
	double balance;				// ���
	std::string desc;			// ����

public:
	// ���캯��
	AccountRecord(Date date, Account* account, double amount, double balance, std::string desc);

	// get����
	Account* getAccount() { return account; }
	Date getDate() { return date; }
	double getAmount() { return amount; }

	// ��ʽ�����
	void show();
};

extern multimap<Date, AccountRecord> recordMap;