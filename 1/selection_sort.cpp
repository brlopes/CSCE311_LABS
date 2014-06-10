/*	Bruno Lopes
 *	CSCE 311 Assignment #1
 * Selection sort
 */
#include <iostream>
#include <stdlib.h>    //rand
#include <time.h> 
#include <array>

using namespace std;


int main()
{
	int arrayA[5] = {0};
	int n, size, low, buff;
	
	size = (sizeof(arrayA))/4;
	cout << "ARRAY SIZE: " << size << endl;
	

	//fill array
	for(n=0; n<size; n++)
	{
		arrayA[n] = rand() % 10 + 1; //realistic
	}
	

	//display array
	cout << "Received array:  " ;
	for(n=0; n<size; n++)
	{
		cout << arrayA[n] << " | " ;
	}
	cout << endl;
	
	
	//sort array
	cout << "Sorted array:  ";
	for(n=0; n<size-1; n++) //pos 
	{
		low = n;
		for(int i=n+1; i<size; i++) //compare
		{
			if(arrayA[i] < arrayA[low])
			{
				buff = arrayA[n];
				arrayA[n] = arrayA[i];
				arrayA[i] = buff;
			}
		}
	}
	
	
	//display sorted array
	cout << "Sorted array:  ";
	for(n=0; n<size; n++) //index
	{
		cout << arrayA[n] << " | " ;
	}

	cout << endl;
	system("pause");

}