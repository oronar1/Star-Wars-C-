/**************************************************************************** 
* File description 
****************************************************************************/ 
/*! \file ImperialRepairShip.cpp
*\brief This file contains the implimentation of the ImperialRepairShip class. 
* 
*This class creates ship from the type of repair ships that belongs to Empire side.
*This ship class inherit from the RepairShip class.
*This type of ships can repair other ships by increasing it HitPoints in 35 points.
*
* \author Author1's ID: 300534781
* \author Author2's ID: 317035038.
*/
/**************************************************************************** 
* Include library files 
****************************************************************************/ 
#include <iostream>
#include <string>
/**************************************************************************** 
* Include header files 
****************************************************************************/
#include "ImperialRepairShip.h"
using namespace std;
//! ImperialShip constructor.
/*!
*Builds ImperialRepairShip with the next parameters :
*	Shields=200	
*	HitPoints=200
*	RepairTool=35
*	Name=Imperial Repair Ship
*/
ImperialRepairShip::ImperialRepairShip(): RepairShip(200,200,200,200,Repair_Ship){
		this->Name="Imperial Repair Ship ";
		this->repairTool=35;
	}	
//! ImperialShip destructor.
/*!
*Destroy ImperialRepairShip.
*/
ImperialRepairShip::~ImperialRepairShip(){}
/***********************************************
* functions implementations
***********************************************/

//function
/****************************************************************************/
//! Displays the ships Shields level and Hit Points
/*!\brief Displays the ships Shields level and Hit Points
*/
void ImperialRepairShip::printData(){
cout<<" Shields:"<<this->getShields()<<"/200"<<", Hit Points:"<<this->hitPoints<<"/200";
}
//function
/****************************************************************************/
//! Displays the whole status of the ship: Type, Name, Shields level and Hit Points
/*!\brief Displays the whole status of the ship: Type, Name, Shields level and Hit Points
*/
void ImperialRepairShip :: printStatus(){
	if(!(this->isShipDead())){
	if(this->getType()==War_Ship)
		cout<<"War Ship: ";
	else if(this->getType()==Repair_Ship)
		cout<<"Repair Ship: ";
	this->printName();
	cout<<"Shields:"<<this->shields<<"/200"<<", Hit Points:"<<this->hitPoints<<"/200"<<endl;
	}
}
//function
/****************************************************************************/
//! Perform action on a specified ship.
/*!\brief Perform a repair action on a specified ship. 
*@param SpaceShip &target - the ship that need a repair 
*/
void ImperialRepairShip :: performAction(SpaceShip &target){
	if (!(target.isShipDead()))
		target.increaseHitPoints(35);
}
//function
/****************************************************************************/
//! Prints the ships name
/*!\brief Prints the ships name 
*/ 
void ImperialRepairShip :: printName(){
	cout<<this->Name;
}
