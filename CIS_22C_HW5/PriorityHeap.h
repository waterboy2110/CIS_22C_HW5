// CIS_22C_HW5.cpp : header file.


/***********************
James Agua
CIS 22C Deanza Winter
Heaps
Homework 5
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

	// Constructor and Destructor
	Customer(){name = ""; mileage = 0; years = 0; priority = 0; serialNumber = 0;} 
	~Customer(){}
};

class PriorityHeap
{	
private:
	int count;

public:
	~PriorityHeap();

	// Heap Operations
	bool insertHeap(Customer);							// Add a customer::example from class
	void reHeapUp(int);									// ReHeapUp example from class
	void reHeapDn(int, int);							// ReHeapDn example from class
	bool isEmpty() const;								// Determine if tree is empty
    bool deleteRoot(int);								// Delete the root customer in the heap.
	void heapPrint() const;								// Prints the heap.
	void setCount(int aCount){count = aCount;}			// Needed to initialize count.
	void calcSerialNumber(Customer&);					// Calculate the SN in the insertHeap method
	int getCount() const {return count;}				// Returns the count of the Heap
};

#endif