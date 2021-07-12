#include "coin_plant.h"

CoinPlant::CoinPlant(): need_visit_(0), left_visit_(0), reward_(0), Plant(){}

CoinPlant::CoinPlant(const char type, const std::string name, const int cost, const int hp, const int visit, const int reward): need_visit_(visit), left_visit_(visit), reward_(reward), Plant(type, name, cost, hp){}

void CoinPlant::showEffect(std::ostream &os) const{
	os << this->getName() << " $" << this->getCost() << " HP: " << this->getHp() << " - gives $" << this->reward_ << " every " << this->need_visit_ << " rounds";
}

void CoinPlant::showStatus(std::ostream &os) const{
	os << this->getName() << " HP: " << this->getHp() << " (" << this->left_visit_ << " more visit";
	if (this->left_visit_ > 1)
		os << "s";
	os << ")";
}

void CoinPlant::interactPlayer(std::ostream &os, Player &player, std::vector<Plant*> &plants){
	this->left_visit_ -= 1;
	if (this->left_visit_ == 0){
		left_visit_ = need_visit_;
		player.setMoney(+this->reward_);
		os << "You have earned $" << this->reward_ << "! Now you have $" << player.getMoney() << "." << std::endl;
	}
	else
		os << "You still need " << this->left_visit_ << " visit(s) to earn money." << std::endl;
}

void CoinPlant::interactZombie(std::ostream &os, Zombie &zombie){
	this->setHp(-zombie.getDamage());
	os << "Zombie eats plant " << this->getName() << " and causes damage " << zombie.getDamage() << "." << std::endl;
}