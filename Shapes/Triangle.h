//Triangle.h-- Triangle class declaration
//Written by Alex Kohler 

#pragma once

#include "Shape.h" 
using namespace std;

//to move 
//to sclae, pick one corner as anchor, other two move, geometry 


class Triangle: public Shape
{
public:
	Triangle(int x, int y, int x2, int y2, int x3, int y3, Colors color) : Shape(x,y, color) 
	{
		X = x; //x anchor point, should not change in scale function, only in move function 
		Y = y; //y anchor point 
		X2 = x2;
		Y2 = y2;
		X3 = x3;
		Y3 = y3;
		Color = color;

	}

	virtual void Move(int deltaX, int deltaY) //virtual: emphasize you are overriding base class function
	{
		X  += deltaX; //to move a triangle, move all three points 
		Y  += deltaY;
		X2 += deltaX;
		Y2 += deltaY;
		X3 += deltaX;
		Y3 += deltaY;

	}

	//triangle
	//given by 3 coordinates
	//to scale a triangle, pick one pt as anchor(X,Y)
	// calculate dx and dy, so for x1, y1, dX=x1-x, dY=y2-y
	//scaled distance = dY*scale
	//must add this to anchor 
	//xnew =x ' = x + dX*scale


	virtual void Scale(float scaleFactor)
	{

		//take care of (x2, y2)
		int dX;
		int dY;
		dX =  X2-X;
		dY =  Y2-Y;
		int scaledDistanceX;
		scaledDistanceX = int(dX * scaleFactor);
		int scaledDistanceY;
		scaledDistanceY = int(dY * scaleFactor);
		X2 = X2 + scaledDistanceX;
		Y2 = Y2 + scaledDistanceY;

		//take care of (X3, Y3)
		dX =  X3-X;
		dY =  Y3-Y;
		scaledDistanceX = int(dX * scaleFactor);
		scaledDistanceY = int(dY * scaleFactor);
		X3 = X3 + scaledDistanceX;
		Y3 = Y3 + scaledDistanceY;

	}


	virtual void Draw() const
	{
		cout << "TRIANGLE with coordinates (" << X << ", " << Y << "), (" << X2 << ", " << Y2 << "), (" << X3 << ", " << Y3 << ")" << endl;
	}

private:
	int X2,Y2, X3, Y3;

};