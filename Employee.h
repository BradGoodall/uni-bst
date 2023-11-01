#pragma once
#include <iostream>
#include <string>

using namespace std;
class Employee
{
public:
	int salary; //The employee's annual salary
	string name; //The employee's name

	Employee();
	Employee(int salary, string name);

	virtual void outputEarnings();
	virtual void outputJobDescription();
};

