//main.cpp- Binary tree main entry point
//Written by Alex Kohler


#include <iostream>
using namespace std;


template<typename DATA_TYPE> struct TreeNode
{
	TreeNode(const DATA_TYPE& value, TreeNode* left = NULL, TreeNode* right = NULL)
	{
		Value = value;
		Left = left;
		Right = right;
	}

	DATA_TYPE Value;
	TreeNode* Left;
	TreeNode* Right;

	bool IsLeaf() const
	{
		return Left == NULL && Right == NULL;
	}



};




TreeNode<char>* treeConstructor(char* expression)
{
	TreeNode<char>* treeRoot;
	TreeNode<char>* currentNode;
	treeRoot = NULL;
	currentNode = NULL;

	for (int i=0; expression[i] != '\0'; i++)
	{
		if (expression[i] >= '0' && expression[i] <= '9')
		{
			TreeNode<char>* node = new TreeNode<char>(expression[i]);
			if (currentNode == NULL) 
				treeRoot = currentNode = node;
			else
				currentNode->Right = node;
		}

		if ( expression[i] == '+')
		{
			TreeNode<char>* newRoot =new TreeNode<char>(expression[i]);
			newRoot->Left = treeRoot;
			treeRoot = newRoot;
			currentNode = newRoot;
		}

		if ( expression[i] == '-')
		{
			TreeNode<char>* newRoot =new TreeNode<char>(expression[i]);
			newRoot->Left = treeRoot;
			treeRoot = newRoot;
			currentNode = newRoot;
		}

		if ( expression[i] == '*' && currentNode->Right==NULL)
		{
			TreeNode<char>* newRoot =new TreeNode<char>(expression[i]);
			newRoot->Left = treeRoot;
			treeRoot = newRoot;
			currentNode = newRoot;
		}

		else if (expression[i] == '*')
		{
			TreeNode<char>* newChild = new TreeNode<char>(expression[i]);
			newChild->Left =currentNode->Right;
			currentNode->Right = newChild;
			currentNode = newChild;
		}




		if ( expression[i] == '/' && currentNode->Right==NULL)
		{
			TreeNode<char>* newRoot = new TreeNode<char>(expression[i]);
			newRoot->Left = treeRoot;
			treeRoot = newRoot;
			currentNode = newRoot;

		}



		else if (expression[i] == '/')
		{
			TreeNode<char>* newChild = new TreeNode<char>(expression[i]);
			newChild->Left =currentNode->Right;
			currentNode->Right = newChild;
			currentNode = newChild;
		}
	}

	return treeRoot;

}


float ValueOf( TreeNode<char>* node)
{

	float value;
	if (node->IsLeaf() == true)
	{
		return	value = node-> Value - '0'; 
	}

	else 
	{
		if (node->Value == '*')
		{
			return	value = ValueOf(node->Left) * ValueOf(node->Right);
		}

		if (node->Value == '/')
		{
			return	value = ValueOf(node->Left) / ValueOf(node->Right);
		}

		if (node->Value == '+')
		{
			return	value = ValueOf(node->Left) + ValueOf(node->Right);
		}

		if (node->Value == '-')
		{
			return	value = ValueOf(node->Left) - ValueOf(node->Right);
		}
		

	}

}




void main ()
{
	char input[25];
	cin >> input;
	TreeNode<char>* treeRoot;
	treeRoot = treeConstructor (input);
	cout << "Success!" << endl;
	cout << ValueOf(treeRoot) << endl;

	system("pause");

}
