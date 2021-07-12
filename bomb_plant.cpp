#include "bomb_plant.h"

BombPlant::BombPlant(): damage_(0), Plant(){}

BombPlant::BombPlant(const char type, const std::string name, const int cost, const int damage): damage_(damage), Plant(type, name, cost, damage){}

void BombPlant::showEffect(std::ostream &os) const{
	os << this->getName() << " $" << this->getCost() << " HP: " << this->getHp() << " - gives " << this->damage_ << " damage points";
}

void BombPlant::showStatus(std::ostream &os) const{
	os << this->getName() << " HP: " << this->getHp();
}

void BombPlant::interactPlayer(std::ostream &os, Player &player, std::vector<Plant*> &plants){
	os << "Your " << this->getName() << " is guarding your land." << std::endl;
}

void BombPlant::interactZombie(std::ostream &os, Zombie &zombie){
	zombie.setHp(-this->damage_);
	os << this->getName() << " gives " << this->damage_ << " damage to the zombie!" << std::endl;
	this->setHp(-this->damage_);
	os << "Zombie eats plant " << this->getName() << " and causes damage " << zombie.getDamage() << "." << std::endl;
}