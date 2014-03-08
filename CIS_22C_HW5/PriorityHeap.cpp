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
//
//
//
// **************************************************
void PriorityHeap::reHeapDn(int root, int bottom)
{
	Customer temp;
	int maxChild, rightChild, leftChild;
	leftChild	= 2 * root + 1;
	rightChild	= 2 * root + 2;

	//if(customers[leftChild].getSerialNumber() <= customers[bottom].getSerialNumber())		// Left child is part of the heap
	if(leftChild <= bottom)
	{
		if(leftChild == bottom)																// Only one child
			maxChild = leftChild;
		else
		{
			if(customers[leftChild].getSerialNumber() <= customers[rightChild].getSerialNumber())
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}
		if(customers[root].getSerialNumber() < customers[maxChild].getSerialNumber())
		{    //swap
			temp = customers[root];
			customers[root] = customers[maxChild];				// crashes here in recursion
			customers[maxChild] = temp;
			reHeapDn(maxChild, bottom);							
		}
	}

	/*	
From example
void Heap::ReheapDown(int root, int bottom)
{
 int maxChild, rightChild, leftChild;
 
 leftChild = 2*root+1;
 rightChild = 2*root+2;
 
 if(leftChild <= bottom) // left child is part of the heap
 {
   if(leftChild == bottom) // only one child
        maxChild = leftChild;
   else
   {
        if(elements[leftChild] <= elements[rightChild])
            maxChild = rightChild;
        else
            maxChild = leftChild;
   }
   if(elements[root] < elements[maxChild])
   {
       Swap(elements, root, maxChild);
       ReheapDown(maxChild, bottom);
    }
  }
}
http://sourcecodemania.com/heap-data-structure-in-cpp/
	
		Algorithm reheapDown ( root, last )

    if ( there is a left child)
        leftKey = left child key
        if ( there is a left child)			//right child?
            rightKey = right child key
        else
            rightKey = null
        end if
        largest= right child
        if ( leftKey > rightKey)
             largest = left child
        end if
        if (root key < largest key)
            swap root and largest
            reheapDown(largest, last)
        end if
    end if
end reheapDown
	*/

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
//
//
// **************************************************
bool PriorityHeap::deleteRoot(int last)
{
	if(customers.size() == 0)				// Heap is empty
		return false;
	
	cout << "\nRemoving Customer: " << customers[0].getName() << " " << customers[0].getSerialNumber() << endl;

	customers[0] = customers[customers.size() - 1];			// Move the last node to the root
	customers.pop_back();								// Delete the last node
	//setCount(last--);
	
	reHeapDn(0, customers.size() - 1);
	//count--;
	//setCount(last--);
	//customers.pop_back();					// Delete the bottom customer (was the root)
	heapPrint();
	return true;

/*
Algorithm deleteHeap ( last, dataOut )  // last is the count

    if (heap is empty)
        return false
    end if
    dataOut = root data
    heap[0] = heap[last]
    reheapDown(0, last)
    return true
end deleteHeap

*/
}

