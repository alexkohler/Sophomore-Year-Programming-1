#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <list>
using namespace std;

#define DEFAULT_LIST_SIZE	10

//add template class 
template<typename DATA_TYPE>
class HashTable
{
	//typedef std::list< std::pair<string,int> > keyValue; 

public:

	//**Constructors- with optional size parameter 
	HashTable()
	{

		Size = DEFAULT_LIST_SIZE; //sets default size for sake of index calculation
		string empty = "";
		int emptyVal = -1;
		list<pair<DATA_TYPE, int>> emptyList;
		emptyList.push_back(make_pair(empty, emptyVal));
		for (int i=0; i < Size; i++)
		{
			myTable.push_back(emptyList);
		}
	}



	HashTable(int size) //constructor with size option 
	{
		Size = size; //sets default size for sake of index calculation
		string empty = "";
		int emptyVal = -1;
		list<pair<DATA_TYPE, int>> emptyList;
		emptyList.push_back(make_pair(empty, emptyVal));
		for (int i=0; i < Size; i++)
		{
			myTable.push_back(emptyList);
		}
	}

	//**Hashing function-takes ASCII code of first character 
	int hash(DATA_TYPE readString) {
		return (int) readString[0];
	}

	//Insert method- inserts a string at its (hash code % size), if it already exists, add another to the list 
	void insert(DATA_TYPE inputString, int value)
	{

		emptyList.push_back("");
		int index = hash(inputString) % Size;
		if (myTable[index].front().first == emptyList.front() && myTable[index].front().second == -1)//if the index is empty
		{
			myTable[index].pop_back();
			myTable[index].push_back(make_pair(inputString, value));
		}
		else //otherwise, there is something in the list and we must add to the list
			myTable[index].push_back(make_pair(inputString,value));
	}

	//returns index if the string if found in the vector, that is, at the front of each list in the vector, ekse returns false index (-1) 
	int foundInVector(DATA_TYPE searchKey, int searchValue)
	{
		pair<DATA_TYPE, int> searchPair = make_pair(searchKey, searchValue);
		//will eventually have to change string to data_TYPE
		for (int i=0; i<Size; i++)
		{
			if (myTable[i].front() == searchPair)
				return i;

		}
		return -1;
	}


	//modifies table and returns true if modified, else false
	bool foundInList(DATA_TYPE searchKey, int searchValue)
	{
		string empty = "";
		int emptyVal = -1;
		list<pair<DATA_TYPE, int>> emptyList;
		emptyList.push_back(make_pair(empty,emptyVal));
		pair<DATA_TYPE, int> searchPair = make_pair(searchKey, searchValue);
		list<pair<DATA_TYPE, int>>::iterator iter;
		int i=0;
		while (i <Size)
		{
			iter=myTable[i].begin();
			while (iter!=myTable[i].end())
			{
				if (*iter == searchPair)
				{
					*iter = emptyList.front();
					return true;
				}
				else
					iter++;
			}
			i++;
		}
		return false;
	}




	//Remove method-removes a string from the hash table 
	void remove(DATA_TYPE inputString, int searchValue) 
	{
		string empty = "";
		int emptyVal = -1;
		list<pair<DATA_TYPE, int>> emptyList;
		emptyList.push_back(make_pair(empty,emptyVal));
		emptyList.push_back(make_pair(empty,emptyVal));
		if (foundInVector(inputString, searchValue) > -1){//means value was found
			int index = foundInVector(inputString, searchValue);

			myTable[index].pop_front();//remove the value
			myTable[index].push_back(emptyList.front());
			cout << "Value removed!" << endl;
		}

		else 
			if (foundInList(inputString, searchValue)==true)
			{}
			else 
				cout << "Value not found!" << endl;

		//otherwise it's not here
	}





	//[] Operator, return value of inputted key 
	int operator [] (DATA_TYPE key )
	{



		int index;
		index=hash(key) % Size;
		if (myTable[index].front().first == key) //if the first value in our pair, at the front of the list in our vector at [index] is our key, return the value
			return myTable[index].front().second;
		else //otherwise the key may be further down our list, and we must traverse it 
		{	
			string empty = "";
			int emptyVal = -1;
			list<pair<DATA_TYPE, int>> emptyList;
			emptyList.push_back(make_pair(empty,emptyVal));
			list<pair<DATA_TYPE, int>>::iterator iter;//declare what we need to traverse list 

			iter=myTable[index].begin();
			while (iter!=myTable[index].end())
			{
				pair<string, int> checkPair;
				checkPair = *iter;
				if (checkPair.first == key)
				{
					return checkPair.second;
				}
				else
					iter++;
			}

			return -1;

		}

	}

	//Print function--prints contents of Hash table
	void print ()
	{
		DATA_TYPE empty = "";
		int emptyVal = -1;
		list<pair<DATA_TYPE, int>> emptyList;
		emptyList.push_back(make_pair(empty,emptyVal));
		int index=0;
		while (index < Size)
		{
			//declare iterator and go through list to make sure there are no values past the vector 
			list<pair<DATA_TYPE, int>>::iterator iter;//declare what we need to traverse list 

			iter=myTable[index].begin();

			while (iter!=myTable[index].end())
			{
				pair<DATA_TYPE, int> emptyPair;
				pair<DATA_TYPE, int> checkPair;
				checkPair = *iter;
				emptyPair = emptyList.front();
				if (checkPair == emptyPair)
				{
					iter++;
				}
				else
				{
					cout << "(" << checkPair.first << ", " << checkPair.second << "), " << endl;
					iter++;
				}
			}

			index++;
		}
	}



private:
	int Size;
	list<string> emptyList;
	vector<list<pair<DATA_TYPE,int>>> myTable; //vector of a list of pairs 
};