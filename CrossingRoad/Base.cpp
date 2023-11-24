#include "Base.h"

Base::Base()
	: rng(std::chrono::steady_clock::now().time_since_epoch().count()) {}

int Base::randomNumber(int l, int r) {
	return std::uniform_int_distribution<int>(l, r)(rng);
}

void Base::randomGame(int difficulty) {
	const float widthLane = 48.0;
	std::string allRoadType[] = { "Road", "Field" };
	std::string allObjectType[] = { "tree", "TREE" };
	int allObjectSize[] = { 36, 48 };

	lanes.clear();

	Road newRoad = Road("Road", widthLane);
	lanes.push_back(newRoad);

	for (int i = 2; i <= std::min(25 + difficulty * 4, 550); ++i) {
		std::string type = allRoadType[randomNumber(0, 1)];
		newRoad = Road(type, widthLane * i);

		if (type == "Road") {
			float speed = float(randomNumber(300, 250000 - difficulty * 1750)) / 10000;

			if (lanes.back().getType() == "Road") {
				if (lanes.back().getSpeed() > 0) {
					newRoad.setSpeed(speed);
				}
				else {
					newRoad.setSpeed(-speed);
				}
			}

			int numCar = 1 + difficulty + randomNumber(0, difficulty);

			for (int j = 1; j <= numCar; ++j) {
				Vehicle newCar = Vehicle(float(randomNumber(0, 1919)), widthLane * i, 48, 48, "Blue");
				newRoad.addCar(newCar);
			}
		}
		else {
			int numObj = randomNumber(0, difficulty - 1);

			for (int j = 1; j <= numObj; ++j) {
				int temp = randomNumber(0, 1);
				Object newObj = Object(float(randomNumber(0, 1919)), widthLane * i, allObjectSize[temp],
					allObjectSize[temp], allObjectType[temp]);
				newRoad.addObject(newObj);
			}
		}

		lanes.push_back(newRoad);
	}
}

Base::Base(std::mt19937_64 seed)
	: rng(seed) {}

void Base::printAll () {
	for (Road& road : lanes) {
		road.printAll();
		std::cout << "-------------" << std::endl;
	}
}