#pragma once
#include <iostream>
#include <cmath>
class SavingsAccount //���������˻���
{
private:
	int id;				//�˺�
	double balance;		//���
	double rate;		//����������
	int lastDate;		//�ϴα������ʱ��
	double accumulation;	//�����ۼ�֮��
	//��õ�ָ������Ϊֹ�Ĵ������ۻ�ֵ��
	void record(int date, double amount);
	//������Ϣ ��
	double accumulate(int date) const {
		return accumulation + balance * (date - lastDate);
	} 
public:
	//���캯��
	SavingsAccount(int date, int id, double rate); 
	// ����˻�id
	int getId() const { return id; }
	// ����˻����
	double getBalance() const { return balance; }
	// ��ô���������
	double getRate() const { return rate; }
	//�����ֽ�
	void deposit(int date, double amount); 
	//ȡ���ֽ�
	void withdraw(int date, double amount); 
	//������Ϣ��ÿ��1��1�յ���һ�θú���
	void settle(int date); 
	//��ʾ�˻���Ϣ
	void show() const; 
};

