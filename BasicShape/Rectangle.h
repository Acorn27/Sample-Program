// Specification file for Rectangle derived class
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "BasicShape.h"

class Rectangle : public BasicShape
{
private:
	long width;
	long length;

public:
	Rectangle(long w, long l)
		{ width = w; length = l; calcArea(); }

	long getWidth() 
		{ return width; }

	long getLength() 
		{ return length; }

	void calcArea() 
		{ double temp = length * width; BasicShape::setArea(temp); }
};

#endif