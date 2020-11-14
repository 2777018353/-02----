#include "account.h"
// ���캯��
SavingsAccount::SavingsAccount(int date, int id, double rate)
{
	this->id = id;
	balance = 0;
	this->rate = rate;
	lastDate = date;
	accumulation = 0;
	std::cout << date << '\t' << '#' << getId() << " is created" << std::endl;
}

// �����ֽ�
void SavingsAccount::deposit(int date, double amount)
{
	record(date, amount); // ����ĿǰΪֹ�������Ϣ
}

//����������Ϣ
void SavingsAccount::settle(int date) {
	double interest = accumulate(date) * rate / 365;
	if (interest != 0)
		record(date, interest);
	accumulation = 0;
}

//��õ�ָ������Ϊֹ�Ĵ������ۻ�ֵ
void SavingsAccount::record(int date, double amount)
{
	accumulation = accumulate(date);
	lastDate = date;
	amount = floor(amount * 100 + 0.5) / 100;	// ����С�������λ
	balance += amount;
	std::cout << date << "\t#" << id << "\t" << amount << "\t" << balance << std::endl;
}

// ȡ���ֽ�
void SavingsAccount::withdraw(int date, double amount)
{
	accumulation = accumulate(date);
	lastDate = date;
	amount = floor(amount * 100 + 0.5) / 100;	// ����С�������λ
	balance -= amount;
	std::cout << date << '\t' << '#' << id << '\t' << -amount << '\t' << balance << std::endl;
}

void SavingsAccount::show() const
{
	std::cout << '#' << getId() << '\t' << "Balance: " << getBalance();
}