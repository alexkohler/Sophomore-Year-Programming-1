//String.h - string class declaration
//Written by Alex Kohler
#pragma once

#define NOT_FOUND	-1

#include <iostream>
#include <sstream>
using namespace std;


//Encapsulates C-string
//Regular classes- all functions should go into cpp file



class String
{
public:
	//Default constructor, initializes empty string
	String();

	//Copy constructor, performs deep copy
	String(const String& source);

	//Init- constructor allocates new string of size characters
	String(int size);

	//Init-constructor, initializes this String with a C-string
	String(char* text);

	//Destructor
	~String();

	//Assignment operator, performs deep copy 
	String& operator = (const String& source);

	//initializes this String by copying charactes from text C-string
	String& operator = (const char* text);


	//Returns a reference to a character at the specified index
	char& operator[] (int index) const;


	//operator overloading- functions that only differ by argument types 

	//Comparison operators: two things are equal
	//and when they have the same size and all characters are same
	bool operator == (const String& compareTo) const;
	bool operator != (const String& compareTo) const;

	//Returns a new string that is a concatenation of this String and appendix
	//String operator + (const String& appendix) const;


	//Returns the size of this string by looking for null-terminator
	int GetSize() const;

	int GetLength(const char* text) const;

	//returns the size of the specified C-string
	static int GetSize(char* text); //does not care about data members, therefore we should use static
	//this function can be called on class itself instead of a particular class instance



	//Returns encapsulated C-String
	char* GetText() const;

	//Returns the index of aChar in this String starting at startPosition
	//If aChar is not found in this stirng, return NOT_FOUND
	//int Find(char aChar, int index = 0) const;


	//Returns a new string which is a substring of this string starting at
	//startPosition and length characters long. If length is omitted(default
	//value of 0 is used) then the substring spans until the end of this string
	//String Substring(int startPosition, int length = 0) const;


	


private:
	//Throws a string-type exception when index is out of bounds
	void CheckBounds (int index, const char* source) const
	{
		//Bounds check
		if ( (index < 0) || (index >= GetSize() ) ) 
		{
			stringstream error;
			error << "Error: String:: operator[], index " << index <<" is out of bounds(0.." << (GetSize() - 1) << ")";

			throw error.str();
		}

	}

	//The encapsulated C-string given by a pointer to the first character
	char* Text;
};

std::ostream& operator << (std::ostream& out, const String& myString);            //cannot pass by const reference, ostream is modified