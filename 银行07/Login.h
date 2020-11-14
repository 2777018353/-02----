#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <conio.h>
#include "RuntimeError.h"
using namespace std;

class Login // 建立登录类
{
private:
	map<string, string> account_info;	// 用户信息
	map<string, string>::iterator iter;	// 迭代器
	string user_name;					// 用户名
	string password;					// 密码

public:
	// 构造函数
	Login() :user_name(""), password(""), iter(account_info.begin()) {};

	// get方法
	string getUserName() { return user_name; }

	// 初始化
	bool Init();
	// 登录
	bool Signin();
	// 注册
	void Register();
	// 读取信息
	void ReadInfo();
	// 隐藏密码
	void HidePassword();
};

