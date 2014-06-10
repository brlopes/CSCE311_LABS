#pragma once
#include <string>

using namespace std;

class Node
{
private: 
	// If the children are null then the question is guessing the animal, otherwise it is narrowing down the field to a particular animal
	Node *no = nullptr;
	Node *yes = nullptr;
	string question = "";	
public:
	Node();
	Node(Node *no, Node *yes, string question);
	~Node();
	void setNo(Node *no);
	Node* getNo();
	void setYes(Node *yes);
	Node* getYes();
	string getQuestion();
};

