/*
Bruno Lopes	CSCE-311
sample of implementation of the STACK data structure using the STL
:


stacks can take common data types: strings, chars, ints, classes etc..

*/

#include <iostream>
#include <cstdlib>
#include <string>

#include <set>  //the stack itself


using namespace std;



int main()
{
	//making a set of chars:
	set<char> s;

	//iterator created to seek in the set(oppose to c++11 for loop class example):
	set<char>::iterator p;


	//adding to the set
	s.insert('A');
	s.insert('D');
	s.insert('D');// sets do no add repeated, just skips it
	s.insert('C');
	s.insert('A');
	s.insert('B');
	
	cout << "contents of set: " << endl;
	p = s.begin(); //set iterator (*pointer) to the begining of set


	//going tru the set using an iterator (pointer)
	while( p != s.end())
	{
		cout << *p << endl;
		p++;
	}
		

	//check contents of set:
	cout << "\n DOES IT CONTAINS G ? " << endl;
	if(s.find('G') == s.end())
		cout << "NO!!!  element not FOUND on this SET! " << endl;
	else
		cout << "YESS!!! element found on this SET" << endl;

	 

	//to remove stuff from set:
	cout << "REMOVING STUFF: " << endl;
	s.erase('A');
	p = s.begin(); //set iterator (*pointer) to the begining of set
	while( p != s.end())
	{
		cout << *p << endl;
		p++;
	}



	return 0;
}
