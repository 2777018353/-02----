#include "account.h"

SavingsAccount::SavingsAccount(Date date, string id, double rate) :lastDate(date), id(id), rate(rate)
{
	balance = 0;
	accumulation = 0;
	date.show();
	cout << '\t' << '#' << id << " created" << endl;
}

void SavingsAccount::record(Date date, double amount, string operation)
{
	accumulation = accumulate(date);
	lastDate = date;
	amount = floor(amount * 100 + 0.5) / 100;//保留小数点后两位
	balance += amount;
	total += amount;
	date.show();
	cout << "\t#" << id << "\t" << amount << "\t" << balance << '\t' << operation << endl;
}

void SavingsAccount::record(Date date, double amount)
{
	accumulation = accumulate(date);
	lastDate = date;
	amount = floor(amount * 100 + 0.5) / 100;
	balance += amount;
	total += amount;
	date.show();
	cout << '\t' << '#' << id << '\t' << amount << '\t' << balance << "\tinterest" << endl;
}

void SavingsAccount::deposit(Date date, double amount, string operation)
{
	record(date, amount, operation);
}

void SavingsAccount::withdraw(Date date, double amount, string operation)
{
	accumulation = accumulate(date);
	lastDate = date;
	amount = floor(amount * 100 + 0.5) / 100;//保留小数点后两位
	balance -= amount;
	total -= amount;
	date.show();
	cout << "\t#" << id << "\t" << -amount << "\t" << balance << '\t' << operation << endl;
}

void SavingsAccount::settle(Date date)
{
	double interest;
	if (isLeap(date.getYear() - 1))
	{
		interest = accumulate(date) * rate / 366;
	}
	else
	{
		interest = accumulate(date) * rate / 365;
	}
	if (interest != 0)
		record(date, interest);
	accumulation = 0;
}

void SavingsAccount::show()
{
	cout << id << "\tBalance: " << balance;
}


double SavingsAccount::getTotal()
{
	return total;
}