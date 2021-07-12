#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include "map.h"
#include "plant.h"
#include "player.h"
#include "zombie.h"
#include "plant_factory.h"


void showTitle(){
	std::cout << "-----------------------------" << std::endl
			  << "|     Plants vs. Zombies     |" << std::endl
			  << "-----------------------------" << std::endl;
}

void showRules(){
	std::cout << "=============================================================================" << std::endl
			  << "Plants vs. Zombies Rule:" << std::endl
			  << std::endl
			  << "How to win:" << std::endl
			  << "  (1) All zombies are dead." << std::endl
			  << "  (2) At least one plant is live." << std::endl
			  << "  (3) The number of dead bomb plants cannot exceed the number of zombies." << std::endl
			  << std::endl
			  << "How to lose:" << std::endl
			  << "  All plants are dead." << std::endl
			  << "=============================================================================" << std::endl;
}

int inputNum(const int min_num, const int max_num, const int default_num){
	int num;
	std::cin >> num;
	std::cin.ignore();
	if (num >= min_num and num <= max_num)
		return num;
	else
		return default_num;
}

void startGame(){
	constexpr int MIN = 1;
	constexpr int MAX = 10;
	constexpr int DFL_LAND = 8;
	constexpr int DFL_ZOMBIE = 3;
	showTitle();
	std::cout << "Number of lands on the map (1-10, default: 8)...>";
	const int land_num = inputNum(MIN, MAX, DFL_LAND);
	std::cout << "Number of zombies on the map (1-10, default: 3)...>";
	const int zombie_num = inputNum(MIN, MAX, DFL_ZOMBIE);
	PlantFactory plant_factory;
	const int choice_num = plant_factory.readFile("plants.txt");
	showRules();
	std::cout << "Press enter key to continue...";
	std::cin.ignore();
	std::system("clear || cls");
	std::random_device rd;
	std::mt19937 gen = std::mt19937(rd());
	std::uniform_int_distribution<int> unif(0, land_num - 1);
	Map map(land_num);
	Player player(unif(gen), land_num);
	std::vector<Zombie> zombies;
	for (int i = 0; i < zombie_num; ++i)
		zombies.push_back(Zombie(i, unif(gen), land_num));
	std::vector<Plant*> current_plants = map.getPlants();
	int dead_bomb_num = 0;
	while (true){
		map.showMap(std::cout, player, zombies);
		if (map[player.getPos()].hasPlant())
			map[player.getPos()].getPlant().interactPlayer(std::cout, player, current_plants);
		else if (!player.hasMoney())
			std::cout << "You do not have enough money to plant anything!" << std::endl;
		else{
			while (true){
				std::cout << plant_factory << std::endl;
				std::cout << "Player $" << player.getMoney() << ":    Enter your choice (" << choice_num << " to give up, default: " << choice_num << ")...>";
				const int choice = inputNum(0, choice_num, choice_num);
				if (choice == choice_num){
					std::cout << "You give up!" << std::endl;
					break;
				}	
				map[player.getPos()].growPlant(plant_factory.createPlant(choice));
				if (player.getMoney() >= map[player.getPos()].getPlant().getCost()){
					player.setMoney(-map[player.getPos()].getPlant().getCost());
					std::cout << "You have planted " << map[player.getPos()].getPlant().getName() << " at land " << player.getPos() << " !" << std::endl;
					break;
				}
				map[player.getPos()].clear();
				std::cout << "Not enough money! Please input again!" << std::endl;
				std::cout << "Press enter key to continue...";
				std::cin.ignore();
			}
		}
		std::cout << "Press enter key to continue...";
		std::cin.ignore();
		current_plants = map.getPlants();
		if (current_plants.size() == 0){
			std::cout << std::endl << "Oh no... You have no plant on the map ...." << std::endl;
			std::cout << "Press enter key to continue...";
			std::cin.ignore();
			return;
		}
		std::system("clear || cls");
		for (auto &zombie: zombies){
			if (zombie.isAlive()){
				unif = std::uniform_int_distribution<int>(1, zombie.getMaxStep());
				zombie.move(unif(gen));
				map.showMap(std::cout, player, zombies);
				std::cout << "Zombie [" << zombie.getId() << "] moves to land " << zombie.getPos() << "." << std::endl;
				if (map[zombie.getPos()].hasPlant()){
					map[zombie.getPos()].getPlant().interactZombie(std::cout, zombie);
					if (!map[zombie.getPos()].getPlant().isAlive()){
						if (map[zombie.getPos()].getPlant().getType() == 'B')
							dead_bomb_num += 1;
						std::cout << "Plant " << map[zombie.getPos()].getPlant().getName() << " is dead!" << std::endl;
						map[zombie.getPos()].clear();
						current_plants = map.getPlants();
						if (current_plants.size() == 0){
							std::cout << "Press enter key to continue...";
							std::cin.ignore();
							std::cout << std::endl << "Oh no... You have no plant on the map ...." << std::endl;
							std::cout << "Press enter key to continue...";
							std::cin.ignore();
							return;
						}
					}
					if (dead_bomb_num > zombie_num / 2){
						std::cout << std::endl << "You lose the game since you cannot use that many bomb plants!" << std::endl;
						std::cout << "Press enter key to continue...";
						std::cin.ignore();
						return;
					}
					if (!zombie.isAlive())
						std::cout << "Zombie is killed!" << std::endl;
				}
				std::cout << "Press enter key to continue...";
				std::cin.ignore();
				std::system("clear || cls");
			}
		}
		bool no_zombie = true;
		for (auto &zombie: zombies){
			if (zombie.isAlive()){
				no_zombie = false;
				break;
			}
		}
		if (no_zombie){
			std::cout << std::endl << "Congratulations! You have killed all zombies!" << std::endl;
			std::cout << "Press enter key to continue...";
			std::cin.ignore();
			return;
		}
		unif = std::uniform_int_distribution<int>(1, player.getMaxStep());
		player.move(unif(gen));
	}
	return;
}
