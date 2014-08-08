//Vector.h- Vector (aka dynamic array) template class declaration 
//Written by Alex Kohler

#pragma once

#include <sstream>
using namespace std;


#define INITIAL_CAPACITY	20
#define CAPACITY_BOOST		10
#define CAPACITY_SHRINK      5

//encapsulates C-array and gives it additional features
template<typename DATA_TYPE>
class Vector //both keywords class and struct are equivalent, however, everything by default in class is private, struct is all public by default 
{
public:
	//Hybrid default/init constructor
	Vector(int initialCapacity = INITIAL_CAPACITY)
	{
		Size = 0;
		Capacity = initialCapacity;
		Data = NULL;


		//Dynamically allocate Data on heap using the new operator
		Data = new DATA_TYPE[Capacity];
	}

	//copy constructor, performs DEEP COPY
	Vector (const Vector& source)
	{

		//intentionally resetting data pointer to prevent the delete[] operator from freezing
		//in the assignent operator that follows 
		Data = NULL;

		//Calling the assignment operator to do the deep copy
		*this = source;
	
	
	}

	
	//Destructor
	~Vector()
	{
		//dispose memory previously allocated with new 
		delete [] Data;
		Data = NULL; 
	}


	//assignment operator that performs DEEP COPY
	//must return reference to the current Vector
	//if type void, could not chain Vector equivalence
	Vector& operator = (const Vector& source)
	{

		//to avoid memory leak, delete old data
		delete [] Data;

		Size = source.Size; //or .GetSize()
		Capacity = source.Capacity;
	
		//need to allocate memory
		Data = new DATA_TYPE[Capacity];

		//copy each element one by one
		for (int i = 0; i < Size; i++)
		Data[i] = source.Data[i];
		//Return the reference to this Vector
		return *this; 

	}


	void Add(DATA_TYPE newElement)//can just call insert function 
	{
		//1. Do we have enough capacity?
		if ( Size >= Capacity)
		{
			//2. If not then reallocate the Vector
			//increase capacity
			Capacity += CAPACITY_BOOST;
		
			DATA_TYPE* newData = new DATA_TYPE[Capacity];

			//Copy from the old C-array into newData
			for (int i = 0; i < Size; i++)
				newData[i] = Data[i];

			//dispose of the old C-array
			delete [] Data;

			//re-assign the pointers 
			Data = newData; 
		}





		//3. Put the new element into the vector
		Data[Size] = newElement; //[Size - 1 + 1]
		Size++;

	}


	
void Remove(int index){


	//Are we meeting capacity requirements? (Must shrink when its size is less than half the capacity)
	if ( Size < Capacity / 2){
		//if so, we must shrink the vector 
		Capacity -= CAPACITY_SHRINK;

	DATA_TYPE* newData = new DATA_TYPE[Capacity]; 


	//copy old c array
	for (int i = 0; i < Size; i++)
				newData[i] = Data[i];


	//dispose of the old C-array
			delete [] Data;

	//re-assign the pointers 
			Data = newData; 
	}

	for (int i = index + 1; i < Size; i++){
	Data[i - 1 ] = Data[i];
	}
	
	Size--; 
	}
			


void Insert(int index, DATA_TYPE insertValue){

	if (index < 0 || index > Size) {
		throw;
	}


	//Are we meeting capacity requirements? (Must shrink when its size is less than half the capacity)
	if ( Size == Capacity){
		//if so, we must shrink the vector 
		Capacity += CAPACITY_BOOST;

	DATA_TYPE* newData = new DATA_TYPE[Capacity]; 


	//copy old c array
	for (int i = 0; i < Size; i++)
				newData[i] = Data[i];


	//dispose of the old C-array
			delete [] Data;

	//re-assign the pointers 
			Data = newData; 
	}

	
	for (int i = Size; i > index; i--)
	{Data[i] = Data[i-1];}
	
	
	Data[index] = insertValue;
	Size++;
	}



	
 




	//Index operator for accessing vector elements
	//must return by reference to enable modification of vector values!!!
	DATA_TYPE& operator [] (int index) const //not modifying object, add const
	{
		//Bounds check
		if ( (index < 0) || (index >= Size ) ) 
		{
			stringstream error;
			error << "Error: Vector:: operator[], index " << index <<" is out of bounds(0.." << (Size - 1) << ")";

			throw error.str();
		}


		return Data[index];
	}

	//function to retrieve size
	//const modifier means that the function does NOT modify this object
	//(it does NOT change any DATA MEMBERS of this class)
	//Hence this function can be called on a const reference!
	//can only be used on member functions and member operators, not constructors or destructors

	int GetSize()  const //since this is simply returning size(not modifying object), can add const
		{ 
			return Size; }

int GetCapacity() const //function to retreive capacity 
	{ 
	return Capacity; }



private: 
	//The encapsulated C-array given by a pointer
	DATA_TYPE* Data;
	//Vector size
	int Size; 
	//Vector capacity
	int Capacity;

	//implement bounds check function


};


//stream output operator for printing the vector to console 
//typename& makes it a refeence
//const maakes your reference read only and thus
//prevents your
template<typename DATA_TYPE>
ostream& operator << (ostream& out, const Vector<DATA_TYPE>& myVector)
{
	for (int i = 0; i < myVector.GetSize(); i++){
		out << myVector[i] << " ";
	}
	return out;
}








//private-gears, wires, face (unnecessary information) (accidental malfunction)- everything by default in class is private
//public-wheel, pedals, nads , everything by default in struct in public
//pascal names for members
//local-stack, ex, function is returned, stack is destroyed, static memory
//global-heap, exists as long as program is running (global storage), dynamic memory
//Default constructor- no arguments, no constructor has return type
//throw- keyword in c++, used for exception, signal to program that says correctional action is needed
//try-an exception can occur
//shallow copy-everything is copied, pointers, etc. By default, c++ makes shallow copy(also gives default constructor/destructor)
//if vector has no pointers, shallow copy will work
//deep copy- (copying vector)-copying size, capacity- allocates new memory and makes new vector
//if pointer,


//assignment-test everything in main 