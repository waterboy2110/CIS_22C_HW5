// CIS_22C_HW5.cpp : main project file.
/***********************
James Agua
CIS 22C Deanza Winter
Heaps
Homework 5
***********************/
	  /*
	  Priority number = A / 1000 + B � C
		where
		A is the customer�s total mileage in the past year
		B is the number of years in her or his frequent flier program
		C is the sequence number representing the customer�s arrival position when s/he booked the flight 
		(the first customer�s sequence number is 1, second in the file is 2, and so on).
	  */

#include "stdafx.h"
using namespace System;

// Function Prototypes
bool processFile(PriorityHeap *);					// Open and process the input file
void Strtok(vector<string>*, string, char*);		// Split up the string into sub strings.
void removeCustomers(PriorityHeap *);

int main(array<System::String ^> ^args)
{
	// Create a pointer to a new priority heap and allocate
	PriorityHeap *ptrPriorityHeap = new PriorityHeap;

	bool success = processFile(ptrPriorityHeap);			// Add the file data to the node

	removeCustomers(ptrPriorityHeap);						// Remove customers from the heap

	delete ptrPriorityHeap;
	cout << "\n\t***goodbye***\n";
    return 0;
}


//**************************************************
// Definition of function processFile.
// This function will read all the data from
// the file and call addHeap to build the heap.
//**************************************************
bool processFile(PriorityHeap *heap)
{
   ifstream inFile;
   string readStr;
   string fileName;
   bool empty = true;
   fileName = "overbooked.txt";
   Customer customer;
   vector<string> vString;
   string name;
   int sequence = 0;

   // Open file to read, if couldn't open, display error
   // and exit with false
   inFile.open(fileName.c_str());
   if (!inFile)
   {
      cout << "Error opening " << fileName << "!\n";
      return false;
   }
	// Process each string in the file.
  while (getline(inFile, readStr))
  {
	  // Seperate the strings into groups of strings and numbers.
	  // If the vector has 5 elements the name is the first 3.
	  Strtok(&vString, readStr, " ");
	  if(vString.size() == 5)
		  name = vString[0] + " " + vString[1] + " " + vString[2];
	  else
		  name = vString[0] + " " + vString [1];
	 
	  // Set Customer data.
	  customer.setName(name);												// Set the name
	  customer.setMileage(atoi(vString[vString.size() - 2].c_str()));		// Set the mileage
	  customer.setYears(atoi(vString[vString.size() - 1].c_str()));			// Set the years
	  sequence++;															// Update the sequence number
	  // Set the customers priority number.
	  customer.setPriority(customer.getMileage() / 1000 + customer.getYears() - sequence);

	   heap->insertHeap(customer);											// Add the user to the heap
	   empty = false;
	   vString.clear();														// Clear the tokenizing vector
   }

   inFile.close();
 
   if (empty)
      return false;

   return true;
}

//***************************************************
// Definition of function Strok.
// This function tokenizes the string and returns
// each element of the string as a string in a vector.
//***************************************************

void Strtok(vector<string>* vstring, string cptr, char* delimiter)
{
	string astring = cptr;
	string stemp;
	int start = 0;
	int index = astring.find(delimiter);
	// Process the string and load the vector
	while (index != string::npos)
	{
		stemp.assign(astring,start,index-start);
		vstring->push_back(stemp);
		start = index + 1;
		index = astring.find(delimiter,start);
	}
	stemp.assign(astring,start,astring.length()-start);
	vstring->push_back(stemp);
}

//**************************************************
// Definition of function removeCustomers
// Calls the deleteCustomer function and removes
// customers from the heap. Loops through and removes
// all customers
// Pre - A pointer to the PriorityHeap
// Post - Customers are deleted.
//**************************************************
void removeCustomers(PriorityHeap *heap)
{
	for(int i = heap->getCount(); i > 0; i--)
		heap->deleteRoot();
	if(heap->isEmpty())
		cout << "\tHeap is empty\n";
}