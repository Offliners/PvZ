#include "horn_plant.h"

HornPlant::HornPlant(): damage_(0), Plant(){}

HornPlant::HornPlant(const char type, const std::string name, const int cost, const int hp, const int damage): damage_(damage), Plant(type, name, cost, hp){}

void HornPlant::showEffect(std::ostream &os) const{
	os << this->getName() << " $" << this->getCost() << " HP: " << this->getHp() << " - gives " << this->damage_ << " damage points";
}

void HornPlant::showStatus(std::ostream &os) const{
	os << this->getName() << " HP: " << this->getHp();
}

void HornPlant::interactPlayer(std::ostream &os, Player &player, std::vector<Plant*> &plants){
	os << "Your " << this->getName() << " is guarding your land." << std::endl;
}

void HornPlant::interactZombie(std::ostream &os, Zombie &zombie){
	zombie.setHp(-this->damage_);
	os << this->getName() << " gives " << this->damage_ << " damage to the zombie!" << std::endl;
	if (zombie.isAlive()){
		this->setHp(-zombie.getDamage());
		os << "Zombie eats plant " << this->getName() << " and causes damage " << zombie.getDamage() << "." << std::endl;
	}
}