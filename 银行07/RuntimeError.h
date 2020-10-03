#pragma once

#define INPUTERRORCOMMAND	0	  // 输入的命令不正确(字符个数多于1)
#define INPUTNOCOMMAND		1	  // 输入的命令不存在

#define CREATEACCOUNTERROR	2	  // 创建账户失败
								  
#define DATEINPUTINVAILD	3	  // 日期格式错误
#define DATEORDERERROR		4	  // 日期输入顺序错误
								  
#define CHANGEPREVIOUSDATE	5	  // 向前改变日期
#define CHANGEDATEINVAILD	6	  // 改变的日期不存在
								  
#define WITHDRAWOVERBALANCE 7	  // 将要取出的金额大于余额
#define WITHDRAWERROR		8	  // 取出金额为负数
#define DEPOSITERROR		9	  // 存入金额为负数
								  
#define ACCOUNTNOEXIST		10	  // 账户不存在

#include <iostream>
#include <stdexcept>
using namespace std;

class RuntimeError
{
public:
	static void Error(int error_type);
};

