#ifndef BASE_H
#define BASE_H

#include <vector>
#include <random>
#include <chrono>

#include "Character.h"
#include "Road.h"

class Base {
private:
	std::mt19937_64 rng;
	

public:
	std::vector<Road> lanes;

	Base();

	int randomNumber(int l, int r);

	void randomGame(int difficulty);
	void playGame(int difficulty, int stage, RenderWindow& window);

	//// For debug
	//Base(std::mt19937_64 seed);
	//void printAll();
};

#endif // BASE_H
