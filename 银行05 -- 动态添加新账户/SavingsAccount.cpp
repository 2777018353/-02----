#include "SavingsAccount.h"

void SavingsAccount::record(Date date, double amount, string desc)
{
	acc.getAccumulation(date);	// �ۻ��߸�������ۼ�
	amount = floor(amount * 100 + 0.5) / 100;//����С�������λ
	setBalance(amount);	// �������
	acc.setValue(getBalance());	// �����ۼ��߱���
	total += amount;
	date.show();
	recordMap.insert(make_pair(date, AccountRecord(date, this, amount, getBalance(), desc)));
	cout << "\t#" << getId() << "\t" << amount << "\t" << getBalance() << '\t' << desc << endl;
}

// ���
void SavingsAccount::deposit(Date date, double amount, string desc)
{
	record(date, amount, desc);
}

// ȡ��
void SavingsAccount::withdraw(Date date, double amount, string desc)
{
	acc.getAccumulation(date);	// �ۻ��߸�������ۼ�
	amount = floor(amount * 100 + 0.5) / 100;//����С�������λ
	setBalance(-amount);	// �������
	acc.setValue(getBalance());	// �����ۼ��߱���
	total -= amount;
	date.show();
	recordMap.insert(make_pair(date, AccountRecord(date, this, -amount, getBalance(), desc)));
	cout << "\t#" << getId() << "\t" << -amount << "\t" << getBalance() << '\t' << desc << endl;
}

// ����
void SavingsAccount::settle(const Date& date)
{
	if (date.getMonth() == 1 && date.getDay() == 1)
	{
		double interest;
		if (Date::isLeapYear(date.getYear() - 1))
		{
			interest = acc.accumulate(date) * getRate() / 366;
		}
		else
		{
			interest = acc.accumulate(date) * getRate() / 365;
		}
		if (interest != 0)
		{
			record(date, interest);
		}
		acc.reset();
	}
}

void SavingsAccount::show()
{
	cout << getId() << '\t' << "Balance: " << getBalance();
}