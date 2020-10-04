#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <conio.h>
#include "RuntimeError.h"
using namespace std;

class Login
{
private:
	map<string, string> account_info;
	map<string, string>::iterator iter;
	string user_name;
	string password;

public:
	Login() :user_name(""), password(""), iter(account_info.begin()) {};
	void Init();
	bool Signin();
	void Register();
	void ReadInfo();
	void HidePassword();
};

