/**************************************************************************** 
* File description 
****************************************************************************/ 
/*! \file RepairShip.h
*\brief This file contains the description of the RepairShip class. 
* 
* \class RepairShip
*This class creates ship from the type of repair ships.
*This ship class inherit from the SpaceShip class.
*This type of ships can repair other ships by increasing it HitPoints.
*
* \author Author1's ID: 300534781
* \author Author2's ID: 317035038.
*/
#ifndef REPAIRSHIP_H_
#define REPAIRSHIP_H_
/**************************************************************************** 
* Include header files 
****************************************************************************/
#include "SpaceShip.h"
/*! \class RepairShip 
* 
*This class creates ship from the type of repair ships.
*This ship class inherit from the SpaceShip class.
*/
class RepairShip : public SpaceShip{//inherit spaceship
protected:
	///Contain the level of repair tool of the ships
	int repairTool;
	///Contain the Type of the ship
	Type ShipType;
public:
	///Constructor
	RepairShip(int maxShields,int shields,int hitPoints, int maxHitPoints,Type);
	///Destructor
	~RepairShip();
/**************************************************************************** 
* Function prototypes 
****************************************************************************/ 
	///Returns Type of this ship 
	Type getType(); 
	///Return the level of repairtool 
	int getMunition();
	///Increase Shields of the ship
	void increaseShields();
	//Prints Shields and Hit Points of the ship
	virtual void printData()=0;
};

#endif
