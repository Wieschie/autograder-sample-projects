#include <iostream>
#include <fstream> 
#include <string>  
#include "Point.h" 
using namespace std;

int main()
{
	//int numOfPoints = 0;
	Point ptmax1;
	Point ptmax2;
	Point ptmin2;
	Point ptmin1;
	double dummy;
	double distmin = 10000000000000000000000000000000000000000000000000000000000000.0;
	double distmax = .00000000000000000000000000000000000000000000000000000000000001;
	const int MAX_NUM_POINTS = 1000;
	Point p[MAX_NUM_POINTS];
	string fileName;
	ifstream infile;


	cout << "Enter file name: ";
	cin >> fileName;

	string pathName;// = "c:\\users\\e0616675\\documents\\visual studio 2013\\Projects\\pointproject\\pointproject\\";
	pathName = "H:\\visual studio 2013\\projects\\P1255Hoffman2\\P1255Hoffman2\\"; //if using Citrix App Server 

	//C:\Users\e0616675\documents\visual studio 2013\Projects\pointproject\pointproject\Text1.txt

	infile.open(pathName + fileName);
	if (infile.fail())
	{
		cout << "Cannot open file " << fileName << " Aborting." << endl;
		return 1;
	}

	cout << "Reading in numbers." << endl;
	int numOfPoints = 0;

	while (infile >> ws && !infile.eof() && numOfPoints < MAX_NUM_POINTS)
	{
		infile >> p[numOfPoints];

		numOfPoints++;
	}

	infile.close();

	cout << "The number of points is " << numOfPoints << endl;
	for (int x = 0; x < numOfPoints; x++)
	{
		cout << p[x] << endl;
	}
	for (int i = 0; i < numOfPoints; i++)
	{
		for (int g = 0; g < numOfPoints; g++)
		{
			if (p[i] != p[g])
			{
				dummy = p[i].distance(p[g]);
				if (dummy < distmin)
				{
					distmin = dummy;
					ptmin1 = p[i];
					ptmin2 = p[g];
				}
				else if (dummy > distmax)
				{
					distmax = dummy;
					ptmax1 = p[i];
					ptmax2 = p[g];
				}

			}
		}
	}
	//Minimum distance  =  # is between (#,#) and (#,#) 
	cout << "The number of points is " << numOfPoints << endl;
	cout << "Minimum distance = " << distmin << " is between " << ptmin1 << " and " << ptmin2 << endl;
	cout << "Maximum distance = " << distmax << " is between " << ptmax1 << " and " << ptmax2 << endl;
}