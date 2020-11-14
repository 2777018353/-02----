#include "RuntimeError.h"

void RuntimeError::Error(int error_type)
{
	switch (error_type)
	{
	case INPUTERRORCOMMAND:
		cout << "Please enter a command with only one letter." << endl;
		break;
	case INPUTNOCOMMAND:
		cout << "Please enter the correct commend." << endl;
		break;
	case DATEINPUTINVAILD:
		cout << "The date entered does not exist. Please enter again." << endl;
		break;
	case DATEORDERERROR:
		cout << "Please cheak the dates if in the wrong order." << endl;
		break;
	case CHANGEPREVIOUSDATE:
		cout << "You cannot specify a previous day" << endl;
		break;
	case CHANGEDATEINVAILD:
		cout << "This is a invaild day. Please input again." << endl;
		break;
	case WITHDRAWOVERBALANCE:
		cout << "Your account does not have enough money." << endl;
		break;
	case WITHDRAWERROR:
		cout << "You cannot withdraw negative amounts" << endl;
		break;
	case DEPOSITERROR:
		cout << "You cannot deposit negative amounts." << endl;
		break;
	case ACCOUNTNOEXIST:
		cout << "This account does exist. Please cheak and enter again." << endl;
		break;
	case CREATEACCOUNTERROR:
		cout << "We only provide SavingsAccount(s) or CreditAccount(c) service." << endl;
		break;
	case USERNOMATCHPASSWORD:
		cout << "User name and password do not match." << endl;
		break;
	case RATEERROR:
		cout << "Please input correct rate." << endl;
	default:
		break;
	}
}