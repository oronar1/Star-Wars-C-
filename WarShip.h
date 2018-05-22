/**************************************************************************** 
* File description 
****************************************************************************/ 
/*! \file WarShip.h
*  \brief This file contains the description of the WarShip class. 
* 
* \class WarShip
*This class creates ship from the type of war ships.
*This ship class inherit from the SpaceShip class.
*This type of ships can attack other ships by decreasing it Shields and HitPoints.
*
* \author Author1's ID: 300534781
* \author Author2's ID: 317035038.
*/
#ifndef WARSHIP_H_
#define WARSHIP_H_
/**************************************************************************** 
* Include header files 
****************************************************************************/
#include "SpaceShip.h"
/*! \class WarShip 
*This class creates ship from the type of war ships.
*This ship class inherit from the SpaceShip class.
*/
class WarShip:public SpaceShip{//inherit spaceship
protected:
	///Contain the level of weapon of the ships
	int weapon;
	///Contain the Type of the ship
	Type ShipType;
public:
	///Constructor
	WarShip(int maxShields,int shields,int hitPoints,int maxHitPoints,int weapon,Type);
	///Destructor
	~WarShip();
/**************************************************************************** 
* Function prototypes 
****************************************************************************/ 
	///Returns Type of this ship  
	Type getType(); 
	///Increases the ships shields 	 
	void increaseShields();
	///Return the level of weapon
	int getMunition();
	//Prints Shields and Hit Points of the ship
	virtual void printData()=0;
};

#endif 
