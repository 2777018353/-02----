//step5.cpp

#include <iostream>

#include <vector>

#include <algorithm>

#include <fstream>

#include "CreditAccount.h"

#include "SavingsAccount.h"

using namespace std;



struct deleter {

	template <class T> void operator () (T* p) { delete p; }

};

void restore(Date date, vector<Account*> accounts);

int main() {

	Date date(2008, 11, 1);//起始日期

	vector<Account*> accounts;//创建账户数组，元素个数为0

	ofstream text("commands.txt", ios::app);

	restore(date, accounts);

	cout << "(a)add account (d)deposit (w)withdraw (s)show (c)change day (n)next month (q)query (e)exit" << endl;

	char cmd;

	do {

		//显示日期和总金额

		date.show();

		cout << "\tTotal: " << Account::getTotal() << "\tcommand> ";

		// return 0; // 提交时删除注释...(我也不懂你既不输入又不结束为啥就说我运行时间过长?Ծ‸Ծ)

		char type;

		int index, day;

		double amount, credit, rate, fee;

		string id, desc;

		Account* account;

		Date date1, date2;



		cin >> cmd;

		// 如果还未停止输入
		if (cmd != 'e')
		{
			text << cmd << ' ';
		}

		switch (cmd) {

		case 'a'://增加账户

			cin >> type >> id;
			text << type << ' ' << id << ' ';

			if (type == 's') {

				cin >> rate;
				text << rate << '\n' << endl;

				account = new SavingsAccount(date, id, rate);

			}

			else {

				cin >> credit >> rate >> fee;
				text << credit << ' ' << rate << ' ' << fee << '\n' << endl;

				account = new CreditAccount(date, id, credit, rate, fee);

			}

			accounts.push_back(account);

			break;

		case 'd'://存入现金

			cin >> index >> amount;


			getline(cin, desc);
			text << desc << '\n' << endl;

			accounts[index]->deposit(date, amount, desc);

			break;

		case 'w'://取出现金

			cin >> index >> amount;
			text << index << ' ' << amount << ' ';

			getline(cin, desc);
			text << desc << '\n' << endl;

			accounts[index]->withdraw(date, amount, desc);

			break;

		case 's'://查询各账户信息

			for (size_t i = 0; i < accounts.size(); i++) {

				cout << "[" << i << "] ";

				accounts[i]->show();

				cout << endl;

			}

			break;

		case 'c'://改变日期

			cin >> day;
			text << day << '\n' << endl;

			if (day < date.getDay())

				cout << "You cannot specify a previous day";

			else if (day > date.getMaxDay())

				cout << "Invalid day";

			else

				date = Date(date.getYear(), date.getMonth(), day);

			break;

		case 'n'://进入下个月

			if (date.getMonth() == 12)

				date = Date(date.getYear() + 1, 1, 1);

			else

				date = Date(date.getYear(), date.getMonth() + 1, 1);

			for (vector<Account*>::iterator iter = accounts.begin(); iter != accounts.end(); ++iter)

				(*iter)->settle(date);

			break;

		case 'q'://查询一段时间内的账目

			date1 = Date::read();

			date2 = Date::read();

			Account::query(date1, date2);

			break;

		}

	} while (cmd != 'e');





	for_each(accounts.begin(), accounts.end(), deleter());

	return 0;

}

void restore(Date date, vector<Account*> accounts)
{
	ifstream text("commands.txt");

	char cmd;

	while (text.peek() != EOF)
	{
		char type;

		int index, day;

		double amount, credit, rate, fee;

		string id, desc;

		Account* account;

		Date date1, date2;



		text >> cmd;

		switch (cmd) {

		case 'a'://增加账户

			text >> type >> id;

			if (type == 's') {

				text >> rate;

				account = new SavingsAccount(date, id, rate);

			}

			else {

				text >> credit >> rate >> fee;

				account = new CreditAccount(date, id, credit, rate, fee);

			}

			accounts.push_back(account);

			break;

		case 'd'://存入现金

			text >> index >> amount;

			getline(text, desc);

			accounts[index]->deposit(date, amount, desc);

			break;

		case 'w'://取出现金

			text >> index >> amount;

			getline(text, desc);

			accounts[index]->withdraw(date, amount, desc);

			break;

		case 's'://查询各账户信息

			for (size_t i = 0; i < accounts.size(); i++) {

				cout << "[" << i << "] ";

				accounts[i]->show();

				cout << endl;

			}

			break;

		case 'c'://改变日期

			text >> day;

			if (day < date.getDay())

				cout << "You cannot specify a previous day";

			else if (day > date.getMaxDay())

				cout << "Invalid day";

			else

				date = Date(date.getYear(), date.getMonth(), day);

			break;

		case 'n'://进入下个月

			if (date.getMonth() == 12)

				date = Date(date.getYear() + 1, 1, 1);

			else

				date = Date(date.getYear(), date.getMonth() + 1, 1);

			for (vector<Account*>::iterator iter = accounts.begin(); iter != accounts.end(); ++iter)

				(*iter)->settle(date);

			break;

		case 'q'://查询一段时间内的账目

			date1 = Date::read();

			date2 = Date::read();

			Account::query(date1, date2);

			break;

		}

	}
}