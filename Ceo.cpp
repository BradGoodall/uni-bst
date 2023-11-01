#include "Ceo.h"

Ceo::Ceo(int salary, string name, int annualBonus)
{
	this->salary = salary;
	this->name = name;
	this->annualBonus = annualBonus;
}

void Ceo::outputEarnings()
{
	cout << "Salary: " << salary << endl;
	cout << "Annual Bonus: " << annualBonus << endl;
}

void Ceo::outputJobDescription()
{
	cout << "Job Description: Runs the company, sometimes shows up to work." << endl;
}
