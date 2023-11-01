/*
	ADS103 - Assessment 3
	Brad Goodall
*/

#include <iostream>
#include <string>
#include <time.h> //Time for seeding rand
#include <list> //Linked Lists
#include "BST.h" //Binary Search Tree
#include "AVL.h" //Balanced Binary Search Tree
#include "Node.h" //Node for the trees
#include "BinaryMaxHeap.h" //Binary Max Heap Structure
#include <chrono> //Used for timing
#include "Employee.h" //Employee Base Class
#include "Ceo.h" //CEO Class
#include "Programmer.h"//Programmer Class
#include "Janitor.h" //Janitor Class

using namespace std;
using namespace chrono;

void runTask1(int numbersToAdd);
void populateStructures(int numbersToAdd, list<Node>& myList, BST& myBST, AVL& myAVL);
void numberSearch(list<Node> myList, BST myBST, AVL myAVL, int num);
void runTask2();

int main()
{
	//Amount of numbers to add in Task 1 (Assessment Requires: 150000)
	int numbersToAdd = 10000;

	//Display the main menu
	bool exit = false;
	while (!exit)
	{
		//Show the header
		system("cls");
		cout << "####################################################" << endl;
		cout << "\tADS103 - Assessment 3 - Brad Goodall" << endl;
		cout << "####################################################" << endl;

		//Show the options
		cout << "Select an option" << endl
			<< "\t[1] Run Task 1 - Data Structure Searching" << endl
			<< "\t[2] Run Task 2 - Max Heap with Polymorphic Data" << endl
			<< "\t[3] Exit" << endl;

		//Receive an option and check validity
		int choice = 0;
		while ((choice != 1) && (choice != 2) && (choice != 3))
		{
			cin >> choice;
			if (choice == 1)
				runTask1(numbersToAdd);
			else if (choice == 2)
				runTask2();
			else if (choice == 3)
				exit = true;
			else
				cout << "Invalid Option, try again." << endl;
		}
	}

	return 0;
}

void runTask1(int numbersToAdd)
{
	//Settings
	bool showMessages = false; //Show the cout messages used for testing

	//Seed the rand function
	srand(time(NULL));

	steady_clock::time_point testAdd; //These ones are used for testing
	steady_clock::time_point testEnd;

	//Create our data structures
	list<Node> myList;
	BST myBST;
	AVL myAVL;

	myAVL.displayRotations = false;

	//Show the header
	system("cls");
	cout << "#################################################" << endl;
	cout << "\tTask 1 - Data Structure Searching" << endl;
	cout << "#################################################" << endl;

	cout << "Adding " << numbersToAdd << " numbers... (This may take a while)" << endl;

	//Populate the data structures
	populateStructures(numbersToAdd, myList, myBST, myAVL);

	//Output some info about the AVL tree
	if (showMessages)
	{
		cout << "AVL inorder traversal:" << endl;
		myAVL.inOrderTraversal(myAVL.root);
		cout << "\nAVL ROOT : " << myAVL.root->number << endl;
	}

	//Display the menu
	bool exit = false;
	while (!exit)
	{
		//Show the options
		cout << endl;
		cout << "Select an option" << endl
			<< "\t[1] Search for a number in all data structures" << endl
			<< "\t[2] Exit" << endl;

		//Receive an option and check validity
		int choice = 0;
		while ((choice != 1) && (choice != 2))
		{
			cin >> choice;
			if (choice == 1)
			{
				cout << "Enter a number to find (1-100000) : ";
				int num;
				cin >> num;
				numberSearch(myList, myBST, myAVL, num);
			}
			else if (choice == 2)
				exit = true;
			else
				cout << "Invalid Option, try again." << endl;
		}
	}
}

