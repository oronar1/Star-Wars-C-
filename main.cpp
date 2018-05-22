/*! \mainpage file main.c
*  \section Introduction
*General Description:
* This is the first assignment for C++ language programming laboratory.
* This program creates text based Star Wars game simulator.
*There are two sides in the game, Rebels and Empire. Both sides have fleets that have warships and repair ships. The number of ships of both Types are decided by
*user. User also can choose to play by rounds or to run the game untill one side win.
*The game has limit of 50 iterations.
*The program has next main menu:<br>
*Star Wars <br>
*---------------<br> 
*(1)New Game <br> 
*(2)Quit<br>

*The program has next secondary menu:<br><br>
*Star Wars - Round 1 <br>
*--------------------------------<br> 
*(1)Print Fleets <br>      
*(2)Play one round <br>      
*(3)Play until the end of battle <br>
*(4)Back to main  menu <br>     
* \author Author1's ID: 300534781
* \author Author2's ID: 317035038.
*
*****************************************************************/
/*! \file main.c
*  \brief Star Wars
*@full  This is the first assignment for C++ language programming laboratory.
* This program creates text based Star Wars game simulator.
*There are two sides in the game, Rebels and Empire. Both sides have fleets that have warships and repair ships. The number of ships of both Types are decided by
*user. User also can choose to play by rounds or to run the game untill one side win.
*The game has limit of 50 iterations.
*The program has next main menu:<br>
*Star Wars <br>
*--------------- <br>
*(1)New Game <br> 
*(2)Quit<br>

*The program has next secondary menu:<br><br>
*Star Wars - Round 1 <br>
*--------------------------------<br> 
*(1)Print Fleets <br>      
*(2)Play one round <br>      
*(3)Play until the end of battle <br>
*(4)Back to main  menu <br>     
* \author Author1's ID: 300534781
* \author Author2's ID: 317035038.
*
*****************************************************************/
/**************************************************************************** 
* Include library files 
****************************************************************************/ 
#include <iostream>
#include <cstdlib>
#include <ctime>
/**************************************************************************** 
* Include header files 
****************************************************************************/
//#include "TieFighter.h"
//#include "Xwing.h"
//#include "WarShip.h"
//#include "RepairShip.h"
//#include "ImperialRepairShip.h"
//#include "RebelRepairShip.h"
#include "StarWars.h"
#define MAX_ITERATIONS 50;

using namespace std;
/***********************************************
* Functions prototypes
***********************************************/
void mainMenu();//main menu
int numberOfShips();
int getChoice(int lower,int upper);
//function
/****************************************************************************/
//! Displays the main menu option to user.
/*!\brief Displays the main menu option to user.
*
*/
/****************************************************************************/
void mainMenu(){
	cout<<endl<<"Star Wars"<<endl; 
	cout<<"---------------"<<endl; 
	cout<<"(1)New Game"<<endl;  
	cout<<"(2)Quit"<<endl;   
	cout<<"---------------"<<endl; 
}
//function
/****************************************************************************/
//! Check that user enters only digits.
/*!\brief Check that user enters only digits between certain params.
*@param lower - lowest number that user can press
*@param upper - highest number that user can press
*@return - users choice
*/
/****************************************************************************/
int getChoice(int lower,int upper){
	string choice;
	int usersChoice,i,flag=1;
	do{
		do{
			cout<<"Enter your choice:"<<endl;
			flag=1;
			cin>>choice;
			int length=choice.length();
				for(i=0;i!=length;i++){
					if(!isdigit(choice[i])){
						flag=0;
					}//if
				}//for
				if(flag==0){
					cout<<endl<<" Wrong input!!!"<<endl;
				}
		}while(flag==0);
			usersChoice=atoi(choice.c_str());
		}while(usersChoice<lower||usersChoice>upper);
	return usersChoice;
}
//function
/****************************************************************************/
//! Check that user enters only digits and initialize number of ships to be created.
/*!\brief Check that user enters only digits and initialize number of ships to be created.
*@return - users choice
*/
/****************************************************************************/
int numberOfShips(){
	string choice;
	int usersChoice,i,flag=1;
	do{
		do{
			flag=1;
			cin>>choice;
			int length=choice.length();
				for(i=0;i!=length;i++){
					if(!isdigit(choice[i])){
						flag=0;
					}//if
				}//for
				if(flag==0){
					cout<<endl<<" Wrong input!!! "<<endl;
					cout<<"Enter Again: "<<endl;
				}
		}while(flag==0);	
		usersChoice=atoi(choice.c_str());
		}while(usersChoice<0);
	return usersChoice;
}
//typedef main program code
/*!\brief thats the main code of the program.
* It accepts from user how he want to simulate the battle, how many ships on each side.
* 
*@return- displays the battle process
*
*/

int main()
{
	int choice=0,secChoice=0;
	int n_r_ReapirShip;
	int n_r_WarShip;
	int n_i_ImperialRepairShip;
	int n_i_WarShip;
	srand(time(NULL));
	do{
	mainMenu();
	choice=getChoice(1,2);
	switch(choice){
		case 1:{//new game
			cout<<"Enter the number of Rebel War ships: ";
			n_r_WarShip=numberOfShips();
			cout<<endl<<"Enter the number of Rebel Repair ships: ";
			n_r_ReapirShip=numberOfShips();
			cout<<endl<<"Enter the number of Imperial War ships: ";
			n_i_WarShip=numberOfShips();
			cout<<endl<<"Enter the number of Imperial Repair ships: ";
			n_i_ImperialRepairShip=numberOfShips();
			StarWars game(n_r_WarShip,n_r_ReapirShip,n_i_WarShip,n_i_ImperialRepairShip);
			do{
			game.secondaryMenu();//show secondary menu
			secChoice=getChoice(1,4);
			switch(secChoice){
				case 1:{	//print fleets
					game.printFleets();}
					break;
				case 2:{//play one round
					if(game.getStatus()==0){
					game.playRound();
					game.printFleets();
					game.printStatus();
					}
					else 
						game.printStatus();}
					break;
				case 3:{//Play until the end of battle
					int i=game.getRound();
					int y=MAX_ITERATIONS;
						
						do{
								game.playRound();
								game.printFleets();
								game.printStatus();
								i=game.getRound();
						}while(i<y && game.getStatus()==0);
						if((i>=y)&&(game.getStatus()==Status(0))){
							cout<<endl<<"The Game has Reached it Maximum Iteration"<<endl;
							game.setStatus(Draw);
							game.printStatus();
						}
					   }//case
					break;
				case 4://back to main menu
					break;
				
			};
			  }while(secChoice!=4); 
			   }
			break;
			   
		case 2:{//quit game
				cout<<endl<<"You choose to quit"<<endl;
				cout<<"The program has been stopped"<<endl;
				exit(0);
			   }
			break;
	};
	}while(choice!=0);
	return 0;
}//main
