/*	Bruno Lopes
 *	CSCE 311 Assignment #2-6
 * HEAP sort
*/


#include <math.h>
#include <iostream>
#include <array>
#include <time.h>

using namespace std;

void max_heapify(int *a, int i, int n);
void heapsort(int *a, int n);
void build_maxheap(int *a, int n);

#define MAX_SIZE 5000
#define RANDRANGE 100000


int main()
{

    int i, j;
	int n = MAX_SIZE;
	int* a = (int*)malloc(sizeof(int) * MAX_SIZE);

	double diff, cclock;
	srand(time(NULL));
	clock_t start, end;
	
	
    for (i = 1; i < n+1; i++)
    {

        a[i] = rand() % RANDRANGE;
    }


	start = clock();
    build_maxheap(a,n);
    heapsort(a, n);
	end   = clock();
	diff = (end - start);
	cclock = CLOCKS_PER_SEC;
	diff = diff/cclock;



	cout << "HEAP SORT:" << endl;
	cout << "Array size: " << MAX_SIZE << endl;
	cout << "Array elements size: " << RANDRANGE << endl;
	cout << "Time enlapsed: " << diff << "s" << endl;

	
	//OUTPUT test:
/*	
    cout << "HEAP SORTED output: " << endl;
    for (j = 1; j < n; j++)
    {
        cout<<a[i]<<endl;
    }
*/

}


void build_maxheap(int *a, int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        max_heapify(a, i, n);
    }
}

void max_heapify(int *a, int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2*i;
    while (j <= n)
    {
        if (j < n && a[j+1] > a[j])
            j = j+1;
        if (temp > a[j])
            break;
        else if (temp <= a[j])
        {
            a[j/2] = a[j];
            j = 2*j;
        }
    }
    a[j/2] = temp;
    return;
}

void heapsort(int *a, int n)
{
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        max_heapify(a, 1, i - 1);
    }
}

