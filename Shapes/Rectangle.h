//Rectangle.h -- Rectangle shape class declaration
//Written by Alex Kohler

#pragma once


#include "Shape.h" 
using namespace std;



class Rectangle: public Shape
{
public:
	Rectangle(int x, int y, int width, int height, Colors color) : Shape(x,y,color) 
	{
		X = x;
		Y = y;
		Width = width;
		Height = height;
		Color = color;

	}

	virtual void Move(int deltaX, int deltaY) //emphasize you are overriding base class function
	{
		X += deltaX;
		Y += deltaY;

	}

	virtual void Scale(float scaleFactor)
	{
		Height = int(Height * scaleFactor);
		Width = int(Width * scaleFactor); //force explicit conversion to int
	}


	virtual void Draw() const
	{
		cout << "RECTANGLE at top left corner (" << X << ", " << Y << ") of width " << Width << " and height " << Height << " and color " << GetColor() << endl;
	}

private:
	int Width, Height;

};