//main.cpp - Binary Insert main entry point 
//Written by Alex Kohler


#include <vector>
#include <string>
#include <iostream>

using namespace std;


template<typename DATA_TYPE>
// Find the index of ‘value’ in sorted ‘myVector’. Returns NOT_FOUND when the value is not there
int BinaryInsert(const vector<DATA_TYPE>& myVector, const DATA_TYPE& value,
   int startPos, int length)
{
   // Base case: empty vector?
   if (length == 0 )//simply inserted at index 0
      return 0; 
   // Base case: only one element in the vector?
   if ( length == 1 )
      if (myVector[startPos] > value )//if the initial value already within the vector is greater than the value to be inserted
         return 0; //then the inserted value must be inserted BEFORE myvector at startpos
      else //if the inital value within the vector is less than the value to be inserted 
         return  1; // then put new value AFTER myvector at startpos
   // Is the element in the middle larger than the value we wish to insert?
   if (myVector[startPos + length/2] > value )
      // Yes, so recursively BinaryInsert the lower half of the vector
      return BinaryInsert(myVector, value, startPos, length/2);
   else
      // No, so recursively BinaryInsert the upper half of the vector
      return BinaryInsert(myVector, value, startPos + length/2, length - length/2);
}


void main()
{
vector<string> myVector; 
vector <int>::iterator Iter;

//Read a string from cin
string value;
//Determine at what index to insert this string into the vector
//Insert the string into the vector
int index;

for (int i=0; i<4; i++)
{
cin >> value;
index = BinaryInsert(myVector, value, 0, myVector.size()); //initial index check

int count=0;
//while (index == 1 && count -1 + myVector.size()/2 < myVector.size() ) //if you can insert after, check the next value 
//{
//index = (BinaryInsert(myVector, value, count, myVector.size())); 
//count++;
//}
//myVector.insert(myVector.begin() + count, value);
//count = 0;
//}



for ( ; (count != myVector.size()) && (index==1); count++ );
index = (BinaryInsert(myVector, value, count, myVector.size())); 

}
cout << myVector[0];
cout << myVector[1];
cout << myVector[2];
cout << myVector[3];
}
