
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

//#include "TestPointGenerator.h"
#include "Point.h"

using namespace std;

//Define a maximum number of points
const int MAX_NUM_POINTS = 1000;

int main() {
	//This is the pathname from the given code. Using this as a "root" for the rest of the program
	string pathName = ""; //leave empty if using local VS 2013/15 version
	//pathname = "H:\\visual studio 2013\\projects\\...\\";   //if using Citrix App Server

	/*
	Commenting out the test file generating code.
	I ran it once, and am using the files that are in tf to test it.
	*/
	/*
	//Create the random test file generator
	TestPointGenerator generator(7, 17, 0.0, 100.0); //See TestPointGenerator.h for details

	//Generate a bunch of test files into the local folder titled "tf"
	//You need to create a folder in your local version called "tf" to generate more test files
	int f;
	stringstream testFileName;
	for (f = 0; f < 100; f++) {
		testFileName.str(""); //Clears the string buffer
		testFileName << pathName << "extras\\file" << f << ".txt";
		generator.generateTestData(testFileName.str());
	}

	char g;
	//Pauses it so that I can look at the results
	cout << "Close by entering any character: ";
	cin >> g;
	return 0; //Done generating files, exit the program early
	*/

	//This is the actual program now

	//Allow the program to run multiple times by recreating all the objects.
	//Make a do-while loop. Only exit when the user enters the 'q' character at the end.
	bool running = true;
	do {

		Point p[MAX_NUM_POINTS]; //Initialize array to store points into


		// Copied directly from the provided project PDF
		string fileName; // name of file
		ifstream infile; // Input file stream; used to read file named fileName

		//get file name from user. The file will likely be in the "tf" folder
		cout << "NOTE: Used test files located in the \"tf\" directory for local testing\n";
		cout << "\n"; //Spacing
		cout << "Enter file name: ";
		cin >> fileName;

		//try to open file
		infile.open(pathName + fileName);
		if (infile.fail()) {
			cout << "Cannot open file " << fileName << ". Try again." << endl;
		}
		else {
			//infile is connect to fileName so start reading points into an array for representing the set
			cout << "Reading in numbers." << endl;
			unsigned numOfPoints = 0;
			while (infile >> ws && !infile.eof() && numOfPoints < MAX_NUM_POINTS) {
				infile >> p[numOfPoints];
				// uses overloaded >> operator for reading points
				cout << "Reading in point: " << p[numOfPoints] << endl;
				numOfPoints++;
			}
			//done reading so close file
			infile.close();

			//Report the number of points read
			cout << "Read " << numOfPoints << " points from " << fileName << endl;

			//Bounds checking
			if (numOfPoints > 1) { //Need at least 2 points to run the algorithm

				//Time to find the farthest and closest points now
				Point closest1 = p[0];
				Point closest2 = p[0];
				double closestDistance = 9999; //Large initial value
				Point farthest1 = p[0];
				Point farthest2 = p[0];
				double farthestDistance = 0; //Small initial value

				unsigned int i, j;
				/*
					Using a regular int throws the compiler warning C4018 because
					int can be a negative number, while the unsigned numOfPoints
					can't. Because signed and unsigned numbers are handled differently,
					the signed number is converted to unsigned, which could make
					it different if the signed number was negative.

					http://stackoverflow.com/questions/7443222/how-do-i-deal-with-signed-unsigned-mismatch-warnings-c4018
				*/
				double dis;
				for (i = 0; i < numOfPoints; i++) {
					for (j = 0; j < numOfPoints; j++) {
						if (i != j) { //Can't have them be equal because then the distance between them would be 0
							dis = p[i].distance(p[j]);
							if (dis < closestDistance) {
								closest1 = p[i];
								closest2 = p[j];
								closestDistance = dis;
							}
							if (dis > farthestDistance) {
								farthest1 = p[i];
								farthest2 = p[j];
								farthestDistance = dis;
							}
						}
					}
				}
				//Report the results
				cout << "Minimum distance = " << closestDistance << " is between " << closest1 << " and " << closest2 << endl;
				cout << "Maximum distance = " << farthestDistance << " is between " << farthest1 << " and " << farthest2 << endl;
				cout << "\n"; //Spacing
			}
			else {
				cout << "Not enough points to find the closest and farthest points.\n";
				cout << "Aborting...";
				return 1;
			}
		}
		char inputChar;
		do {
			cout << "Enter \'q\' to exit the program, or \'r\' to reset: ";
			cin >> inputChar;
			cout << "\n";
			//Skip over all other characters in case the user puts in a bunch of them
			cin.ignore(9999, '\n');
		} while (!(inputChar == 'q' || inputChar == 'r'));

		if (inputChar == 'q') {
			running = false;
		}
	} while (running);
	return 0;
}