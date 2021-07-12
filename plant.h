#ifndef _PLANT_
#define _PLANT_

#include <iostream>
#include <string>
#include <vector>
#include "player.h"
#include "zombie.h"


class Plant{
public:
	Plant();
	Plant(const char type, const std::string name, const int cost, const int hp);
	virtual ~Plant() = default;
	char getType() const;
	std::string getName() const;
	int getCost() const;
	int getHp() const;
	void setHp(const int diff);
	bool isAlive() const;
	int getPos() const;
	void setPos(const int pos);
	virtual void showEffect(std::ostream &os) const = 0;
	virtual void showStatus(std::ostream &os) const = 0;
	virtual void interactPlayer(std::ostream &os, Player &player, std::vector<Plant*> &plants);
	virtual void interactZombie(std::ostream &os, Zombie &zombie);
	friend std::ostream& operator<<(std::ostream &os, const Plant &plant);

private:
	const char type_ = 0;
	const std::string name_ = "";
	const int cost_ = 0;
	const int max_hp_ = 0;
	int hp_ = 0;
	int pos_ = 0;
};

#endif