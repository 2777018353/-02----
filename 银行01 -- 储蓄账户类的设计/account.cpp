#include "account.h"
// 构造函数
SavingsAccount::SavingsAccount(int date, int id, double rate)
{
	this->id = id;
	balance = 0;
	this->rate = rate;
	lastDate = date;
	accumulation = 0;
	std::cout << date << '\t' << '#' << getId() << " is created" << std::endl;
}

// 存入现金
void SavingsAccount::deposit(int date, double amount)
{
	record(date, amount); // 计算目前为止本金加利息
}

//计算至今利息
void SavingsAccount::settle(int date) {
	double interest = accumulate(date) * rate / 365;
	if (interest != 0)
		record(date, interest);
	accumulation = 0;
}

//获得到指定日期为止的存款金额按日累积值
void SavingsAccount::record(int date, double amount)
{
	accumulation = accumulate(date);
	lastDate = date;
	amount = floor(amount * 100 + 0.5) / 100;	// 保留小数点后两位
	balance += amount;
	std::cout << date << "\t#" << id << "\t" << amount << "\t" << balance << std::endl;
}

// 取出现金
void SavingsAccount::withdraw(int date, double amount)
{
	accumulation = accumulate(date);
	lastDate = date;
	amount = floor(amount * 100 + 0.5) / 100;	// 保留小数点后两位
	balance -= amount;
	std::cout << date << '\t' << '#' << id << '\t' << -amount << '\t' << balance << std::endl;
}

void SavingsAccount::show() const
{
	std::cout << '#' << getId() << '\t' << "Balance: " << getBalance();
}