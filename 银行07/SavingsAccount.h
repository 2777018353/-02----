#pragma once
#include "Account.h"
#include "Accumulator.h"
class SavingsAccount :
    public Account
{
private:
    Accumulator acc;
    double rate;

public:
    SavingsAccount(Date date, string id, double rate) :acc(date), Account(id), rate(rate) 
    {
        date.show();
        cout << "\t#" << getId() << " created" << endl;
    };
    
    double getRate() { return rate; }
    
    virtual void record(Date date, double amount, string desc = "interest");
    virtual void deposit(Date date, double amount, string desc);
    virtual bool withdraw(Date date, double amount, string desc);
    virtual void settle(const Date& date);
    virtual void show();
};

