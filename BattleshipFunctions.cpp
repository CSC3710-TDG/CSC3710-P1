#include<iostream>
#include<ctime>
#include<climits>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include <sstream>	// for ostringstream
#include <cctype>
#include <iomanip>
#include <fstream>
#include <cstdlib>
//#include"module2Main.cpp"
using namespace std;
//Class Declarations
class ship{

public:
   void setHealth(int);
   int checkHealth();
   void setSunk(bool);
   bool checkSunk();
   void hit();

private:
   int health;
   int length;
   bool isSunk;

};
//class containing all ship member functions and properties for the operation of ship objects

class player{

public:
void setType(int);
int checkType();
void setHealth();
int checkHealth();
void decrementHealth();
char takeTurn(char [10][10], char [10][10]);
bool verifyShot(char [10][10], char, int);

private:
int type;//what kind of user? 0 for cpu. 1 for human.
int health;

};
//class containing all player member functions and properties for the operation of player objects



//Function Declarations
void Welcome();
void NewGame();
void LoadGame();
void InitializeGame();
void PrintHelpGuide();
void PrintHighScores();
void createGrid(char [10][10]);
void printGrid(char [10][10]);
void RandomPlacement(char [10][10]);
bool verifyPlacement(int, char, int, char, int, char [10][10]); //length and coordinates and grid
void PrintHighScores ();
void PrintHelpGuide ();
void BubbleSort(int list1[], string list2[], int size);
int playGame(char [10][10], char [10][10]);
//primary module 2 handler to define gameplay
//expects two grids, the usergrid and cpugrid
//returns nothing

//Welcome function when you first enter the game.
void Welcome()
{
   int choice; //=0;
do{
   cout << "\033[2J\033[1;1H";

   cout<<"*******************************************************************"<<endl;
   cout<<"                            BATTLESHIP                             "<<endl;
   cout<<"*******************************************************************"<<endl;
   cout<< endl <<endl;
   cout<<"Please select one of the following choices:(Enter the corresponding number)"<<endl;
   cout<<"1 - Start New Game"<<endl;
   cout<<"2 - Load a Saved Game"<<endl;
   cout<<"3 - View the Highscores List"<<endl;
   cout<<"4 - Access the Help Guide"<<endl;
   cout<<"5 - Quit"<<endl;
   cout<<endl;
   cout<<"Enter the number: ";
   
//   do {
      cin>>choice;
   
      if(choice==1){
         NewGame();
      }/*else if(choice==2){
         LoadGame();
      }*/else if(choice==3){
         PrintHighScores();
      }else if(choice==4){
         PrintHelpGuide();
      }else if(choice==5){
         cout << "\033[2J\033[1;1H";
         cout<<"*******************************************************************"<<endl;
         cout<<"                            BATTLESHIP                             "<<endl;
         cout<<"*******************************************************************"<<endl;
         cout<< endl <<endl;
         cout<<"Thanks for playing Battleship!"<<endl;
      }else{
         cout<<"You have invalid entry, Please try again."<<endl;
      }
   }while(choice != 5);

}


//Create Gridchar [] [] 
void createGrid (char grid[10][10])
{
   
   for(int i=0; i<10; i++){
      for(int j=0; j<10; j++){
          grid[i][j]='.';
      }
   }

}

void printGrid(char grid[10][10])
{
   cout<<"   A B C D E F G H I J"<<endl;
   int x=1;

    
   for(int i=0; i<10; i++){
      if(x<10){
         cout<<" ";
      }
      cout<<x;
      x++;
      for(int j=0; j<10; j++){
          cout<<" "<<grid[i][j];
      }
      cout<<endl;
   }
}

