#include "map.h"

Map::Map(): land_num_(0){
	this->lands_.clear();
}

Map::Map(const int land_num): land_num_(land_num){
	this->lands_ = std::vector<Land>(land_num);
	for (int i = 0; i < land_num; ++i)
		this->lands_[i] = Land(i);
}

Map::~Map(){
	this->lands_.clear();
}

std::vector<Plant*> Map::getPlants() const{
	std::vector<Plant*> plants;
	for (auto &land: this->lands_){
		if (land.hasPlant())
			plants.push_back(&land.getPlant());
	}
	return plants;
}

void Map::showMap(std::ostream &os, const Player &player, const std::vector<Zombie> &zombies) const{
	for (int i = 0; i < this->land_num_; ++i){
		os << "[" << i << "]";
		this->lands_[i].showLand(os, (i == player.getPos()), zombies);
		os << std::endl;
	}
	os << "------------------------------------------------" << std::endl;
	os << "Zombie information:" << std::endl;
	for (auto &zombie: zombies){
		if (zombie.isAlive())
			os << zombie << std::endl;
	}
	os << "================================================" << std::endl;
}

Land& Map::operator[](const int index){
	return this->lands_[index];
}