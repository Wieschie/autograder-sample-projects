#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include "Point.h"
using namespace std;
/*
Project 1
Joryn Meehan
cs 255
*/

///////   prototype number generator  /////
///*
void randomNumbers(string name) {

	srand(time(0));

	unsigned i;
	unsigned j;

	const int MAX_VALUE = 100;

	double nums[MAX_VALUE];
	ifstream output;



	ofstream fout(name);


	fout << setiosflags(ios::showpoint) << setprecision(3);


	for (i = 0; i < MAX_VALUE; ++i) {

		fout << "( " << ((rand() % 100)) << ", " << ((rand() % 200) + 50) << ')' << endl;

	}




	return;
}
// */

int main() {

	const int MAX_SIZE = 1000;
	double value[MAX_SIZE];



	ifstream input; //connect to file
	ifstream fout;
	string name;

	int numVals = 1;

	Point p[MAX_SIZE];

	int iteration = 0;
	unsigned  i;
	unsigned j;
	unsigned k;
	int indexMin = 0;
	double temp = 0.0;

	Point max1;
	Point max2;
	Point min1;
	Point min2;

	double maxDist = 0.0;
	double minDist = 0.0;

	cout << "Enter file name" << endl;
	cin >> name;

	///////   TEST NUMBERS ////////
	randomNumbers(name);




	//////////   OPEN THE FILE   ////////
	input.open(name);
	if (input.fail()) {
		cout << "corrupt data" << endl;
		cout << "file " << name << " could not be opened" << endl;
		exit(1);
	}

	////////////   SEARCH FILE    //////////
	cout << "Reading in numbers." << endl;
	unsigned numOfPoints = 0;
	while (input >> ws && !input.eof() && numOfPoints < MAX_SIZE)
	{
		input >> p[numOfPoints]; // uses overloaded >> operator for reading points
		numOfPoints++;
	}

	input.close();



	for (i = 0; i < numOfPoints; ++i) {

		cout << p[i] << endl;
	}

	//////////  SET MIN DIST ////////
	minDist = p[0].distance(p[1]);



	/////////   CHECK FOR NEW DIST    /////////
	for (i = 0; i < numOfPoints - 1; ++i) {
		for (j = i + 1; j < numOfPoints; ++j) {


			if (p[i].distance(p[j]) > maxDist) {
				maxDist = p[i].distance(p[j]);
				max1 = p[i];
				max2 = p[j];
			}



			else if (p[i].distance(p[j]) <= minDist) {

				minDist = p[i].distance(p[j]);
				min1 = p[i];
				min2 = p[j];
			}

		}
	}

	cout << "the max distance is: " << maxDist << " between: " << max1 << max2 << endl;
	cout << "the min distance is: " << minDist << " between: " << min1 << min2 << endl;

	/*
	for (i = 0; i < numVals; ++i){
	cout << value[i] << ' ';
	}

	cout << endl;
	// */


	return 0;
}