//main.cpp
//Written By Alexander Kohler

#include <vector>
#include <list>
#include "HashTable.h"
using namespace std; 

void main()
{
	HashTable<string> myHash;
	string key;
	int value;
	vector<string> keyHolder;
	vector<int> valueHolder;
	cout << "Taking in 4 key/value pairs..." << endl;
	for (int i=0; i<4; i++)
	{
		cout << "Please input a key: ";
		cin >> key;
		keyHolder.push_back(key);
		cout << "Please input a value for " << key << ": ";
		cin >> value;
		valueHolder.push_back(value);
		myHash.insert(keyHolder[i], valueHolder[i]);
	}


	for (int i=0; i<4; i++)
	{
		cout << "Your hash code for " << keyHolder[i] << " is " << myHash.hash(keyHolder[i]) << endl;
	}

	cout << "Enter a key/value pair you previously entered to remove" << endl;
	cout << "Enter a key: " ;
	cin >> key;
	cout << "Enter " << key << "'s value(NOT its hashcode): ";
	cin >> value;
	myHash.remove(key, value);
	cout << "Hash table now contains: " << endl;
	myHash.print();

	system("pause");
}