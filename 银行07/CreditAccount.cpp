#include "CreditAccount.h"

void CreditAccount::record(Date date, double amount, string desc)
{
	acc.getAccumulation(date);
	amount = floor(amount * 100 + 0.5) / 100;//����С�������λ
	setBalance(-amount);	// �������
	acc.setValue(getBalance());	// �����ۼ��߱���
	total -= amount;
	date.show();
	recordMap.insert(make_pair(date, AccountRecord(date, this, -amount, getBalance(), desc)));
	cout << "\t#" << getId() << "\t" << -amount << "\t" << getBalance() << '\t' << desc << endl;
}

// ���
void CreditAccount::deposit(Date date, double amount, string desc)
{
	acc.getAccumulation(date);
	amount = floor(amount * 100 + 0.5) / 100;//����С�������λ
	setBalance(amount);
	acc.setValue(getBalance());	// �����ۼ��߱���
	total += amount;
	date.show();
	recordMap.insert(make_pair(date, AccountRecord(date, this, amount, getBalance(), desc)));
	cout << "\t#" << getId() << "\t" << amount << "\t" << getBalance() << '\t' << desc << endl;
}

// ȡ�� �ɹ�����true ʧ�ܷ���false
bool CreditAccount::withdraw(Date date, double amount, string desc)
{
	if (amount > getBalance() + credit)
	{
		RuntimeError::Error(WITHDRAWOVERBALANCE);
		return false;
	}
	record(date, amount, desc);
	return true;
}

// ����
void CreditAccount::settle(const Date& date)
{
	double interest;

	interest = acc.accumulate(date) * getRate();

	if (interest != 0)
	{
		record(date, -interest);
	}
	if (date.getMonth() == 1)	// �����
	{
		settleFee(date);
	}
	acc.reset();
}

// �������
void CreditAccount::settleFee(Date date)
{
	setBalance(-fee);
	total -= fee;
	acc.setValue(getBalance());
	date.show();
	cout << "\t#" << getId() << '\t' << -fee << '\t' << getBalance() << "\tannual fee" << endl;
}

// ��ʽ�����
void CreditAccount::show()
{
	double temp_credit;
	if (getBalance() < 0)
	{
		temp_credit = credit + getBalance();
	}
	else
	{
		temp_credit = credit;
	}
	cout << getId() << "\tBalance: " << getBalance() << "\tAvailable credit:" << temp_credit;
}

// ��������
void CreditAccount::RepaymentReminder()
{
	if (getBalance() < 0)
	{
		cout << "PAY ATTENTION! " << getId() << " need to repay " << -getBalance() << "$." << endl;
	}
	return;
}