// CIS_22C_HW5.cpp : main project file.

#include "stdafx.h"
using namespace System;

// Function Prototypes
bool processFile(PriorityHeap *);					// Open and process the input file
string removeTrailingWhiteSpace(string);			// Clean up student name string of trailing junk

int main(array<System::String ^> ^args)
{
	// Create a pointer to a new priority heap and allocate
	PriorityHeap *ptrPriorityHeap = new PriorityHeap;
	/*

	*/

	// Add the file data to the node
	bool success = processFile(ptrPriorityHeap);

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

	// Open file to read, if couldn't open, display error
   // and exit with false
   inFile.open(fileName.c_str());
   if (!inFile)
   {
      cout << "Error opening " << fileName << "!\n";
      return false;
   }
	// Process each string in the file beginnging with students PIN
  while (getline(inFile, readStr, ' '))
  {
	  
	  // node.pin = atoi(readStr.c_str());		// Finish processing the students PIN

	   getline(inFile, readStr, ';');			// Process the students name
	   //node.name = removeTrailingWhiteSpace(readStr);

	   getline(inFile, readStr);				// Process the students gpa
	  // node.gpa = atof(readStr.c_str());

	  // cout << "DEBUG node data: " << customer.getName()<< " " << customer.getMileage << " " << customer.getYears << endl;
	  // heap->addCustomer(customer);
	  // tree->addNode(node);						// Add the node to the tree
	  
	   empty = false;
   }

   inFile.close();
 
   if (empty)
      return false;

   return true;
}

//**************************************************
// Definition of function removeTrailingWhiteSpace.
// This function removes trailing white spaces at
// the back of the string, str, and returns the new
// string. Removes trailing tabs, line feeds,
// spaces, and carriage returns.
//**************************************************
string removeTrailingWhiteSpace(string str)
{
   int i = str.length() - 1;  // zero based
   while (str[i] == '\t' || str[i] == '\n' || str[i] == ' ' || str[i] == '\r')
   {
      str.erase(i, 1);
      i--;
   }
   return str;
}