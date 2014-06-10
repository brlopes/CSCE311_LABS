/*
Bruno Lopes	CSCE-311
sample of implementation of the vector data structure using the STL
DONT NEED TO WORRY ABOUT SIZE LIKE IN ARRAYS !!
VECTOR ALLOCATES ITSELF THE PROPER SIZE
VECTOR WE CAN USE ANY DATA TYPE (STRINGS CLASSES ETC)

ITERATORS: ALREADY included ON STD LIBRARY:
same as: 
#include std::vector;
*/

#include <iostream>
#include <cstdlib>
#include <string>

#include <vector> // the vector itself

using namespace std;





int main()
{
	//to make a vector, make data type vector which is a template class type
	//or vector <string>, vector <class>
	vector<int> v; //creates vector v

	//to add stuff to the vector:
	v.push_back(0); //add 10 to the vector
	v.push_back(1); //add 100 to the vector
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);


	//the iterator itself, from #include std::vector;, but already on using namespace std;
	vector<int>::iterator p; //p as a pointer

	p = v.begin();

	//we can use the iterator to change/set stuff:
	*p = 000;

	//we can insert at a specific position (iterator p currently def as v.begin):
	v.insert(p, 9); //inserts 9, and push everything else down the list

	//we can take stuff out of the end of vector:
	v.pop_back(); //pops out last element (4) off vector

	//we can erase at specific location
	v.erase(v.begin()+2); //erases the v[1] element(counts 0), the number 1 and pushes list up



	
	while(p != v.end())
	{
		cout << *p << endl;
		p++;
	}

	//we can also clear all elements in the vector list:
	v.clear();


/*
	c++ 11
	//we can use the ranged-for loop which is new from C++11
	for (auto &i : v) //&reference to the ith item
	{
		i++; //it would add +1 to each value on v
	}

	for (auto i : v) //auto detects data type of v
	{
		cout << i << endl;
	}
*/




	return 0;
}
