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


// global constants

// function prototypes
void PrintHelpGuide ();
void PrintHighScores ();
void BubbleSort(int list1[], string list2[], int size);



int main() {

	char choice;

	cout << "main game play here" << endl;

do {
	cout << " Press \"h\" to view the Help Guide. \n Press \"c\" to view the High Scores list. \n Press \"q\" to quit and exit the game menu." << endl;
        cin >> choice;
// lowercase the choice value

	if (choice == 'h')
		PrintHelpGuide ();
	else if (choice == 'c')
		PrintHighScores ();
	else if (choice == 'q')
		cout << "game has been quitted" << endl;
	else
		cout << "ERROR. You entered an invalid character. Please try again." << endl;

} while (choice != 'q');

	return 0;
}


void PrintHighScores ()
{
	cout << "HIGH SCORES LIST" << endl;

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
//			x--;
			endFile = true;
		}
		else
		{
			x++;
			inputFile >> arrayScores[x] >> arrayNames[x];
		}

//		inputFile >> arrayScores[x] >> arrayNames[x];
//		x++;
	} while (endFile == false);

	size = x + 1;

	//*****need to sort arrayNames the same time as arrayScores (do that in bubbleSort)
//******need to consider when there are no high scores in the text file, when size is 0...***


//sort the top 10 highest scores
	BubbleSort(arrayScores, arrayNames, size);

//print the high scores
	for (y=0; y < (size-1); y++) {
		cout << arrayScores[y] << " - " << arrayNames[y] << endl;
	}

	inputFile.close();

	//press "R" to return to game play
	char discardchar;
	cout << "Press any key to return to the main menu: " ;
	cin >> discardchar;
}


void BubbleSort(int list1[], string list2[], int size)
{
/*
      int numb;
      bool swap;
      string str;

cout<<"in BubbleSort function"<<endl;

for(int x = 0; x < (size-1); x++)
{
	cout<<list1[x]<<" - "<<list2[x]<<endl;
}
*/

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
/*

      do
      {
            swap = false;
            for(int i = 0; i < (size-1); i++)
            {

		cout << "list1[i]: " << list1[i] << " - list1[i+1]: " << list1[i+1] <<endl;

                  if(list1[i] < list1[i+1])
                  {

                        numb = list1[i];
		            str = list2[i];
                        list1[i] = list1[i+1];
		            list2[i] = list2[i+1];
                        list1[i+1] = numb;
		            list2[i+1] = str;

                        swap = true;
                  }
            }
      }while(swap);
*/
/*
for(int x = 0; x < (size-1); x++)
{
        cout<<list1[x]<<" - "<<list2[x]<<endl;
}


cout<<"out of BubbleSort function"<<endl;
*/

}


void PrintHelpGuide ()
{
	cout << "HELP GUIDE" << endl;

	//press "R" to return to game play
        char discardchar;
        cout << "Press any key to return to the main menu: " ;
        cin >> discardchar;
}

