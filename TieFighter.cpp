/**************************************************************************** 
* File description 
****************************************************************************/ 
/*\brief This file contains the description of the TieFighter class. 
* 
* \class TieFighter
*This class creates ship from the type of war ships that belongs to Empire side.
*This ship class inherit from the WarShip class.
*This type of ships can attack other ships by reducing it HitPoints or shields in 40 points.
*
* \author Author1's ID: 300534781
* \author Author2's ID: 317035038.
*/
/**************************************************************************** 
* Include library files 
****************************************************************************/ 
#include <iostream>
#include <cstdlib>
#include <cstring>
/**************************************************************************** 
* Include header files 
****************************************************************************/
#include "TieFighter.h"
using namespace std;
//! TieFighter constructor.
/*!
*Builds TieFighter with the next parameters :
*	Shields=110	
*	HitPoints=110
*	Weapon=40
*	Name=Tie Fighter
*/
TieFighter::TieFighter():WarShip(110,110,110,110,40,War_Ship){
		this->Name="Tie Fighter";
	}
//! TieFighter destructor.
/*!
*Destroy TieFighter.
*/
TieFighter::~TieFighter(){}

/***********************************************
* functions implementations
***********************************************/

//function
/****************************************************************************/
//! Displays the TieFighter ship Shields level and Hit Points
/*!\brief Displays the ships Shields level and Hit Points
*/
void TieFighter::printData(){
	cout<<" Shields:"<<this->getShields()<<"/110"<<", Hit Points:"<<this->hitPoints<<"/110";
}
//function
/****************************************************************************/
//! Displays the whole status of the ship: Type, Name, Shields level and Hit Points
/*!\brief Displays the whole status of the ship: Type, Name, Shields level and Hit Points
*/
void TieFighter::printStatus(){
	if(!this->isShipDead()){
		if(this->getType()==War_Ship)
			cout<<"War Ship: ";
		else if(this->getType()==Repair_Ship)
			cout<<"Repair Ship: ";
		this->printName();
	cout<<", Shields:"<<this->getShields()<<"/110"<<", Hit Points:"<<this->hitPoints<<"/110"<<endl;
	}//if
}
//function
/****************************************************************************/
//! Perform action on a specified ship.
/*!\brief Perform a attack action on a specified ship. 
*@param SpaceShip &target - the ship that will be attacked
*/
void TieFighter:: performAction(SpaceShip &target){
	if(!target.isShipDead()){
		if (target.getShields()>0)
			target.reduceShields(40);
		else if (target.getHitPoints()>0){
			target.reduceHitPoints(40);
		//	if(target.isShipDead())
		//		target.~SpaceShip();
		}//else if
	}
}

//function
/****************************************************************************/
//! Prints the ships name
/*!\brief Prints the ships name 
*/  
void TieFighter:: printName(){
	cout<<this->Name;
}
