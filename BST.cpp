#include "BST.h"

void BST::insert(Node* newNumber)
{
	//IF the root is NULL (tree is empty), then make this number the root
	if (root == NULL)
	{
		root = newNumber;
		return; //Exit function early, we are done here
	}

	//Some pointers to help us navigate the tree to find where to put the new number
	Node* current = root; //Current node we're pointing at
	Node* parent = NULL; //Parent of current (Node visited last time)

	while (true) //Infinite loop
	{
		//Let's keep track of where we were before moving down further
		parent = current;

		//LEFT or RIGHT???
		//If newNumber's number is less than the number at the current node, then go LEFT
		if (newNumber->number < current->number)
		{
			//< means we go down deeper into the left side tree
			current = current->leftChild;
			//if current is NULL, we just found an empty space to insert our number
			if (current == NULL)
			{
				//Done, place number here
				parent->leftChild = newNumber;
				return; //Exit function, we're done!
			}
		}
		else //otherwise go RIGHT
		{
			current = current->rightChild;
		}
		//if current is NULL, we just found an empty space to insert our number
		if (current == NULL)
		{
			//Done, place number here
			parent->rightChild = newNumber;
			return; //Exit function, we're done!
		}
	}
}

Node* BST::search(int number, bool showSearchPath)
{
	//If the tree is empty
	if (root == NULL)
	{
		cout << "Tree is empty!" << endl;
		return NULL;
	}

	Node* current = root; //Current node we're pointing at

	//Keep looping until I find a match
	while (current->number != number)
	{
		if (showSearchPath)
			cout << current->number << endl;

		//Haven't found it yet, lets explore left or right down in the tree
		if (number < current->number)
		{
			//Go left
			current = current->leftChild;
		}
		else
		{
			//Go right
			current = current->rightChild;
		}

		//If current is NULL, search number cannot be found
		if (current == NULL)
		{
			cout << number << " could not be found!" << endl;
			return NULL;
		}
	}

	cout << number << " found!" << endl;
	return current; //Should be pointing to match in tree :)
}

//Outputs stuff in the tree in accending order
void BST::inOrderTraversal(Node* current)
{
	//Current == NULL is the end of this branch path
	//This if stops from infinite looping
	if (current != NULL)
	{
		inOrderTraversal(current->leftChild);
		cout << current->number << endl;
		inOrderTraversal(current->rightChild);
	}
}

//these are based on when it outputs the data to the console
//preOrder means it outputs the data before recursion
void BST::preOrderTraversal(Node* current)
{
	if (current != NULL)
	{
		cout << current->number << endl;
		preOrderTraversal(current->leftChild);
		preOrderTraversal(current->rightChild);
	}
}

//postOrder means it outputs the data after recursion
void BST::postOrderTraversal(Node* current)
{
	if (current != NULL)
	{
		postOrderTraversal(current->leftChild);
		postOrderTraversal(current->rightChild);
		cout << current->number << endl;
	}
}
