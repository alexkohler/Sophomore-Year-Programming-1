//Complex.h - Complex number user-defined type declaration
//Written by Alex Kohler

//User-defined type declaration 
//fixing indenation edit->advanced-> format document (will also fix your braces) 

//To safeguard against accidential multiple inclusions of the same header
//function overload- same function names, different parameters
#pragma once //quiz Q

#include <iostream>

#include <math.h>

using namespace std; 
template<typename DATA_TYPE>
struct Complex
{
	//Default constructor: has no arguments
	Complex() //has to match name of class exactly
	{
		Re = Im = 0.0f;
	}


	//Init constructor: has arguments
	Complex (DATA_TYPE real, DATA_TYPE imaginary)
	{
		Re = real;
		Im = imaginary;
	}


	//hybrid default/init constructor  Complex(DATA_TYPE real = 0.0f, DATA_TYPE imaginary = 0.0f) 

		Complex operator +(/*Complex a, */Complex b)
{
	return
		Complex (Re + b.Re, Im + b.Im);
		}
	//result variable is an instance of class Complex; result is an object
	//Complex result;

	// . is a member access operator - quiz Q
	//result.Re =this->Re + b.Re;
	//result.Im =this->Im + b.Im;

	//return result;




// Uniary - operator for negating this complex number
	Complex operator -() //since this is a member argument, first argument is implicit
	{
		return
			//Returning new unnamed Complex value using the init constructor
			Complex (-Re, -Im);
			//Equivalent to:
			//Complex unnamed (-Re, -Im)
			//return unnamed;
	}

	Complex operator * (Complex b) //multiplication operator
	{
		
		return
			Complex ((Re * b.Re - Im * b.Im), (Im * b.Re + Re * b.Im));

	}

	Complex operator / (Complex b) //division operator 
	{
		return
			 Complex ( (((Re*b.Re) + (Im * b.Im)) / ((b.Re *b.Re) + (b.Im * b.Im))), (((Im * b.Re) - (Re *b.Im) ) / ((b.Re *b.Re) + (b.Im * b.Im))) );

	}


	//Comparison operator: equality
	bool operator == (Complex compareTo)
	{
		return
			(Re == (compareTo.Re) && (Im == compareTo.Im));
	}

	//Comparison operator: inequality

	bool operator != (Complex compareTo)
	{
		return
			// Call == operator and negate its output
			!(*this == compareTo);
	}


	//Member function to compute absolute value of this Complex number
	DATA_TYPE Absolute()
	{
		return sqrt(Re*Re + Im*Im);
	}



//phase function (mistake:must be within struct of complex otherwise data_type is unknown type
 DATA_TYPE Phase()
{
const float  PI_F=3.14159265358979f;
if (Re > 0)
{return atan(Im / Re);}    
 if (Re < 0 && Im >= 0)
 {return atan(Im/Re) + PI_F;}
 if (Re < 0 && Im < 0)
 {return atan(Im/Re) - PI_F;}
 if (Re == 0 && Im > 0)
 {return PI_F / 2;}
 if (Re == 0 && Im < 0)
 {return -PI_F / 2;}
 else
 {cout << "INDETERMINATE" << endl;}
 }




	//fields aka properties aka data members 
	DATA_TYPE Re;
	DATA_TYPE Im;
	}; //ALWAYS put semicolon at the end of class or struct declaration





//class = user defined type



//Global template Stream output operator << for Complex class (global because declared outside class) 
template<typename DATA_TYPE>
ostream& operator << (ostream& out, Complex<DATA_TYPE> myComplex)  //if using void, you may only use the stream output you declared (only ostream)
{
		out << myComplex.Re << " + i" << myComplex.Im;
		return out;
}

//Complex operator -(Complex a, Complex b)
//{
//	result variable is an instance of class Complex; result is an object
//	Complex result;

	// . is a member access operator - quiz Q
//	result.Re = a.Re - b.Re;
//	result.Im = a.Im - b.Im;

//	return result;
//}

//implement * and /, make sure == and != and absolute() works, implement phase() << operator
//Phase- using arctan, find angle between Imaginary axis and the vector created by Re and Im
//for each, must have 2 test cases in main
//only minus is binary and uniary 