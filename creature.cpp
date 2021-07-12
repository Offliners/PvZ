#include "creature.h"

Creature::Creature(): pos_(0), max_step_(0), land_num_(0){}

Creature::Creature(const int pos, const int max_step, const int land_num): pos_(pos), max_step_(max_step), land_num_(land_num){}

int Creature::getPos() const{
	return this->pos_;
}

int Creature::getMaxStep() const{
	return this->max_step_;
}

void Creature::move(const int step){
	this->pos_ = (this->pos_ + step) % this->land_num_;
}