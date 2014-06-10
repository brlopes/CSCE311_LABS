/*
Bruno Lopes	CSCE-311
sample of implementation of the STACK data structure using the STL

MAP:
	associate a key to an object

*/

#include <iostream>
#include <cstdlib>
#include <string>

#include <map>  //the map


using namespace std;



int main()
{

	//to create a map:  map<key (data type), object>
	map<string, string> planets;

	//to seek inside the map using a STD iterator
	map<string, string>::iterator p;  //MUST MATCH MAP TYPE


	//we can overload the array operator, to map string-to-string:
	planets["mercury"] = "The hot planet";
	planets["Venus"] = "atm sulf acid";
	planets["Earth"] = "home";
	planets["Mars"] = "red planet";
	planets["Jupiter"] = "largest planet";
	planets["Saturn"] = "has rings";
	planets["Uranus"] = "tilts sideways";
	planets["Neptune"] = "fast winds";
	planets["Pluto"] = "dwarf planet";


	//to OUTPUT from map:
	cout << planets["Mars"] << endl; //like an array

	//to find on map:
	if(planets.find("Pluto") == planets.end()) //if seek returns end, not found
			cout << "Ceres NOT FOUND!!" << endl;
	else
		cout << "FOUND IT !" << endl;

	//to modify (planets.erase(key):
	planets.erase("Pluto");

	//to iterate tru map, key+values become pairs, we can access via .first(key) and .second(value):
	cout << "To iterate through the map: " << endl;
	
	p = planets.begin();


	while(p != planets.end())
	{
		//cout << p.first << endl;
		//cout << planets.first << endl;
		cout << p->first << " MAPS TO " << p->second << endl;
		//	planets.first << endl;
		//cout << planets.at[p] ;//wrong at type? how can I tell whats asked after the ".at" on VS2010 ?
		//cout << planets.at(p) ;
		//cout << planets.equal_range(p);
		//cout << planets.get_allocator();
		//cout << planets.key_comp(p);
		//cout << planets.value_comp(p);
		p++;
	}








	return 0;
}
