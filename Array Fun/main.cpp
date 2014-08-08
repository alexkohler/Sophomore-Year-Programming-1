//main.cpp - Vector class testing main entry point
//Written by Alex Kohler

#include <iostream>
using namespace std;

//preprocessor constant- standard- all caps, separated by underscore

#define MAX_SIZE	10 // << DO NOT USE A SEMICOLON HERE, macro replaces, no memory

//you may also use a global constant
const int MaxSize = 10; //pascal names

//Print Function: C-Arrays must be passed as 2 arguments: [pointer and size)
void PrintArray(int* someArray, int size) //or int somearray[]
{
	for ( int i = 0; i < size; i++)
	cout << someArray[i] << endl;
}

void main()//()-function call operator, []-index operator
{
	//C-array of integers
	//myArray is a pointer of type int* (pointer to an integer), akin to a piece of paper with address on it
	int myArray[MAX_SIZE] = {0}; //all array values will be set to 0 

	//sizeof(myArray) / sizeof(


	for (int i = 0; i <MAX_SIZE, i++;)
		myArray[i] = i + 1;
	

PrintArray(myArray, MAX_SIZE); //printing a pointer to screen gives address

	//Pointer to an integer (* after data type means a pointer)
	int* myPointer = NULL;
	//compatible types, each is int*
	myPointer = myArray;
	
	myPointer++; //points to next array element (2nd)
	myPointer +=2; //points to fourth array element;
	myPointer--; //points to third element
	
	myPointer = myArray + 30;
	int myValue2 = *myPointer;

	//equivalent to
	myPointer = &myArray[3]; // & is address-of operator
	


	//* in front of a pointer dereferences the pointer (removes (1) * from pointer type)
	//thus giving you the value the pointer points to)
	int myValue = *myPointer; // int* -> int


	//index operator derferences the pointer it is applied to
	myValue = myArray[1];
	//Equivalent to
	myValue = *(myArray + 1/* 1 *sizeof(int) */);

	int sizeOfInt = sizeof(int); //sizeof() computes the size of a data structure in bytes
	int sizeOfPointer = sizeof(myPointer);//4 bytes
	int sizeOfArray = sizeof (myArray);//40 bytes
	int arraySize = sizeof (myArray)/sizeof(int);
	//pointers 64 bit- 8 bytes, 32 bit-4 bytes

	system("pause");
}