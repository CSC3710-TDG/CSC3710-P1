/*
	CSC1720 Spring 2013 Lecture 19/Lab 6 Creating and Using Classes
	Author: Scott Russell
	Created: 2/8/13
	Records and Structures
*/

#include <iostream>
#include <sstream>	// for ostringstream
#include <string>
#include <cctype>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>


using namespace std;
void BubbleSort(int list1[], string list2[], int size);

void PrintHighScores ()
{
        cout << "\033[2J\033[1;1H";
 	cout<<"*******************************************************************"<<endl;
        cout<<"                            BATTLESHIP                             "<<endl;
        cout<<"*******************************************************************"<<endl;
        cout<< endl <<endl;
	cout << "HIGH SCORES LIST" << endl<< endl;

	ifstream inputFile;
	inputFile.open("highscores.txt");

	int arrayScores[100];
	string arrayNames[100];
	int x, y, size;

//read in the high scores
	bool endFile = false;
	x = 0;
inputFile >> arrayScores[x] >> arrayNames[x];

	do {
		if (inputFile.eof())
		{
			endFile = true;
		}
		else
		{
			x++;
			inputFile >> arrayScores[x] >> arrayNames[x];
		}

	} while (endFile == false);

	size = x + 1;

//sort the top 10 highest scores
	BubbleSort(arrayScores, arrayNames, size);

//print the high scores
	int z=0;
	for (y=0; y < (size-1); y++) {

		if (y>0 && arrayScores[y] == arrayScores[y-1])
		{
			cout << z << ") " << arrayScores[y] << " - " << arrayNames[y] << endl;
			z++;
		}
		else
		{
			z++;
			cout << z << ") " << arrayScores[y] << " - " << arrayNames[y] << endl;
		}
	}

	inputFile.close();

	//press "R" to return to game play
	string discardstr;
	cout << endl << "Press any key to return to the main menu: " ;
	cin >> discardstr;
}

void BubbleSort(int list1[], string list2[], int size)
{
	for(int x=0; x<size; x++)
	{
		for(int y=0; y<size-1; y++)
		{
			if(list1[y]<list1[y+1])
			{
				int temp = list1[y+1];
					string temp2 = list2[y+1];
				list1[y+1] = list1[y];
					list2[y+1] = list2[y];
				list1[y] = temp;
					list2[y] = temp2;
			}
		}
	}


}


void PrintHelpGuide ()
{
        cout << "\033[2J\033[1;1H";
 	cout<<"*******************************************************************"<<endl;
        cout<<"                            BATTLESHIP                             "<<endl;
        cout<<"*******************************************************************"<<endl;
        cout<< endl <<endl;
	cout << "HELP GUIDE" << endl;

	//press "R" to return to game play
        string discardstr;
        cout << endl << "Press any key to return to the main menu: " ;
        cin >> discardstr;
}


