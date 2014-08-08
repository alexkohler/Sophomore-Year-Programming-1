//String.cpp ) String class implementation
#include "String.h"
#include <sstream>
//Encapsulates C-string
//Regular classes- all functions should go into cpp file


	//Default constructor, initializes empty string
	String::String()
	{
		Text = NULL;
	}

	//Init- constructor allocates new string of size characters
	String::String(int size)
	{
		Text = new char[size];
	}

	//Init-constructor, initializes this String with a C-string
	String::String(char* text)
	{
		Text = NULL;
		*this = text;
	}

	//Copy constructor, performs deep copy
	String::String(const String& source)
	{
		Text = NULL;
		//calling the assignment operator to perform deep copy
		*this = source;
	}

	//Destructor
	String::~String()
	{
		delete[] Text;
	}

	//Assignment operator, performs deep copy 
	String& String::operator = (const String& source)
	{
		return 
			*this = source.GetText();
	}
	


	//Returns a reference to a character at the specified index
	char& String::operator[] (int index) const   //put string:: in front of operator keyword NOT THE TYPENAME
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
	//Comparison operators: two things are equal
	//and when they have the same size and all characters are same
	bool String::operator == (const String& compareTo) const
	{
		return 
			(GetSize() == compareTo.GetSize() && GetText() == compareTo.GetText()); //if things have same size and all characters, they must be equal 
	}

	bool String::operator != (const String& compareTo) const
	{
		return 
			!(*this == compareTo);
	}

	//Returns a new string that is a concatenation of this String and appendix
	//String String::operator + (const String& appendix) const
	//	{
	//		String a = *this;
	//		char A = a.GetText();

//			return
//				a;
		}


	//Returns the size of this string by looking for null-terminator
	int String::GetSize() const
	{
		return
			GetSize(Text);
	}


	// Returns the count of characters in a C-string text; NULL-terminator is not counted
int String::GetLength(const char* text) const
{
	int count=0;
	for (int i=0; text[i] != '/0'; i++)
	{
		count++;
	}

	return count; 
}


	//returns the size of the specified C-string
	//static int GetSize(char* text);
	//Returns encapsulated C-String
	char* String::GetText() const
	{
		return Text;
	}




	//Returns the index of aChar in this String starting at startPosition
	//If aChar is not found in this stirng, return NOT_FOUND
	//int String::Find(char aChar, int /*index = 0*/) const
	//{

	//}


	//Returns a new string which is a substring of this string starting at
	//startPosition and length characters long. If length is omitted(default
	//value of 0 is used) then the substring spans until the end of this string
	//String String::Substring(int startPosition, int length/* = 0*/) const
	//{
	//}


	


std::ostream& operator << (std::ostream& out, const String& myString)//cannot pass by const reference, ostream is modified
{
	return
		//We simply print the encapsulated C-string
		out << myString.GetText();

}