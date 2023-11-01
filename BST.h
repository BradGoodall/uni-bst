#pragma once
#include "Node.h"

using namespace std;

//Binary Search Tree
//Root node sort of acting as centre
//Everything smaller than root, is sorted on the left branch somewhere
//Everything equal-to or bigger is sorted to the right
class BST
{
public:
	Node* root = NULL;
	virtual void insert(Node* newNumber);
	Node* search(int number, bool showSearchPath = false);

	//Recursive traversal functions
	void inOrderTraversal(Node* current);
	void preOrderTraversal(Node* current);
	void postOrderTraversal(Node* current);
};

