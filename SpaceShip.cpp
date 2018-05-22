/**************************************************************************** 
* File description 
****************************************************************************/ 
/*\brief This file contains the implementation of the SpaceShip class. 
* 
* \class SpaceShip
*This class creates ship.
*This class creates Spce ship.
*This is the basic class of all ships.
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
#include "SpaceShip.h"
using namespace std;
//! SpaceShip destructor.
/*!
*Destroy SpaceShip.
*/
SpaceShip::~SpaceShip(){};

/***********************************************
* functions implementations
***********************************************/

//function
/****************************************************************************/
//! Check if the ship is dead
/*!\brief Returns the result of the check if the ship is dead
*@return - is ship dead
*/ 
bool SpaceShip::isShipDead(){
	return isDead;
}
//function
/****************************************************************************/
//! Get hit points of the ship
/*!\brief Get hit points of the ship
*@return - hit points of the ship
*/ 
int SpaceShip::getHitPoints(){
	return hitPoints;
}
//function
/****************************************************************************/
//! Set hit points of the ship
/*!\brief Set hit points of the ship
*@parameter change - indicates the new value of the hit points
*/ 
void SpaceShip::setHitPoints(int change){
	hitPoints=change;
	if(hitPoints>maxHitPoints)
		hitPoints=maxHitPoints;
}
//function
/****************************************************************************/
//! Get shields level of the ship
/*!\brief Get shields level of the ship
*@return - returns the value of the shields
*/ 
int SpaceShip::getShields(){
	return shields;
}
//function
/****************************************************************************/
//! Set shields level of the ship
/*!\brief Set shields level of the ship
*@parameter change - indicates the new value of the shields
*/ 
void SpaceShip::setShields(int change){
	shields=change;
	if(shields>maxShields)
		shields=maxShields;
}
//! SpaceShip default constructor.
/*!
*sets all ship parameters to 0.
*/
SpaceShip::SpaceShip(){
	shields=0; 
	maxShields=0; 
	hitPoints=0; 
	maxHitPoints=0; 
	isDead=0;
}
//function
/****************************************************************************/
//! Reduce shields of the ship
/*!\brief Reduce shields of the ship. If shields are 0, than hit points reduced.
*@parameter amount - indicates the value of change to be made to the shields.
*@return shields - returns new value of shields of the ship
*/ 
int SpaceShip::reduceShields(int amount){
	if(amount>shields){
		amount=amount-shields;
		this->reduceHitPoints(amount);
		shields=0;
	}
	else
		shields-=amount;
	if(shields<=0){
			shields=0;
	}
	return shields;
}
//function
/****************************************************************************/
//! Reduce hit points of the ship
/*!\briefReduce hit points of the ship. If hit points are 0, than ship is declared as dead.
*@parameter amount - indicates the value of change to be made to the hit points.
*
*/ 
void SpaceShip::reduceHitPoints(int amount){
	if(!(this->isShipDead())){
	hitPoints=hitPoints-amount;
	if(hitPoints<=0){
		hitPoints=0;
		isDead=1;
	}
	}
}
//function
/****************************************************************************/
//! Increase hit points of the ship
/*!\brief Increase hit points of the ship.
*@parameter amount - indicates the value of change to be made to the hit points.
*
*/ 
/*Function implementation to increase Hit Points*/
void SpaceShip::increaseHitPoints(int amount){
	if(!(this->isShipDead())){
	this->hitPoints+=amount;
	if(this->hitPoints > this->maxHitPoints)
		this->hitPoints=this->maxHitPoints;
	}
}
