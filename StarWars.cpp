/**************************************************************************** 
* File description 
****************************************************************************/ 
/*! \file StarWars.cpp
*\brief This file contains the description of the StarWars class. 
* 
* \class StarWars
*This class creates a battle field of star wars
* \author Author1's ID: 300534781
* \author Author2's ID: 317035038.
*/
/**************************************************************************** 
* Include library files 
****************************************************************************/ 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
/**************************************************************************** 
* Include header files 
****************************************************************************/
#include "StarWars.h"
#include "Xwing.h"
#include "TieFighter.h"
#include "RebelRepairShip.h"
#include "ImperialRepairShip.h"
///Number of maximum games iteration
#define MAX_ITERATIONS 50
//! StarWars default constructor.
/*!
*sets game status to 0=game in progress and round to 1.
*/
StarWars::StarWars(){
	this->round=1;
	this->gameStatus=Status(0);
};
//! StarWars constructor.
/*!
*Initialize the lists of fleets with specified number of ships
*@param r_Warships - number of rebel war ships
*@param r_RepairShips - number os rebel Repair Ship
*@param i_Warships - number of imperial War Ships
*@param i_RepairShips - number of imperial Repair Ships
*/
StarWars::StarWars(int r_Warships,int r_RepairShips,int i_Warships,int i_RepairShips){
	list<SpaceShip *>::iterator rebel;
	rebel = RebelFleet.begin();//iterator on rebel fleet
	list<SpaceShip *>::iterator imperia;
	imperia = ImperialFleet.begin();//iterator on imperial fleet
	/*add rebels warships*/
	for(int i=0;i<r_Warships;i++){
		RebelFleet.push_back(new Xwing);
	}
	
	/*add imperial warships*/
	for(int i=0;i<i_Warships;i++){
		ImperialFleet.push_back(new TieFighter);
	}
	/*add rebel repairships*/
	for(int i=0;i<r_RepairShips;i++){
		RebelFleet.push_back(new RebelRepairShip);
	}

	/*add imperial repairships*/
	for(int i=0;i<i_RepairShips;i++){
		ImperialFleet.push_back(new ImperialRepairShip);
	}
	round=1;
	gameStatus=Status(0);
}
//function
/****************************************************************************/
//! Play one round of star wars
/*!\brief Play one round of star wars while the side that perform action first is chosed randomly.
*Both sides perform actions, warships attacks enemy fleet and repair ships repair friend ships.
*/ 
void StarWars::playRound(){
	SpaceShip * rebelShip;//rebels
	SpaceShip * current;//current ship that perform action
	SpaceShip * imperialShip;//emperials
	SpaceShip * target;//target
	imperialShip=ImperialFleet.front();
	rebelShip = RebelFleet.front();
/******************iterators*************************************************/
	list<SpaceShip *>::iterator rebel;//rebel iterator
	rebel =RebelFleet.begin();//iterator on rebel fleet
	list<SpaceShip *>::iterator imperia;
	imperia = ImperialFleet.begin();
	list<SpaceShip *>::iterator actual;
/********************************************************************************/
	int randomShip;
	int side=randomSide();//chooce wich side will attack first
	switch(side){
		/***************rebels attack first***************/
		case 1:
			if( (RebelFleet.empty() && ImperialFleet.empty()) )
				this->setStatus(Draw);//draw
			else if( (!RebelFleet.empty() && ImperialFleet.empty()) )
				this->setStatus(Rebels_Won);//rebels won
			else if( (RebelFleet.empty() && !ImperialFleet.empty()) )
				this->setStatus(Empire_Won);//imperia won

			if(!ImperialFleet.empty()&&!RebelFleet.empty()){
			cout<<endl<<"Round "<< this->getRound()<<endl<<"=================================="<<endl<<endl;

			for ( rebel=RebelFleet.begin() ; (rebel != RebelFleet.end())&&(!ImperialFleet.empty()); rebel++ ){  //runs on rebel list
			   current=*rebel;
				if (current->getType()==Type(0)){   //if current ship is warShip
				   randomShip=random(ImperialFleet);//loot the enemy ship to attack
				   actual=ImperialFleet.begin();
			   }//if
				else{   //current ship is repair
				   randomShip=random(RebelFleet);//loot the friend ship to repair
			       actual=RebelFleet.begin();
				}//else

				for (; randomShip>0;randomShip--){
				   actual++;
				}//for
				target = *actual;
				current->printName();
				if(current->getType()==Type(0)){
					cout<<" attacks ";target->printName();cout<<" with: ";target->printData();
					cout<<", causing ";cout<<current->getMunition();cout<<" damage"<<endl;
				}
				else{ 
					cout<<" repairs ";
					cout<<current->getMunition();
					cout<<" damage to ";target->printName();
					cout<<" with: ";target->printData();cout<<endl;
				}
				current->performAction(*target);
				
				//if(ImperialFleet.empty()){//check if there is enemy ships if no then rebels won
				//	this->gameStatus=Status(1);
				//}
			}	//big for
			}//big if
/**************************imperials turn*****************************/
			if(!ImperialFleet.empty()&&!RebelFleet.empty()){
				for ( imperia=ImperialFleet.begin() ; (imperia != ImperialFleet.end())&&(!RebelFleet.empty()); imperia++ ){  //runs on rebel list
			   current=*imperia;
			   if (current->getType()==Type(0)){   //if current ship is warShip
				   randomShip=random(RebelFleet);//loot the enemy ship to attack
				   actual=RebelFleet.begin();
			   }//if
				else{   //current ship is repair
				   randomShip=random(ImperialFleet);//loot the friend ship to repair
				    actual=ImperialFleet.begin();
				}//else
	
				for (; randomShip>0;randomShip--){
				   actual++;
				}//for
				target = *actual;
				current->printName();

				if(current->getType()==Type(0)){
					cout<<" attacks ";target->printName();cout<<" with: ";target->printData();
					cout<<", causing ";cout<<current->getMunition();cout<<" damage"<<endl;
				}
				else{ 
					cout<<" repairs ";
					cout<<current->getMunition();
					cout<<" damage to ";target->printName();
					cout<<" with: ";target->printData();cout<<endl;
				}
				current->performAction(*target);
				
				//if(RebelFleet.empty()){//check if there is enemy ships
				//	this->gameStatus=Status(2);
				//}
		  }//big for
		round++;//increase rounds
			}//big if

			//Deleting dead ships from Rebel fleet.
			rebel = RebelFleet.begin();
			for (int i = RebelFleet.size(); i>0; i--){
				rebelShip = *rebel;
				if (rebelShip->isShipDead()){
					rebel--;
					delete rebelShip;
					RebelFleet.remove(rebelShip);
				}
				rebel++;
			}

			//Deleting dead ships from Emperial fleet.
			imperia = ImperialFleet.begin();
			for(int i = ImperialFleet.size(); i>0; i--){
				imperialShip = *imperia;
				if (imperialShip->isShipDead()){
					imperia--;
					delete imperialShip;
					ImperialFleet.remove(imperialShip);
				}
				imperia++;
			}

			//regenerating shields
			for ( rebel=RebelFleet.begin() ; (rebel != RebelFleet.end())&&(!ImperialFleet.empty()); rebel++ ){
				current=*rebel;
				current->increaseShields();
			}
			for ( imperia=ImperialFleet.begin() ; imperia != ImperialFleet.end(); imperia++ ){
				current=*imperia;
				current->increaseShields();
			}
			
			if( (RebelFleet.empty() && ImperialFleet.empty()) )
				this->setStatus(Draw);//draw
			else if( (!RebelFleet.empty() && ImperialFleet.empty()) )
				this->setStatus(Rebels_Won);//rebels won
			else if( (RebelFleet.empty() && !ImperialFleet.empty()) )
				this->setStatus(Empire_Won);//imperia won			
	
		break;
/*******************************imperials start************************************/
		case 2:
			if( (RebelFleet.empty() && ImperialFleet.empty()) )
				this->setStatus(Draw);//draw
			else if( (!RebelFleet.empty() && ImperialFleet.empty()) )
				this->setStatus(Rebels_Won);//rebels won
			else if( (RebelFleet.empty() && !ImperialFleet.empty()) )
				this->setStatus(Empire_Won);//imperia won

			if(!ImperialFleet.empty()&&!RebelFleet.empty()){
			cout<<endl<<"Round "<< this->getRound()<<endl<<"=================================="<<endl<<endl;
			for ( imperia=ImperialFleet.begin() ; (imperia != ImperialFleet.end())&&(!RebelFleet.empty()); imperia++ ){  //runs on rebel list
				   current=*imperia;//regenerating shiields
			   if (current->getType()==Type(0)){   //if current ship is warShip
				   randomShip=random(RebelFleet);//loot the enemy ship to attack
				   actual=RebelFleet.begin();
			   }//if
				else{   //current ship is repair
				   randomShip=random(ImperialFleet);//loot the friend ship to repair
				    actual=ImperialFleet.begin();
				}//else

				for (; randomShip>0;randomShip--){
				   actual++;
				}//for
				target = *actual;
/*****printing the action**************************************************************************/
				current->printName();
				if(current->getType()==Type(0)){
					cout<<" attacks ";target->printName();cout<<" with: ";target->printData();
					cout<<", causing ";cout<<current->getMunition();cout<<" damage"<<endl;
				}
				else{ 
					cout<<" repairs ";
					cout<<current->getMunition();
					cout<<" damage to ";target->printName();
					cout<<" with: ";target->printData();cout<<endl;
				}
				current->performAction(*target);
				
			//	if(RebelFleet.empty()){//check if there is enemy ships
			//		this->gameStatus=Status(2);
			//	}
			}//big for
			}//big if
/***************rebels attack**************************************************************************/
			if(!ImperialFleet.empty()&&!RebelFleet.empty()){
				for ( rebel=RebelFleet.begin() ; (rebel != RebelFleet.end())&&(!ImperialFleet.empty()); rebel++ ){  //runs on rebel list
				current=*rebel;
				if (current->getType()==Type(0)){   //if current ship is warShip
					randomShip=random(ImperialFleet);//loot the enemy ship to attack
					actual=ImperialFleet.begin();
				}//if
				else{   //current ship is repair
					randomShip=random(RebelFleet);//loot the friend ship to repair
					actual=RebelFleet.begin();
				}//else

				for (; randomShip>0;randomShip--){
					 actual++;
				}//for

				target = *actual;
/********************printing action*******************************************/
				current->printName();
				if(current->getType()==Type(0)){
					cout<<" attacks ";target->printName();cout<<" with: ";target->printData();
					cout<<", causing ";cout<<current->getMunition();cout<<" damage"<<endl;
				}
				else{ 
					cout<<" repairs ";
					cout<<current->getMunition();
					cout<<" damage to ";target->printName();
					cout<<" with: ";target->printData();cout<<endl;
				}
				/*performing an action*/
				current->performAction(*target);

			//	if(ImperialFleet.empty()){//check if there is enemy ships
			//		this->gameStatus=Status(1);
			//	}//if
			}//big for
			round++;//reduce rounds
			}//big if
			
			//Deleting dead ships from Rebel fleet.
			rebel = RebelFleet.begin();
			for (int i = RebelFleet.size(); i>0; i--){
				rebelShip = *rebel;
				if (rebelShip->isShipDead()){
					rebel--;
					delete rebelShip;
					RebelFleet.remove(rebelShip);
				}
				rebel++;
			}

			//Deleting dead ships from Emperial fleet.
			imperia = ImperialFleet.begin();
			for(int i = ImperialFleet.size(); i>0; i--){
				imperialShip = *imperia;
				if (imperialShip->isShipDead()){
					imperia--;
					delete imperialShip;
					ImperialFleet.remove(imperialShip);
				}
				imperia++;
			}
			//regenerating shiields
			for ( rebel=RebelFleet.begin() ; rebel != RebelFleet.end(); rebel++ ){
				current=*rebel;
				current->increaseShields();
			}
			for ( imperia=ImperialFleet.begin() ; imperia != ImperialFleet.end(); imperia++ ){
				current=*imperia;	
				current->increaseShields();
			}

			if( (RebelFleet.empty() && ImperialFleet.empty()) )
				this->setStatus(Draw);//draw
			else if( (!RebelFleet.empty() && ImperialFleet.empty()) )
				this->setStatus(Rebels_Won);//rebels won
			else if( (RebelFleet.empty() && !ImperialFleet.empty()) )
				this->setStatus(Empire_Won);//imperia won
			break;
	};
}
//! StarWars destructor.
/*\briefDestroy SpaceShip that are in the lists.
*
*/
StarWars::~StarWars(){
	list<SpaceShip *>::iterator iter;
	SpaceShip *ship;
	if(!(RebelFleet.empty())){
		iter=RebelFleet.begin();
		for(;iter!=RebelFleet.end();iter++){
			ship=*iter;
			delete ship;
		}//for
	}//if

	if(!(ImperialFleet.empty())){
		iter=ImperialFleet.begin();
		for(;iter!=ImperialFleet.end();iter++){
			ship=*iter;
			delete ship;
		}//for
	}//if
	
};
//function
/****************************************************************************/
//! Get the status of the game
/*!\brief Get the status of the game
*@return - status of the game
*/ 
Status StarWars::getStatus(){
	return	this->gameStatus;
}
//function
/****************************************************************************/
//! Display the status of the game
/*!\brief Display the status of the game
*
*/ 
void StarWars::printStatus(){
	if(this->getStatus()==Status(0))
		cout<<endl<<" Game_In_Progress "<<endl;
	if(this->getStatus()==Status(1))
		cout<<endl<<" Rebels_Won "<<endl;
	if(this->getStatus()==Status(2))
		cout<<endl<<" Empire_Won "<<endl;
	if(this->getStatus()==Status(3))
		cout<<endl<<" Draw "<<endl;
}
//function
/****************************************************************************/
//! Set status of the game
/*!\brief Set status of the game
*@return - status of the game
*
*/ 
Status StarWars::setStatus(Status status){
	return this->gameStatus=Status(status);
}
//function
/****************************************************************************/
//! Set round of the game
/*!\brief Set round of the game
*@return - round of the game
*
*/ 
int StarWars::setRound(int round){
	return this->round=round;
}
//function
/****************************************************************************/
//! Get round of the game
/*!\brief Get round of the game
*@return - round of the game
*
*/ 
int StarWars::getRound(){
	return this->round;
}
//function
/****************************************************************************/
//! Loot randomly the ship to perform action on
/*!\brief Loot randomly the ship to perform action on
*@param list<SpaceShip *> objectsList - list of target ships
*@return number of the ship to attack
*
*/ 
int StarWars::random(list<SpaceShip *> objectsList){
 /*loot random number*/
 int random_integer=0;
 int lowest=0, highest=objectsList.size()-1;
 int range=(highest-lowest)+1;
 random_integer = rand()%range;  
 return random_integer;
}//function
//function
/****************************************************************************/
//! Loot randomly the side to perform action first
/*!\brief Loot randomly the side to perform action first
*
*@return number of the side to perform action first
*
*/ 
int StarWars::randomSide(){
	int random_integer;
		random_integer = (rand()%2)+1;
	return random_integer;
}//function
//function
/****************************************************************************/
//! Displays fleets of ships
/*!\brief Displays fleets of ships
*
*/ 
void StarWars::printFleets(){//print fleets of both sides
	list<SpaceShip *>::iterator fleetIterator;
	SpaceShip * current;
	int i;
	fleetIterator = RebelFleet.begin();//iterator on rebel fleet
	cout<<endl<<"  Rebel Fleet:"<<endl<<"---------------------------"<<endl;
	for(i=0;fleetIterator!=RebelFleet.end();i++){
		current=*fleetIterator;
		current->printStatus();
		fleetIterator++;
	}
	fleetIterator=ImperialFleet.begin();
	cout<<endl<<"  Imperial Fleet:"<<endl<<"---------------------------"<<endl;
	for(i=0;fleetIterator!=ImperialFleet.end();i++){
		current=*fleetIterator;
		current->printStatus();
		fleetIterator++;
	} 
}
//function
/****************************************************************************/
//! Displays secondary menu of the game
/*!\brief Displays fleets of ships
*
*/
void StarWars::secondaryMenu(){
	cout<<endl<<"Star Wars";cout<<"-"<<"Round "<< this->getRound()<<endl; 
	cout<<"--------------------------------"<<endl; 
	cout<<"(1)Print Fleets"<<endl;       
	cout<<"(2)Play one round"<<endl;      
	cout<<"(3)Play until the end of battle"<<endl; 
	cout<<"(4)Back to main  menu"<<endl;     
	cout<<"--------------------------------"<<endl; 
}
