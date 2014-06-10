//
//Attempt to doubly linked lists, not working
//issues mainly surrounding how to figure out position on list without a general
//control array type of variable


#include <iostream>
#include <string>
#include "MyList.cpp"
#include "Node.h"
using namespace std;

#define SIZE 10
#define RAND 10


int main()
{

	int i;
	int A[SIZE];

	Node<int> intNode(0);
	MyList<int> numList;


	//generate rand array
	cout << "RANDOM LIST:\t\t";
	for (i = 0; i < SIZE; i++)
    {
		A[i] = rand() % RAND;
		cout << A[i] << " | ";
		numList.add(A[i]);
    }
	cout << endl;


	numList.Bsort();
	numList.output();
	

	//system("pause");

	return 0;
	
}