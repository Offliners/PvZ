#include "heal_plant.h"

HealPlant::HealPlant(): heal_(0), Plant(){}

HealPlant::HealPlant(const char type, const std::string name, const int cost, const int hp, const int heal): heal_(heal), Plant(type, name, cost, hp){}

void HealPlant::showEffect(std::ostream &os) const{
	os << this->getName() << " $" << this->getCost() << " HP: " << this->getHp() << " - gives all your plants " << this->heal_ << " HP back.";
}

void HealPlant::showStatus(std::ostream &os) const{
	os << this->getName() << " HP: " << this->getHp();
}

void HealPlant::interactPlayer(std::ostream &os, Player &player, std::vector<Plant*> &plants){
	for (auto &plant: plants)
		plant->setHp(+this->heal_);
	os << "All your plants have recovered " << this->heal_ << " HP!" << std::endl;
}

void HealPlant::interactZombie(std::ostream &os, Zombie &zombie){
	this->setHp(-zombie.getDamage());
	os << "Zombie eats plant " << this->getName() << " and causes damage " << zombie.getDamage() << "." << std::endl;
}