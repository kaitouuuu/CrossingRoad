#ifndef BASE_H
#define BASE_H

#include <vector>
#include <random>
#include <chrono>

#include "Road.h"

class Base {
private:
	std::vector<Road> lanes;
	std::mt19937_64 rng;

public:
	Base();

	int randomNumber(int l, int r);

	void randomGame(int difficulty);
	void playGame();

	// For debug
	Base(std::mt19937_64 seed);
	void printAll();
};

#endif // BASE_H
