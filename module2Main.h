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
#include <iostream>

using namespace std;

class ship{

public:
void setHealth(int);
void setSunk(bool);

private:
int health;
int length;
bool isSunk;

};

class player{

public:
void setHealth();
void setDead();

private:
int health;
bool isDead;

};

void playGame(char[10][10], char[10][10]);
//primary module 2 handler to define gameplay
//expects two grids, the usergrid and cpugrid
//returns nothing

/*
void shipInit(ship, ship, ship, ship, ship, ship, ship, ship, ship, ship);
//function to quickly initialize all ships on the board
//expects 10 ship: 5 from user and 5 for cpu
//returns nothing
*/

void playGame(char usergrid[10][10], char cpugrid[10][10]){

	ship userCar, cpuCar, userBat, cpuBat, userDes, cpuDes, userSub, cpuSub, userPat, cpuPat;
	player user, cpu;
	userCar.setHealth(5);
	cpuCar.setHealth(5);
	userBat.setHealth(4);
	cpuBat.setHealth(4);
	userDes.setHealth(3);
	cpuDes.setHealth(3);
	userSub.setHealth(3);
	cpuSub.setHealth(3);
	userPat.setHealth(3);
	cpuPat.setHealth(3);
	user.setHealth();
	cpu.setHealth();

	while(
}
