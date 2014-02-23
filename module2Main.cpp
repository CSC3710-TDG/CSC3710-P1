/*
Triad Development Group
Battleship console game
Module 2 - Gameplay Module
*/

//PrintHighScores functionality:
//throughout the game, keep a running total of the shots taken by each player and the number of hits for each player
//in this way, we can calculate the hit percentage at the end of the game
//for the purposes of calculating the player's score, we will use the following procedure:
//-each time you get a hit, you get  10 points
//-each time you get hit, you lose 10 points
//-each time you sink a ship, you get points equal to the ship bonus (10x the length of the ship)
//-each time one of your ships is sunk, you lose points equal to the ship bonus
//-at the end of the game, your score is multiplied by 100% plus your hit percentage (eg. *175% for a hit percentage of 75%)
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

//Class Declarations
//class containing all ship member functions and properties for the operation of ship objects
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


//class containing all player member functions and properties for the operation of player objects

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

//if statement here for help guide

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
