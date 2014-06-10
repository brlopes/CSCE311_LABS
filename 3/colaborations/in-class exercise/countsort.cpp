#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// This is a non-stable countsort. 
// nums is the array, n is the size, and max is the value of the
// biggest number in the array (i.e. the data value range is 0-max).
// This version uses index 0 of the nums array, unlike our heapsort.
void countsort(int nums[], int n, int max)
{
   int count[max]; // count array

   // Initialize count array
   for (int i = 0; i < max; i++)
	count[i] = 0;
   // Do the counting
   for (int i = 0; i < n; i++)
	count[nums[i]]++;
  // Loop through the count array and put the values back
  // into array nums
  int sortindex = 0;
  for (int i = 0; i < max; i++)
	if (count[i]>0)
		for (int j = 0; j < count[i]; j++)
			nums[sortindex++] = i;	
}

int main()
{
  const int MAXVAL = 100000;
  const int SIZE = 500000; // 5000 was too small, went too fast
  int nums[SIZE];
  srand(time(NULL)); // Seed random number generator

 // Get random integers between >=0 and < 100000
 for (int i = 0; i < SIZE; i++)
    nums[i] = rand() % MAXVAL; 

 // Uncomment if you want the output to show the random numbers
 //for (int i = 0; i < SIZE; i++)
 //  cout << nums[i] << " ";
 //cout << endl << endl;
 
 // Sort
 countsort(nums, SIZE, MAXVAL); 

 // Uncomment if you want the output to show the random numbers
 //for (int i = 0; i < SIZE; i++)
 //  cout << nums[i] << " ";
 //cout << endl << endl;
	
 return 0;
}

