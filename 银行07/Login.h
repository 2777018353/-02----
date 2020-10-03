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
public:
	void Init();
	void Signin();
	void Register();
	void ReadInfo();
	string HidePassword();
};

