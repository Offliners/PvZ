#ifndef _HORNPLANT_
#define _HORNPLANT_

#include <iostream>
#include <string>
#include "plant.h"
#include "zombie.h"

class HornPlant: public Plant{
public:
	HornPlant();
	HornPlant(const char type, const std::string name, const int cost, const int hp, const int damage);
	~HornPlant() = default;
	virtual void showEffect(std::ostream &os) const override;
	virtual void showStatus(std::ostream &os) const override;
	virtual void interactPlayer(std::ostream &os, Player &player, std::vector<Plant*> &plants) override;
	virtual void interactZombie(std::ostream &os, Zombie &zombie) override;

private:
	int damage_ = 0;
};

#endif