//New Game function
void NewGame ()
{
   char usergrid[10][10];
   char cpugrid[10][10];
   bool istrue;
   char x1, x2;
   int y1,y2;
   createGrid(usergrid);
   createGrid(cpugrid);
   printGrid(usergrid);
   cout<<"Now please select the coordinates for your ships: "<<endl;
//This first loop is for Aircraft Carrier (5 units)
   do{
      cout<<"Enter the start and ending coordinates for your Aircraft Carrier(5 units long)."<<endl;
      cout<<"Please enter in the format A1 A5 or A1 E1: ";
      cin>>x1>>y1>>x2>>y2;
      istrue=verifyPlacement(5, x1, y1, x2, y2, usergrid);
      if(istrue==false)
         cout<<"INVALID SHIP PLACEMENT, Please try again."<<endl;
     }while(istrue==false);
     if(x1==x2){
       for(int i=y1;i<=y2; i++)
          usergrid[i-1][x1-65]='C';
     }else{
         for(int i=x1;i<=x2; i++)
            usergrid[y1-1][i-65]='C';
      }
      printGrid(usergrid);  
//This is for the Battleship (4 units)
   do{
      cout<<"Enter the start and ending coordinates for your Battleship(4 units long)."<<endl;
      cout<<"Please enter in the format A1 A5 or A1 E1: ";
      cin>>x1>>y1>>x2>>y2;
      istrue=verifyPlacement(4, x1, y1, x2, y2, usergrid);
      if(istrue==false)
         cout<<"INVALID SHIP PLACEMENT, Please try again."<<endl;
     }while(istrue==false); 
     if(x1==x2){
       for(int i=y1;i<=y2; i++)
          usergrid[i-1][x1-65]='B';
     }else{
         for(int i=x1;i<=x2; i++)
            usergrid[y1-1][i-65]='B';
      }
      printGrid(usergrid);  
//This is for the Destroyer (3 units)
   do{
      cout<<"Enter the start and ending coordinates for your Destroyer(3 units long)."<<endl;
      cout<<"Please enter in the format A1 A5 or A1 E1: ";
      cin>>x1>>y1>>x2>>y2;
      istrue=verifyPlacement(3, x1, y1, x2, y2, usergrid);
      if(istrue==false)
         cout<<"INVALID SHIP PLACEMENT, Please try again."<<endl;
     }while(istrue==false); 
     if(x1==x2){
       for(int i=y1;i<=y2; i++)
          usergrid[i-1][x1-65]='D';
     }else{
         for(int i=x1;i<=x2; i++)
            usergrid[y1-1][i-65]='D';
      }
      printGrid(usergrid);  
//This is for the Submarine (3 unitS)
   do{
      cout<<"Enter the start and ending coordinates for your Submarine(3 units long)."<<endl;
      cout<<"Please enter in the format A1 A5 or A1 E1: ";
      cin>>x1>>y1>>x2>>y2;
      istrue=verifyPlacement(3, x1, y1, x2, y2, usergrid);
      if(istrue==false)
         cout<<"INVALID SHIP PLACEMENT, Please try again."<<endl;
     }while(istrue==false); 
     if(x1==x2){
       for(int i=y1;i<=y2; i++)
          usergrid[i-1][x1-65]='S';
     }else{
         for(int i=x1;i<=x2; i++)
            usergrid[y1-1][i-65]='S';
      }
      printGrid(usergrid);  
//This is for the Patrol Boat (2 units)
   do{
      cout<<"Enter the start and ending coordinates for your Patrol Boat(2 units long)."<<endl;
      cout<<"Please enter in the format A1 A5 or A1 E1: ";
      cin>>x1>>y1>>x2>>y2;
      istrue=verifyPlacement(2, x1, y1, x2, y2, usergrid);
      if(istrue==false)
         cout<<"INVALID SHIP PLACEMENT, Please try again."<<endl;
     }while(istrue==false); 
     if(x1==x2){
       for(int i=y1;i<=y2; i++)
          usergrid[i-1][x1-65]='P';
     }else{
         for(int i=x1;i<=x2; i++)
            usergrid[y1-1][i-65]='P';
      }
      printGrid(usergrid);  
      RandomPlacement(cpugrid);
      playGame(usergrid, cpugrid);


}
bool verifyPlacement (int length, char x1, int y1, char x2, int y2, char usergrid[10][10])
{
   if(x1!=x2 && y1!=y2){
      return false;
   }else if(x1==x2 && (y2-y1+1)!=length){
      return false;
   }else if(y1==y2 && (x2-x1+1)!=length){
      return false;
   }else if(x1==x2){
      for(int i=y1; i<=y2; i++){
         if(usergrid[i-1][x1-65]!='.'){
            return false;
         }
      }
    return true;
   }else if(y1==y2){
       for(int i=x1;i<=x2;i++){
          if(usergrid[y1-1][i-65]!='.'){
             return false;
          }
       }
    return true;
   }
   else
      return true;
}
 

