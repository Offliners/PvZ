#include "player.h"

Player::Player(): money_(0), Creature(){}

Player::Player(const int pos, const int land_num): money_(DFL_MONEY), Creature(pos, MAX_STEP, land_num){}

int Player::getMoney() const{
	return this->money_;
}

void Player::setMoney(int diff){
	this->money_ += diff;
}

bool Player::hasMoney() const{
	return this->money_ > 0;
}