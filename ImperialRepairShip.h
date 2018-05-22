/**************************************************************************** 
* File description 
****************************************************************************/ 
/*! \file ImperialRepairShip.h
*\brief This file contains the description of the ImperialRepairShip class. 
* 
* \class ImperialRepairShip
*This class creates ship from the type of repair ships that belongs to Empire side.
*This ship class inherit from the RepairShip class.
*This type of ships can repair other ships by increasing it HitPoints in 35 points.
*
* \author Author1's ID: 300534781
* \author Author2's ID: 317035038.
*/
#ifndef IMPERIALREPAIRSHIP_H_
#define IMPERIALREPAIRSHIP_H_
/**************************************************************************** 
* Include header files 
****************************************************************************/
#include "RepairShip.h"
/**************************************************************************** 
* Include library files 
****************************************************************************/ 
#include <string>
/*! \class ImperialRepairShip 
* 
*/
class ImperialRepairShip:public RepairShip{
protected:
	///Contain the name of the ships
	string Name;
public:
	///Constructor
	ImperialRepairShip();
	///Destructor
	~ImperialRepairShip();

	 
/**************************************************************************** 
* Function prototypes 
****************************************************************************/ 
	///Displays the ship Type,its name, Shields and Hit Points 
	void printStatus();		
	///Attacks or repairs target, according to the ship type 
	void performAction(SpaceShip &target); 
	///Prints this ships name 
	void printName(); 
	///Displays the ships Shields level and Hit Points
	void printData();
};

#endif 
