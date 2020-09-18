#include "SavingsAccount.h"

void SavingsAccount::record(Date date, double amount, string desc)
{
	acc.getAccumulation(date);	// �ۻ��߸�������ۼ�
	amount = floor(amount * 100 + 0.5) / 100;//����С�������λ
	setBalance(amount);	// �������
	acc.setValue(getBalance());	// �����ۼ��߱���
	total += amount;
	date.show();
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
	setBalance(getBalance() - amount);	// �������
	acc.setValue(getBalance());	// �����ۼ��߱���
	total -= amount;
	date.show();
	cout << "\t#" << getId() << "\t" << -amount << "\t" << getBalance() << '\t' << desc << endl;
}

// ����
void SavingsAccount::settle(const Date& date)
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