void RandomPlacement(char cpugrid[10][10])
{  
   bool istrue;
   char x1, x2;
   int y1,y2;
   int direction;
   //direction = rand() % 2 + 5;//choose a direction either vertical or horizontal
   do{
      //srand (time(0));
      x1=rand() %6 + 65;
      y1=rand() %6;
      direction = rand() % 2 + 5;
      if(direction==5){
         y2=y1+4;
         x2=x1;
      }else if(direction==6){
         x2=x1+4;
         y2=y1;
      }
      istrue=verifyPlacement(5, x1, y1, x2, y2, cpugrid);
     }while(istrue==false); 
     if(x1==x2){
       for(int i=y1;i<=y2; i++)
          cpugrid[i-1][x1-65]='C';
     }else{
         for(int i=x1;i<=x2; i++)
            cpugrid[y1-1][i-65]='C';
      }
   do{
      //srand (time(0));
      x1=rand() %7 + 65;
      y1=rand() %7;
      direction = rand() % 2 + 5;
      //direction==5?direction++:direction--;
      if(direction==5){
         y2=y1+3;
         x2=x1;
      }else if(direction==6){
         x2=x1+3;
         y2=y1;
      }
      istrue=verifyPlacement(4, x1, y1, x2, y2, cpugrid);
     }while(istrue==false); 
     if(x1==x2){
       for(int i=y1;i<=y2; i++)
          cpugrid[i-1][x1-65]='B';
     }else{
         for(int i=x1;i<=x2; i++)
            cpugrid[y1-1][i-65]='B';
      }
   do{
      //srand (time(0));
      x1=rand() %8 + 65;
      y1=rand() %8;
      direction = rand() % 2 + 5;
      //direction==5?direction++:direction--;
      if(direction==5){
         y2=y1+2;
         x2=x1;
      }else if(direction==6){
         x2=x1+2;
         y2=y1;
      }
      istrue=verifyPlacement(3, x1, y1, x2, y2, cpugrid);
     }while(istrue==false); 
     if(x1==x2){
       for(int i=y1;i<=y2; i++)
          cpugrid[i-1][x1-65]='D';
     }else{
         for(int i=x1;i<=x2; i++)
            cpugrid[y1-1][i-65]='D';
      }
   do{
      //srand (time(0));
      x1=rand() %8 + 65;
      y1=rand() %8;
      direction = rand() % 2 + 5;
      //direction==5?direction++:direction--;
      if(direction==5){
         y2=y1+2;
         x2=x1;
      }else if(direction==6){
         x2=x1+2;
         y2=y1;
      }
      istrue=verifyPlacement(3, x1, y1, x2, y2, cpugrid);
     }while(istrue==false); 
     if(x1==x2){
       for(int i=y1;i<=y2; i++)
          cpugrid[i-1][x1-65]='S';
     }else{
         for(int i=x1;i<=x2; i++)
            cpugrid[y1-1][i-65]='S';
      }
   do{
      //srand (time(0));
      x1=rand() %9 + 65;
      y1=rand() %9;
      direction = rand() % 2 + 5;
      //direction==5?direction++:direction--;
      if(direction==5){
         y2=y1+1;
         x2=x1;
      }else if(direction==6){
         x2=x1+1;
         y2=y1;
      }
      istrue=verifyPlacement(2, x1, y1, x2, y2, cpugrid);
     }while(istrue==false); 
     if(x1==x2){
       for(int i=y1;i<=y2; i++)
          cpugrid[i-1][x1-65]='P';
     }else{
         for(int i=x1;i<=x2; i++)
            cpugrid[y1-1][i-65]='P';
      }


}
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
	char discardchar;
	cout << endl << "Press any key to return to the main menu: " ;
	cin >> discardchar;
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
        char discardchar;
        cout << endl << "Press any key to return to the main menu: " ;
        cin >> discardchar;
}
// **************************************************************THIS IS MODULE TWO******************************************************************************************************


