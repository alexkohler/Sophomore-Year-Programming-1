//main.cpp-main entry point for dequeue
//Written by Alex Kohler

#include <iostream>
#include <string>
#include <queue>
using namespace std; 

struct OperationPriority{ //put into new header
   OperationPriority(char operation, int priority)
   {
      Operation = operation;
      Priority = priority;
   }   char Operation;   int Priority;};



void main() 
{
queue<OperationPriority> myQueue;
string expression;
cout << "Please input an expression to determine the priority of: " << endl; 
cin >> expression; //getline expression into a string?
int nestingLevel = 0;

for (int i=0; i<expression.size(); i++)
	{
	switch(expression[i]) 
	{
		case '(':
			nestingLevel++; 
			break; 
		case ')':
			nestingLevel--;
			break; 
		case '*':
		case '/':
			myQueue.push(OperationPriority(expression[i], nestingLevel*2 +2));
			break;
		case '+'://case for minus //when no break, essentially an or 
		case '-':
			myQueue.push(OperationPriority(expression[i], nestingLevel*2 + 1));
			break;
	}
	}

	//while q is not empty, print the front
	while (!myQueue.empty())
	{
	cout << "(" << myQueue.front().Operation << ","<< myQueue.front().Priority << ")";
	myQueue.pop();
	}
		
		
	



system("pause");

}