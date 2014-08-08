//main.cpp-main entry point for linked list
//Written by Alex Kohler with much assisstance from Max Fomitchev-Zamilov


#include <iostream>
#include <list>
#include <string>

using namespace std;

#define MAX_STRINGS 5


void main ()
{

	list<string> myList; 

	for ( int i = 0; i < MAX_STRINGS; i++ )
	{
		string input;
		cin >> input;

		list<string>::iterator pos = myList.begin();

		for ( ; (pos != myList.end()) && (input > *pos); pos++ );

		myList.insert(pos, input);

	}

	for ( list<string>::iterator pos = myList.begin(); pos!=myList.end(); pos++ )
	{
		cout << *pos << endl;
	}

	system ("pause");

}