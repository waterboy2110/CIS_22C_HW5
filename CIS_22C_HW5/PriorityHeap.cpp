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
void PriorityHeap::reHeapUp(Customer &heap)		//examples use index to array - should use ints here
{
	cout << "not implemented" << endl;

/*
Algorithm reheapUp ( newElement )

    if ( newElement is not the root of the heap)
        parent = parent of the newElement
        if ( newElement key > parent key)
            exchange newElement and parent
            reheapUp(parent)
        end if
    end if
end reheapUp

* From an example
void Heap::ReheapUp(int root, int bottom)
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
// Definition of insertHeap
//
//
// **************************************************
bool PriorityHeap::insertHeap(Customer cust)
{
	cout << "not implemented" << endl;
	return true;

/*
Algorithm insertHeap ( newData )

    if (heap is full)
        return false
    end if
    last = last + 1
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


// What I was working on - Delete if everything else seems to work.
//bool PriorityHeap::addCustomer(Customer customerNode)
//{
//	bool success = false;
//	Customer *Pwalk;							// Pointer to walk the tree
//	Customer *parent = NULL;					// Pointer to the parent node
//	Customer *newCustomer = new Customer;		// Create a new node for the tree
//	*newCustomer = customerNode;				// Strange - only sorts correctly if I make this assignment
//		/*
//		Really just want to add nodes in a breadth fasion
//		Should be able to walk the tree and look for nulls
//
//		just try a couple recursive methods and see what they do
//		*/										// but I'm making the same assignment below in the if...
//	
//
//	if(root == NULL)				// First node to be saved is always the root
//	{
//		root = new Customer;
//		*root = customerNode;
//	}
//	else							// Walk the tree to find the next empty node
//	{
//		Pwalk = root;
//		while(Pwalk)
//		{
//			parent = Pwalk;
//			if(*customerNode->getLeftLeaf())
//				*Pwalk = Pwalk->getLeftLeaf();
//			//else
//				*Pwalk = Pwalk->getRightLeaf();
//		}
//		
///*		if(newNode->name < parent->name)
//		{
//			parent->left = newNode;
//			*newNode = studentNode;
//		}
//		else
//		{
//			parent->right = newNode;
//			*newNode = studentNode;
//		}*/		
//	}
//	count++;
//	return success;
//}
