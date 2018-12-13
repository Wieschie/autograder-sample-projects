#ifndef __POINT__
#define __POINT__
#include <iostream> 
#include <math.h> 
using namespace std;

class Point
{
public:

	Point()
	{
		setX(0.0);
		setY(0.0);
	}
	Point(double x, double y)
	{
		setX(x);
		setY(y);
	}
	Point(double x)
	{
		setX(x);
		setY(0.0);
	}
	Point(const Point & p)
	{

	}

	const Point & operator=(const Point  & rhs)
	{
		x = rhs.x;
		y = rhs.y;
		return 0;
	}
	bool operator==(const Point p) const
	{
		if (x == p.x && y == p.y)
		{

			return(true);
		}
		else
			return(false);
	}
	bool operator!=(const Point p) const
	{
		if (x != p.x || y != p.y)
		{

			return(true);
		}
		else
			return(false);
	}

	double distance(const Point p)
	{
		double dist;
		double d;
		d = ((x - p.x)*(x - p.x)) + ((y + p.y)*(y + p.y));
		dist = sqrt(d);
		return dist;
	}
	double getX()const
	{
		return x;
	}
	double getY()const
	{
		return y;
	}
	void setX(double x1)
	{
		x = x1;
	}
	void setY(double y1)
	{
		y = y1;
	}

private:
	double x;
	double y;
};
istream & operator>>(istream & in, Point & p)
{
	double x;
	double y;
	char separator;
	in >> separator;
	in >> x;
	in >> separator;
	in >> y;
	in >> separator;
	p.setX(x);
	p.setY(y);
	return in;

}
ostream & operator<<(ostream & out, const Point &p)
{
	out << '(' << p.getX() << ',' << p.getY() << ')';
	return out;
}
#endif

