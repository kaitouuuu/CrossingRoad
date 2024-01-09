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
    std::vector<TrafficLight> lights;
	Base();

	int randomNumber(int l, int r);

	void randomGame(int difficulty, bool& fromSave, std::string saveType[], float saveSpeed[], int saveNum[]);
};

#endif // BASE_H
