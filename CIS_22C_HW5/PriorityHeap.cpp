// CIS_22C_HW5.cpp

/***********************
James Agua
CIS 22C Deanza Winter
Binary Search Tree
Homework 4
***********************/

#include "stdafx.h"

//*************************************
// Definition of method addNode
// Use interitive mode to find a leaf node in
// a left / right fasion. 
// Allows duplicate nodes. Duplicates are stored
// on the right.
// Pre - a new student node.
// Returns a bool if successful.
//*************************************
bool PriorityHeap::addCustomer(Customer customerNode)
{
	bool success = false;
	Customer *Pwalk;							// Pointer to walk the tree
	Customer *parent = NULL;					// Pointer to the parent node
	Customer *newCustomer = new Customer;		// Create a new node for the tree
	*newCustomer = customerNode;				// Strange - only sorts correctly if I make this assignment
		/*
		Really just want to add nodes in a breadth fasion
		Should be able to walk the tree and look for nulls

		make ritht and left public and get ride of the get and set - no need - seems to work
		update count here and use priotity as the counter in main
		just try a couple recursive methods and see what they do
		*/										// but I'm making the same assignment below in the if...
	

	if(root == NULL)				// First node to be saved is always the root
	{
		root = new Customer;
		*root = customerNode;
	}
	else							// Walk the tree to find the next empty node
	{
		Pwalk = root;
		while(Pwalk)
		{
			parent = Pwalk;
			//if(customerNode->getLeftLeaf())
				*Pwalk = Pwalk->getLeftLeaf();
			//else
				*Pwalk = Pwalk->getRightLeaf();
		}
		
/*		if(newNode->name < parent->name)
		{
			parent->left = newNode;
			*newNode = studentNode;
		}
		else
		{
			parent->right = newNode;
			*newNode = studentNode;
		}*/		
	}
	count++;
	return success;
}
