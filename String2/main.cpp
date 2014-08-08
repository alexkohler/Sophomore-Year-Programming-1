
#pragma once
#include <iostream>

using namespace std;
#include "string.h"
#include <sstream>
#define MAX_SIZE 20

void main()
{


	String myString1("Apple");
	String myString2("Sauce");
	cout << "TESTING GETLENGTH OPERATOR" << endl;
	cout << myString1 << " is "<< myString1.GetLength() << " letters long" << endl;
	cout << myString2 << " is "<< myString2.GetLength() << " letters long" << endl;
	cout << endl << endl << endl;


	cout << "TESTING GETTEXT OPERATOR" << endl;
	cout << "Should output " << myString1 << endl;
	cout << myString1.GetText() << endl;
	cout << "Should output " << myString2 << endl;
	cout << myString2.GetText() << endl;
	cout << endl << endl << endl;

	cout << "TESTING [] OPERATOR" << endl;
	cout << "The letter at index 0 of " << myString1 << " is " << myString1[0] << endl; 
	cout << "The letter at index 2 of " << myString2 << " is " << myString2[2] << endl; 
	cout << endl << endl << endl;


	cout << "TESTING COMPARISON OPERATORS" << endl;
	cout << "Seeing if myString1 == myString2 (myString1 is " << myString1 << ", myString2 is " << myString2 << ")" << endl;
	cout << (myString1 == myString2) << endl;
	cout << "Seeing if myString1 != myString2 (myString1 is " << myString1 << ", myString2 is " << myString2 << ")" << endl;
	cout << (myString1 != myString2) << endl;
	cout << "Seeing if myString1 > myString2 (Is " << myString1 << " longer than " << myString2 << "?) " << endl;
	cout << (myString1 > myString2) << endl;
	cout << "Seeing if myString1 < myString2 (Is " << myString2 << " longer than " << myString1 << "?) " << endl;
	cout << (myString1 < myString2) << endl;
	cout << endl << endl << endl;





	cout << "TESTING CONCATENATION (+) OPERATOR" << endl;
	cout << myString1 << " + " << myString2 << " = ";
	cout << myString1 + myString2 << endl;
	cout << endl << endl << endl;


	try{
		cout << "TESTING FIND OPERATOR" << endl;
		cout << "Looking for 'p' in " << myString1 << ". Should return index of letter " << endl;
		cout << "(if not found should return -1)" << endl;
		cout << "...Found at index " << myString1.Find('p', 2) << endl;
		//cout << "Looking for 'q' in " << myString2 << "." << endl;
		//cout << "Found at index " << myString1.Find('q', -1) << endl; //commented out to avoid error
		cout << endl << endl << endl;


		cout << "TESTING SUBSTRING OPERATOR" << endl;
		cout << "Attempting to substring " << myString1 << "starting at index 0, ending at 4"<< endl;
		cout << myString1.Substring(0,4) << endl;
		cout << "Testing 0 length exception, should output " << myString2 << endl; 
		cout << myString2.Substring(0) << endl;


	}

	catch (string error)
	{
		cout << error << endl;
	}





	system("pause");



}