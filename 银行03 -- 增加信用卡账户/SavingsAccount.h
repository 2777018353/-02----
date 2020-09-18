#pragma once
#include "Account.h"
#include "Accumulator.h"
class SavingsAccount :
    public Account
{
private:
    Accumulator acc;    // �ۼ���
    double rate;        // ������
public:
    // ���캯�� date����acc, id����Account
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

