/* Bruno Lopes, Best (not stable) count sort ever built!
 * CSCE 311 Assignment #3-1
 * COUNT sort (not stable), did my best on the algorithm to keep O(n)
 * to alter values of n or k change the defined max/range
 * the program was built in order to properly run on O(n) and demonstrate large values of k
 * Large values of K can decrease perfomance drastically, Compared to QuickSort it will output 
 * better results with lower values of k, keeping k below 5 count sort usually performed best.
 * 
*/

#include <iostream>
#include <array>
#include <time.h>

using namespace std;

#define MAX_SIZE 10		//n
#define RANDRANGE 9//000		//k



int main()
{
	int i, j, k, temp;
	int count= 0;
   

	int A[MAX_SIZE] = {0};
	int B[MAX_SIZE] = {0};
	int C[RANDRANGE] = {0};
	//int* Ainput = (int*)malloc(sizeof(int) * MAX_SIZE);
	//int* Boutput = (int*)malloc(sizeof(int) * MAX_SIZE);
	//int* Ctemp = (int*)malloc(sizeof(int) * MAX_SIZE); 
	
	

	cout << "=========================================" << endl;
	cout << "SORT TYPE: COUNT-SORT:" << endl;
	cout << "Array size(n): " << MAX_SIZE << endl;
	cout << "Array elements size(k): " << RANDRANGE << endl;
	cout << "=========================================" << endl;


	//fill array A[] with random values determined by MAX_SIZE of array
	cout << "Array A[]: \t";
	for (i = 0; i < MAX_SIZE; i++)
    {
		A[i] = rand() % RANDRANGE;
		cout << A[i] << " ";
    }
	cout << endl;


	//fill array C[] with zeros by the size of RANDRANGE
	cout << "C[zeros]: \t";
	for (i = 0; i < RANDRANGE; i++)
    {
		//C[i] = 0;
		cout << C[i] << " ";
    }
	cout << endl;

	
	cout << "C[found]: \t";
	for (i = 0; i < MAX_SIZE; i++) 
	{
			C[A[i]]++;				//for every element of A[n] increment C[k]
			cout<<C[A[i]]<< " ";
	}
	cout << endl;
	


	//Confirm values input on C
	cout << "C[counted]: \t";
	for (i = 0; i < RANDRANGE; i++)
    {
		cout << C[i] << " ";
    }
	cout << endl;

	

	//output sorted values onto B
	for (i = 0; i < RANDRANGE; i++)
    {
		while(C[i] > 0)
		{
			if(count != MAX_SIZE) //keeping both boundaries (A/B[n] vs C[k];
			{
				B[count] = i;
				count++;
				C[i]--; //very necessary sanity check
			}
		}
	}

			
/*	//Confirm clear values input on C
	cout << "C[clear]: \t";
	for (i = 0; i < RANDRANGE; i++)
    {
		cout << C[i] << " ";
    }
	cout << endl;
*/


	//check values on B
	cout << "B[sorted]: \t";
	for (i = 0; i < MAX_SIZE; i++)
    {
		cout << B[i] << " ";
    }
	cout << endl;
	

	system("PAUSE");

}
