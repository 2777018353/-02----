#include "RuntimeError.h"

void RuntimeError::Error(int error_type)
{
	switch (error_type)
	{
	case DATEINPUTINVAILD:
		cout << "The date entered does not exist. Please enter again." << endl;
	case DATEORDERERROR:
		cout << "Please cheak the dates if in the wrong order." << endl;
	case CHANGEPREVIOUSDATE:
		cout << "You cannot specify a previous day" << endl;
	case CHANGEDATEINVAILD:
		cout << "This is a invaild day. Please input again."<<endl;
	default:
		break;
	}
}