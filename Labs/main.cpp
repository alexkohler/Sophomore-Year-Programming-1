//main.cpp- Complex number test program main entry point
//Written by Alex Kohler

//f10(step over)-starting program in debug mode- see how variables change
//f11(step into)
//call stack- clicking will show where function is called
//

#include <iostream>
#include "Complex.h"
#include "Complex.h"
using namespace std;

void main()
{
	//Complex number a
	Complex<float> a(1.0f, 2.0f); //can put any data type within brackets, cannot add int + float, etc

	//Complex number b
	Complex<float> b(10.0f, 20.0f);

	//Complex number 3 given by its real and imaginary parts
	Complex<float> c;
	c = a + b; // for global + operator c=+(a,b); f1=help
				//for member + operator: c= a.+(b) (operator within class)
	//TEST CASE for the + operator
	cout << "TEST CASES FOR THE + OPERATOR" << endl;
	c = b + a; //c = b.+(); // THIS ->	b 

	cout << "c = a + b = " << c.Re  << " + i" << c.Im << endl;
	cout << "should print 11 + i22" << endl;
	cout << c << endl; //cout is type ostream (hover)

	Complex<float> d; 
	cout << endl;
	d = c + a;
	cout << "d = c + a = " << d.Re << " + i" << d.Im << endl;
	cout << "Should print 12 + i24" << endl;
	cout << d << endl;
	cout << endl <<endl <<endl;


	
	cout << "TEST CASES FOR UNIARY - OPERATOR" << endl;
	Complex<float> uniaryNegation; 
	uniaryNegation = -b;
	cout << "The uniary negation of b is = -(" << b << ")" << endl;
	cout << "Should print -10 + i(-20)" << endl;
	cout << uniaryNegation << endl;
	cout << endl;

	uniaryNegation = -a;
	cout << "The uniary negation of a is = - (" << a << ")" << endl;
	cout << "Should print -1 + i(-2)" << endl;
	cout << uniaryNegation << endl;
	cout << endl <<endl <<endl;

	
	cout << "TEST CASES FOR BINARY - OPERATOR" << endl;
	
	Complex<float> binaryNegation;
	binaryNegation =  b + -a;
	cout << "b + -a = (" << b.Re << " - " << a.Re << ") + i(" << b.Im << "-" << a.Im << ")" << endl;
	cout << "Should print 9 + i18" << endl;
	cout << binaryNegation << endl;
	cout << endl;

	binaryNegation = c + -a;
	cout << "c + -a = " << binaryNegation.Re << " + i" << binaryNegation.Im <<  endl;
	cout << "Should print 10 + i20" << endl;
	cout << binaryNegation << endl;
	cout << endl <<endl <<endl;


	

	cout << "TEST CASES FOR ABSOLUTE() FUNCTION " << endl;
	c.Re = 3.0f;
	c.Im = 4.0f;
	cout << "|c| = " << "sqrt(c.Re^2 + c.Im^2) = " << "sqrt((" << c.Re << "*" << c.Re << ") + (" << c.Im << "*" << c.Im << "))" << endl;
	cout << "Should print 5" << endl; 
	cout << c.Absolute() << endl;
	cout << endl;

	c.Re = 5.0f;
	c.Im  = 12.0f;
	cout << "|c| = " << "sqrt(c.Re^2 + c.Im^2) = " << "sqrt((" << c.Re << "*" << c.Re << ") + (" << c.Im << "*" << c.Im << "))" << endl;
	cout << "Should print 13" << endl; 
	cout << c.Absolute() << endl;
	cout << endl <<endl <<endl;





	cout << "TEST CASES FOR EQUALITY FUNCTION" << endl;
	cout << "Testing if c==c, should print true (1). (c is " << c << " and c is " << c << ".)" << endl;
	cout << (c ==  c);
	cout << endl;

	cout << "Testing if c==a, should print false (0). (c is " << c << " and a is " << a << ".)" << endl;
	cout << (c ==  a);
	cout << endl <<endl <<endl;


	cout << "TEST CASES FOR INEQUALITY FUNCTION" << endl;
	cout << "Testing if c!=c, should print false (0). (c is " << c << " and c is " << c << ".)" << endl;
	cout << (c != c) << endl;

	cout << "Testing if c!=a, should print true (1). (c is " << c << " and a is " << a << ".)" << endl;
	cout << (c != a) << endl;


	cout << endl << endl << endl;


	cout << "TEST CASES FOR * operator"  << endl;
	cout << "a * b =" << "(" << a.Re << " * " << b.Re << " - " << a.Im << " * " << b.Im <<" ) + (" << a.Im <<"*" <<  b.Re << " + i" << a.Re << "*" << b.Im << ")i = (" << a.Re*b.Re << "-" << a.Im*b.Im << ") + (" << a.Im*b.Re << "+" << a.Re*b.Im << ")" << endl;
	cout << "Should print " << (a.Re * b.Re - a.Im * b.Im) << " + i" << (a.Im * b.Re + a.Re * b.Im) << endl;
	cout << a * b << endl;


	cout << "a * c =" << "(" << a.Re << " * " << c.Re << " - " << a.Im << " * " << c.Im <<" ) + (" << a.Im <<"*" <<  c.Re << " + i" << a.Re << "*" << c.Im << ")i = (" << a.Re*c.Re << "-" << a.Im*c.Im << ") + (" << a.Im*c.Re << "+" << a.Re*c.Im << ")" << endl;
	cout << "Should print " << (a.Re * c.Re - a.Im * c.Im) << " + i" << (a.Im * c.Re + a.Re * c.Im) << endl;
	cout << a * c << endl;
	cout << endl << endl << endl;




	cout << "TEST CASES FOR / OPERATOR" << endl; 
	cout << a << endl;
	cout << b << endl;
	cout << "a / b =" << "= ((" << a.Re*b.Re << "+" << a.Im*b.Im << ")/( "<< b.Im << "^2 +" << b.Re << "^2)) + i((" << a.Im*b.Re << "-" << a.Re*b.Im << ")/(" << b.Im << "^2 + " << b.Re << "^2))" << endl;
	cout << "Should print " <<(((a.Re*b.Re) + (a.Im * b.Im)) / ((b.Re *b.Re) + (b.Im * b.Im))) << " + i" << (((a.Im * b.Re) - (a.Re *b.Im) ) / ((b.Re *b.Re) + (b.Im * b.Im))) << endl;
    cout << a / b << endl;
	cout << endl;


	cout << a << endl;
	cout << b << endl;
	cout << "b / a =" << "= ((" << b.Re*a.Re << "+" << b.Im*a.Im << ")/( "<< a.Im << "^2 +" << a.Re << "^2)) + i((" << b.Im*a.Re << "-" << b.Re*a.Im << ")/(" << a.Im << "^2 + " << a.Re << "^2))" << endl;
	cout << "Should print " <<(((b.Re*a.Re) + (b.Im * a.Im)) / ((a.Re *a.Re) + (a.Im * a.Im))) << " + i" << (((b.Im * a.Re) - (b.Re *a.Im) ) / ((a.Re *a.Re) + (a.Im * a.Im))) << endl;
    cout << b / a << endl;
	cout << endl << endl << endl;

	
	
	cout << "TEST CASES FOR PHASE FUNCTION" << endl;
	a.Re = 1;
	a.Im = 2;
	cout << "Phase of " << a << " is = atan (" << a.Im << "/" << a.Re << ")" << endl;
	cout << "Should print " << atan(a.Im / a.Re) << " radians" <<  endl;
	cout << a.Phase() << " radians " << endl << endl;
	
	a.Re = -5;
	a.Im = 3;
	const float  PI_F=3.14159265358979f;
	cout << "Phase of " << a << " is = atan (" << a.Im << "/" << a.Re << ") + (pi) " << endl;
	cout << "Should print " << atan(a.Im / a.Re) + (PI_F) << " radians" <<  endl;
	cout << a.Phase() << " radians " << endl;



	system("pause");
}