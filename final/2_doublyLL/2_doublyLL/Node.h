#pragma once
class Node
{
private:
	int n;
	Node *next;
public:
	Node(void);
	Node(int number);
	void setNumber();
	int getNumber(int number);
	void setNext(Node *next);
	Node* getNext;

	~Node(void);
};

/*
#pragma once
template<class T> //lets make a node of data type T


class Node
{
private:
	T data;		//store some data (generic T type)
	Node *next;		//link to next node
public:
	Node();
	Node(T n);
	void setData(T n);	//set #
	T getData();		//get #
	void setNext(Node *next);	//set node that comes after
	Node* getNext();			//retrieve next node
	~Node();
};
