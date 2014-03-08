// CIS_22C_HW5.cpp
/***********************
James Agua
CIS 22C Deanza Winter
Heaps
Homework 5
***********************/

#include "stdafx.h"

vector<Customer> customers;						// A dynamic array of customer objects

// **************************************************
// Definition of heapPrint
// Loops through the heap for the size of the heap (array)
// and prints the output.
// Pre - nothing
// Post - Prints the entire heap (array)
// **************************************************
void PriorityHeap::heapPrint() const
{
	cout << "\nThe Heap Contains:\n";
	for(int i = 0; i < customers.size(); i++)
		cout << customers[i].getName() 
		<< " " << customers[i].getSerialNumber() << endl;
}

// **************************************************
// Definition of reHeapUp
// Calculates the parent index (bottom -1) / 2
// and determines if the bottom (last in) customer
// serial number is greater than the parent serial
// number. If so, swaps the bottom and parent and
// the recursivly calls reHeapUp.
// Pre - the number of customers (int count)
// Post - the array is heapified by serial number
// **************************************************
void PriorityHeap::reHeapUp(int bottom)
{
	Customer temp;											// Temp object used for exchange
	
	if (bottom > 0)
	{
		int parentIndex = (bottom - 1) / 2;					// Parent index calculation

		if(customers[bottom].getSerialNumber() > customers[parentIndex].getSerialNumber())		// is bottom SN larger than parent SN?
		{
			temp = customers[bottom];						// Swap bottom and parent
			customers[bottom] = customers[parentIndex];
			customers[parentIndex] = temp;
		
			reHeapUp(parentIndex);							// Call reHeapUp with parentIndex
		}													// End Swap
	}														// At the root
}

// **************************************************
// Definition of reHeapDn
// Determine if the bottom of the heap is a left or 
// right node. Uses calculation to determine left or
// right. If sub heap requires a swap performs the 
// swap and calls itself to reform the heap.
// Pre - The parent of a sub heap
// Post - The heap is reformed after removeal of a node
// **************************************************
void PriorityHeap::reHeapDn(int root, int bottom)
{
	Customer temp;
	int maxChild, rightChild, leftChild;
	leftChild	= 2 * root + 1;									// Points to the left child of (sub)heapParent
	rightChild	= 2 * root + 2;									// Points to the right child of (sub)heapParent

	if(leftChild <= bottom)
	{
		if(leftChild == bottom)									// Only one child
			maxChild = leftChild;
		else
		{
			if(customers[leftChild].getSerialNumber() <= customers[rightChild].getSerialNumber())
				maxChild = rightChild;
			else												// Two children - determine which one to swap with parent
				maxChild = leftChild;
		}
		if(customers[root].getSerialNumber() < customers[maxChild].getSerialNumber())
		{    
			temp = customers[root];								// Swap the bottom node with the subHeap parent
			customers[root] = customers[maxChild];
			customers[maxChild] = temp;
			reHeapDn(maxChild, bottom);							
		}
	}
}

// **************************************************
// Definition of calcSerialNumber
// Calculates the serial number of each customer.
// The serial number is the the ordering number of
// the hash table.
// serial number = priority * 1000 + (1000 – number of customers)
// Pre - a pointer to the customer
// Post - the serialNumber of the customer is updated.
// **************************************************
void PriorityHeap::calcSerialNumber(Customer &cust)
{
	int serialNumber;
	serialNumber = cust.getPriority() * 1000 + (1000 - (count + 1));
	cust.setSerialNumber(serialNumber);
}

// **************************************************
// Definition of insertHeap
// Inserts customers into an array heap using a vector
// so that the heap is dynamic. Calls calcSerialNumber()
// as this is the heaps key. Calls reHeapUp on each
// customer added.
// Pre - A customer object
// Post - Adds the customer to the vector, updates the
// serialNumber and adds it to the customer and reorders
// the heap.
// **************************************************
bool PriorityHeap::insertHeap(Customer cust)
{
	calcSerialNumber(cust);													// Calculate the SerialNumber - this is the heaps key
	customers.push_back(cust);												// Insert the customer into the array
	cout << "\nInsert Customer: " << customers[count].getName() 
		 << " " << customers[count].getSerialNumber() <<  endl;				// New Customer to insert

	reHeapUp(count);														// Call reHeapUp after each insert
	count++;

	heapPrint();
	return true;
}

// **************************************************
// Definition of deleteHeap
// Determines if heap is empty and returns if so.
// Swaps the bottom node with the root node and calls
// reheapDn to reshape the heap (based on customers
// serialNumber). Removes the bottom node (pop.back())
// Pre - Nothing
// Post - Heap is deleted - reshaped and printed one
// customer at a time.
// **************************************************
bool PriorityHeap::deleteRoot()
{
	if(customers.size() == 0)							// Heap is empty
		return false;
	
	cout << "\nRemoving Customer: " << customers[0].getName() << " " << customers[0].getSerialNumber() << endl;

	customers[0] = customers[customers.size() - 1];		// Move the last node to the root
	customers.pop_back();								// Delete the last node	
	reHeapDn(0, customers.size() - 1);					// Reshape the heap
	heapPrint();
	count--;
	return true;
}

// **************************************************
// Definition of isEmpty
// Pre - nothing
// Post - Returns true if no more customers
// in the array.
// **************************************************
bool PriorityHeap::isEmpty() const
{
	if(count == 0)
		return true;
	return false;
}

