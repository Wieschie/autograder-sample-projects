
#include <iostream>
#include <math.h>

#include "Point.h"

//0 - arg constructor
Point::Point() {
	this->setX(0);
	this->setY(0);
}

//2 - arg constructor
Point::Point(double x, double y) {
	this->setX(x);
	this->setY(y);
}

//1 - arg constructor
Point::Point(double x) {
	this->setX(x);
	this->setY(0);
}

//copy constructor 
Point::Point(const Point & p) {
	this->setX(p.getX());
	this->setY(p.getY());
}

const Point & Point::operator=(const Point & rhs) {
	//Don't assign it if it is just the same thing
	if (this != &rhs) { //Are they in the same address?
		this->setX(rhs.getX());
		this->setY(rhs.getY());
	}
	return *this;
}

bool Point::operator==(const Point p) const {
	return this->getX() == p.getX() && this->getY() == p.getY();
}

bool Point::operator!=(const Point p) const {
	return !(this->getX() == p.getX() && this->getY() == p.getY());
}

double Point::distance(const Point p) const {
	return sqrt(((this->getX() - p.getX())*(this->getX() - p.getX())) + ((this->getY() - p.getY())*(this->getY() - p.getY())));
}

double Point::getX() const {
	return this->x;
}

double Point::getY() const {
	return this->y;
}

void Point::setX(double x) {
	this->x = x;
}

void Point::setY(double y) {
	this->y = y;
}

istream & operator>>(istream & in, Point & p) { //overload >>
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

ostream & operator<<(ostream & out, const Point p) { //overload <<
	out << '(' << p.getX() << ',' << p.getY() << ')';
	return out;
}