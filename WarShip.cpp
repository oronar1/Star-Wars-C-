/**************************************************************************** 
* File description 
****************************************************************************/ 
/** 
*\brief This file contains the implementation of the WarShip class. 
* 
* \class WarShip
*This class creates ship from the type of Repair Ship.
*This ship class inherit from the SpaceShip class.
*This type of ships can repair other ships by increasing it HitPoints.
*
* \author Author1's ID: 300534781
* \author Author2's ID: 317035038.
*/
/**************************************************************************** 
* Include library files 
****************************************************************************/ 
#include <iostream>
/**************************************************************************** 
* Include header files 
****************************************************************************/
#include "WarShip.h"
using namespace std;
//! WarShip constructor.
/*!
*Builds WarShip with the next parameters :
*	@param Type - holds the type of the ship.
*	@param maxShields - integer that specify maximum shields of the ship.
*	@param shields - integer that specify shields of the ship
*	@param hitPoints - integer that specify hit points of the ship
*	@param maxHitPoints - integer that specify max hit points of the ship
*	@param weapon - integer that specify weapon of the ship
*/
WarShip::WarShip(int maxShields,int shields,int hitPoints,int maxHitPoints,int weapon,Type):SpaceShip(){
		this->ShipType=Type(0);
		this->maxShields=maxShields;
		this->shields=shields;
		this->hitPoints=hitPoints;
		this->maxHitPoints=maxHitPoints;
		this->weapon=weapon;
	}
//! WarShip destructor.
/*!
*Destroy WarShip.
*/
WarShip::~WarShip(){}

/***********************************************
* functions implementations
***********************************************/

//function
/****************************************************************************/
//! Returns the WarShip weapon level.
/*!\brief Returns the WarShip weapon level.
*@return -weapon level of the ship
*/
int WarShip::getMunition(){
	return weapon;
}
//function
/****************************************************************************/
//! Increase shields of the WarShip ship.
/*!\brief Increase shields of the WarShip ship by 15.
*
*/
void WarShip::increaseShields(){
	if(!(this->isShipDead())){
		shields+=15;
		if(this->shields >= this->maxShields){
			this->shields=this->maxShields;
		}//if
	}//if
}
//function
/****************************************************************************/
//! Returns the Type of the ship
/*!\brief Returns the Type of the ship
*
*/
Type WarShip::getType(){
	return Type(0);
}

