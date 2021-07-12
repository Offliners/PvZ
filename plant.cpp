#include "plant.h"

Plant::Plant(): type_(0), name_(""), cost_(0), hp_(0), max_hp_(0){}

Plant::Plant(const char type, const std::string name, const int cost, const int hp): type_(type), name_(name), cost_(cost), hp_(hp), max_hp_(hp){}

char Plant::getType() const{
	return this->type_;
}

std::string Plant::getName() const{
	return this->name_;
}

int Plant::getCost() const{
	return this->cost_;
}

int Plant::getHp() const{
	return this->hp_;
}

void Plant::setHp(const int diff){
	this->hp_ += diff;
	if (this->hp_ > this->max_hp_)
		this->hp_ = this->max_hp_;
}

bool Plant::isAlive() const{
	return this->hp_ > 0;
}

int Plant::getPos() const{
	return this->pos_;
}

void Plant::setPos(const int pos){
	this->pos_ = pos;
}

void Plant::interactPlayer(std::ostream &os, Player &player, std::vector<Plant*> &plants){
	return;
}

void Plant::interactZombie(std::ostream &os, Zombie &zombie){
	return;
}

std::ostream& operator<<(std::ostream &os, const Plant &plant){
	plant.showStatus(os);
	return os;
}