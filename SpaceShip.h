/**************************************************************************** 
* File description 
****************************************************************************/  
/*! \file SpaceShip.h
*\brief This file contains the description of the SpaceShip class. 
* 
* \class SpaceShip
*This class creates Spce ship.
*This is the basic class of all ships.
* \author Author1's ID: 300534781
* \author Author2's ID: 317035038.
*/
#ifndef SPACESHIP_H_
#define SPACESHIP_H_
using namespace std;
//! An enum Type.
/*! Holds two possible types of the ships.
*	Type(0)=War_Ship.
*	Type(1)=Repair_Ship.
*/
enum Type{ War_Ship,Repair_Ship}; //Ships Types
/*! \class SpaceShip 
* 
*This class creates space ship.
*This is the basic class of all ships.
*/
class SpaceShip { 
		
		public: 
			///Constructor
			SpaceShip();
			//! A virtual destructor.
			/*!
			*/
			virtual ~SpaceShip(); 
/**************************************************************************** 
* Function prototypes 
****************************************************************************/ 
			//! A pure virtual function.
			/*!
			*Displays the ships status that contain Type, Name, Shields level and Hit Points 
			*/	
			virtual void printStatus()=0; 
			//! A pure virtual function.
			/*!
			*Attacks or repairs target, according to ship type
			*/
			virtual void performAction(SpaceShip &target)=0; 
			//! A pure virtual function.
			/*!
			*Returns the Type ships
			*/ 
			virtual Type getType()=0; 
			//! A pure virtual function.
			/*!
			*Print the name of the ship
			*/ 
			virtual void printName()=0; 
    		//! A pure virtual function.
			/*!
			*Increases the ships shields 
			*/
			virtual void increaseShields()=0; 
			///Reduces the ships shields 
			int reduceShields(int amount); 
			///Reduces the ships hit points 
			void reduceHitPoints(int amount); 
			///Increases the ships hit points 
			void increaseHitPoints(int amount); 
			//! A pure virtual function.
			/*!
			*Returns the level of munition of the ship
			*/
			virtual int getMunition()=0;
			///Returns the shields level of the ship
			int getShields();
			///Set the shields of the ship
			void setShields(int change);
			///Returns the hit points of the ship
			int getHitPoints();
			///Set the Hit Points of the ship
			void setHitPoints(int change);
			///Check if the ship is dead
			bool isShipDead();
			//! A pure virtual function.
			/*!
			*Displays shields and hit points of the ship
			*/
			virtual void printData()=0;
		
	protected: 
			//shields level of the ship
			int shields; 
			//maximum level of the ship
			int maxShields; 
			//hit ponts of the ship
			int hitPoints; 
			//maximum hit points of the ship
			int maxHitPoints; 
			//boolean to check if the ship is dead
			bool isDead;
};
#endif
