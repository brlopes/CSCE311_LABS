
 
//#include "NodeMap.h"
#include <stdio.h>
#include <limits.h> //INT_MAX size
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <map>  

using namespace std;

#define V 16 //max nodes/edges
 

int minDistance(int dist[], bool sptSet[])
{
   //Initialize min value
   int min = INT_MAX;
   int min_index;
 
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




void print(int dist[], int n)
{

	cout << "NODE\t\tWEIGHT" << endl;

	for (int i = 1; i < V; i++)
		cout << i <<"\t\t" << dist[i] << endl;
}
 




int dijkstra(double graph[V][V], int src)
{
	int dist[V];    
 	bool sptSet[V]; 
                     
 	for (int i = 0; i < V; i++)//set all to infinity*
	{
		dist[i] = 100000;
		sptSet[i] = false;
	}
     
	dist[src] = 0;		// Distance of source 0
 
	// Find shortest path for all vertices
	for (int count = 0; count < V-1; count++)
	{  
		int u = minDistance(dist, sptSet);//extract min
 		sptSet[u] = true;
 
		for (int v = 0; v < V; v++)
		{
			if ( (!sptSet[v] && graph[u][v]) && (dist[u] != INT_MAX) && (dist[u]+graph[u][v] < dist[v]) )
			{
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}
 
     print(dist, V);
	 return 0;
}
 

int main()
{

/*	ifstream f;
	f.open("data");
	int numNodes;
	f >> numNodes;
	for (int i = 0; i < numNodes; i++)
	{
		int nodeNumber;
		f >> nodeNumber;
		string nodeName;
		f.ignore();	
		getline(f, nodeName);
		int numEdges;
		f >> numEdges;
		cout << "Read in: " << nodeNumber << " " << nodeName << " edges: " << numEdges << endl;
		for (int j = 0; j < numEdges; j++)
		{
			int destNode;
			double weight;
			f >> destNode >> weight;
			cout << "  " << destNode << " " << weight << endl;
		}
	}
*/


	//edges and weight starting at 0
	double graph[V][V] =	{	{},
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

	
	int source = 0;
	int input;
   
	while(source != -1)
	{
		cout << "\nINPUT DISTANCE, -1 to exit: ";
		cin >> input;

		if(input == -1)
			break;

		source = dijkstra(graph, input);
	}

    return 0;
}

