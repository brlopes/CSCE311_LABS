/*	Bruno Lopes
 *	CSCE 311 Assignment #1
 * Selection sort + Binary Search
 */

import java.util.Scanner;

public class BinarySearch 
{

  //split binary search, takes array and V
 public static int binarySearch(int[] a, int v) 
 {
 int low = 0;
 int high = a.length -1;
 int mid;
  while (low <= high) 
  {
        mid = (low + high) / 2;
        if (a[mid] > v) {
            high = mid - 1;
        } else if (a[mid] < v) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
 System.out.println("\nNOT FOUND");
 return 0;
 }
  
 public static void main(String[] args) 
 {
  int a[] ={5,1,3,7,12,11,9}; //==sudo
  int alength = a.length;
  int v;
  int i;
  int j;
  
 System.out.print("VALUE OF V: ");
 Scanner scan = new Scanner(System.in);
 String s = scan.next();
 v = scan.nextInt();;
  
  
  //display array:
  System.out.println("ORIGINAL ARRAY: ");
  for (i=0; i<a.length; i++)
  System.out.print(" | " +a[i]);
  

   //sort array:
  for (j=1; j < alength; j++) 
  {
   for (i=0; i < alength-j; i++) 
   {
    if (a[i] > a[i+1]) 
    {
     int temp = a[i];
     a[i] = a[i+1];
     a[i+1] = temp;
    }
   }
  }
  
  //display sorted array
  System.out.println("\nMerge sorted:");
  for (i=0;i < alength;i++) 
  {
  System.out.print(" | " +a[i]);
  }
  
  //call binary search
  System.out.println("\nV(" + v + ") found at a[" + binarySearch(a, v) + "]" );
  
  
 }   
 }