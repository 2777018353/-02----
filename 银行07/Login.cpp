#include "Login.h"

bool Login::Init()
{
	ReadInfo();
	cout << "Please login(l), register(r) or exit(e).\tcommand>";
	string command;
	char cmd;
	cin >> command;

	while (command.size() != 1)
	{
		RuntimeError::Error(INPUTERRORCOMMAND);
		cout << "Please login(l), register(r) or exit(e).\tcommand>";
		cin >> command;
	}
	cmd = command[0];
	while (cmd != 'l' && cmd != 'r' && cmd != 'e')
	{
		RuntimeError::Error(INPUTNOCOMMAND);
		cout << "Please login(l) or register(r).\tcommand>";
		cin >> cmd;
	}
	switch (cmd)
	{
	case 'l':
		while (!Signin()) 
		{
			RuntimeError::Error(USERNOMATCHPASSWORD);
			user_name = "";
			password = "";
		}
		break;
	case 'r':
		Register();
		break;
	case 'e':
		return 0;
	default:
		break;
	}
	return 1;
}

bool Login::Signin()
{
	cout << "Please input your user name:\t";
	cin >> user_name;
	cout << "Please input your password:\t";
	HidePassword();
	iter = account_info.find(user_name);
	if (iter == account_info.end() || iter->second != password)
	{
		return false;
	}
	return true;
}

void Login::Register()
{
	cout << "Please input your user name:\t";
	cin >> user_name;
	cout << "Please input your password:\t";
	HidePassword();
	ofstream accounts("Account.txt", ios::app);
	accounts << user_name << ' ' << password << '\n' << endl;
	accounts.close();
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
	accounts.close();
}

void Login::HidePassword()
{
	char c;
	while (true)
	{
		c = _getch();
		if (c != char(13))
		{
			switch (c)
			{
			case 8:
				if (password.size() != 0)
				{
					cout << "\b \b";
					password = password.substr(0, password.length() - 1);
				}
				break;
			default:
				cout << "*";
				password += c;
				break;
			}
		}
		else
		{
			break;
		}
	}
	cout << endl;
}