#pragma once
#include "Node.cpp" //instead of .h -> way c++ handles templates
template<class T>

class MyList
{
private:
	Node<T> *headPtr;	
	Node<T> *tailPtr;	
	int numNodes;

public:
	MyList(void);//constructor initialize linklist

	void add(T data); // ads to the list
	void remove(T data); //remove num from list
	bool contains(T data); // T/F if num is in the list
	void output(void);

	void Bsort();
	
	~MyList(void);

};
