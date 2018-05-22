/**************************************************************************** 
* File description 
****************************************************************************/ 
/* \brief This file contains the description of the Xwing class. 
* 
*  \class Xwing
*This class creates ship from the type of war ships that belongs to Rebels side.
*This ship class inherit from the WarShip class.
*This type of ships can attack other ships by reducing it HitPoints or shields in 45 points.
*
* \author Author1's ID: 300534781
* \author Author2's ID: 317035038.
*/
/**************************************************************************** 
* Include library files 
****************************************************************************/ 
#include <iostream>
#include <cstring>
/**************************************************************************** 
* Include header files 
****************************************************************************/
#include "Xwing.h"
using namespace std;
//! Xwing constructor.
/*!
*Builds Xwing with the next parameters :
*	Shields=100	
*	HitPoints=100
*	Weapon=45
*	Name=X-wing
*/
Xwing::Xwing():WarShip(100,100,100,100,45,War_Ship){
		this->Name="X-wing";
		this->weapon=45;
	}
//! Xwing destructor.
/*!
*Destroy Xwing.
*/
Xwing::~Xwing(){};


/***********************************************
* functions implementations
***********************************************/

//function
/****************************************************************************/
//! Displays the Xwing ship Shields level and Hit Points
/*!\brief Displays the ships Shields level and Hit Points
*/
void Xwing::printData(){
cout<<" Shields:"<<this->getShields()<<"/100"<<", Hit Points:"<<this->hitPoints<<"/100";
}
//function
/****************************************************************************/
//! Displays the whole status of the ship: Type, Name, Shields level and Hit Points
/*!\brief Displays the whole status of the ship: Type, Name, Shields level and Hit Points
*/
void Xwing::printStatus(){
	if(!(this->isShipDead())){
		if(this->getType()==War_Ship)
			cout<<"War Ship: ";
		else if(this->getType()==Repair_Ship)
			cout<<"Repair Ship: ";
		this->printName();
	cout<<", Shields:"<<this->getShields()<<"/100"<<", Hit Points:"<<this->hitPoints<<"/100"<<endl;
	}//if
}

//function
/****************************************************************************/
//! Perform action on a specified ship.
/*!\brief Perform a attack action on a specified ship. 
*@param SpaceShip &target - the ship that will be attacked
*/
void Xwing:: performAction(SpaceShip &target){
	if(!(target.isShipDead())){
		if (target.getShields()>0)
			target.reduceShields(45);
		else if (target.getHitPoints()>0){
			target.reduceHitPoints(45);
	
	}
	}
}
//function
/****************************************************************************/
//! Prints the ships name
/*!\brief Prints the ships name 
*/  
void Xwing:: printName(){
	cout<<this->Name;
}
