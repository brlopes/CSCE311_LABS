/*
Bruno Lopes	CSCE-311
EVIL HANGMAN - "not so evil"
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>

using namespace std;


void printman(int points);


int main()
{
	vector<string>::iterator p;		//p as a pointer
	vector<string> v;				//creates vector v, holds all words
	vector<string> goodlist;		//possible matches wordlist

	string word ="";
	string guesses;
	int points = 0;
	vector<bool> disco;
	string input;
	int database = 0;

	srand(time(NULL));

	
	


	//INPUT TO FILE
	string STRING;
	ifstream infile;
	infile.open ("words.txt");
	while(!infile.eof())
    {
	    getline(infile,STRING); 
		v.push_back(STRING);
		database++;
    }
	infile.close();

	cout << "============================================================" << endl;
	cout << "========== WELCOME TO THE HANGMAN NOSTALGIA ================" << endl;
	cout << "============================================================" << endl;
	cout << "+\n+\n+\n";

	

	cout << "WORDs on DATABASE: " << database << endl;
	cout << "PLAYER 2 select a letter: ";
	cin >> input;
	cout << "input: " << input << endl;


	p = v.begin();
	while(p != v.end())
	{
		//cout << "vector[" << p->data() << "] = "; //help to verify whats found

		string text = p->data(); 
		string target = input;
		int idx = text.find(target);


			if (idx!=string::npos)
			{ 
				//matchesnotfound++;
				//cout << "found at index: " << idx << endl;
				//badlist.push_back(p->data());
			}
			else 
			{
				//matchesfound++;
				//cout << "not found" << endl;
				goodlist.push_back(p->data());
			}
		p++;
	}
	//system ("pause");
////////////////////////////////////////////////////////////////////
	p = goodlist.begin();
	bool alive = true;
	string cheat = goodlist[rand() % goodlist.size()];
	word = cheat;
	vector<bool> discovered(word.size(), false);

	while(alive)
	{

		char guess = 'a';
		printman(points);

		for(int i = 0; i < word.size(); ++i)
		{
			if(discovered[i])
			{
				cout << word[i];
			}
			else
			{
				cout << "_";
			}
		}

		cout << endl;
			
		cout << "Next guess: ";
		cin >> guess;


		if(guesses.find(guess) != string::npos)
		{
			cout << "You've guessed that letter, try another\n";
		}
		else
		{
			guesses.append(&guess);

			if(word.find(guess) != string::npos)
			{

				for(int i = 0; i < word.size(); ++i)
				{
					if(word[i] == guess) 
						discovered[i] = true;
				}
			}
			else
			{
				points++;
			}
		}

		if(points == 9)
		{
			printman(points);
			cout << "DEFEAT!!! The correct word is: " << word << endl;
			return 0;
		}

		if(all_of(discovered.begin(), discovered.end(),[](bool b){return b;}))
		{
			cout << "CONGRATULATIONS YOU SAVED THE MAN!!"
				<< endl;
			return 0;
		}
	}


	return 0;
}

//PRINT HANGMAN
void printman(int points)
{

	//system ("cls");
	switch(points)
	{
		case 0:
			cout << "\n\n\n\n\n";
			break;
		case 1:
			cout << "\n\n\n\n_____";
			break;
		case 2:
			cout << "|\n|\n|\n|\n|____";
			break;
		case 3:
			cout << "|/---\n|\n|\n|\n|____";
			break;
		case 4:
			cout << "|/---\n|  o\n|\n|\n|____";
			break;
		case 5:
			cout << "|/---\n|  o\n|  |\n|\n|____";
			break;
		case 6:
			cout << "|/---\n|  o\n| /|\n|\n|____";
			break;
		case 7:
			cout << "|/---\n|  o\n| /|\\\n|\n|____";
			break;
		case 8:
			cout << "|/---\n|  o\n| /|\\\n| /\n|____";
			break;
		case 9:
			cout << "|/---\n|  o\n| /|\\\n| / \\\n|____";
			break;
		default:
			cout << "|/---\n|  o\n| /|\\\n| / \\\n|____";
			break;
	}

	cout << endl;

	return;
}