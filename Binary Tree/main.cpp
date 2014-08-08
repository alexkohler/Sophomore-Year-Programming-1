//main.cpp- Binary tree main entry point
//Written by Alex Kohler


#include <iostream>
#include "tree.h"
using namespace std;


void main ()
{

	char input[25];
	cout << "Please enter an expression to be evaluated" << endl;
	cin >> input;
	TreeNode<char>* treeRoot;
	treeRoot = treeConstructor (input);
	cout << ValueOf(treeRoot) << endl;

	system("pause");

}
