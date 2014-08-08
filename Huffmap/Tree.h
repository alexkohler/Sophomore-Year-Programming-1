//Tree.h- tree structure implementation
//Written by Alexander Kohler


#pragma once

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

	bool operator > (const TreeNode& compareTo) 
	{ 
		return(Value > compareTo.Value); 
	} 
	bool operator < (const TreeNode& compareTo) 
	{ 
		return(Value < compareTo.Value); 
	} 
	bool operator == (const TreeNode& compareTo) 
	{ 
		return(Value == compareTo.Value); 
	} 



	bool IsLeaf() const
	{
		return Left == NULL && Right == NULL;
	}


};