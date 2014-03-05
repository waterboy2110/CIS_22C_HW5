// CIS_22C_HW5.cpp : header file.


/***********************
James Agua
CIS 22C Deanza Winter
Binary Search Tree
Homework 4
***********************/

#ifndef PRIORITY_HEAP_H
#define PRIORITY_HEAP_H

/*~*~*************************
 The customer structure contains the following fields:
- name
- mileage
- years
- priority
- serial number = priority * 1000 + (1000 – number of customers)
// build the heap based on the serial number
*~*~*************************/

#include <string>

using namespace std;

class Customer			// Customer object
{
private:					
	string name;		// Customers name.
	int mileage;		// Number of miles customer has flown.
	int years;			// Number of years customer has flown.
	int priority;		// Priority is the order in which the file is read.
	int serialNumber;	// = priority * 1000 + (1000 - count).
	Customer *right;	// Pointer to the right child.
	Customer *left;		// Pointer to the left child.


public:
	// Sets and Gets for private data members.
	string getName(){return name;} const
	int getMileage(){return mileage;} const
	int getYears(){return years;} const
	int getSerialNumber(){return serialNumber;} const
	int getPriority(){return priority;} const

	void setName(string aName){name = aName;}
	void setMileage(int aMileage){mileage = aMileage;}
	void setYears(int aYears){years = aYears;}
	void setSerialNumber(int aSerialNumber){serialNumber = aSerialNumber;}
	void setPriority(int aPriority){priority = aPriority;}


	Customer getRightLeaf(){return *right;}					// Return the right pointer.
	Customer getLeftLeaf(){return *left;}					// Return the left pointer.


	// Constructor and Destructor
	Customer(){name = ""; mileage = 0; years = 0; priority = 0; serialNumber = 0; right = NULL; left = NULL;} 
	~Customer(){}
};

class PriorityHeap
{
public:
	//PriorityHeap();
	~PriorityHeap();

	// Heap Operations
	bool addCustomer(Customer);							// Add a customer
	void reHeapUp();
	void reHeapDn();
	bool isEmpty() const;								// Determine if tree is empty
    void clear(Customer*);								// Delete all Customers in the heap.
	void inOrderPrint(Customer*); const					// Traverse the tree and print ordered results
	int getCount() const {return count;}				// Returns the count of the Heap
	Customer getRoot() const {return *root;}			// Returns the root of the Heap
	void setCount(int inCount){count = inCount;}		// Set the number of customers
	bool isLeaf(Customer*);								// Return true if Customer is a leaf
	void printLevel(Customer*);							// Prints the Heap in a level order

private:
	Customer *root;										// Pointer to the root of the Binary Search Tree
	int count;
};

#endif