/*
Bruno Lopes	CSCE-311
sample of implementation of the STACK data structure using the STL
:
STACK functions on STL
	top	 = tell us the value on top of the stack
	push = add things on top of stack
	pop = takes thing out of the top of the stack


stacks can take common data types: strings, chars, ints, classes etc..

*/

#include <iostream>
#include <cstdlib>
#include <string>

#include <stack>  //the stack itself


using namespace std;



int main()
{
	//making a stack of chars:
	stack<char> s;



	//INPUT
	cout << "ENTer a line of text: " << endl;
	char next;

	cin.get(next); //reading individual characters
	
	while(next != '\n')
	{
		s.push(next);
		cin.get(next); // reads the next character
	}
	 

	//OUTPUT
	cout << "written backwards: " << endl;
	while( !s.empty() ) //or: while(s.top() != '\n')
	{
		cout << s.top() << endl;
		s.pop();
	}
	


	return 0;
}
