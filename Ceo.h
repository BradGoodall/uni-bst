#pragma once
#include "Employee.h"

class Ceo : public Employee
{
public:
	int annualBonus;

	Ceo(int salary, string name, int annualBonus);
	void outputEarnings();
	void outputJobDescription();
};

