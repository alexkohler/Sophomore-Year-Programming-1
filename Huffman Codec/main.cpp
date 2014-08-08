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


	vector<SymbolPriority> temp;
	temp = makeTempVector(message);


	for ( unsigned int i=0; i < temp.size(); i++)
	{
		code = HuffmanCode(temp[i].Symbol,tree,code);
		cout << temp[i].Symbol << " " << code << endl;
		output << temp[i].Symbol << " " << code << endl;
		code = "";//empty string to stop concatenation
	}
	code = Encode(message, tree);

	cout << "Encoded message is " << code << endl;
	output << endl << code<<  endl;

	toDecimal(code, output);
	cout << "Conversion back to binary: " << toBinary(code, output) << endl;
	cout <<	" (Extra 0s due to 8 bit assumption)" << endl;


	decodedMessage = Decode(code, tree);
	cout << endl << "Decoded message is " << decodedMessage << endl;
	output << decodedMessage << endl;
	system("pause");

}
