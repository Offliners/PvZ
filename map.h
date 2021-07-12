#ifndef _MAP_
#define _MAP_

#include <iostream>
#include <vector>
#include "land.h"

class Map{
public:
	Map();
	Map(const int land_num);
	~Map();
	std::vector<Plant*> getPlants() const;
	void showMap(std::ostream &os, const Player &player, const std::vector<Zombie> &zombies) const;
	Land& operator[](const int index);

private:
	const int land_num_ = 0;
	std::vector<Land> lands_;
};

#endif