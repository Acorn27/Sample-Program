// Specification file for Circle derived class
#ifndef CIRCLE_H
#define CIRCLE_H
#include "BasicShape.h"

class Circle : public BasicShape
{
private:
	long centerX;
	long centerY;
	double radius;
public:
	Circle(long x, long y, double rad)
		{ centerX = x; centerY = y; radius = rad; calcArea(); }

	long getCenterX() 
		{	return centerX; }

	long getCenterY() 
		{ return centerY; }

	void calcArea()	
		{ double temp = 3.14159 * radius * radius; BasicShape::setArea(temp);}

	double getArea() 
		{ return BasicShape::getArea();}
};

#endif