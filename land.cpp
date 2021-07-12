#include "land.h"

Land::Land(): index_(0), plant_(nullptr){}

Land::Land(const int index): index_(index), plant_(nullptr){}

Land::~Land(){
	if (this->plant_ != nullptr)
		this->clear();
}

Plant& Land::getPlant() const{
	return *(this->plant_);
}

bool Land::hasPlant() const{
	return this->plant_ != nullptr;
}

void Land::growPlant(Plant *plant){
	this->plant_ = plant;
	plant_->setPos(this->index_);
}

void Land::clear(){
	delete this->plant_;
	this->plant_ = nullptr;
}

void Land::showLand(std::ostream &os, const bool has_player, const std::vector<Zombie> &zombies) const{
	os << "{";
	if (has_player)
		os << "*";
	else
		os << " ";
	for (auto &zombie: zombies){
		if (zombie.isAlive()){
			if (this->index_ == zombie.getPos())
				os << zombie.getId();
			else
				os << " ";
		}
	}
	os << "}";
	if (this->plant_ == nullptr)
		os << "Empty";
	else
		os << *(this->plant_);
}