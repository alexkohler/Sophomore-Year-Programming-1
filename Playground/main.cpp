#include <iostream>
using namespace std;

int x[10];
int get_element_of_x(int index) {
if (index < 0 || index >= 6) {
throw std::out_of_range(
"In get_element_of_x, the value of index is out of range");
}
return x[index];
}

void main (){
//throw fun 
int val;
try {
val = get_element_of_x(10);
}
catch (std::out_of_range& ex) {
cerr << "Out of range exception occurred\n";
cerr << ex.what() << endl;
abort(); // Exit with an error indication.
}
system ("pause");
}







//pointer fun 
//int* myPointer;
//int integer=5;
//myPointer = &integer; //
//cout << "I am now pointing to integer (5) " << integer << myPointer << endl; //outputting a pointer will give its hexadecimal address
//int barrel;
//barrel  = *myPointer; //derefencing myPointer into a barrel
//cout << "The barrel should have a 5- " << barrel << endl;
//cout << "However, the address should not have changed. " << endl;
//cout << myPointer <<endl <<endl; 
//cout << "incrementing a pointer makes no goddamn sense so don't do it" << endl;
//cout << "instead, use the dereference to change values " << endl << endl;
//*myPointer += 5;
//cout << "I added 5 to the derefenced myPointer, " << endl;
//cout << "which essentially adds 5 to what it points to (integer)" << endl;
//cout << "assignment/modification of a derefenced pointer IS equal to changing the value of what it points to" << endl;
//cout << integer << endl;
//int myArray[]={0,5,1};
//if (myArray[1] == *(myArray + 1) && &myArray[1] == (myArray +1)) // can use pointers to reference arrays and their respective memory locations 
//{cout << "gfy" << endl;} 