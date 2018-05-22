/**************************************************************************** 
* File description 
****************************************************************************/ 
/*!\file Xwing.h
* \brief This file contains the description of the Xwing class. 
* 
* \class Xwing
*This class creates ship from the type of war ships that belongs to Rebels side.
*This ship class inherit from the WarShip class.
*This type of ships can attack other ships by reducing it HitPoints or shields in 40 points.
*
* \author Author1's ID: 300534781
* \author Author2's ID: 317035038.
*/
#ifndef XWING_H_
#define XWING_H_
/**************************************************************************** 
* Include header files 
****************************************************************************/
#include "WarShip.h"
/**************************************************************************** 
* Include library files 
****************************************************************************/
#include <string>
 
/*!\class Xwing 
*This ship class inherit from the WarShip class.
*This type of ships can attack other ships by reducing it HitPoints or shields in 45 points.
*/

class Xwing : public WarShip{
	protected:
		///Contain the name of the ships
	string Name;
public:
	///Constructor
	Xwing();
	///Destructor
	~Xwing();
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
