#pragma once

#define INPUTERRORCOMMAND	0	  // 输入的命令不正确(字符个数多于1)
#define INPUTNOCOMMAND		1	  // 输入的命令不存在
#define CREATEACCOUNTERROR	2	  // 创建账户失败
#define RATEERROR			3	  // 利率不正确
#define DATEINPUTINVAILD	4	  // 日期格式错误
#define DATEORDERERROR		5	  // 日期输入顺序错误
#define CHANGEPREVIOUSDATE	6	  // 向前改变日期
#define CHANGEDATEINVAILD	7	  // 改变的日期不存在
#define WITHDRAWOVERBALANCE 8	  // 将要取出的金额大于余额
#define WITHDRAWERROR		9	  // 取出金额为负数
#define DEPOSITERROR		10	  // 存入金额为负数
#define ACCOUNTNOEXIST		11	  // 账户不存在
#define USERNOMATCHPASSWORD	12	  // 账号密码不匹配

#include <iostream>
#include <stdexcept>
using namespace std;

class RuntimeError
{
public:
	static void Error(int error_type);
};

