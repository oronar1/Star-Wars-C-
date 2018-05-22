/**************************************************************************** 
* File description 
****************************************************************************/ 
/*! \file StarWars.h
*\brief This file contains the description of the StarWars class. 
* 
* \class StarWars
*This class creates a battle field of star wars
* \author Author1's ID: 300534781
* \author Author2's ID: 317035038.
*/
/**************************************************************************** 
* Include library files 
****************************************************************************/ 
#include <list>
#include <iostream>
/**************************************************************************** 
* Include header files 
****************************************************************************/
#include "SpaceShip.h"
using namespace std;
#ifndef STARWARS_H_
#define STARWARS_H_
//! An enum Status.
/*! Holds 4 possible game statuses.
*	Status(0)=Game_In_Progress.
*	Status(1)=Rebels_Won.
*	Status(2)=Empire_Won.
*	Status(3)=Draw
*/
enum Status{
		Game_In_Progress,
		Rebels_Won,
		Empire_Won,
		Draw
};
/*! \class StarWars 
* 
*This class creates StarWars battle field.
*/
class StarWars { 
public: 
///Constructor
  StarWars(); 
  ///Constructor
  StarWars(int r_Warships,int r_RepairShips,int i_Warships,int i_RepairShips);
  ///Destructor
  ~StarWars(); 
/**************************************************************************** 
* Function prototypes 
****************************************************************************/ 

  ///Play one round of the Star Wars simulation game 
  void playRound(); 
  ///loot randomly space ship
  int random(list<SpaceShip *> objectsList);//randomize between ships
  ///loot randomly side to play
  int randomSide();//chose the side to attack first
  ///Display the two fleets ships, with all their details 
  void printFleets(); 
  ///Display status of game
  void printStatus();
  ///Set nmber of the round to play
  int setRound(int round);
  ///Get the round of game
   int getRound();
   ///Get status of game
   Status getStatus();
   ///Set status of game
   Status setStatus(Status status);
   ///Dsiplay secondary menu of the game
   void secondaryMenu();
private: 
  Status gameStatus; //status of game
  int round; //round
  list<SpaceShip *> RebelFleet; //list of rebel ships
  list<SpaceShip *> ImperialFleet; //list of empire ships
}; 
#endif 
