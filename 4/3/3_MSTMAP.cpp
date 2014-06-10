//issues...

//#include "NodeMap.h"
#include <stdio.h>
#include <limits.h> //INT_MAX size
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <map>  


using namespace std;

#define V 15 //max nodes/edges
 

int minKey(int key[], bool mstSet[])
{
	int min = INT_MAX;
	int min_index = 0;

	for (int v = 0; v < V; v++)
	{

		if (mstSet[v] == false && key[v] < min)
		{
			min = key[v];
			min_index = v;
		}
	}
	return min_index;
}


void print(int parent[], int n, int graph[V][V])
{
	int temp;
	printf("Edge\tWeight\n");	
	
	for (int i = 1; i < V; i++)
	{
		cout << "PARENT: " << parent[i] << endl;
		cout << "graph[i][parent[i]]: " << graph[i][parent[i]] << endl;

		int temp = parent[i];

		cout << parent[i] << " - " << i << "\t" << graph[i][temp] << endl;
	}
}



void MST(int graph[V][V])
{
	int parent[V]; 
	int key[V]; 
	bool mstSet[V]; 
 
	for (int i = 0; i < V; i++)
	{
		key[i] = INT_MAX;
		mstSet[i] = false;
	}
	
	key[0] = 0;  
	parent[0] = -1; 

	for (int count = 0; count < V-1; count++)
	{
		int u = minKey(key, mstSet);
		//cout << "u: " << u << endl;
		mstSet[u] = true;
 	
		for (int v = 0; v < V; v++)
		{
			if(graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
			{
				parent[v]  = u;
				key[v] = graph[u][v];
			}
		}
	}
 
	//print(parent, V, graph);

	
}



int minDistance(int dist[], bool sptSet[])
{
   //Initialize min value
   int min = INT_MAX;
   int min_index = 0;
 
   for (int i = 0; i < V; i++)
   {
     if ( (sptSet[i] == false) && (dist[i] <= min) )
	 {
         min = dist[i];
		 min_index = i;
	 }
   }
   return min_index;
}




int main()
{
	

	//edges and weight starting at 0
int graph[V][V] =	{	{},
							{0, 0, 271, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},			//#1 JBER
							{0, 271, 0, 221, 0, 0, 0, 0, 18, 239, 0, 0, 0, 0, 0, 0},	//#2 Tikahtnu
							{0, 0, 221, 0, 0, 119, 0, 260, 218, 0, 0, 0, 0, 240, 0, 0},	//#3 Science&Nature
							{0, 0, 0, 0, 0, 131, 79, 0, 0, 0, 0, 0, 0, 0, 125, 076},	//#4 Sullivan Arena
							{0, 0, 0, 119, 131, 0, 0, 0, 0, 0, 0, 0, 0, 0, 145, 0},		//#5 Merril Field
							{0, 0, 0, 0, 79, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 158},		//#6 Anchorage Museum
							{0, 0, 0, 260, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 0, 0},		//#7 AK Railroad
							{0, 0, 18, 218, 0, 0, 0, 0, 0, 0, 0, 0, 0, 209, 0, 0},		//#8 Cheney Lake
							{0, 0, 239, 0, 0, 0, 0, 0, 125, 0, 0, 189, 0, 29, 0, 0},	//#9 Totem 8
							{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 161, 0, 0, 0, 0},			//#10 Campbell Creek
							{0, 0, 0, 0, 0, 0, 0, 0, 0, 189, 161, 0, 189, 138, 0, 0},	//#11 Crime Lab
							{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 189, 0, 94, 0, 14},		//#12 Golden Donuts
							{0, 0, 0, 24, 0, 0, 0, 0, 209, 29, 0, 138, 94, 0, 81, 0},	//#13 UAA
							{0, 0, 0, 0, 125, 145, 0, 0, 0, 0, 0, 0, 0, 81, 0, 102},	//#14 Don Jose
							{0, 0, 0, 0, 76, 0, 158, 0, 0, 0, 0, 0, 14, 0, 102, 0},		//#15 Steamdot Coffee

						 };
	
	MST(graph);
 
    return 0;
}

