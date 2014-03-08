// CIS_22C_HW5.cpp
/***********************
James Agua
CIS 22C Deanza Winter
Binary Search Tree
Homework 4
***********************/

#include "stdafx.h"


vector<Customer> customers;

//*************************************
// Definition of method addNode
// Use interitive mode to find a leaf node in
// a left / right fasion. 
// Allows duplicate nodes. Duplicates are stored
// on the right.
// Pre - a new student node.
// Returns a bool if successful.
//*************************************

/*
	Will add data to an array. On each add will reheap up to keep the array ordered and to reflect the heap
	When printing will print the top node (node[0]), move the last node to node[0] and delete the last node
	calculations: 
			leftChild = 2*root+1;
			rightChild = 2*root+2;

*/
// **************************************************
// Definition of reHeapUp
// 
//
// **************************************************
void PriorityHeap::reHeapUp(int bottom)		// examples use index to array - should use ints here
{
	Customer parent;							// Parent object calculated by index
	Customer temp;								// Temp object used for exchange
	
	//for(int i = count; i >=0; i--)
	//cout << "DEBUG: Reheap Up " << customers[i].getName() << " " << customers[i].getSerialNumber() << endl;
	
	//if(newCustomer.getSerialNumber() > customers[0].getSerialNumber())		// argument passed in is not the root
	if (bottom > 0)
	{
		int parentIndex = (bottom - 1) / 2;			// Parent index calculation
		parent = customers[parentIndex];

		if(customers[bottom].getSerialNumber() > parent.getSerialNumber())
		{
			temp = customers[bottom];
			customers[bottom] = customers[parentIndex];
			customers[parentIndex] = temp;
		
			reHeapUp(parentIndex);
		}
	}


/*
Algorithm reheapUp ( newElement )

    if ( newElement is not the root of the heap)	// if new element NOT vector[0] //this is root.
        parent = parent of the newElement			// calc parent = (bottom - 1) / 2
        if ( newElement key > parent key)			// if (cust.getSN() > parentSN)
            exchange newElement and parent			// swap newElement and parent
            reheapUp(parent)						// call reheapUp with parent.
        end if
    end if
end reheapUp

* From an example
void Heap::ReheapUp(int root, int bottom)		// root is always 0, parent is calculated
{
 int parent;
 
 if(bottom > root) // tree is not empty
 {
   parent = (bottom-1)/2;
   if(elements[parent] < elements[bottom])
   {
     Swap(elements, parent, bottom);
     ReheapUp(root, parent);
    }
  }
}

*/
}

// **************************************************
// Definition of reHeapDn
//
//
//
// **************************************************
void PriorityHeap::reHeapDn(Customer &customer)
{
	cout << "not implemented" << endl;
	/*
	Algorithm reheapDown ( root, last )

    if ( there is a left child)
        leftKey = left child key
        if ( there is a left child)
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
// as this is used to rebuid the heap in each insert.
// Pre - A customer object
// Post - Adds the customer to the vector, updates the
// serialNumber and adds it to the customer and reorders
// the heap.
// **************************************************
bool PriorityHeap::insertHeap(Customer cust)
{
	calcSerialNumber(cust);
	customers.push_back(cust);	
	cout << "DEBUG in INSERT " << customers[count].getName() 
		<< " " << customers[count].getSerialNumber() <<  endl;
	//reHeapUp(customers[count]);		// try with the count
	reHeapUp(count);	
	count++;

	for(int i = 0; i < count; i++)
		cout << "DEBUG: Insert post reheap " << customers[i].getName() << " " << customers[i].getSerialNumber() << endl;

	return true;

/*
Algorithm insertHeap ( newData )

    if (heap is full)			//dont care using vector
        return false
    end if
    last = last + 1				// using pushback
    heap[last] = newData
    reheapUp(last)
    return true
end insertHeap
*/
}

// **************************************************
// Definition of deleteHeap
//
//
// **************************************************
void deleteHeap(int last, Customer &dataOut)

{
/*
Algorithm deleteHeap ( last, dataOut )

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

