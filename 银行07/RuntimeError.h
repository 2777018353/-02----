#pragma once

#define INPUTERRORCOMMAND	0	  // ����������ȷ(�ַ���������1)
#define INPUTNOCOMMAND		1	  // ������������
#define CREATEACCOUNTERROR	2	  // �����˻�ʧ��
#define RATEERROR			3	  // ���ʲ���ȷ
#define DATEINPUTINVAILD	4	  // ���ڸ�ʽ����
#define DATEORDERERROR		5	  // ��������˳�����
#define CHANGEPREVIOUSDATE	6	  // ��ǰ�ı�����
#define CHANGEDATEINVAILD	7	  // �ı�����ڲ�����
#define WITHDRAWOVERBALANCE 8	  // ��Ҫȡ���Ľ��������
#define WITHDRAWERROR		9	  // ȡ�����Ϊ����
#define DEPOSITERROR		10	  // ������Ϊ����
#define ACCOUNTNOEXIST		11	  // �˻�������
#define USERNOMATCHPASSWORD	12	  // �˺����벻ƥ��

#include <iostream>
#include <stdexcept>
using namespace std;

class RuntimeError
{
public:
	static void Error(int error_type);
};

