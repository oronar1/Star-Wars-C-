StarWars_Game: main.o SpaceShip.o StarWars.o WarShip.o RepairShip.o RebelRepairShip.o ImperialRepairShip.o TieFighter.o Xwing.o
	g++ -Wall main.o SpaceShip.o StarWars.o WarShip.o RepairShip.o RebelRepairShip.o ImperialRepairShip.o TieFighter.o Xwing.o -o StarWars_Game
	rm StarWars.o
	rm Xwing.o
	rm WarShip.o
	rm TieFighter.o
	rm SpaceShip.o
	rm RepairShip.o
	rm RebelRepairShip.o
	rm main.o
	rm ImperialRepairShip.o

WarShip.o: WarShip.cpp 
	g++ -c -Wall WarShip.cpp

RepairShip.o: RepairShip.cpp 
	g++ -c -Wall RepairShip.cpp

TieFighter.o: TieFighter.cpp
	g++ -c -Wall TieFighter.cpp

Xwing.o: Xwing.cpp
	g++ -c -Wall Xwing.cpp

ImperialRepairShip.o: ImperialRepairShip.cpp
	g++ -c -Wall ImperialRepairShip.cpp

RebelRepairShip.o: RebelRepairShip.cpp
	g++ -c -Wall RebelRepairShip.cpp

StarWars.o: StarWars.cpp
	g++ -c -Wall StarWars.cpp

main.o: main.cpp 
	g++ -c -Wall main.cpp



