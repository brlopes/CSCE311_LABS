#include "Node.h"
#include <cstdlib>

using namespace std;

template<class T>
Node<T>::Node()
{
	next = nullptr;
	previous= nullptr;
	left= nullptr;
	right = nullptr;
	
} 

template<class T>
Node<T>::Node(T n) 
{
	data = n;
	next = nullptr;
}

template<class T>
void Node<T>::setData(T n)
{
	data = n;
}

template<class T>
T Node<T>::getData()
{
	return data;
}
//____________________________________________
template<class T>
void Node<T>::setNext(Node *Tnext)
{
	this->next = Tnext;
}

template<class T>
void Node<T>::setPrev(Node *Tprev)
{
	this->prev = Tprev;
}


template<class T>

void Node<T>::setLeft(Node *Tleft)
{
	this->next = Tleft;
}


template<class T>
void Node<T>::setRight(Node *Tright)
{
	this->right = *Tright;
}


template<class T>
Node<T>* Node<T>::getNext()
{
	return next;
}












template<class T>
Node<T>::~Node()
{
}
