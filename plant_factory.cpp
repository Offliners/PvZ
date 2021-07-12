#include <fstream>
#include <cstring>
#include <cstddef>
#include "plant_factory.h"
#include "coin_plant.h"
#include "horn_plant.h"
#include "bomb_plant.h"
#include "heal_plant.h"

PlantFactory::PlantFactory(){
	this->plants_.clear();
}

PlantFactory::~PlantFactory(){
	for (auto p: this->plants_)
		delete p;
	this->plants_.clear();
}

int PlantFactory::readFile(const std::string &filename){
	std::ifstream plants_file(filename);
	if (!plants_file){
		std::cout << filename << " cannot be opened!" << std::endl;
		return 0;
	}
	char type = 0;
	while (plants_file.get(type)){
		std::string name = "";
		char temp = 0;
		int cost = 0;
		int hp = 0;
		int visit = 0;
		int reward = 0;
		int damage = 0;
		int heal = 0;
		switch(type){
			case 'C':
				plants_file >> name >> temp >> cost >> hp >> visit >> reward;
				this->plants_.push_back(new CoinPlant(type, name, cost, hp, visit, reward));
				break;
			case 'S':
				plants_file >> name >> temp >> cost >> hp >> damage;
				this->plants_.push_back(new HornPlant(type, name, cost, hp, damage));
				break;
			case 'B':
				plants_file >> name >> temp >> cost >> hp;
				this->plants_.push_back(new BombPlant(type, name, cost, hp));
				break;
			case 'H':
				plants_file >> name >> temp >> cost >> hp >> heal;
				this->plants_.push_back(new HealPlant(type, name, cost, hp, heal));
				break;
		}
	}
	return this->plants_.size();
}

Plant* PlantFactory::createPlant(const int index) const{
	Plant *new_plant = nullptr;
	switch(this->plants_[index]->getType()){
		case 'C':
			new_plant = new CoinPlant();
			std::memcpy(new_plant, this->plants_[index], sizeof(CoinPlant));
			break;
		case 'S':
			new_plant = new HornPlant();
			std::memcpy(new_plant, this->plants_[index], sizeof(HornPlant));
			break;
		case 'B':
			new_plant = new BombPlant();
			std::memcpy(new_plant, this->plants_[index], sizeof(BombPlant));
			break;
		case 'H':
			new_plant = new HealPlant();
			std::memcpy(new_plant, this->plants_[index], sizeof(HealPlant));
			break;
	}
	return new_plant;
}

std::ostream& operator<<(std::ostream &os, const PlantFactory &plant_factory){
	for (std::size_t i = 0; i < plant_factory.plants_.size(); ++i){
		os << "[" << i << "] ";
		plant_factory.plants_[i]->showEffect(os);
		os << std::endl;
	}
	return os;
}
