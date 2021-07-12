#ifndef _ZOMBIE_
#define _ZOMBIE_

#include <iostream>
#include "creature.h"

class Zombie: public Creature{
public:
	static constexpr int DFL_DAMAGE = 15;
	static constexpr int DFL_HP = 40;
	static constexpr int MAX_STEP = 3;
	Zombie();
	Zombie(const int id, const int pos, const int land_num);
	~Zombie() = default;
	int getId() const;
	int getDamage() const;
	void setHp(const int diff);
	bool isAlive() const;
	friend std::ostream& operator<<(std::ostream &os, const Zombie &zombie);

private:
	const int id_ = 0;
	const int damage_ = 0;
	int hp_;
};

#endif