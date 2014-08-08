//Quicksort
//written by Alexander Kohler


#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename DATA_TYPE>
int partition (vector<DATA_TYPE>& sortVector, int startPos/*m*/, int endPos/*n*/)
{
DATA_TYPE pivot;
bool sorted = false;
pivot = sortVector[0]; //let first element value be pivot
while (sorted == false){
//Scan the array from the left to find the index (up) of the first value larger than the pivot.
for (int i=0; i<sortVector.size(); i++)
{
	if (sortVector[i] > pivot){//if the value at index i is larger than the piviot
		startPos = i; //then our index up is at this index
		break;//want first value, so break out of the loop after it is found
	}
}

//Scan the array from the right to find the index (down) of the first value smaller than or equal to the pivot
for (int i=sortVector.size()-1; i >= 0; i--)
{
	if (sortVector[i] <= pivot){
		endPos = i;
		break;
	}
}

//If up < down then we swap the larger and the smaller values and repeat the process from step 2 else we break out of the loop.
if (startPos < endPos){
swap(sortVector[startPos], sortVector[endPos]);

}

else
sorted = true;//break out of the loop
}

//Finally, swap the value at the first index with the value at the down index.
swap(sortVector[0], sortVector[endPos]);
return endPos; //return index of the pivot


}


template<typename DATA_TYPE>
void QuickSort(vector<DATA_TYPE> sortVector, int startPos, int endPos)//endpos is same as size
{
int m;
if (endPos - startPos <= 0)
return;

m = partition(sortVector, startPos, endPos);
QuickSort(sortVector, startPos, m-1);
QuickSort(sortVector, m+1, endPos);


}


void main()
{
string readString;
vector<string> stringVector;
//Reads 5 strings from cin;
//Stores these strings in a vector (unsorted);
for (unsigned int i=0; i<5; i++)
{
cin >> readString;
stringVector.push_back(readString);
}

//Sorts the string vector in-place using template QuickSort() function;
QuickSort<string>(stringVector, 0, stringVector.size()-1);
//Prints the string vector (the output must be alphabetically sorted).
for (int i=0; i<5; i++)
cout << stringVector[i] << endl;



system("pause");
}