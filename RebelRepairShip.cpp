/**************************************************************************** 
* File description 
****************************************************************************/ 
/*! \file RebelRepairShip.cpp
*\brief This file contains the implimentation of the RebelRepairShip class. 
* 
*This class creates ship from the type of repair ships that belongs to Rebel side.
*This ship class inherit from the RepairShip class.
*This type of ships can repair other ships by increasing it HitPoints in 30 points.
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
#include "RepairShip.h"
#include "RebelRepairShip.h"
using namespace std;
//! RebelRepairShip constructor.
/*!
*Builds RebelRepairShip with the next parameters :
*	Shields=200	
*	HitPoints=200
*	RepairTool=30
*	Name=Rebel Repair Ship
*/
RebelRepairShip::RebelRepairShip():RepairShip(200,200,200,200,Repair_Ship){
		this->Name="Rebel Repair Ship";
		this->repairTool=30;
	}
//! RebelRepairShip destructor.
/*!
*Destroy RebelRepairShip.
*/
RebelRepairShip::~RebelRepairShip(){}

/***********************************************
* functions implementations
***********************************************/

//function
/****************************************************************************/
//! Displays the ships Shields level and Hit Points
/*!\brief Displays the ships Shields level and Hit Points
*/
void RebelRepairShip::printData(){
cout<<" Shields:"<<this->getShields()<<"/200"<<", Hit Points:"<<this->hitPoints<<"/200";
}
//function
/****************************************************************************/
//! Displays the whole status of the ship: Type, Name, Shields level and Hit Points
/*!\brief Displays the whole status of the ship: Type, Name, Shields level and Hit Points
*/
void RebelRepairShip::printStatus(){
	if(!(this->isShipDead())){
	if(this->getType()==War_Ship)
		cout<<"War Ship: ";
	else if(this->getType()==Repair_Ship)
		cout<<"Repair Ship: ";
	this->printName();
	cout<<", Shields:"<<this->getShields()<<"/200"<<", Hit Points:"<<this->hitPoints<<"/200"<<endl;
	}
}
//function
/****************************************************************************/
//! Perform action on a specified ship.
/*!\brief Perform a repair action on a specified ship. 
*@param SpaceShip &target - the ship that need a repair 
*/
void RebelRepairShip:: performAction(SpaceShip &target){
	if (!(target.isShipDead()))
		target.increaseHitPoints(30);
}
//function
/****************************************************************************/
//! Prints the ships name
/*!\brief Prints the ships name 
*/ 
void RebelRepairShip :: printName(){
	cout<<this->Name;
}
