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
//-each time you sink a ship, you get points equal to the ship bonus (10x the length of the ship)
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
#include <cstring>


using namespace std;


void saveGame(string, char[10][10], char[10][10]);

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
char takeTurn(string, char [10][10], char [10][10], char [10][10], char [10][10]);
bool verifyShot(string, char [10][10], char [10][10], char [10][10], char, int);
void addScore(int);
int checkScore();
void incrementShots();
void incrementHits();
void calcPercent();
void genScore();
void setName();

private:
int type;//what kind of user? 0 for cpu. 1 for human.
int health;
int score;
int shots;
int hits;
double hitPercent;
string name;

};

// **************************************************************THIS IS MODULE TWO******************************************************************************************************


/*
void shipInit(ship, ship, ship, ship, ship, ship, ship, ship, ship, ship);
//function to quickly initialize all ships on the board
//expects 10 ship: 5 from user and 5 for cpu
//returns nothing
*/

int playGame(string name, char usergrid[10][10], char cpugrid[10][10]){

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
user.addScore(100);
cpu.addScore(100);

//cout << "I got here3!" << endl;

while(user.checkHealth() > 0 && cpu.checkHealth() > 0){

//cout << "I got in the loop!" << endl;

selected = user.takeTurn(name, usergrid, cpugrid, cpugrid, userview);

//cout << "User took a turn!" << endl;

switch(selected){
case '.':
cout << "MISS!" << endl;
break;
case 'C':
cout << "HIT!" << endl;
user.incrementHits();
cpuCar.hit();
cpu.decrementHealth();
user.addScore(10);
if(cpuCar.checkHealth()==0){
cout << "You have sunk the opponent's Aircraft Carrier!" << endl;
cpuCar.setSunk(true);
user.addScore(50);
}
break;
case 'B':
cout << "HIT!" << endl;
user.incrementHits();
cpuBat.hit();
cpu.decrementHealth();
user.addScore(10);
if(cpuBat.checkHealth()==0){
cout << "You have sunk the opponent's Battleship!" << endl;
cpuBat.setSunk(true);
user.addScore(40);
}
break;
case 'D':
cout << "HIT!" << endl;
user.incrementHits();
cpuDes.hit();
cpu.decrementHealth();
user.addScore(10);
if(cpuDes.checkHealth()==0){
cout << "You have sunk the opponent's Destroyer!" << endl;
cpuDes.setSunk(true);
user.addScore(30);
}
break;
case 'S':
cout << "HIT!" << endl;
user.incrementHits();
cpuSub.hit();
cpu.decrementHealth();
user.addScore(10);
if(cpuSub.checkHealth()==0){
cout << "You have sunk the opponent's Submarine!" << endl;
cpuSub.setSunk(true);
user.addScore(30);
}
break;
case 'P':
cout << "HIT!" << endl;
user.incrementHits();
cpuPat.hit();
cpu.decrementHealth();
user.addScore(10);
if(cpuPat.checkHealth()==0){
cout << "You have sunk the opponent's Patrol Boat!" << endl;
cpuPat.setSunk(true);
user.addScore(20);
}
break;
default:
cout << "OH NO SOMETHING WENT TERRIBLY WRONG!" << endl;
break;
}
printGrid(userview);
if(cpu.checkHealth()==0){
cout << "Congratulations! You have won the game!" << endl;

user.genScore();
ofstream highscores;
highscores.open("highscores.txt", ios::app);
highscores << user.checkScore() << " " << name << endl;
highscores.close();

cout << "Press any key to continue!" << endl;
cin >> discardchar;
return 1;
}

//cout << "Finished user's turn!" << endl;

selected2 = cpu.takeTurn(name, usergrid, cpugrid, usergrid, userview);
switch(selected2){
case '.':
cout << "MISS!" << endl;
break;
case 'C':
cout << "HIT!" << endl;
cpu.incrementHits();
userCar.hit();
user.decrementHealth();
cpu.addScore(10);
if(userCar.checkHealth()==0){
cout << "Your opponent has sunk your Aircraft Carrier!" << endl;
userCar.setSunk(true);
cpu.addScore(50);
}
break;
case 'B':
cout << "HIT!" << endl;
cpu.incrementHits();
userBat.hit();
user.decrementHealth();
cpu.addScore(10);
if(userBat.checkHealth()==0){
cout << "Your opponent has sunk your Battleship!" << endl;
userBat.setSunk(true);
cpu.addScore(40);
}
break;
case 'D':
cout << "HIT!" << endl;
cpu.incrementHits();
userDes.hit();
user.decrementHealth();
cpu.addScore(10);
if(userDes.checkHealth()==0){
cout << "Your opponent has sunk your Destroyer!" << endl;
userDes.setSunk(true);
cpu.addScore(30);
}
break;
case 'S':
cout << "HIT!" << endl;
cpu.incrementHits();
userSub.hit();
user.decrementHealth();
cpu.addScore(10);
if(userSub.checkHealth()==0){
cout << "Your opponent has sunk your Submarine!" << endl;
userSub.setSunk(true);
cpu.addScore(30);
}
break;
case 'P':
cout << "HIT!" << endl;
cpu.incrementHits();
userPat.hit();
user.decrementHealth();
cpu.addScore(10);
if(userPat.checkHealth()==0){
cout << "Your opponent has sunk your Patrol Boat!" << endl;
userPat.setSunk(true);
cpu.addScore(20);
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

void player::addScore(int input){
score+=input;
}

int player::checkScore(){
return score;
}

void player::incrementShots(){
shots++;
}

void player::incrementHits(){
hits++;
calcPercent();
}

void player::calcPercent(){
hitPercent=hits/shots;
}

void player::genScore(){
score=score*(1+hitPercent);
}

char player::takeTurn(string name, char usergrid[10][10], char cpugrid[10][10], char grid[10][10], char view[10][10]){
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

	while(verifyShot(name, usergrid, cpugrid, view, x, y)==false){
	cout << "INVALID POSITION!" << endl << "Please choose a position to fire at (in the form A1): ";
	cin >> x >> y;
	}

        cout << "\033[2J\033[1;1H";
	cout<<"*******************************************************************"<<endl;
	cout<<"                            BATTLESHIP                             "<<endl;
	cout<<"*******************************************************************"<<endl;
  	cout<< endl <<endl;
	cout << "You fired at " << x << y << "... ";
	incrementShots();

}
else{
	do{
	x=rand() %10 + 65;
        y=rand() %10;
	}while(verifyShot(name, usergrid, cpugrid, grid, x, y)==false);
	cout << "-------------------------------------------------------------------" << endl;
	cout << "The computer fired at " << x << y << "... ";
	incrementShots();
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

bool player::verifyShot(string name, char usergrid[10][10], char cpugrid[10][10], char grid[10][10], char x, int y){
x=toupper(x);
if(x=='?'){
PrintHelpGuide();
}
else if(x=='S'){
saveGame(name, usergrid, cpugrid);
}
else if(x=='Q'){
	char response;
	cout << "Would you like to save the game first (Y/N)? ";
	cin >> response;
	while(response != 'Y' && response != 'N'){
		cout << "Please enter Y or N!" << endl;
		cout << "Would you like to save the game first (Y/N)? ";
		cin >> response;
	}
	if(response=='Y'){
		saveGame(name, usergrid, cpugrid);
	}
	else{
		quitGame();
	}
}
else if(!(x>=65 && x<=74)){
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

void saveGame(string name, char usergrid[10][10], char cpugrid[10][10]){
	ofstream saved;
	saved.open("saved.txt", ios::trunc);
	saved << name << endl;
    
   for(int i=0; i<10; i++){
      for(int j=0; j<10; j++){
          saved << usergrid[i][j] << " ";
      }
      saved<<endl;
   }
	cout << endl;
	for(int i=0; i<10; i++){
      for(int j=0; j<10; j++){
          saved << cpugrid[i][j] << " ";
      }
      saved<<endl;
   }
	saved.close();
}
