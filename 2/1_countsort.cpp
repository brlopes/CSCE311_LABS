/*	Bruno Lopes
 *	CSCE 311 Assignment #2-6
 * QUICK sort
 on my tests quick sort performed faster compared to heap sort due to the large size of randoms
 if the rand was smaller (more repeated values) quick sort will be worst because it would have a
 hard time finding the median (all same).
 LARGE RAND: quick > heap
 SMALL RAND: quick < heap
*/

#include <iostream>
#include <array>
#include <time.h>

using namespace std;

void quickSort(int a[], int first, int last);
int pivot(int a[], int first, int last);
void swap(int& a, int& b);
void swapNoTemp(int& a, int& b);
void print(int array[], const int& N);


#define MAX_SIZE 5000
#define RANDRANGE 100000



int main()
{
	int i, j;
    int* a = (int*)malloc(sizeof(int) * MAX_SIZE);
	int n = MAX_SIZE;

	double diff, cclock;
	srand(time(NULL));
	clock_t start, end;


	for (i = 1; i < n+1; i++)
    {

        a[i] = rand() % RANDRANGE;
    }

	start = clock();
    quickSort(a, 0, n-1);
	end   = clock();
	diff = (end - start);
	cclock = CLOCKS_PER_SEC;
	diff = diff/cclock;
	

	cout << "HEAP SORTED output: " << endl;
    for (j = 1; j < n; j++)
    {
        cout<<a[i]<<endl;
    }


	cout << "QUICK SORT:" << endl;
	cout << "Array size: " << MAX_SIZE << endl;
	cout << "Array elements size: " << RANDRANGE << endl;
	cout << "Time enlapsed: " << diff << "s" << endl;

}
 
void quickSort( int *a, int a0, int af ) 
{
    int qspivot;
 
    if(a0 < af)
    {
        qspivot = pivot(a, a0, af);
        quickSort(a, a0, qspivot-1);
        quickSort(a, qspivot+1, af);
    }
}
 
int pivot(int *a, int a0, int af) 
{
    int  p = a0;
    int qspivot = a[a0];
	int temp;

    for(int i = a0+1 ; i <= af ; i++)
    {
		if(a[i] <= qspivot)
		{
			temp = a[i];
			a[i] = a[p];
			a[p] = temp;
            p++;
        }
    } 
	temp = a[p];
	a[p] = a[0];
	a[0] = temp;
    return p;
}
