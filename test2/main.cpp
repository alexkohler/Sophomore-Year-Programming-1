//main.cpp- Test 2 main entry point
//Written by Alex Kohler

#include <iostream>
#include <string>
#include <list>
#include <sstream>

using namespace std;
#define MAX_STRINGS 5

//Task: write a program that reads 5 strings from cin, stores them in a linked list and then recursively searches the list for a specified value (which is also read from cin).


//6)	Declare Search() function as template function, template argument specifies list data type;
//7)	The function must declare three parameters: a List to search in, starting iterator position, and the value to search for;
//8)	The function must return iterator position of the search value in the list;
//9)	The function must throw an exception if the value is not found in the list;
//10)	The exception must be caught and reported in the main;
//11)	The function must search the list recursively.

//1)	Use typename list<T>::iterator to declare iterator as a parameter and as return type in the Search() function.
//2)	Recursive search algorithm: if the word at the current iterator position is not the word you are looking for then search recursively from the next iterator position; base case – you are at the end of the list.


template <typename T>

typename list<T>::iterator Search(list<T>& aList, typename list<T>::iterator pos, T& value )
{

	//Base case- you are at the end of the list
	if (pos == aList.end()) 
	{
		stringstream error;
		error << "Error: Value was not found" << endl;

		throw error.str();
	}



	else	
		if (*pos != value)
	{
		pos = ++pos;
		return Search(aList, pos, value); //forgot fucking return 
	}


		else 
			return pos;
	

}


//Main: 
//1)	Declare a list of strings;
//2)	Write for-loop to read a word from cin and push_back() it to the list;
//3)	Read a search word from cin.
//4)	Call Search() function and pass the list and the search word.
//5)	Convert the iterator position returned by the Search() function to integer using the distance() function as follows: int index = distance(myList.begin(), pos), print the resulting integer to cout as the position at which the search word was found in the list.





void main()
{
list<string> stringList;
string input;
list<string>::iterator stringPosition;
list<string>::iterator found;

for (int i=0; i<MAX_STRINGS; i++)
{
cin >> input;
stringList.push_back(input);
}

string searchWord;
cin >> searchWord;
try{
stringPosition = stringList.begin();
stringPosition = Search (stringList, stringPosition, searchWord);
int index = distance(stringList.begin(), stringPosition);
cout << "Found at position " << index;
}


catch(string error)
{
	cout << error;
}

system("pause");
}
