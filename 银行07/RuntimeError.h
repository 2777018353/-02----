#pragma once

#define INPUTERRORCOMMAND	0	  // ����������ȷ(�ַ���������1)
#define INPUTNOCOMMAND		1	  // ������������

#define CREATEACCOUNTERROR	2	  // �����˻�ʧ��
								  
#define DATEINPUTINVAILD	3	  // ���ڸ�ʽ����
#define DATEORDERERROR		4	  // ��������˳�����
								  
#define CHANGEPREVIOUSDATE	5	  // ��ǰ�ı�����
#define CHANGEDATEINVAILD	6	  // �ı�����ڲ�����
								  
#define WITHDRAWOVERBALANCE 7	  // ��Ҫȡ���Ľ��������
#define WITHDRAWERROR		8	  // ȡ�����Ϊ����
#define DEPOSITERROR		9	  // ������Ϊ����
								  
#define ACCOUNTNOEXIST		10	  // �˻�������

#include <iostream>
#include <stdexcept>
using namespace std;

class RuntimeError
{
public:
	static void Error(int error_type);
};

