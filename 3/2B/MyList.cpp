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




//__ADD TO THE LIST:
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

	//check if the list was emptu so we can set the head
	if (headPtr == nullptr)
	{
		headPtr = temp;  
	}
	numNodes++;

	
}


/////////////////////__CHECK LIST
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


//SORT LIST
template<class T>
void MyList<T>::Bsort()
{	
	Node<T> *current = headPtr;
	Node<T> *previous = nullptr;
	Node<T> *right = nullptr;
	Node<T> *left = nullptr;
	T data;

	for (int i  = 0; i < numNodes; i++)
	{
		current = headPtr;
		previous = nullptr;

		while(current != nullptr) //untill head reaches end of list
		{	
			
				if(previous != nullptr) //if previous is not last
				{	
					if(current->getData() < previous->getData())
					{
						
						if(previous = headPtr)
						{
							previous->setLeft(*nullptr);
							previous->setPrev(*nullptr);
						}
						else
						{
							previous->setLeft(previous);
						}

					
						previous->setNext(setNext(current));
						previous->setRight(right);  //

						current->setPrev(previous->setPrev(previous));
						current->setNext(setNext(previous));
						current->setLeft(left);
						current->setRight(right);



					}
					else
					{
						//set pointer to left
					}
				}

			previous = current;
			current = current->getNext();//otherwise move to next one
		}
	}
}




///////////////////__OUTPUT LIST
template<class T>
void MyList<T>::output()
{
	cout << "SORTED LIST:\t\t";
	Node<T> *current = headPtr;

	while(current != nullptr) //untill reaches end of list
	{
		cout << current->getData() << " | ";
		current = current->getNext();//otherwise move to next one
	}
	cout << endl;
}


//////////////////////////__DESTRUCTOR
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
