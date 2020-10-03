#pragma once

#define DATEINPUTINVAILD 0
#define DATEORDERERROR 1

#define CHANGEPREVIOUSDATE 2
#define CHANGEDATEINVAILD 3

#include <iostream>
#include <stdexcept>
using namespace std;

class RuntimeError
{
public:
	static void Error(int error_type);
};

