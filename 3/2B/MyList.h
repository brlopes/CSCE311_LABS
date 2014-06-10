#pragma once
#include "Node.cpp"
template<class T>

class MyList
{
private:
	Node<T> *headPtr;
	Node<T> *tailPtr;
	int numNodes;
public:
	MyList();

	void add(T data);

	bool contains(T data); 
	void output();

	void Bsort();

	~MyList(void);

};
