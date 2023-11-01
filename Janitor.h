#pragma once
#include "Employee.h"
class Janitor : public Employee
{
public:
	Janitor(int salary, string name);
	void outputJobDescription();
};

