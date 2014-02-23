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

using namespace std;

//Function Declarations
void Welcome();
void NewGame();
void LoadGame();
void InitializeGame();
void PrintHelpGuide();
void PrintHighScores();
void RandomPlacement(char [10][10]);
bool verifyPlacement(int, char, int, char, int, char [10][10]); //length and coordinates and grid
void BubbleSort(int list1[], string list2[], int size);
int playGame(string name, char [10][10], char [10][10]);
//primary module 2 handler to define gameplay
//expects two grids, the usergrid and cpugrid
//returns nothing
//Struct Declaration:
struct Placement{
  int lengtharray [5] = {5,4,3,3,2};
  char shiparray [5] ={'C', 'B', 'D', 'S', 'P'};
  string shipnamearray [5] = {"Aircraft Carrier", "Battleship", "Destroyer", "Submarine", "Patrol Boat"}; 
  int directionnumberarray [5] = {6,7,8,8,9};
};

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
      }else if(choice==2){
         LoadGame();
      }else if(choice==3){
         PrintHighScores();
      }else if(choice==4){
         PrintHelpGuide();
      }else if(choice==5){
         quitGame();
      }else{
         cout<<"You have invalid entry, Please try again."<<endl;
      }
   }while(choice != 5);

}


//New Game function
void NewGame ()
{  
   string name;
   char usergrid[10][10];
   char cpugrid[10][10];
   bool istrue;
   char x1, x2;
   int y1,y2;
   createGrid(usergrid);
   createGrid(cpugrid);
   cout<<"Please enter your first name: ";
   cin>>name;
   printGrid(usergrid);
   cout<<name<<", now please select the coordinates for your ships: "<<endl;
 
   Placement item;
   for(int z=0;z<5;z++){
   do{
      cout<<"Enter the start and ending coordinates for your ";
      cout<< item.shipnamearray[z];
      cout<<" ("<<item.lengtharray[z]<< " units long)."<<endl;
      cout<<"Please enter in the format A1 A5 or A1 E1: ";
      cin>>x1>>y1>>x2>>y2;
      x1=toupper(x1);
      x2=toupper(x2);
      istrue=verifyPlacement(item.lengtharray[z], x1, y1, x2, y2, usergrid);
      if(istrue==false)
         cout<<"INVALID SHIP PLACEMENT, Please try again."<<endl;
     }while(istrue==false);
     if(x1==x2){
       for(int i=y1;i<=y2; i++)
          usergrid[i-1][x1-65]=item.shiparray[z];
     }else{
         for(int i=x1;i<=x2; i++)
            usergrid[y1-1][i-65]=item.shiparray[z];
      }
      printGrid(usergrid);  
      }
      RandomPlacement(cpugrid);
      playGame(name, usergrid, cpugrid);
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
   Placement item;
   //direction = rand() % 2 + 5;//choose a direction either vertical or horizontal
  for(int z=0;z<5;z++){
  do{
      //srand (time(0));
      x1=rand() %item.directionnumberarray[z] + 65;
      y1=rand() %item.directionnumberarray[z];
      direction = rand() % 2 + 5;
      if(direction==5){
         y2=y1+(item.lengtharray[z]-1);
         x2=x1;
      }else if(direction==6){
         x2=x1+(item.lengtharray[z]-1);
         y2=y1;
      }
      istrue=verifyPlacement(item.lengtharray[z], x1, y1, x2, y2, cpugrid);
     }while(istrue==false); 
     if(x1==x2){
       for(int i=y1;i<=y2; i++)
          cpugrid[i-1][x1-65]=item.shiparray[z];
     }else{
         for(int i=x1;i<=x2; i++)
            cpugrid[y1-1][i-65]=item.shiparray[z];
      }
   }
}

void LoadGame()
{
   string name;
   char usergrid[10][10];
   char cpugrid[10][10];
   
   ifstream load;
   load.open("saved.txt");
   load>>name;   
   for(int i=0; i<10; i++){
      for(int j=0; j<10; j++){
          load>>usergrid[i][j];
      }
   }
   for(int i=0; i<10; i++){
      for(int j=0; j<10; j++){
          load>>cpugrid[i][j];
      }
   }


   playGame(name,usergrid,cpugrid);
   
}
