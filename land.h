#ifndef _LAND_
#define _LAND_

#include <iostream>
#include <vector>
#include "plant.h"

class Land{
public:
	Land();
	Land(const int index);
	~Land();
	Plant& getPlant() const;
	bool hasPlant() const;
	void growPlant(Plant *plant);
	void clear();
	void showLand(std::ostream &os, const bool has_player, const std::vector<Zombie> &zombies) const;

private:
	int index_ = 0;
	Plant *plant_ = nullptr;
};

#endif