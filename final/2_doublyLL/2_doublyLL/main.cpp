//old main before using implementations from class
//all functions direct on main
//here for reference



#include "Node.h"
#include <iostream>

using namespace std;

int main()
{

	Node *headPtr = nullptr;	//head
	Node *tailPtr = nullptr;	//tail
	int temp;					//temp storage

	////first, make a first node
	//headPtr = new Node();
	//tailPtr = headPtr; 
	//cout << "ENter value for 1st node: " << endl;
	//cin >> temp;
	//headPtr->setNum(temp);
	
	//lets make a loop to enter numbers for each node, -1 to stop
	while(temp != -1)
	{
		//fill value in to the new node
		Node *newNode = new Node(temp);

		//point tail to last entered node:
		tailPtr->setNext(newNode);
		//set tail to the new node:
		tailPtr = newNode;

		//read in next value:
		cin >> temp;
	}


	////output list, use a temp var to access head, then hop it to next
	//cout << "Result: ";
	Node *p = headPtr;
	Node *previous = nullptr;
	Node *current = nullptr;
	//while(p != nullptr)
	//{
	//	cout << p->getNum() << " ";
	//	p = p->getNext();
	//} 
	//cout << endl;
	 

	//just to search for a node
	int target;
	//cout << "enter number to search: ";
	//cin >> target;
	//cout << endl;
	//current = headPtr;
	//while(current != nullptr)
	//{
	//	if(current->getNum() == target)
	//	{
	//		cout << "Found the target " << endl;
	//		break;
	//	}
	//	previous = current; //so previous is always 1 node behind
	//	current = current->getNext(); //if you didnt find, go next
	//}
	////if p = nullptr then target was not found
	//if(current == nullptr)
	//{
	//	cout << "target not found" << endl;
	//}
	//else
	//{
	//	cout << "We found: " << current->getNum() << endl;
	//}



	//delete  a node
//	int target;
	cout << "enter number to DELETE: ";
	cin >> target;
	cout << endl;
	current = headPtr;
	while(current != nullptr)
	{
		if(current->getNum() == target)
		{
			cout << "Found the target " << endl;
			break;
		}
		previous = current; //so previous is always 1 node behind
		current = current->getNext(); //if you didnt find, go next
	}
	//if p = nullptr then target was not found
	if(current == nullptr)
	{
		cout << "target not found" << endl;
	}
	else
	{
		cout << "We found: " << current->getNum() << endl;
		if(previous != nullptr)
		{
			previous->setNext(current->getNext()); 
			delete current; 
		}
		else //in case that target found is at the head of list
		{
			//deleting front of list:
			headPtr = current->getNext();  
			delete current;
		}
	}


	//output the list after deleting
	p = headPtr;
	cout << "\nOutput list: " <<endl;
	while(p != nullptr)
	{
		cout << p->getNum() << " ";
		p = p->getNext();
		//cout <<  " P->getNext: " << p->getNum()  << endl;
	} 
	cout << endl;


	////free the memory to guarantee no memory leaks
	//previous = nullptr;
	//current = headPtr;
	//while(current != nullptr)
	//{
	//	previous = current;
	//	current = current->getNext();
	//	delete previous;
	//}





/*	Node *ptr = new Node();
	Node *ptr2 = new Node(100);
	
	ptr->setNext(ptr2);//set pointer next to ptr 2 (linking the list)

	cout << (*ptr).getNum() << endl;
	cout << ptr->getNext()->getNum() << endl; //ptr->getNext points to  ptr2
*/	//cout << ptr2->getNum() << endl;

	system("pause");

	return 0;
	
}