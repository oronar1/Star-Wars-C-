/**************************************************************************** 
* File description 
****************************************************************************/ 
/*! \file RebelRepairShip.h
*\brief This file contains the description of the RebelRepairShip class. 
* 
* \class RebelRepairShip
*This class creates ship from the type of repair ships that belongs to Rebel side.
*This ship class inherit from the RepairShip class.
*This type of ships can repair other ships by increasing it HitPoints in 30 points.
*
* \author Author1's ID: 300534781
* \author Author2's ID: 317035038.
*/
#ifndef REBELREPAIRSHIP_H_
#define REBELREPAIRSHIP_H_
/**************************************************************************** 
* Include header files 
****************************************************************************/
#include "RepairShip.h"
/**************************************************************************** 
* Include library files 
****************************************************************************/ 
#include <string>
/*! \class RebelRepairShip 
* 
*/
class RebelRepairShip : public RepairShip{//inherit RepairShip
protected:
	///Contain the name of the ships
	string Name;
public:
	///Constructor
	RebelRepairShip();
	///Destructor
	~RebelRepairShip();
/**************************************************************************** 
* Function prototypes 
****************************************************************************/ 
	///Displays the ships Type, name, shields and hit points 
	void printStatus();		
	///Attacks or repairs target, according to ship type 
	void performAction(SpaceShip &target); 
	///Prints this ships name 
	void printName();
	///Displays the ships Shields level and Hit Points
	void printData();
};
#endif 
