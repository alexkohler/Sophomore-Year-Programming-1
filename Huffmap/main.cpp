//main.cpp- Huffman Codec main entry point
//Written by Alexander Kohler


#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
#include "PriorityQueue.h"
#include "Tree.h"
#include "Huffman.h" 
using namespace std;



void main(){

	string message;
	string code;
	string decodedMessage;
	ofstream output("result.txt");
	getline(cin, message); 
	TreeNode<SymbolPriority>* tree = MakeTree(message);
	typedef map<char, string> HuffmanMap;
	HuffmanMap huffMap;
	symbolMap tempMap;

	tempMap = makeTempSymMap(message);

	for (int i=0; i<message.size(); i++)
		makeHuffmanMap(message[i], tree, code, huffMap);

	std::map<char, int>::iterator iter=tempMap.begin();
	while (iter != tempMap.end()) 
	{
		code = HuffmanCode(iter->first,huffMap); 
		cout << iter->first << " " << code << endl;
		output << iter->first << " " << code << endl;
		code = "";//empty string to stop concatenation
		iter++;
	}
	code = Encode(message, huffMap);

	cout << "Encoded message is " << code << endl;
	output << endl << code<<  endl;


	decodedMessage = Decode(code, tree);
	cout << endl << "Decoded message is " << decodedMessage << endl;
	output << decodedMessage << endl;
	system("pause");

}

