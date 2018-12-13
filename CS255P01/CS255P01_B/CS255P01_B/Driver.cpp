// B
//CS 255-02
//Project 1:Minimum and Maximum Distances between Cartesian Plane Points
//Project Start Date:2/13/15
//Project Due Date: 2/18/15

#include <iostream>
#include <fstream>
#include <string>
#include "Point.h"


using namespace std;
int main() {

	const int MAX_NUM_POINTS = 1000;
	Point p[MAX_NUM_POINTS]; //array


	string fileName; // name of file
	ifstream infile; // Input file stream; used to read file named fileName
	//get file name from user
	cout << "Enter file name: ";
	cin >> fileName;
	string pathName = "H://visual studio 2013\\Projects\\P1255Brennan\\P1255Brennan\\";

	infile.open(pathName + fileName);

	if (infile.fail())
	{
		cout << "Cannot open file " << fileName
			<< " Aborting." << endl;
		return 1;
	}
	//infile is connect to fileName so start reading points into an array for representing the set
	cout << "Reading in numbers." << endl;
	unsigned numOfPoints = 0;
	while (infile >> ws && !infile.eof() && numOfPoints < MAX_NUM_POINTS)
	{
		infile >> p[numOfPoints]; // uses overloaded >> operator for reading points
		numOfPoints++;
	}
	//done reading so close file
	infile.close();

	cout << "Points read..." << endl;
	for (unsigned i = 0; i < numOfPoints; i++) {
		cout << p[i] << endl;
	}

	if (numOfPoints > 1) {
		//initializations
		double maxDist = 0;
		double minDist = 9999;
		Point maxPoint1 = p[0];
		Point maxPoint2 = p[0];
		Point minPoint1 = p[0];
		Point minPoint2 = p[0];
		double distance;

		for (unsigned i = 0; i < numOfPoints; i++) {
			for (unsigned j = 0; j < numOfPoints; j++) {
				if (i != j) {

					distance = p[i].distance(p[j]);
					if (distance > maxDist) {
						maxPoint1 = p[i];
						maxPoint2 = p[j];
						maxDist = distance;
					}

					if (distance < minDist) {
						minPoint1 = p[i];
						minPoint2 = p[j];
						minDist = distance;
					}
				}
			}
		}

		//print results

		cout << "Minimum distance = " << minDist << " is between " << minPoint1 << " and " << minPoint2 << endl;
		cout << "Maximum distance = " << maxDist << " is between " << maxPoint1 << " and " << maxPoint2 << endl;

	}
	else { cout << "Must enter a file with more points" << endl; }
}
