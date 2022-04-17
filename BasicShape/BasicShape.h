// Specification file for BasicShape base class
#ifndef BASICSHAPE_H
#define BASICSHAPE_H

class BasicShape
{
private:
	double area;

public:
	double getArea() 
		{return area;}

	virtual void calcArea() = 0;

	void setArea(double a) 
		{ area = a; }
};

#endif