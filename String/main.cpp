//Main.cpp - String class testing program main entry poin
//Written by Alex Kohler

#include <iostream>
#include "String.h"
using namespace std;

#define MAX_SIZE	20

void main()
{
	
	char string1[MAX_SIZE] = "John";
	char string2[MAX_SIZE] = "Jacob";
	char string3[MAX_SIZE] = "Jingleheimer";
	char string4[MAX_SIZE] = "blank";

	cout << string1 << endl;

	cout << "TESTING LENGTH OPERATOR" << endl;
	cout << "Checking length of string" << string1 << endl;
	cout << "Should be 4 characters long" << endl; 
	cout << "Length is " << GetLength(string1) << endl;

//	cout << "Test case for = operator, assigning blank string (originally reading " << string4 << ") a new string with name " << string1 << endl; 


	



	wchar_t* unicodeString = L""; //16 bit, unicode character for implementing oriental languages (must be preceded by L)

	char myString[MAX_SIZE] = "test string\0";

	//another C-string given by a pointer
	char* myString2 = "another string";

	//Modify strings
	myString[0]-= 2;//subtracts 2 from first ascii value of first character
					//subtract 32- uppercase letter; add 32, lowercase letter


	//Copy content
	int i = 0;
	for (; myString[i] != '/0'; i++)
		myString[i] = myString2[i];
	myString[i] = '/0';


	system("pause");
}



	//C-string is an array of characters
	//different from C-Array- has a NULL terminator
	//char-shows up as ascii code
	//string will continue until it reaches null terminator
	//  / operator for strings(accessing ascii code, newline, null term, etc
	//whenever manupulating char strings, add one extra to index to account for null terminator 