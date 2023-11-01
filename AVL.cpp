#include "AVL.h"

//Using reccursion, we keep exploring down, then pass final height values up
int AVL::height(Node* node)
{
	int h = 0;
	//Helps break recursion cycle when we get to NULLs at bottom of branches
	if (node != NULL)
	{
		int leftH = height(node->leftChild);
		int rightH = height(node->rightChild);

		//Max gets the bigger of the 2 and discards the smaller
		int maxH = max(leftH, rightH);
		h = maxH + 1;
	}
	return h;
}

int AVL::difference(Node* node)
{
	//If empty tree, then it's balanced, it's 0
	if (node == NULL)
		return 0;

	int leftH = height(node->leftChild);
	int rightH = height(node->rightChild);
	int balanceFactor = leftH - rightH;

	return balanceFactor;
}

Node* AVL::RRrotation(Node* parent)
{
	Node* temp = parent->rightChild;
	parent->rightChild = temp->leftChild;
	temp->leftChild = parent;

	if (displayRotations)
		cout << "RR Rotation on " << parent->number << endl;

	return temp;
}

Node* AVL::LLrotation(Node* parent)
{
	Node* temp = parent->leftChild;
	parent->leftChild = temp->rightChild;
	temp->rightChild = parent;

	if (displayRotations)
		cout << "LL Rotation on " << parent->number << endl;

	return temp;
}

//Needs 2 rotations,
//First rotation rotates bottom 2 nodes,
//Second rotation does a LLrotation
Node* AVL::LRrotation(Node* parent)
{
	Node* temp = parent->leftChild;
	parent->leftChild = RRrotation(temp);

	if (displayRotations)
		cout << "LR Rotation on " << parent->number << endl;

	return LLrotation(parent);
}

//Needs 2 rotations,
//First rotation rotates bottom 2 nodes,
//Second rotation does a RRrotation
Node* AVL::RLrotation(Node* parent)
{
	Node* temp = parent->rightChild;
	parent->rightChild = LLrotation(temp);

	if (displayRotations)
		cout << "RL Rotation on " << parent->number << endl;

	return RRrotation(parent);
}

Node* AVL::balance(Node* parent)
{
	//Get balance factor
	int balanceFactor = difference(parent);

	//IF balance factor is not within -1,0,1 then lets work out which rotations to do
	if (balanceFactor > 1)
	{
		//Left branch is heavy, now work out if it's left or right child heavy
		if (difference(parent->leftChild) > 0)
		{
			//Left child heavy
			parent = LLrotation(parent);
		}
		else
		{
			//Right child heavy
			parent = LRrotation(parent);
		}
	}
	else if (balanceFactor < -1)
	{
		//Right branch is heavy, now work out if it's left or right child heavy
		if (difference(parent->rightChild) > 0)
		{
			//Left child heavy
			parent = RLrotation(parent);
		}
		else
		{
			//Right child heavy
			parent = RRrotation(parent);
		}
	}

	return parent;
}

Node* AVL::insertAVL(Node* parent, Node* newNumber)
{
	//IF subtree empty, this becomes the parent
	if (parent == NULL)
	{
		parent = newNumber;
		return parent;
	}

	//Parent not NULL, so we haven't found an empty space to stick new student yet
	//So we need to go down either left or right path
	if (newNumber->number < parent->number)
	{
		parent->leftChild = insertAVL(parent->leftChild, newNumber);
		parent = balance(parent);
	}
	else //Assume ID >= parent's ID
	{
		parent->rightChild = insertAVL(parent->rightChild, newNumber);
		parent = balance(parent);
	}
}

void AVL::insert(Node* newNumber)
{
	root = insertAVL(root, newNumber);
}
