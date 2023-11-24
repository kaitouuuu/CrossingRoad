#ifndef BASE_H
#define BASE_H

#include <vector>

#include "Road.h"

class Base {
private:
	std::vector<Road> lanes;

public:
	Base();

	void randomGame(int difficulty);
	void playGame();
};

#endif // BASE_H
