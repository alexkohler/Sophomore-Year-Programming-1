//Circle.h -- Circle shape class declaration
//Written by Alex Kohler

#pragma once


#include "Shape.h"
using namespace std;


//Data member with limited range

//Subclass aka derived class aka child class of Shape
class Circle: public Shape
{
public:
	Circle(int x, int y, int radius, Colors color) : Shape(x,y, color)
	{
		Radius = radius;

	}


	//move function is inherited without modification

	//virtual void Move(int deltaX, int deltaY)
	//{
	//	X += deltaX;
	//	Y += deltaY;

	//	}


	//Overriding pure virtual Scale() function from the base class
	virtual void Scale(float scaleFactor)
	{
		Radius = int(Radius * scaleFactor); //force explicit conversion to int
	}


	void Draw() const
	{
		cout << "CIRCLE at (" << X << ", " << Y << ") of radius " << Radius << " and color " << GetColor() << endl;
	}

private:
	//X, Y, color members are inherited from shape 
	int Radius;




};