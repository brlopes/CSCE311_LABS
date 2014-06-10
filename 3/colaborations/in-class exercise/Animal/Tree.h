#pragma once
#include "Node.h"

class Tree
{
private:
	Node *root = nullptr;	
	void freeMemory(Node *root);
	void askQuestion(Node *root, Node *parent);
public:
	Tree();
	~Tree();
	void playGame();

};

