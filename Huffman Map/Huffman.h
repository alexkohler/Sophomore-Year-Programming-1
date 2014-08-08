//Huffman.h- Huffman function implementation

#pragma once
#include <map>
#include "Tree.h"
#include "PriorityQueue.h"

using namespace std;
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



typedef map<char, int> symbolMap;//pay moar attention

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




//encodes a message based on huffman tree
/*string mapEncode(const string& message, huffmanMap huffMap)
{
	string code;
	//For each character in the sentence call HuffmanCode() and concatenate the results.
	for (unsigned int i=0; i < message.size(); i++) //watch sizing with array bullshit
	{
		code = 
	}
	return code;

}*/





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





//huffmap - char, string 
typedef map<char, string> huffmanMap;
string makeRealHuffMap(const TreeNode<SymbolPriority>* huffman, string code, huffmanMap huffMap) //used to traverse tree, rename other huffman 
{
	//Base case: you are in a leaf, add that value to map 
	if (huffman->IsLeaf() == true)
		huffMap[huffman->Value.Symbol]=code;
			
	else
		//start by going to the left and adding '0' to the code (code + '0')
		if (!makeRealHuffMap(huffman->Left, code + '0', huffMap).empty()) //if the return string is not empty
			return makeRealHuffMap(huffman->Left, code + '0',huffMap); //then return it without going to the right 

		else
			makeRealHuffMap(huffman->Right, code + '1', huffMap); //else return the result of going to the right. (adding a 1 to the code) 
}







/*
string HuffmanCodeMap(const char symbol, const TreeNode<SymbolPriority>* huffman, string code) //used to traverse tree, rename other huffman 
{
	//Base case: you are in a leaf
	if (huffman->IsLeaf() == true)
		//if the leaf contains the character you are looking for then return the code (third argument)
			if (huffman->Value.Symbol == symbol)
				return code; 
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
		if (!HuffmanCode(symbol, huffman->Left, code + '0').empty()) //if the return string is not empty
			return HuffmanCode(symbol, huffman->Left, code + '0'); //then return it without going to the right 

		else
			return HuffmanCode(symbol, huffman->Right, code + '1'); //else return the result of going to the right. (adding a 1 to the code) 
}*/





/*string HuffmanCode(const char symbol, const TreeNode<SymbolPriority>* huffman, string code)
{
	//Base case: you are in a leaf
	if (huffman->IsLeaf() == true)
		//if the leaf contains the character you are looking for then return the code (third argument)
			if (huffman->Value.Symbol == symbol)
				return code; 
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
		if (HuffmanCode(symbol, huffman->Left, code + '0') != "") //if the return string is not empty
			return HuffmanCode(symbol, huffman->Left, code + '0'); //then return it without going to the right 

		else
			return HuffmanCode(symbol, huffman->Right, code + '1'); //else return the result of going to the right. (adding a 1 to the code) 
}



typedef map<char, string> huffmanMap;
huffmanMap makeHuffmanMap(string& code, const TreeNode<SymbolPriority>* huffman, huffmanMap& myMap, symbolMap symMap)
{


	std::map<char, int>::iterator iter=symMap.begin();
	while (iter != symMap.end()) 
	{
		code = HuffmanCode(iter->first,huffman,code); //
		myMap[iter->first] = code; //
		cout << iter->first<< " " << code << endl; 
		code = "";//empty string to stop concatenation
		iter++;//increment iterator 
	}

	return myMap;
}


*/