void populateStructures(int numbersToAdd, list<Node>& myList, BST& myBST, AVL& myAVL)
{
	//Set-up our time variables
	steady_clock::time_point begin;
	steady_clock::time_point end;

	//Populate our data structures
	begin = steady_clock::now();
	for (int i = 0; i < numbersToAdd; i++)
	{
		int n = (rand() + rand() + rand() + rand()) % 100000; //Add some rands together since it caps at 32767
		myList.push_back(Node(n));
		myBST.insert(new Node(n));
		myAVL.insert(new Node(n));
	}
	end = steady_clock::now();

	//Output the time taken
	int durationMin = duration_cast<minutes>(end - begin).count();
	int durationSec = duration_cast<seconds>(end - begin).count();
	int durationMill = duration_cast<milliseconds>(end - begin).count();
	if (durationMill < 1000)
		cout << "Completed - Time Taken : " << durationMill << "[ms]" << endl;
	else if (durationMill < 60000)
		cout << "Completed - Time Taken : " << durationSec % 60 << "[sec] " << durationMill % 1000 << "[ms]" << endl;
	else
		cout << "Completed - Time Taken : " << durationMin % 60 << "[min] " << durationSec % 60 << "[sec] " << durationMill % 1000 << "[ms]" << endl;
}

void numberSearch(list<Node> myList, BST myBST, AVL myAVL, int num)
{
	//Set-up our time variables
	steady_clock::time_point begin;
	steady_clock::time_point end;

	//List Search
	cout << "Starting List Search..." << endl;
	begin = steady_clock::now(); //Start Timer
	bool found = false;
	for (list<Node>::iterator i = myList.begin(); i != myList.end(); i++)
	{
		if (i->number == num) //If we found the number
		{
			cout << num << " Found!" << endl;
			found = true;
			end = steady_clock::now(); //End Timer
			int durationList = duration_cast<milliseconds>(end - begin).count();
			cout << "List Search Completed - Time Taken : " << durationList << "[ms]" << endl << endl;
		}
	}
	if (!found) //If we couldn't find it
	{
		cout << num << " was not found!" << endl;
		end = steady_clock::now(); //End Timer
		int durationList = duration_cast<milliseconds>(end - begin).count();
		cout << "List Search Completed - Time Taken : " << durationList << "[ms]" << endl << endl;
	}

	//BST Search
	cout << "Starting BST Search..." << endl;
	begin = steady_clock::now(); //Start Timer
	Node* nPtr1 = myBST.search(num, false);
	end = steady_clock::now(); //End Timer
	int durationBST = duration_cast<milliseconds>(end - begin).count();
	cout << "BST Search Completed - Time Taken : " << durationBST << "[ms]" << endl << endl;

	//AVL Search
	cout << "Starting AVL Search..." << endl;
	begin = steady_clock::now(); //Start Timer
	Node* nPtr2 = myAVL.search(num, false);
	end = steady_clock::now(); //End Timer
	int durationAVL = duration_cast<milliseconds>(end - begin).count();
	cout << "AVL Search Completed - Time Taken : " << durationAVL << "[ms]" << endl << endl;
}

void runTask2()
{
	//Show the header
	system("cls");
	cout << "#######################################################" << endl;
	cout << "\tTask 2 - Max Heap with Polymorphic Data" << endl;
	cout << "#######################################################" << endl;

	//Create our Binary Max Heap
	BinaryMaxHeap staffMembers;

	//Add all of the staff members to it
	staffMembers.insert(new Programmer(80000, "Bob", 100, 4000));
	staffMembers.insert(new Programmer(65000, "Tony", 5600, 5));
	staffMembers.insert(new Programmer(57000, "Jeff", 450, 200));
	staffMembers.insert(new Programmer(90000, "Enrico", 3000, 350));
	staffMembers.insert(new Programmer(69000, "Amanda", 0, 2));
	staffMembers.insert(new Programmer(55000, "Jessica", 200, 150));
	staffMembers.insert(new Ceo(120000, "Adam", 10000));
	staffMembers.insert(new Janitor(40000, "Bill"));
	staffMembers.insert(new Janitor(45000, "Greg"));
	staffMembers.insert(new Janitor(50000, "Sally"));
	
	//Display the highest ranked staff members information and then remove them from the heap
	while (staffMembers.size() > 0)
	{
		//Grab the top employee
		Employee* topEmployee = staffMembers.extractMax();
		//Output their information
		cout << "Name: " << topEmployee->name << endl;
		topEmployee->outputEarnings();
		topEmployee->outputJobDescription();
		//Delete them from the heap
		staffMembers.deleteMax();
		cout << endl;
	}
	
	system("pause");
}