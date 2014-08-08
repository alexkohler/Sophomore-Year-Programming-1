//main.cpp - Vector class testing main entry point
//Written by Alex Kohler

#include <iostream>
#include "Vector.h"
using namespace std;
//function to print Vector
template<typename DATA_TYPE>
//typename& means it is a reference
//const makes your reference read only and thus prevents your object from being accidentally modified 
//OBJECTS ALMOST ALWAYS PASSED BY REFERENCE 
void Print(const Vector<DATA_TYPE>& myVector)
{
	for (int i = 0; i < myVector.GetSize(); i++){
		cout << myVector[i] << " ";
	}
}

//typename argument name- pass by value, passing copy of original
//primitive types- int, char, bool- okay to pass by value
//objects- pass by reference(&), passing the ORIGINAL, not a copy
//reference-stores address like pointer, unlike pointers, this address is never accesible/not modifiable, references do not need dereferenced


void main(){



	//myVector allocated statically on stack 
	//myVector object is initialized using the default constructor;
	Vector<int> myVector(15);
	Vector<int> myVector2;

	myVector2 = myVector; //every class by default has assignment operator, however, is by default a shallow copy 


	//Populate the vectors with numbers 1-10

	for (int i = 0; i < 10; i++)
		myVector.Add(i+1);

	cout << "Vector currently holds..." << endl;
	cout << myVector << endl << endl;



	cout << "Adding 11 into myVector..." << endl;
	myVector.Add(11);
	cout << "Vector now holds..." << endl;
	cout << myVector << endl << endl;


	cout << "Inserting 14 into the first entry of myVector... " << endl;
	myVector.Insert (0, 14);//had an error with an out of bounds value, fixed it with insert
	cout << "Vector now holds..." << endl;
	cout << myVector << endl << endl;;

	cout << "Removing 14 from the first entry of myVector..." << endl;
	myVector.Remove(0);
	cout << "Vector now holds..." << endl;
	cout << myVector<< endl << endl;;


	cout << "TEST FOR SHRINKAGE (via .Remove)" << endl;
	cout << "To shrink the vector, size must be less than half of capacity" << endl;
	cout << "Capacity is currently " << myVector.GetCapacity() << ". Size is currently " << myVector.GetSize() << "." << endl;
	cout << "To do that, I will remove 7 values and check capacity afterwards. " << endl; 
	int tempCapacityShrink = myVector.GetCapacity();
	for (int i = 0; i<7; i++){
		myVector.Remove(i);}
	cout << "Capacity is now " << myVector.GetCapacity() << ", shrinking 5 from its previous value of " << tempCapacityShrink << "." << endl;
	cout << "Vector now holds..." << endl;
	cout << myVector << endl << endl;




	cout << "TEST FOR GROWTH (via .Add)" << endl;
	cout << "Expanding capacity beyond the  set number of " << myVector.GetCapacity() << endl;
	cout << "to see if Add function will allow it to grow" << endl;
	cout << "To do that, I will add an additional eight values and check capacity afterwards" << endl;

	int tempCapacityGrow = myVector.GetCapacity();
	for (int i=5 ; i<13; i++)
	{
	myVector.Add(i*2);
	}
	cout << "Vector now holds..." << endl;
	cout << myVector << endl << endl;

	cout << "Capacity is now " << myVector.GetCapacity() << ", growing 10 from its previous value of " << tempCapacityGrow << "." << endl << endl << endl;;



	try //can use multiple try/catch blocks
	{
		cout << "TESTING [] OPERATOR" << endl;
		cout << "Testing within bounds:Calling first element myVector[0], should output 2" << endl;
		cout << "myVector[1] = " << myVector[0] << endl;
		cout << "Testing out of bounds- Calling element[-1]: Should throw out of bounds error" << endl;
		cout << "myVector[-1] = " << myVector[-1] << endl;
		cout << endl << endl;

		//Allocate object pointed by myVectorPointer dynamically on heap using the new operator
		Vector<float>* myVectorPointer = new Vector<float>;

		//Dispose of the object and calls the destructor 
		delete myVectorPointer;

	}

	catch(string error)
	{
		//error handing code goes here
		cout << error << endl;
	}

	system("pause");
}