#include "Date.h"
using namespace std;

int main()
{
	Date d1(2008, 11, 5);
	Date d2(2008, 12, 5);

	cout << CalcDays(d1, d2);
}