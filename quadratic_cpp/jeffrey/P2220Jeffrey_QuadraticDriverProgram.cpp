//Solution to Project 2 for CS220-02 Fall 2014
/* Description: This program finds the roots of a quadratic polynomial
when real roots exist and indicates complex roots. Furthermore, it
solves a linear polynomial if given one, and looks for the degenerate and
inconsistent cases when a constant alone is given.
Author: John Jeffrey
Date:  Fall 2014

Notes: Commented-out is version that uses functions for find the roots of quadratic

*/
#include <iostream>
#include <cmath>
using namespace std;
//double quadraticRoots(double, double, double, double&, double&);

int main()
{
	double a, b, c;
	double discriminant;
	double root1, root2;

	cout << "Program computes and prints the real roots " << endl;
	cout << "of a quadratic polynomial: a*x^2 + b*x + c. " << endl;
	cout << "Enter three real numbers a, b, and c, separated by spaces: ";
	cin >> a >> b >> c;

	if (a == 0)
	if (b == 0)
	if (c == 0)
		cout << "No roots for the degenerate case of 0 = 0." << endl;
	else
		cout << "No roots for the constant function " << c << endl;
	else {
		cout << "The only root for the linear case of " << b << "*x";
		if (c != 0)
			cout << " + " << c << " = 0 " << " is: " << -c / b << endl;
		else
			cout << " = 0 " << " is: " << 0 << endl;
	}
	else { // a != 0 so process quadratic cases
		cout << "The quadratic polynomial " << a << "*x^2";
		if (b != 0) cout << " + " << b << "*x ";
		if (c != 0) cout << "+ " << c << " ";

		discriminant = b*b - 4 * a*c;

		if (discriminant >= 0) {
			root1 = (-b + sqrt(discriminant)) / (2 * a);
			root2 = (-b - sqrt(discriminant)) / (2 * a);
		}

		if (discriminant < 0)
			cout << "has two complex roots.\n";
		else if (discriminant == 0){
			cout << "has two equal real roots:\n";
			cout << "root1 = root2 = " << root1 << endl;
		}
		else {
			cout << "had two distinct real roots:\n";
			cout << "root1 = " << root1 << " and root2 = " << root2 << endl;
		}
	}
	return 0;
}
//double quadraticRoots(double a, double b, double c, double& r1, double& r2)
//{
//	double discriminant = b*b - 4*a*c;
//	
//	if( discriminant >= 0) {
//		r1 = (-b + sqrt(discriminant)) / (2*a);
//		r2 = (-b - sqrt(discriminant)) / (2*a);
//	}
//
//	return discriminant;
//}