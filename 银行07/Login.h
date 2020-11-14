#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <conio.h>
#include "RuntimeError.h"
using namespace std;

class Login // ������¼��
{
private:
	map<string, string> account_info;	// �û���Ϣ
	map<string, string>::iterator iter;	// ������
	string user_name;					// �û���
	string password;					// ����

public:
	// ���캯��
	Login() :user_name(""), password(""), iter(account_info.begin()) {};

	// get����
	string getUserName() { return user_name; }

	// ��ʼ��
	bool Init();
	// ��¼
	bool Signin();
	// ע��
	void Register();
	// ��ȡ��Ϣ
	void ReadInfo();
	// ��������
	void HidePassword();
};

