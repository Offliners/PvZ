#ifndef _PLANTFACTORY_
#define _PLANTFACTORY_

#include <iostream>
#include <string>
#include <vector>
#include "plant.h"

class PlantFactory{
public:
	PlantFactory();
	~PlantFactory();
	int readFile(const std::string &filename);
	Plant* createPlant(const int index) const;
	friend std::ostream& operator<<(std::ostream &os, const PlantFactory &pf);

private:
	std::vector<Plant*> plants_;
};

#endif
