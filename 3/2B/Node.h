#pragma once
template<class T>
class Node
{
private:
	T data;
	Node *next;
	Node *prev;
	Node *left;
	Node *right;
public:
	Node();
	Node(T n);
	void setData(T n);
	T getData();

	void setNext(Node *next);
	void setPrev(Node *prev);
	void setLeft(Node *left);
	void setRight(Node *right);
	
	Node* getNext();


	~Node();
};

