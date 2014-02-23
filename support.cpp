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




//Create Gridchar [] [] 
void createGrid (char grid[10][10])
{
   
   for(int i=0; i<10; i++){
      for(int j=0; j<10; j++){
          grid[i][j]='.';
      }
   }

}

//Print Grid
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

