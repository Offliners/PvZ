#ifndef _CREATURE_
#define _CREATURE_

#include <random>

class Creature{
public:
	Creature();
	Creature(const int pos, const int max_step, const int land_num);
	~Creature() = default;
	int getPos() const;
	int getMaxStep() const;
	void move(const int step);

private:
	const int max_step_ = 0;
	const int land_num_ = 0;
	int pos_ = 0;
};

#endif