/*
void shipInit(ship, ship, ship, ship, ship, ship, ship, ship, ship, ship);
//function to quickly initialize all ships on the board
//expects 10 ship: 5 from user and 5 for cpu
//returns nothing
*/

int playGame(char usergrid[10][10], char cpugrid[10][10]){

player user, cpu;
ship userCar, cpuCar, userBat, cpuBat, userDes, cpuDes, userSub, cpuSub, userPat, cpuPat;	
char selected;
char selected2;
char discardchar;
char userview[10][10];
createGrid(userview);
printGrid(userview);

//cout << "I got here!" << endl;

user.setType(1);
cpu.setType(0);

//cout << "I got here2!" << endl;

userCar.setHealth(5);
cpuCar.setHealth(5);
userBat.setHealth(4);
cpuBat.setHealth(4);
userDes.setHealth(3);
cpuDes.setHealth(3);
userSub.setHealth(3);
cpuSub.setHealth(3);
userPat.setHealth(2);
cpuPat.setHealth(2);
user.setHealth();
cpu.setHealth();

//cout << "I got here3!" << endl;

while(user.checkHealth() > 0 && cpu.checkHealth() > 0){

//cout << "I got in the loop!" << endl;

selected = user.takeTurn(cpugrid, userview);

//cout << "User took a turn!" << endl;

switch(selected){
case '.':
cout << "MISS!" << endl;
break;
case 'C':
cout << "HIT!" << endl;
cpuCar.hit();
cpu.decrementHealth();
if(cpuCar.checkHealth()==0){
cout << "You have sunk the opponent's Aircraft Carrier!" << endl;
cpuCar.setSunk(true);
}
break;
case 'B':
cout << "HIT!" << endl;
cpuBat.hit();
cpu.decrementHealth();
if(cpuBat.checkHealth()==0){
cout << "You have sunk the opponent's Battleship!" << endl;
cpuBat.setSunk(true);
}
break;
case 'D':
cout << "HIT!" << endl;
cpuDes.hit();
cpu.decrementHealth();
if(cpuDes.checkHealth()==0){
cout << "You have sunk the opponent's Destroyer!" << endl;
cpuDes.setSunk(true);
}
break;
case 'S':
cout << "HIT!" << endl;
cpuSub.hit();
cpu.decrementHealth();
if(cpuSub.checkHealth()==0){
cout << "You have sunk the opponent's Submarine!" << endl;
cpuSub.setSunk(true);
}
break;
case 'P':
cout << "HIT!" << endl;
cpuPat.hit();
cpu.decrementHealth();
if(cpuPat.checkHealth()==0){
cout << "You have sunk the opponent's Patrol Boat!" << endl;
cpuPat.setSunk(true);
}
break;
default:
cout << "OH NO SOMETHING WENT TERRIBLY WRONG!" << endl;
break;
}
printGrid(userview);
if(cpu.checkHealth()==0){
cout << "Congratulations! You have won the game!" << endl;
cout << "Press any key to continue!" << endl;
cin >> discardchar;
return 1;
}

//cout << "Finished user's turn!" << endl;

selected2 = cpu.takeTurn(usergrid, userview);
switch(selected2){
case '.':
cout << "MISS!" << endl;
break;
case 'C':
cout << "HIT!" << endl;
userCar.hit();
user.decrementHealth();
if(userCar.checkHealth()==0){
cout << "Your opponent has sunk your Aircraft Carrier!" << endl;
userCar.setSunk(true);
}
break;
case 'B':
cout << "HIT!" << endl;
userBat.hit();
user.decrementHealth();
if(userBat.checkHealth()==0){
cout << "Your opponent has sunk your Battleship!" << endl;
userBat.setSunk(true);
}
break;
case 'D':
cout << "HIT!" << endl;
userDes.hit();
user.decrementHealth();
if(userDes.checkHealth()==0){
cout << "Your opponent has sunk your Destroyer!" << endl;
userDes.setSunk(true);
}
break;
case 'S':
cout << "HIT!" << endl;
userSub.hit();
user.decrementHealth();
if(userSub.checkHealth()==0){
cout << "Your opponent has sunk your Submarine!" << endl;
userSub.setSunk(true);
}
break;
case 'P':
cout << "HIT!" << endl;
userPat.hit();
user.decrementHealth();
if(userPat.checkHealth()==0){
cout << "Your opponent has sunk your Patrol Boat!" << endl;
userPat.setSunk(true);
}
break;
default:
cout << "OH NO SOMETHING WENT TERRIBLY WRONG!" << endl;
break;
}
printGrid(usergrid);
if(user.checkHealth()==0){
cout << "Oh no! You have lost the game!" << endl;
cout << "Press any key to continue!" << endl;
cin >> discardchar;
return 0;
}

//cout << "Finished CPU's turn!" << endl;

//cout << "\033[2J\033[1;1H";//clear screen for beginning of turn

}
return 0;
}

