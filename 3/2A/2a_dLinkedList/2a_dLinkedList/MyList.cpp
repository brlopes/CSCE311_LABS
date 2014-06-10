/*
bubble sort done on "sort" 
the size numNodes counter declared on the header is incremented on each add, I could
have used the global variable SIZE but the counter implementation offers a more dinamic 
control of the List
the remove and contains is not really used but its kept for future references

*/
#include "MyList.h"
#include <iostream>

using namespace std;

template<class T>
MyList<T>::MyList()
{
	headPtr = nullptr;
	tailPtr = nullptr;
	numNodes = 0;
}




//_____________________________________ADD TO LIST_______________________________________________________//
template<class T>
void MyList<T>::add(T data)
{
	//make a new node
	Node<T> *temp = new Node<T>(data);

	//link tail to the new node:
	if(tailPtr == nullptr)
	{
		tailPtr = temp; //the list was empty
	}
	else
	{
		tailPtr->setNext(temp);
		tailPtr = temp;
	}

	//check if the list head was emptu so we can set new head
	if (headPtr == nullptr)
	{
		headPtr = temp;  
	}
	numNodes++;

	
}


//_____________________________________REMOVE FROM LIST_______________________________________________________//
template<class T>
void MyList<T>::remove(T data)
{
	Node<T> *current = headPtr;
	Node<T> *previous = nullptr;

	while(current != nullptr) //untill reaches end of list
	{
		if(current->getData() == data)
		{
			if(previous != nullptr) //if previous is not the head
			{
				previous->setNext(current->getNext()); 
				delete current;
				return;
			}
			else //if previous is the head
			{				
				//deleting 1st thing in list:
				headPtr = current->getNext(); //sets head to next in list
				delete current;
				return; //exit after deleting head of list
			}
		}
		previous = current;
		current = current->getNext();//otherwise move to next one
	}
	numNodes--;
	return;
}


//_____________________________________CHECK LIST_______________________________________________________//
template<class T>
bool MyList<T>::contains(T data)
{
	Node<T> *current = headPtr;
	while(current != nullptr) //untill reaches end of list
	{
		if(current->getData() == data)
		{
			return true;
		}
		current = current->getNext();//otherwise move to next one
	}
	return false; // if never found 
}



//_____________________________________BUBBLE SORT LIST_______________________________________________________//
template<class T>
void MyList<T>::Bsort()
{	
	Node<T> *current = headPtr;
	Node<T> *previous = nullptr;

	for (int i  = 0; i < numNodes; i++) //keep track of where is the end of list
	{
		current = headPtr;	//reset
		previous = nullptr;

		while(current != nullptr) //untill head reaches end of list
		{	
				if(previous != nullptr) //if previous is not last
				{	
					if(current->getData() < previous->getData())
					{
						T data = previous->getData();	
						previous->setData(current->getData());  
						current->setData(data);					
					}
				}

				previous = current;
				current = current->getNext();//otherwise move to next one
		}
	}
}




//_____________________________________OUTPUT LIST_______________________________________________________//
template<class T>
void MyList<T>::output()
{
	Node<T> *current = headPtr;
	cout << "SORTED LIST:\t";

	while(current != nullptr) //all list
	{
		cout << current->getData() << " | ";
		current = current->getNext();//points current to new next
	}
	cout << endl;
}




//_____________________________________DESTRUCTOR_______________________________________________________//
template<class T>
MyList<T>::~MyList()
{   
	Node<T> *previous = nullptr;
	Node<T> *current = headPtr;

	while(current != nullptr)
	{
		previous = current;
		current = current->getNext();
		delete previous;
	}
}
