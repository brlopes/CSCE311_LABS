/*
Bruno Lopes	CSCE-311
sample of implementation of the vector data structure using the STL
DONT NEED TO WORRY ABOUT SIZE LIKE IN ARRAYS !!
VECTOR ALLOCATES ITSELF THE PROPER SIZE
VECTOR WE CAN USE ANY DATA TYPE (STRINGS CLASSES ETC)
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
	v.push_back(10); //add 10 to the vector
	v.push_back(100); //add 100 to the vector

	//we can make a loop to keep adding stuff to the vector:
	cout << "ENTER STUFF TO THIS VECTOR, -1 TO EXIT" << endl;
	int num;
	cin >> num;


	while(num != -1)
	{
		v.push_back(num); //pushing to the back of the vector
		cin >> num;
	}


	//and then output whats inside the vector:
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " "; //we can use array notation to access the vector
	cout << endl;


	



	return 0;
}
