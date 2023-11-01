#pragma once
#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
	int number;
	Node* leftChild; //Needs 2 pointers to point the left and right children nodes
	Node* rightChild;

	Node(int number);
};