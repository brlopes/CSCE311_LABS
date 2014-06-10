#include "node.h"


node::node(void) : id(0), name("unknown!"), parent(nullptr), left(nullptr), right(nullptr) 
{

}


//the other constructor that takes and sets id/name
node::node(int newid, string newname) :  parent(nullptr), left(nullptr), right(nullptr) 
{
	this->id = newid;
	this->name = newname;
}


//returns the id
int node::getID()
{
		return id;	
}


//sets the new id
void node::setID(int newIDpassed)
{
		this->id = newIDpassed;
}


//returns the name string from private
string node::getName()
{
		return name;
}


//pass and set a new string to name
void node::setname(string newname)
{
		this->name = newname;
}



	node::~node(void)
{
}
