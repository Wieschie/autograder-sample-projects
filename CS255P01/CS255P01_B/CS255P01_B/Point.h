#ifndef __POINT__
#define __POINT__
#include <iostream>
#include <math.h>
using namespace std;
class Point
{
public:
	Point() // 0-arg constructor

	{
		this->setX(0);
		this->setY(0);
		//TO DO: implement and set constructed object to (0.0, 0.0)
	}
	Point(double x, double y) //2-arg constructor
	{
		this->x = x;
		this->y = y;
		//TO DO: implement and set constructed object to (x,y)
	}
	Point(double x) //1-arg constructor
	{
		this->x = x;
		this->setY(0);
		//TO DO: implement and set constructed object to (x, 0.0)
	}
	Point(const Point & p) //copy constructor
	{
		this->x = p.x;
		this->y = p.y;//TO DO: implement
		return;
	}
	const Point & operator=(const Point & rhs)
	{
		if (this != &rhs) {
			this->x = rhs.x;
			this->y = rhs.y;

		}
		//TO DO: implement assignment right-hand side point
		// to this point and return the right-hand side object
		return *this;
	}
	bool operator==(const Point p) const
	{
		if ((this->x == p.x) && (this->y == p.y)) {
			return true;
		}
		return false;
		//TO DO: implement by returning true if values of p are both equal to this object
	}
	bool operator!=(const Point p) const
	{
		if ((this->x == p.x) && (this->y == p.y)) {
			return false;
		}
		else { return true; }
		//TO DO: implement
	}
	double distance(const Point p)
	{
		return sqrt((this->getX() - p.getX())* (this->getX() - p.getX()) + ((this->y - p.y) * (this->y - p.y)));

		//TO DO: implement using Euclidean distance
	}
	double getX()const
	{
		return this->x;
		//TO DO: implement returning only x
	}
	double getY()const
	{
		return this->y;
		//TO DO: implement returning only y
	}
	void setX(double x)
	{
		this->x = x;
		//TO DO: implement updating only x
	}
	void setY(double y)
	{
		this->y = y;
		//TO DO: implement updating only y
	}

private:
	double x;
	double y;


};

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

#endif // !__POINT__

