#include "CreditAccount.h"

void CreditAccount::record(Date date, double amount, string desc)
{
	acc.getAccumulation(date);
	amount = floor(amount * 100 + 0.5) / 100;//����С�������λ
	setBalance(-amount);	// �������
	acc.setValue(getBalance());	// �����ۼ��߱���
	total -= amount;
	date.show();
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
	cout << "\t#" << getId() << "\t" << amount << "\t" << getBalance() << '\t' << desc << endl;
}

// ȡ��
void CreditAccount::withdraw(Date date, double amount, string desc)
{
	record(date, amount, desc);
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
	balance -= fee;
	total -= fee;
	date.show();
	cout << "\t#" << getId() << '\t' << -fee << '\t' << balance << "\tannual fee" << endl;
}

// ��ʽ�����
void CreditAccount::show()
{
	double temp_credit;
	if (balance < 0)
	{
		temp_credit = credit + balance;
	}
	else
	{
		temp_credit = credit;
	}
	cout << getId() << "\tBalance: " << balance << "\tAvailable credit:" << temp_credit;
}