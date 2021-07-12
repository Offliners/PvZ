#ifndef _COINPLANT_
#define _COINPLANT_

#include <iostream>
#include <string>
#include "plant.h"
#include "player.h"
#include "zombie.h"

class CoinPlant: public Plant{
public:
	CoinPlant();
	CoinPlant(const char type, const std::string name, const int cost, const int hp, const int visit, const int reward);
	~CoinPlant() = default;
	virtual void showEffect(std::ostream &os) const override;
	virtual void showStatus(std::ostream &os) const override;
	virtual void interactPlayer(std::ostream &os, Player &player, std::vector<Plant*> &plants) override;
	virtual void interactZombie(std::ostream &os, Zombie &zombie) override;

private:
	int need_visit_ = 0;
	int left_visit_ = 0;
	int reward_ = 0;
};

#endif