#pragma once
#include "Account.h"
#include "Accumulator.h"
class SavingsAccount :  // 建立储蓄账户类
    public Account      // 公共继承Account
{
private:
    Accumulator acc;    // 累加器(用于将余额按日累加)
    double rate;        // 年利率

public:
    // 构造函数
    SavingsAccount(Date date, string id, double rate) :acc(date), Account(id), rate(rate) 
    {
        date.show();
        cout << "\t#" << getId() << " created" << endl;
    };
    
    // 获得年利率
    double getRate() { return rate; }
    
    // 处理交易
    virtual void record(Date date, double amount, string desc = "interest");
    // 存入现金
    virtual void deposit(Date date, double amount, string desc);
    // 取出现金
    virtual bool withdraw(Date date, double amount, string desc);
    // 每年1月1日结算
    virtual void settle(const Date& date);
    // 格式化输出
    virtual void show();
    // 提醒还款
    virtual void RepaymentReminder();
};

