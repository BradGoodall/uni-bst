#pragma once
#include "BST.h"

//AVL is a self balancing Binary Search Tree
//AVL - Adelson-Velski & Landis
class AVL : public BST
{
public:
	bool displayRotations = true;

	//Works out height of subtree
	int height(Node* node);

	//Difference between left and right subtrees
	int difference(Node* node);

	//ROTATIONS
	//Return new parent of subtree
	//Parameter: Current parent of subtree
	//Right branch, right child
	Node* RRrotation(Node* parent);
	//Left branch, left child
	Node* LLrotation(Node* parent);
	//Left branch, right child
	Node* LRrotation(Node* parent);
	//Right branch, left child
	Node* RLrotation(Node* parent);

	//BALANCE
	//Balances a tree structure where parent is the middle top node
	//returns new parent after balancing(rotations)
	Node* balance(Node* parent);

	//INSERT
	//Recursive insert that considers parent a subtree
	//This insert also balances itself
	//Returns the new root node of the tree
	Node* insertAVL(Node* parent, Node* newNumber);

	//Overriding insert from parent
	void insert(Node* newNumber);
};

