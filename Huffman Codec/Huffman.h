//Huffman.h- Huffman function implementation

#pragma once
#include "Tree.h"
#include "PriorityQueue.h"


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


TreeNode<SymbolPriority>* MakeTree(const string& message)
{
	PriorityQueue<TreeNode<SymbolPriority>*> myQueue; //min priority queue of TreeNode<SymbolPriority pointers>
	vector<SymbolPriority> temp;
	TreeNode<SymbolPriority>* huff_tree = NULL; 
	for(unsigned int i = 0; i < message.size(); i++) //outer loop-iterates through letters of message
	{ 
		unsigned int j = 0; 
		for(; j < temp.size(); j++) //inner loop- iterates through temp vector, comparing letters already in temp vector to new ones based on iterations of message[i]
		{
			if(message[i] == temp[j].Symbol) //if a match between the message(which is fixed at i), and the symbol of our vector(which will be iterated by the inner loop), then increment the priority
			{ 
				temp[j].Priority++; 
				break; //one case has happened, break the loop and go to the next iteration
			} 
		}
		if(j == temp.size()) //if we reach the end of the loop (which means the loop was not broken), then no match was found, push back the letter at message[i]
			temp.push_back(SymbolPriority(message[i], 1)); 
	}	

	for (unsigned int i=0; i<temp.size(); i++) 
	{ 
		myQueue.Push(new TreeNode<SymbolPriority>(temp[i]));
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


string HuffmanCode(const char symbol, const TreeNode<SymbolPriority>* huffman, string code)
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
}



//encodes a message based on huffman tree
string Encode(const string& message, TreeNode<SymbolPriority>* huffman)
{
	string code;
	//For each character in the sentence call HuffmanCode() and concatenate the results.
	for (unsigned int i=0; i < message.size(); i++) //watch sizing with array bullshit
	{
		code = HuffmanCode(message[i], huffman, code);
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


vector<SymbolPriority> makeTempVector(string message){
PriorityQueue<TreeNode<SymbolPriority>*> myQueue; //min priority queue of TreeNode<SymbolPriority pointers>
	vector<SymbolPriority> temp;
	TreeNode<SymbolPriority>* huff_tree = NULL; 
	for(unsigned int i = 0; i < message.size(); i++) //outer loop-iterates through letters of message
	{ 
		unsigned int j = 0; 
		for(; j < temp.size(); j++) //inner loop- iterates through temp vector, comparing letters already in temp vector to new ones based on iterations of message[i]
		{
			if(message[i] == temp[j].Symbol) //if a match between the message(which is fixed at i), and the symbol of our vector(which will be iterated by the inner loop), then increment the priority
			{ 
				temp[j].Priority++; 
				break; //one case has happened, break the loop and go to the next iteration
			} 
		}
		if(j == temp.size()) //if we reach the end of the loop (which means the loop was not broken), then no match was found, push back the letter at message[i]
			temp.push_back(SymbolPriority(message[i], 1)); 
	}	
	return temp;
}

void toDecimal (string code, ofstream& output)//32 bit support, don't forget to write to file 
{

	if (code.size() <= 8){//if only one byte 
		unsigned long long arr1[1];//array of size one because only one byte 
		unsigned long long value = stoull(code.c_str(), 0, 2); //converting binary number 
		arr1[0] = value;
		cout << "Byte conversion is ";
		cout << arr1[0] << endl;
		output << arr1[0] << endl << endl;
	}
	if (code.size() > 8 && code.size() <= 16){//if two bytes 
		unsigned long long arr2[2]; //array of size two because two bytes
		unsigned long long value1 = stoull(code.substr(0, 8).c_str(), 0, 2);
		unsigned long long value2 = stoull(code.substr(8, code.size()).c_str(), 0, 2);
		cout << "Byte conversion is ";
		arr2[0] = value1;
		arr2[1] = value2;
		cout << arr2[0] << " " << arr2[1] << endl;
		output << arr2[0] << " " << arr2[1] << endl << endl;
	}

	if (code.size() > 16 && code.size() <= 24){//if three bytes 
		unsigned long long arr3[3]; //array of size three because three bytes
		unsigned long long  value1 = stoull(code.substr(0, 8).c_str(), 0, 2);
		unsigned long long value2 = stoull(code.substr(8, 8).c_str(), 0, 2);
		unsigned long long value3 = stoull(code.substr(16, code.size()).c_str(), 0, 2);
		cout << "Byte conversion is ";
		arr3[0] = value1;
		arr3[1] = value2;
		arr3[2] = value3;
		cout << arr3[0] << " " << arr3[1] << " " << arr3[2] << endl;
		output << arr3[0] << " " << arr3[1] << " " << arr3[2] << endl << endl;
	}

	if (code.size() > 24 && code.size() <= 32){//if four bytes 
		unsigned long long arr4[4]; //array of size four because four bytes
		unsigned long long  value1 = stoull(code.substr(0, 8).c_str(), 0, 2);
		unsigned long long value2 = stoull(code.substr(8, 8).c_str(), 0, 2);
		unsigned long long value3 = stoull(code.substr(16, 8).c_str(), 0, 2);
		unsigned long long value4 = stoull(code.substr(24, code.size()).c_str(), 0, 2);
		cout << "Byte conversion is ";
		arr4[0] = value1;
		arr4[1] = value2;
		arr4[2] = value3;
		arr4[3] = value4;
		cout << arr4[0] << " " << arr4[1] << " " << arr4[2] << endl;
		output << arr4[0] << " " << arr4[1] << " " << arr4[2] << endl << endl;
	}




}




string toBinary(string code, ofstream& output) //function to convert byte array to bit string 
	{


		if (code.size() <= 8){//if only one byte 
		unsigned long long arr1[1];//array of size one because only one byte 
		unsigned long long value = stoull(code.c_str(), 0, 2); //converting binary number 
		arr1[0] = value;
		bitset<8>    bits(value);
		//cout << "Decoded byte is byte is " << bits;
		string bitstring = bits.to_string();
		//cout << "Decoded byte is " << bitstring;
		return bitstring;

	}
	if (code.size() > 8 && code.size() <= 16){//if two bytes 
		unsigned long long arr2[2]; //array of size two because two bytes
		unsigned long long value1 = stoull(code.substr(0, 8).c_str(), 0, 2);
		unsigned long long value2 = stoull(code.substr(8, code.size()).c_str(), 0, 2);
		arr2[0] = value1;
		arr2[1] = value2;
		bitset<8>    bits1(value1);
		bitset<8>    bits2(value2);
		//cout << "Decoded byte is " << bits1 << bits2 << "8 bit therefore may be extra zeroes";
		string bitstring1 = bits1.to_string();
		string bitstring2 = bits2.to_string();
		string finalString = bitstring1 + bitstring2;
		//cout << "Decoded byte is " << finalString;
		return finalString;

	}

	if (code.size() > 16 && code.size() <= 24){//if three bytes 
		unsigned long long arr3[3]; //array of size three because three bytes
		unsigned long long  value1 = stoull(code.substr(0, 8).c_str(), 0, 2);
		unsigned long long value2 = stoull(code.substr(8, 8).c_str(), 0, 2);
		unsigned long long value3 = stoull(code.substr(16, code.size()).c_str(), 0, 2);
		vector<bool> swag;
		swag.resize(3);
		int size = swag.size();
		arr3[0] = value1;
		arr3[1] = value2;
		arr3[2] = value3;
		bitset<8>    bits1(value1);
		bitset<8>    bits2(value2);
		bitset<8>    bits3(value3);
		string bitstring1 = bits1.to_string();
		string bitstring2 = bits2.to_string();
		string bitstring3 = bits3.to_string();
		string finalString = bitstring1 + bitstring2 + bitstring3;
		//cout << "Decoded byte is " << finalString;
		return finalString;
	}

	if (code.size() > 24 && code.size() <= 32){//if four bytes 
		unsigned long long arr4[4]; //array of size four because four bytes
		unsigned long long  value1 = stoull(code.substr(0, 8).c_str(), 0, 2);
		unsigned long long value2 = stoull(code.substr(8, 8).c_str(), 0, 2);
		unsigned long long value3 = stoull(code.substr(16, 8).c_str(), 0, 2);
		unsigned long long value4 = stoull(code.substr(24, code.size()).c_str(), 0, 2);
		arr4[0] = value1;
		arr4[1] = value2;
		arr4[2] = value3;
		arr4[3] = value4;
		bitset<8>    bits1(value1);
		bitset<8>    bits2(value2);
		bitset<8>    bits3(value3);
		bitset<8>	 bits4(value4);
		string bitstring1 = bits1.to_string();
		string bitstring2 = bits2.to_string();
		string bitstring3 = bits3.to_string();
		string bitstring4 = bits4.to_string();
		string finalString = bitstring1 + bitstring2 + bitstring3 + bitstring4;
		//cout << "Decoded byte is " << finalString;
		return finalString;
		}
	return "error";
}