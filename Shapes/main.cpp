//main.cpp Shapes program main entry point
//Written by Alex Kohler

#include <iostream>
#include <vector>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"


using namespace std;

void main()
{
	//Storage container for all shapes
	// Shape* can represent circle* and rectangle* and
	//any pointer to any derived class of Shape
	vector<Shape*> shapes;





	//Let's populate the container with some circles
	Circle* myCircle = new Circle(1, 2, 3, Red);
	shapes.push_back(myCircle);
	//Pushing back new unnamed stack-allocated instance of circle
	shapes.push_back(new Circle(11, 22, 33, Red));
	shapes.push_back(new Circle(10, 20, 30, Blue));


	shapes.push_back(new Rectangle(1,2, 3, 4, Black));
	shapes.push_back(new Rectangle(100 ,200, 300, 400, White));
	shapes.push_back(new Rectangle(135, 225, 315, 405, Green));


	shapes.push_back(new Triangle( 1, 0, 5, 0, 3, 5, White));
	shapes.push_back(new Triangle(2, 3, 0, 0, 4, 0, Green));
	shapes.push_back(new Triangle(25, 0, 30, 12, 3, 55, Red));

	//Draw all shapes
	for ( unsigned int i = 0; i < shapes.size(); i++)
		//-> member access operator alllows accessing members on a pointer to an object 
			shapes[i]->Draw();




	//Move all shapes 
	for ( unsigned int i = 0; i < shapes.size(); i++)
		shapes[i]->Move(1,1);


	//Scale all shapes
	for ( unsigned int i = 0; i < shapes.size(); i++)
		shapes[i]->Scale(1.25f);

	cout << "                         REPRINTING SHAPES..." << endl;

	//draw shapes again
	for ( unsigned int i = 0; i < shapes.size(); i++)
		//-> member access operator alllows accessing members on a pointer to an object 
			shapes[i]->Draw();

	//remove memory allocated on heap
	for ( unsigned int i = 0; i < shapes.size(); i++)
		delete shapes[i];

	system("pause");
}