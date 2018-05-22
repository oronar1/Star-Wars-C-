/**************************************************************************** 
* File description 
****************************************************************************/ 
/*\brief This file contains the implementation of the RepairShip class. 
* 
* \class RepairShip
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
#include "RepairShip.h"
using namespace std;
//! RepairShip constructor.
/*!
*Builds RepairShip with the next parameters :
*	@param Type - holds the type of the ship.
*	@param maxShields - integer that specify maximum shields of the ship.
*	@param shields - integer that specify shields of the ship
*	@param hitPoints - integer that specify hit points of the ship
*	@param maxHitPoints - integer that specify max hit points of the ship
*/
RepairShip::RepairShip(int maxShields,int shields,int hitPoints, int maxHitPoints,Type):SpaceShip(){
		this->ShipType=Type(1);
		this->maxShields=maxShields;
		this->shields=shields;
		this->hitPoints=hitPoints;
		this->maxHitPoints=maxHitPoints;
	}
//! RepairShip destructor.
/*!
*Destroy RepairShip.
*/
RepairShip::~RepairShip(){}
/***********************************************
* functions implementations
***********************************************/

//function
/****************************************************************************/
//! Displays the RepairShip Shields level and Hit Points
/*!\brief Displays the ship Shields level and Hit Points
*/
void RepairShip::printData(){
		cout<<" Shields:"<<this->getShields()<<"/200"<<", Hit Points:"<<this->hitPoints<<"/200"<<endl;
}
//function
/****************************************************************************/
//! Returns the RepairShip repair tool
/*!\brief Returns the RepairShip repair tool
*@return -repair tool level of the ship
*/
int RepairShip::getMunition(){
	return repairTool;
}
//function
/****************************************************************************/
//! Increase shields of the repair ship
/*!\brief Increase shields of the repair ship by 0.
*
*/
void RepairShip::increaseShields(){
	if(!(this->isShipDead())){
		shields+=0;
		if(this->shields >= this->maxShields){
			this->shields=this->maxShields;
		}
	}
}
//function
/****************************************************************************/
//! Returns the Type of the ship
/*!\brief Returns the Type of the ship
*
*/
Type RepairShip::getType(){	
	return Type(1);
}
