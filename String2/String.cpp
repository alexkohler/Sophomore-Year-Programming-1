// String.cpp - String class implementation
// Written by ALexKohler

#include "String.h"
#include <sstream>

using namespace std;

// Default constructor
String::String()
{
	Text = NULL;
}

// MUST HAVE: Copy-constructor that performs deep copy
String::String(const String& source)
{
	Text = NULL;
	// Call the assignment operator to perform deep copy
	*this = source;
}

// Init-constructor to initialize this String with a C-string
String::String(const char* text)
{
	Text = NULL;
	// Call the assignment operator to perform deep copy
	*this = text;
}

// Init constructor, allocates this String to hold the size characters
String::String(int size)
{
	Text = new char[size];
}

// Destructor
String::~String()
{
	delete[] Text;
}

// Assignment operator to perform deep copy
String& String::operator = (const String& source)
{
	// Call the other assigment operator to perform deep copy
	*this = source.Text;
	return *this;
}

// Assignment operator to assign a C-string to this String
String& String::operator = (const char* text)
{
	// Ddispose of old Text
	delete[] Text;

	// +1 accounts for NULL-terminator
	int trueLength = GetLength(text) + 1;

	// Dynamically allocate characters on heap
	Text = new char[trueLength];

	// Copy all characters from source to Text; +1 accounts for NULL-terminator
	for ( int i = 0; i < trueLength; i++ )
		Text[i] = text[i];

	return *this;
}

// Returns a reference to a single character from this String
// String myString;
// char c = myString[1];
// myString[1] = 'c';
char& String::operator [] (int index) const
{
	int length = GetLength();

	// Check for valid index
	if ( (index < 0) || (index > length) )
	{
		stringstream error;
		error << "String::operator[] - index " << index <<
			" is out of bounds (0.." << (length - 1) << ")";
		throw String(error.str().c_str());
	}

	return Text[index];
}







// Returns the count of characters in the String
int String::GetLength() const
{
	return GetLength(Text);
}

// Returns the count of characters in a C-string text; NULL-terminator is not counted
int String::GetLength(const char* text)
{
	int count=0;
	for (int i=0; text[i] != NULL; i++)
	{
		count++;
	}

	return count; 
}

char* String::GetText() const
{
	return Text;
}

// Stream output operator to print String to output stream
ostream& operator << (ostream& out, const String& myString)
{
	return out << myString.GetText();
}