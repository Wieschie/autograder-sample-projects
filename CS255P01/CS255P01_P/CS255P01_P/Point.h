// Copied directly from the provided project PDF
#ifndef __POINT__
#define __POINT__

#include <iostream>
#include <math.h>

using namespace std;

class Point {
public:
	//0 - arg constructor
	Point();

	//2 - arg constructor
	Point(double x, double y);

	//1 - arg constructor
	Point(double x);

	//copy constructor 
	Point(const Point & p);

	const Point & operator=(const Point & rhs);

	bool operator==(const Point p) const;

	bool operator!=(const Point p) const;

	double distance(const Point p) const;

	double getX() const;

	double getY() const;

	void setX(double x);

	void setY(double y);

private:
	double x;
	double y;
};
//NOTE semicolon after closing brace

istream & operator>>(istream & in, Point & p);

ostream & operator<<(ostream & out, const Point p);
#endif
