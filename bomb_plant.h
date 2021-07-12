#ifndef _BOMBPLANT_
#define _BOMBPLANT_

#include <iostream>
#include <string>
#include "plant.h"
#include "zombie.h"

class BombPlant: public Plant{
public:
	BombPlant();
	BombPlant(const char type, const std::string name, const int cost, const int damage);
	~BombPlant() = default;
	virtual void showEffect(std::ostream &os) const override;
	virtual void showStatus(std::ostream &os) const override;
	virtual void interactPlayer(std::ostream &os, Player &player, std::vector<Plant*> &plants) override;
	virtual void interactZombie(std::ostream &os, Zombie &zombie) override;

private:
	int damage_ = 0;
};

#endif