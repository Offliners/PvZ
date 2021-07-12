#ifndef _HEALPLANT_
#define _HEALPLANT_

#include <iostream>
#include <string>
#include <vector>
#include "plant.h"
#include "player.h"
#include "zombie.h"

class HealPlant: public Plant{
public:
	HealPlant();
	HealPlant(const char type, const std::string name, const int cost, const int hp, const int heal);
	~HealPlant() = default;
	virtual void showEffect(std::ostream &os) const override;
	virtual void showStatus(std::ostream &os) const override;
	virtual void interactPlayer(std::ostream &os, Player &player, std::vector<Plant*> &plants) override;
	virtual void interactZombie(std::ostream &os, Zombie &zombie) override;

private:
	int heal_ = 0;
};

#endif