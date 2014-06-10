#pragma once
#include<string>

using namespace std;

class node
{
private: 
	int id;
	string name;

public:
	node(void);
	node(int id, string name);//another constructors that takes id and name
	node *parent; //pointer to another node object, opose to using private variables and use set()/get() functions
 	node *left;		//normaly this would be private, with acessors/mutators  
	node *right;
	 

	//the following are some shortcuts to speed up, but bad practice:
	int getID();			//returns the private id
	void setID(int newid);	//sets a new id
	string getName();		//get the private string
	void setname(string newname);	//sets string

	~node(void);


};

