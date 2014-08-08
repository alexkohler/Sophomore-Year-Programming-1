//Huffman Codec main entry point
//Written by Alexander Kohler

#include <string>
#include <map>
#include <iostream>
#include <set>
#include "Huffman.h"
#include "PriorityQueue.h"
#include "Tree.h"
using namespace std;

//Modify your Huffman Codec to use maps for character to Huffman code mapping: 
//Define HuffmanMap type:typedef map<char, string> HuffmanMap; xx
//Write MakeHuffmanMap() function that traverses Huffman tree and populates HuffmanMap where each character is associated with its Huffman code; xx
//Modify your Encode() function to use HuffmanMap instead of Huffman tree xx
//Modify MakeTree() function and replace a temp array of SymbolPriority with a map that relates character to it’s priority.

//NOTES:
//currently working on encode function that only utilizes huffmanmap 

typedef map<char, string> huffmanMap;





//still write to file
//change huffman tree make function to only traverse tree once (if shit hits the fan just use what you already have)
//modify mapencode 



void main(){
	huffmanMap myMap;
	string message;
	string code;
	string decodedMessage;
	getline(cin, message); 
	TreeNode<SymbolPriority>* tree = MakeTree(message);

	symbolMap temp;
	temp = makeTempSymMap(message);

	//myMap = makeHuffmanMap(code, tree, myMap, temp);
	
	makeRealHuffMap(tree, code, myMap);
	//code = MapEncode(message, myMap);


//Map implementation

//Map index operator 



system("pause");
}
