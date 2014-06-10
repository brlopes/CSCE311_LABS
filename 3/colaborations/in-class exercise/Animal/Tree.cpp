#include "Tree.h"
#include <iostream>

using namespace std;

Tree::Tree()
{
	// Initialize with 5 questions and a bunch of animals
	Node *bee = new Node(nullptr, nullptr, "Is it a bee?");
	Node *mosquito = new Node(nullptr, nullptr, "Is it a mosquito?");
	Node *salmon = new Node(nullptr, nullptr, "Is it a salmon?");
	Node *eagle = new Node(nullptr, nullptr, "Is it a eagle?");
	Node *sealion = new Node(nullptr, nullptr, "Is it a sealion?");
	Node *cow = new Node(nullptr, nullptr, "Is it a cow?");
	Node *bloodsucker = new Node(bee, mosquito, "Does it suck blood?");
	Node *feathers = new Node(bloodsucker, eagle, "Does it have feathers?");
	Node *fly = new Node(salmon, feathers, "Does it have fly?");
	Node *swim = new Node(cow, sealion, "Does it swim?");
	Node *mammal = new Node(fly, swim, "Is it a mammal?");

	root = mammal;
}


// Recursively traverse the tree and delete nodes to free up memory
// when the destructor is called
Tree::~Tree()
{
	freeMemory(root);
}

void Tree::freeMemory(Node *root)
{
	if (root->getNo() != nullptr)
		freeMemory(root->getNo());
	if (root->getYes() != nullptr)
		freeMemory(root->getYes());
	delete root;
}

// Root is the current node in the tree while
// parent is the parent node in the tree (needed to change the pointers when we add a new node)
void Tree::askQuestion(Node *root, Node *parent)
{
	// Ask the question, which may be narrowing does the category or asking if it is an animal
	cout << root->getQuestion() << endl;
	char answer;
	cin >> answer;

	// If no children, this is a terminal node and we asked the animal
	if (root->getNo() == nullptr)
	{
		// If we were right, do nothing
		if (answer == 'y')
		{
			cout << "Wow, I guessed it correctly!";
			return;
		}
		else
		// Ask the player for a new animal
		{
			string animal;
			string question;
			char yesOrNo;
			cout << "What animal were you thinking of? " << endl;
			cin.ignore();	// pesky newline from cin
			getline(cin, animal);
			cout << "Enter a yes/no question to distinguish your animal." << endl;
			getline(cin, question);
			cout << "Is the answer yes or no? (y/n)." << endl;
			cin >> yesOrNo;
			// Create animal node
			Node *newAnimal = new Node(nullptr, nullptr, "Is it a " + animal);
			// Create category node and link the animal nodes underneath it
			Node *newCategory = nullptr;
			if (yesOrNo == 'y')			
				newCategory = new Node(root, newAnimal, question);
			else
				newCategory = new Node(newAnimal, root, question);
			// Link the parent to the new category node instead of the animal node it currently links to
			if (parent->getNo() == root)
				parent->setNo(newCategory);
			else
				parent->setYes(newCategory);
		}
	}
	// Otherwise we asked a category question and move to a child node
	else
	{
		if (answer == 'y')
			askQuestion(root->getYes(), root);
		else
			askQuestion(root->getNo(), root);
	}
}

void Tree::playGame()
{
	// Start asking questions at the root
	askQuestion(root, nullptr);
}