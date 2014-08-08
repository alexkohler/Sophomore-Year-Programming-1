//Shape.h -- Shape abstract base class
//Written by Alex Kohler

#pragma once
#include <iostream>
#include <string>
using namespace std;

enum Colors {Red, Green, Blue, Black, White}; //ennumeration-new user defined type, within brackets, all possible values. 
//Data member with limited range

//Superclass Shape or parent clsas
class Shape
{
public:
	Shape(int x, int y, Colors color)
	{
		X = x;
		Y = y;
		Color = color;

	}


	//virtual means that the function can be overridden in a derived class
	virtual void Move(int deltaX, int deltaY)
	{
		X += deltaX;
		Y += deltaY;

	}


	// = 0 means pure virtual function 
	//When a class has pure virtual functions, it becomes an abstract base class
	virtual void Scale(float scaleFactor) = 0;


	virtual void Draw() const = 0;


	//Same as private, except that protected data members are accessible within the derived class hierarchy
protected:
	int X, Y; //Pair of coordinates
	Colors Color;

	string GetColor() const
	{
		switch( Color )
		{
		case Red:
			return "Red";
		case Green:
			return "Green";
		case Blue:
			return "Blue";
		case Black:
			return "Black";
		case White:
			return "White";
		default: 
			throw "Shape::GetColor(): unknown color!";
		}
	}

};