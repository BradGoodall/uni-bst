#pragma once
#include "Employee.h"

class Programmer : public Employee
{
public:
	int bugsCreated;
	int bugsFixed;

	Programmer(int salary, string name, int bugsCreated, int bugsFixed);
	void outputJobDescription();
};