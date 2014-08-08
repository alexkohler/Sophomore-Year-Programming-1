//main.cpp-priority queue main entry point
//Written by Alexander Kohler



#include <iostream>
#include <vector>
#include <string>
#include "PriorityQueue.h"
using namespace std;

struct SymbolPriority
{
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

//stream output operator for symbolpriority structure
ostream& operator << (ostream& out, const PriorityQueue<SymbolPriority>& myQueue)
{
	out << "Symbol: " << myQueue.Top().Symbol << ", Priority: " << myQueue.Top().Priority << endl;

	return out; 
}


void main(){
	string sentence;
	PriorityQueue<SymbolPriority> myQueue;//priority Queue declaration
	vector<SymbolPriority> temp;

	getline(cin, sentence);

	for(unsigned int i = 0; i < sentence.size(); i++) //outer loop-iterates through letters of sentence
	{ 
		unsigned int j = 0; 
		for(; j < temp.size(); j++) //inner loop- iterates through temp vector, comparing letters already in temp vector to new ones based on iterations of sentence[i]
		{
			if(sentence[i] == temp[j].Symbol) //if a match between the sentence(which is fixed at i), and the symbol of our vector(which will be iterated by the inner loop), then increment the priority
			{ 
				temp[j].Priority++; 
				break; //one case has happened, break the loop and go to the next iteration
			} 
		}
		if(j == temp.size()) //if we reach the end of the loop (which means the loop was not broken), then no match was found, push back the letter at sentence[i]
			temp.push_back(SymbolPriority(sentence[i], 1)); 
	}	

	for (unsigned int i=0; i<temp.size(); i++) 
	{ 
		myQueue.Push(temp[i]); 
	} 

	
	//while loop that prints top
	while (!myQueue.IsEmpty())
	{
		cout << myQueue;
		myQueue.Pop();
	}


	system("pause");
}
