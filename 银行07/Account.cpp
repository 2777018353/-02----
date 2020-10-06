#include "Account.h"

double total = 0;

void Account::show()
{
	cout << id << "\tBalance: " << balance;
}

multimap<Date, AccountRecord> recordMap;

typedef pair<Date, AccountRecord> RECORD;

struct cmp
{
	bool operator()(RECORD const & a, RECORD const & b) const
	{
		if (a.second.amount < b.second.amount)
		{
			return true;
		}
		else if (a.second.amount == b.second.amount)
		{
			return a.first < b.first;
		}
		return false;
	}
};

void Account::QuaryByDate(Date start, Date end)
{
	for (auto record : recordMap)
	{
		if (start < record.first && record.first < end)
		{
			record.second.show();
		}
	}
}

void Account::QueryByAmount(Date start, Date end)
{
	multimap<Date, AccountRecord, cmp> temp;
	for (auto record : recordMap)
	{
		if (start < record.first && record.first < end)
		{
			temp.insert(record);
		}
	}
	for (auto record : temp)
	{
		record.second.show();
	}
}

AccountRecord::AccountRecord(Date date, Account* account, double amount, double balance, std::string desc)
{
	this->date = date;
	this->account = account;
	this->amount = amount;
	this->balance = balance;
	this->desc = desc;
}

void AccountRecord::show()
{
	date.show();
	cout << "\t#" << account->getId() << '\t' << amount << '\t' << balance << endl;
}
