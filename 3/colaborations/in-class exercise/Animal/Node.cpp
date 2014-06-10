#include "Node.h"


Node::Node()
{
	// The default is nullptr and ""
}

Node::Node(Node *no, Node *yes, string question)
{
	this->no = no;
	this->yes = yes;
	this->question = question;
}

Node::~Node()
{
}

void Node::setNo(Node *no)
{
	this->no = no;
}

Node* Node::getNo()
{
	return no;
}

void Node::setYes(Node *yes)
{
	this->yes = yes;
}
Node* Node::getYes()
{
	return yes;
}

string Node::getQuestion()
{
	return question;
}
