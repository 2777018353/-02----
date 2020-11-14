#pragma once
#include "Account.h"
#include "Accumulator.h"
class SavingsAccount :  // ���������˻���
    public Account      // �����̳�Account
{
private:
    Accumulator acc;    // �ۼ���(���ڽ������ۼ�)
    double rate;        // ������

public:
    // ���캯��
    SavingsAccount(Date date, string id, double rate) :acc(date), Account(id), rate(rate) 
    {
        date.show();
        cout << "\t#" << getId() << " created" << endl;
    };
    
    // ���������
    double getRate() { return rate; }
    
    // ������
    virtual void record(Date date, double amount, string desc = "interest");
    // �����ֽ�
    virtual void deposit(Date date, double amount, string desc);
    // ȡ���ֽ�
    virtual bool withdraw(Date date, double amount, string desc);
    // ÿ��1��1�ս���
    virtual void settle(const Date& date);
    // ��ʽ�����
    virtual void show();
    // ���ѻ���
    virtual void RepaymentReminder();
};

