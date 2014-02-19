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

