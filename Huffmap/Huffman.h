//Huffman.h- Huffman function implementation

#pragma once
#include "Tree.h"
#include "PriorityQueue.h"
#include <map>

struct SymbolPriority
{
	SymbolPriority(){}

	SymbolPriority(char symbol, int priority)
	{
		Symbol = symbol;
		Priority = priority;
	}

	char Symbol;
	int Priority;

	bool operator > (const SymbolPriority& compareTo) 
	{ 
		return(Priority > compareTo.Priority); 
	} 
	bool operator < (const SymbolPriority& compareTo) 
	{ 
		return(Priority < compareTo.Priority); 
	} 
	bool operator == (const SymbolPriority& compareTo) 
	{ 
		return(Priority == compareTo.Priority); 
	} 

};

typedef map<char, int> symbolMap;
TreeNode<SymbolPriority>*MakeTree(const string& message)
{
	symbolMap symMap;
	PriorityQueue<TreeNode<SymbolPriority>*> myQueue; //min priority queue of TreeNode<SymbolPriority pointers>
	//vector<SymbolPriority> temp;
	TreeNode<SymbolPriority>* huff_tree = NULL; 
	for(unsigned int i = 0; i < message.size(); i++) //outer loop-iterates through letters of message
	{ 
	
				symMap[message[i]]++;

	}	
	std::map<char, int>::iterator iter=symMap.begin();
	while (iter != symMap.end()) 
	{ 
		myQueue.Push(new TreeNode<SymbolPriority>(SymbolPriority(iter->first, iter->second)));
		iter++;
	} 


	//while loop that creats Huffman Tree
	while (myQueue.Size() > 1) //while queue has more than one element
	{
		TreeNode<SymbolPriority>* left = myQueue.Top();
		myQueue.Pop();
		TreeNode<SymbolPriority>* right = myQueue.Top();
		myQueue.Pop();


		TreeNode<SymbolPriority>* newNode = new TreeNode<SymbolPriority> (SymbolPriority('*', left->Value.Priority + right->Value.Priority), left, right); 
		myQueue.Push(newNode);

	
	}

	huff_tree = myQueue.Top();
	myQueue.Pop();
	return huff_tree;
}


typedef map<char, string> HuffmanMap;
string HuffmanCode(const char symbol,  HuffmanMap myMap)
{
	return myMap[symbol];
}



//encodes a message based on huffman tree
string Encode(const string& message, HuffmanMap myMap)
{
	string code;
	//For each character in the sentence call HuffmanCode() and concatenate the results.
	for (unsigned int i=0; i < message.size(); i++) //watch sizing with array bullshit
	{
		code = code + HuffmanCode(message[i], myMap);
	}
	return code;

}



char HuffmanDecode(const string& code, const TreeNode<SymbolPriority>* huffman, unsigned int& index)
{


	//Base Case: If the current node is a leaf, return the character
	if (huffman->IsLeaf())
	{
		return huffman->Value.Symbol;
	}


	else 
		if (code[index] == '0')
		{
			index++;
			return HuffmanDecode(code, huffman->Left, index); //Left edges are associated with zeroes
			//at each recusion either remove the processed bit from the string or advance the current bit index 
		}
		else 
		{
			index++;
			return	HuffmanDecode(code, huffman->Right, index);
		}

}

string Decode(const string& code, const TreeNode<SymbolPriority>* huffman)
{
	string result;
	unsigned int index = 0;
	while (index< code.size()) 
	{
		result += HuffmanDecode(code, huffman, index);
	}
	return result;
}


symbolMap makeTempSymMap(string message){
	symbolMap symMap;
	PriorityQueue<TreeNode<SymbolPriority>*> myQueue; //min priority queue of TreeNode<SymbolPriority pointers>
	//vector<SymbolPriority> temp;
	TreeNode<SymbolPriority>* huff_tree = NULL; 
	for(unsigned int i = 0; i < message.size(); i++) //outer loop-iterates through letters of message
	{ 
	
				symMap[message[i]]++;

	}	
	
	return symMap;
}

string makeHuffmanMap(const char symbol, const TreeNode<SymbolPriority>* huffman, string code, HuffmanMap& huffMap)
{
	//Base case: you are in a leaf
	if (huffman->IsLeaf() == true)
		//if the leaf contains the character you are looking for then return the code (third argument)
			if (huffman->Value.Symbol == symbol)
			{
				huffMap[huffman->Value.Symbol] = code;//I don't know a more efficient way to do this 
				return code;
			}
	//else return an empty string (which means 'wrong leaf') 
			else 
			{
				string emptyString;
				emptyString = "";
				return emptyString;
			}
			//recursion
	else
		//start by going to the left and adding '0' to the code (code + '0')
		if (!makeHuffmanMap(symbol, huffman->Left, code + '0', huffMap).empty()) //if the return string is not empty
			return makeHuffmanMap(symbol, huffman->Left, code + '0', huffMap); //then return it without going to the right 

		else
			return makeHuffmanMap(symbol, huffman->Right, code + '1', huffMap); //else return the result of going to the right. (adding a 1 to the code) 
}