void ship::setHealth(int input){
health=input;
}

int ship::checkHealth(){
return health;
}

void ship::setSunk(bool input){
isSunk=input;
}

bool ship::checkSunk(){
return isSunk;
}

void ship::hit(){
health--;
}

void player::setType(int input){
type=input;
}

int player::checkType(){
return type;
}

void player::setHealth(){
health=17;
}

int player::checkHealth(){
return health;
}

void player::decrementHealth(){
health--;
}

char player::takeTurn(char grid[10][10], char view[10][10]){
char x;
int y;
char selected;

/*if(type==0){
selected = usergrid[x][y];
}
else{
selected = cpugrid[x][y];
}*/

if(type==1){
	cout << "Please choose a position to fire at (in the form A1): ";
	cin >> x >> y;
	while(verifyShot(view, x, y)==false){
	cout << "INVALID POSITION!" << endl << "Please choose a position to fire at (in the form A1): ";
	cin >> x >> y;
	}
        cout << "\033[2J\033[1;1H";
	cout<<"*******************************************************************"<<endl;
	cout<<"                            BATTLESHIP                             "<<endl;
	cout<<"*******************************************************************"<<endl;
  	cout<< endl <<endl;
	cout << "You fired at " << x << y << "... ";
}
else{
	do{
	x=rand() %10 + 65;
        y=rand() %10;
	}while(verifyShot(grid, x, y)==false);
	cout << "-------------------------------------------------------------------" << endl;
	cout << "The computer fired at " << x << y << "... ";
}

selected = grid[y-1][x-65]; //As opposed to above commented out logic, because now takeTurn is passed the corresponding grid

//cout << "I found the position!" << selected << endl;

if(type==0){
selected=='.'?grid[y-1][x-65]=77:grid[y-1][x-65]=88;
}
else{
selected=='.'?view[y-1][x-65]=77:view[y-1][x-65]=88;
}
return selected;	
}

bool player::verifyShot(char grid[10][10], char x, int y){
if(!(x>=65 && x<=74)){
return false;
}
else if(!(y>=1 && y<=10)){
return false;
}
else if(grid[y-1][x-65]=='X'){
return false;
}
else if(grid[y-1][x-65]=='M'){
return false;
}
else
return true;
}

