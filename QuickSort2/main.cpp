//Quicksort
//written by Alexander Kohler-referenced in chapter 10 from Objects&&abstraction--Koffman


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//template<typename DATA_TYPE>

template<typename RI>
RI partition(RI first, RI last) {
// Start up and down at either end of the sequence.
// The first table element is the pivot value.
RI up = first + 1;
RI down = last - 1;
do {
/* Invariant:
All items in table[first] through table[up - 1] <= table[first]
All items in table[down + 1] through table[last - 1] > table[first]
*/
while ((up != last - 1) && !(*first < *up)) {
++up;
}
// Assert: up equals last-1 or table[up] > table[first].
while (*first < *down) {
--down;
}
// Assert: down equals first or table[down] <= table[first].
if (up < down) { // if up is to the left of down,
// Exchange table[up] and table[down].
std::iter_swap(up, down);
}
} while (up < down); // Repeat while up is left of down.
// Exchange table[first] and table[down] thus putting the
// pivot value where it belongs.
// Return position of pivot.
std::iter_swap(first, down);
return down;
}
namespace KW{
template<typename RI>
void quick_sort(RI first, RI last) {
if (last - first > 1) { // There is data to be sorted.
// Partition the table.
RI pivot = partition(first, last);
// Sort the left half.
KW::quick_sort(first, pivot);
// Sort the right half.
KW::quick_sort(pivot + 1, last);
}
}
}
// Insert partition function. See Listing 10.10


using namespace KW;

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
quick_sort(stringVector.begin(), stringVector.end());
//Prints the string vector (the output must be alphabetically sorted).
for (int i=0; i<5; i++)
cout << stringVector[i] << endl;



system("pause");
}