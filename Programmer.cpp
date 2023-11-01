#include "Programmer.h"

Programmer::Programmer(int salary, string name, int bugsCreated, int bugsFixed)
{
	this->salary = salary;
	this->name = name;
	this->bugsCreated = bugsCreated;
	this->bugsFixed = bugsFixed;
}

void Programmer::outputJobDescription()
{
	cout << "Job Description: Writes code, attempts to fix bugs, creates more bugs." << endl
		<< "Bugs Fixed: " << bugsFixed << endl << "Bugs Created: " << bugsCreated << endl;
}
