#include "SavingsAccount.h"

void SavingsAccount::record(Date date, double amount, string desc)
{
	acc.getAccumulation(date);	// 累积者更新余额累计
	amount = floor(amount * 100 + 0.5) / 100;//保留小数点后两位
	setBalance(amount);	// 更新余额
	acc.setValue(getBalance());	// 更新累计者本金
	total += amount;
	date.show();
	recordMap.insert(make_pair(date, AccountRecord(date, this, amount, getBalance(), desc)));
	cout << "\t#" << getId() << "\t" << amount << "\t" << getBalance() << '\t' << desc << endl;
}

// 存款
void SavingsAccount::deposit(Date date, double amount, string desc)
{
	record(date, amount, desc);
}

// 取款
void SavingsAccount::withdraw(Date date, double amount, string desc)
{
	acc.getAccumulation(date);	// 累积者更新余额累计
	amount = floor(amount * 100 + 0.5) / 100;//保留小数点后两位
	setBalance(-amount);	// 更新余额
	acc.setValue(getBalance());	// 更新累计者本金
	total -= amount;
	date.show();
	recordMap.insert(make_pair(date, AccountRecord(date, this, -amount, getBalance(), desc)));
	cout << "\t#" << getId() << "\t" << -amount << "\t" << getBalance() << '\t' << desc << endl;
}

// 结算
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