#include "Login.h"

void Login::Init()
{
	cout << "Please login(l) or register(r).\tcommand>";
	string command;
	char cmd;
	cin >> command;
	
	while (command.size() != 1)
	{
		RuntimeError::Error(INPUTERRORCOMMAND);
		cout << "Please login(l) or register(r).\tcommand>";
		cin >> command;
	}
	cmd = command[0];
	while (cmd != 'l' && cmd != 'r')
	{
		RuntimeError::Error(INPUTNOCOMMAND);
		cout << "Please login(l) or register(r).\tcommand>";
		cin >> cmd;
	}
	switch (cmd)
	{
	case 'l':
		Signin();
		break;
	case 'r':
		Register();
		break;
	default:
		break;
	}
}

void Login::Signin()
{
	string user_name;
	string password;
	cout << "Please input your user name:\t";
	cin >> user_name;
	cout << "Please input your password:\t";
	password = HidePassword();
	cout << password;
}

void Login::Register()
{

}

void Login::ReadInfo()
{
	ifstream accounts("Account.txt", ios::in);
	while (accounts.peek() != EOF)
	{
		string user_name;
		string password;
		accounts >> user_name >> password;
		account_info.insert(make_pair(user_name, password));
	}
}

string Login::HidePassword()
{
	char password[16];
	char c;
	int cnt = 0;
	while ((c = _getch() != '\r'))
	{
		if (cnt < sizeof(password) / sizeof(char))
		{
			password[cnt++] = c;
			putchar('*');
		}
		else if (cnt > 0 && c == '\b')
		{
			cnt--;
			putchar('\b');
			putchar(' ');
			putchar('\b');
		}
	}
	printf("\n");
	password[cnt] = '\0';
	return password;
}