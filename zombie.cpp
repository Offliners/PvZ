#include "zombie.h"

Zombie::Zombie(): id_(0), damage_(0), hp_(0), Creature(){}

Zombie::Zombie(const int id, const int pos, const int land_num): id_(id), damage_(DFL_DAMAGE), hp_(DFL_HP), Creature(pos, MAX_STEP, land_num){}

int Zombie::getId() const{
	return this->id_;
}

int Zombie::getDamage() const{
	return this->damage_;
}

void Zombie::setHp(const int diff){
	this->hp_ += diff;
}

bool Zombie::isAlive() const{
	return this->hp_ > 0;
}

std::ostream& operator<<(std::ostream &os, const Zombie &zombie){
	os << "[" << zombie.id_ << "] Damage: " << zombie.damage_ << " HP:";
	for (int i = 0; i < zombie.hp_; ++i)
		os << "*" ;
	return os;
}