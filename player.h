#ifndef _PLAYER_
#define _PLAYER_

#include "creature.h"

class Player: public Creature{
public:
	static constexpr int DFL_MONEY = 150;
	static constexpr int MAX_STEP = 6;
	Player();
	Player(const int pos, const int land_num);
	~Player() = default;
	int getMoney() const;
	void setMoney(const int diff);
	bool hasMoney() const;

private:
	int money_ = 0;
};

#endif