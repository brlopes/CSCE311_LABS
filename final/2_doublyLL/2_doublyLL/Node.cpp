#include "Node.h"
#include <cstdlib>//where NULL is defined inside cstd lib

using namespace std;

Node::Node(void)
{
	next = nullptr;
}


Node::~Node(void)
{
}

/*
#include "Node.h"
#include <cstdlib>//where NULL is defined inside cstd lib

using namespace std;

template<class T>
Node<T>::Node()
{
	next = nullptr; //or NULL(cstd lib)

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


//takes a pointer to the next node, and store on next variable
template<class T>
void Node<T>::setNext(Node *next)
{
	this->next = next;
}

template<class T>
Node<T>* Node<T>::getNext()
{
	return next;
}

template<class T>
Node<T>::~Node(void)
{
}
