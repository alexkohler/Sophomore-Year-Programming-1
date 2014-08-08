//main.cpp-BST main entry point
//Written by Alex Kohler


#include <iostream>
#include <string>
#include "tree.h"
using namespace std;
//use watch on root and expand to view tree
//then use print function to see alphabetic order 



void main()
{
	string word;
	string remove;
	TreeNode<string>* treeRoot;
	treeRoot = NULL; //give treeRoot an initial value 
	//reads a sentence from cin word-by-word and inserts each word into a BST
	cout << "Please enter an expression: ";
	while (cin.peek() != '\n' )
	{
		cin >> word;
		treeRoot->Insert(word, treeRoot);
	}
	cout << endl << endl;
	treeRoot->InOrderPrint(treeRoot);//prints the tree (using in-order traversal)
	cout << endl << "Please enter a word to remove: "; //prompts for one word to be deleted from BST
	cin >> remove;
	treeRoot->Remove(remove, treeRoot);//deletes the word from BST
	treeRoot->InOrderPrint(treeRoot); //prints the tree again
	cout << endl;

	system("pause");
}
