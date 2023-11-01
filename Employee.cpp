#include "Employee.h"

Employee::Employee()
{
	this->salary = 0;
	this->name = "<PlaceHolder>";
}

Employee::Employee(int salary, string name)
{
	this->salary = salary;
	this->name = name;
}

void Employee::outputEarnings()
{
	cout << "Salary: " << salary << endl;
}

void Employee::outputJobDescription()
{
	cout << "Job Description: <Placeholder>" << endl;
}
