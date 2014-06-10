/*
Bruno Lopes	
CSCE 311 - HW#3.2a
Implementation of Double LinkedList, keeping track of current/previous
and now tracking tail on MyList.h\numNodes
*/
#include <iostream>
#include <string>
#include "MyList.cpp" 
#include "Node.h"
using namespace std;

#define SIZE 10	//size of LinkedList
#define RAND 50	//random size of each node value



int main()
{
	int A[SIZE];

	MyList<int> numList;

	//generate rand list
	cout << "RAND LIST:\t";
	for (int i = 0; i < SIZE; i++)
    {
		A[i] = rand() % RAND;
		numList.add(A[i]);
		cout << A[i] << " | ";
    }
	cout << endl;


	numList.Bsort();
	numList.output();
	
	system("pause");
	return 0;
	
}