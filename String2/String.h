// String.h - String class declaration
// Written by Alex Kohler

#pragma once

#include <iostream>
#include <sstream>
using namespace std;

#define NOT_FOUND -1

// C++ String class that encapsulates an ASCII C-string
class String
{
public:
	// Default constructor
	String();

	// MUST HAVE: Copy-constructor that performs deep copy
	String(const String& source);

	// Init-constructor to initialize this String with a C-string
	String(const char* text);

	// Init constructor, allocates this String to hold the size characters
	String(int size);

	// Destructor
	~String();

	// Assignment operator to perform deep copy
	String& operator = (const String& source);

	// Assignment operator to assign a C-string to this String
	String& operator = (const char* text);

	// Returns a reference to a single character from this String
	char& operator [] (int index) const;

	// Comparison operators
	bool String::operator == (const String& compareTo) const
	{
		return 
			(GetLength() == compareTo.GetLength() && GetText() == compareTo.GetText()); //if things have same size and all characters, they must be equal 
	}

	bool String::operator != (const String& compareTo) const
	{
		return 
			!(*this == compareTo);
	}

	bool operator > (const String& compareTo) const
	{
		if (compareTo.GetLength() == GetLength())
		{
			return 0;
		}

		else if(GetLength() > compareTo.GetLength())
		{
			return GetText();
		}

		else
		{
			return compareTo.GetText();
		}
	}


	bool operator < (const String& compareTo) const
	{
		if (compareTo.GetLength() == GetLength())
		{
			return 0;
		}

		else
			return 
			!(*this > compareTo);

	}

	// Concatenation operator
	String operator + (const String& aString) const
	{		



		String string3(GetLength() + aString.GetLength() + 1);
		int i = 0;
		for (; i < GetLength(); i++)
		{string3[i] = Text[i];}

		//string3[i+1] = aString
		int j=0;
		for (; i < GetLength() + aString.GetLength(); i++)
		{
			string3[i] = aString[j];
			j++;
		}
		string3[i] = NULL;

		return string3;
	}

	// Returns an index of aChar in this String beginning the search
	// at startPosition; when aChar is not found the function returns NOT_FOUND
	// throws an exception when startPosition is out of bounds
	int Find(char aChar, int startPosition = 0) const
	{
		CheckBounds(startPosition, Text);
		for ( int i = startPosition; i<GetLength(); i++)
		{
			if (Text[i] == aChar)
				return i; 
		}

		if (Text[GetLength()] != aChar)
			return NOT_FOUND;
		else
			return NOT_FOUND;

	}



	// Returns a new string that corresponds to a substring of this String
	// beginning at startPosition and length chars long;
	// if length = 0 (not specified) then the substring spans from
	// startPosition until the end of this String
	// throws an exception when startPosition is out of bounds
	String Substring(int startPosition, int length = 0) const
	{
		String Smallstring (length+1); //add one for null terminator
		Smallstring[length]= NULL;
		CheckBounds(startPosition, Text);
		if (length == 0)
		{
			Smallstring = GetText();
			return Smallstring;							

		}

		else
		{


			int i=startPosition;
			for (; i<length; i++)
			{
				Smallstring[i] = Text[i];
			}
			return Smallstring;
		}


	}

	// Returns the count of characters in the String; NULL-terminator is not counted
	int GetLength() const; //cpp

	// Returns the count of characters in a C-string text; NULL-terminator is not counted
	// static means that the mem ber function neither reads nor
	// writes any of the class' data members
	// String::GetLength("blah");
	static int GetLength(const char* text); //cpp

	char* GetText() const; //cpp

private:
	// Throws an String-type exception when index is out of bounds
	void CheckBounds(int index, const char* source) const
	{
		{
			//Bounds check
			if ( (index < 0) || (index >= GetLength() ) ) 
			{
				stringstream error;
				error << "Error: String:: operator[], index " << index <<" is out of bounds(0.." << (GetLength() - 1) << ")";

				throw error.str();
			}

		}


	}

	// The encapsulated C-string
	char* Text;
};

// Stream output operator to print String to output stream
ostream& operator << (ostream& out, const String& text);