#ifndef __POINT__
#define __POINT__

#include<iostream>
#include<math.h>
using namespace std;

class Point
{
public:
	Point() //0-arg constructor
	{
		//TO DO: implement and set constructed object to (0.0, 0.0)
		x = 0.0;
		y = 0.0;
	}
	Point(double x, double y) //2-arg constructor
	{
		//TO DO: implement and set constructed object to (x,y)
		this->x = x;
		this->y = y;
	}
	Point(double x) //1-arg constructor
	{
		//TO DO: implement and set constructed object to (x, 0.0)
		this->x = x;
		this->y = y;

	}
	Point(const Point & p) //copy constructor
	{
		//TO DO: implement
		this->x = p.x;
		this->y = p.y;
	}
	const Point & operator=(const Point & rhs)
	{
		//TO DO: implement assignment right-hand side point
		// to this point and return the right-hand side object
		if (this != &rhs) {

			this->x = rhs.x;
			this->y = rhs.y;
		}
		return *this;
	}
	bool operator==(const Point p) const
	{
		//TO DO: implement by returning true if values of p are both equal to this object
		if (p.getX() == p.getY()) {
			return true;
		}
	}
	bool operator!=(const Point p) const
	{
		//TO DO: implement
		if (p.getX() != p.getY()) {
			return true;
		}
	}
	double distance(const Point p)
	{
		//TO DO: implement using Euclidean distance
		double dist = sqrt(pow((p.getX() - x), 2) + pow(p.getY() - y, 2));
		return dist;
	}
	double getX()const
	{
		//TO DO: implement returning only x
		return x;
	}
	double getY()const
	{
		//TO DO: implement returning only y
		return y;
	}
	void setX(double x)
	{
		//TO DO: implement updating only x
		this->x = x;
	}
	void setY(double y)
	{
		//TO DO: implement updating only y
		this->y = y;
	}
private:
	double x;
	double y;
}; //NOTE semicolon after closing brace
istream & operator>>(istream & in, Point & p) //overload >>
{
	double x;
	double y;
	char separator;
	in >> separator; //read past '('
	in >> x;
	in >> separator; //read past ','
	in >> y;
	in >> separator; //read past ')'
	p.setX(x);
	p.setY(y);
	return in;
}
ostream & operator<<(ostream & out, const Point p) //overload <<
{
	out << '(' << p.getX() << ',' << p.getY() << ')';
	return out;
}
#endif
