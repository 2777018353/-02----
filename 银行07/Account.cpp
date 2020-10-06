#include "Account.h"

double total = 0;

void Account::show()
{
	cout << id << "\tBalance: " << balance;
}

multimap<Date, AccountRecord> recordMap;

typedef pair<Date, AccountRecord> RECORD;

bool cmp(pair<Date, AccountRecord>& a, pair<Date, AccountRecord>& b)
{
	if (abs(a.second.getAmount()) > abs(b.second.getAmount()))
	{
		return true;
	}
	else if (a.second.getAmount() == b.second.getAmount())
	{
		return a.second.getDate() < b.second.getDate();
	}
	else
	{
		return false;
	}
}

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
	vector<pair<Date, AccountRecord>> temp;
	for (auto record : recordMap)
	{
		if (start < record.first && record.first < end)
		{
			temp.push_back(pair<Date, AccountRecord>(record.first, record.second));
		}
	}
	sort(temp.begin(), temp.end(), cmp);
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
