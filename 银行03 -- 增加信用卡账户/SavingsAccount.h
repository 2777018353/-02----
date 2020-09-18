#pragma once
#include "Account.h"
#include "Accumulator.h"
class SavingsAccount :
    public Account
{
private:
    Accumulator acc;    // 累计者
    double rate;        // 年利率
public:
    // 构造函数 date构造acc, id构造Account
    SavingsAccount(Date date, string id, double rate) : acc(date), Account(id), rate(rate)
    {
        date.show();
        cout << '\t' << '#' << id << " created" << endl;
    };

    double getRate() { return rate; }
    void record(Date date, double amount, string desc = "interest");
    void deposit(Date date, double amount, string desc);
    void withdraw(Date date, double amount, string desc);
    void settle(Date date);
};

