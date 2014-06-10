#include "node.h"
#include <iostream>

using namespace std;


//starting at the top, work our way down the binary tree
void traverseTree(node *currentRoot)
{
	if(currentRoot->left != nullptr)		//check if there is a left child
		traverseTree(currentRoot->left);	//if there is we can visit it

	cout << currentRoot->getID() << " " << currentRoot->getName() << endl;

	if(currentRoot->right != nullptr)		//check if there is a right child
		traverseTree(currentRoot->right);	//if there is we call traverse on that node
	
}

//to clean up the tree allocated memory
void deleteTree(node *root)
{
	if(root->left != nullptr)	//check left
		deleteTree(root->left);	//if yes, recursive delete it
	if(root->right != nullptr)	
		deleteTree(root->right);
	delete root;	//delete current node

}



int main()
{

	//creates the root node, points null everywhere else for now
	node *root = new node(10, "Bill");
	
	
	//now we set it up so the root's left points to newNode and newNode parent is root:
	node *newNode = new node(5, "Fred"); //creates left child
	root->left = newNode;//note that if not used public variable (opose to private+gets/sets) this would be root->getLeft() = ...
	newNode->parent = root; //link from child to root

		
	//to make a new next child subnode, using the same variable newNode but changing pointers
	newNode = new node(1, "Carrol");//creates a new sub child node, loosing the pointer to Fred but Fred is already pointed tru root
	root->left->left = newNode;		//where root->left is old newNode, and points to a new left of that (subchild location)
	newNode->parent = root->left;	//points the parent of this newNode object to the left of root (fred, 5)
	/*
	another method to make new next subnode carol, using a new variable newNodeChild:
	node *newNodeChild = new node(1, "Carol");	//creates a new sub child node
	newNode->left = newNodeChild;				//points left of parent NewNode to newNodeChild object
	newNodeChild->parent = newNode;				//points the newNodeChild object to its parent newNode
	*/
	 

	//now we create the right part of this binary tree:
	newNode = new node(20, "BoB");	//creates new node to the right of tree
	root->right = newNode;			//points the right of main root to this newNode 
	newNode->parent = root;			//points the parent of newNode to root  

	//to make left child of Bob, Ted (subchild of left root):
	newNode = new node(15, "Ted");	//creates new node to the be the left child of root->right
	root->right->left = newNode;	//points in the structure of tree, under the root-right child, in the left of it
	newNode->parent = root->right;  //then points the parent to that same root->right
	
	//then to make right child child of Bob,
	newNode = new node(25, "Alice");
	root->right->right = newNode;
	newNode->parent = root->right;
	 
	 //to create a printout routine, we create a recursion -->in_order_traversal: left->current->right
	traverseTree(root);

	//to clean up allocated memory use a recursive bottom-up, left-right cleaning function
	deleteTree(root);//check it out using debugger

	 
	//cout << root->getName() << endl;


	return 0;
}