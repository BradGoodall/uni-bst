#include "Janitor.h"

Janitor::Janitor(int salary, string name)
{
	this->salary = salary;
	this->name = name;
}

void Janitor::outputJobDescription()
{
	cout << "Job Description: Cleans everything, hardest worker, underpaid." << endl;
}
