#include "Base.h"

Base::Base()
	: rng(std::chrono::steady_clock::now().time_since_epoch().count()) {}

int Base::randomNumber(int l, int r) {
	return std::uniform_int_distribution<int>(l, r)(rng);
}

void Base::randomGame(int difficulty) {
	const float widthLane = 48.0;
	std::string allRoadType[] = { "Road", "Field" };

	lanes.clear();

	Road newRoad = Road("Road", widthLane);
	lanes.push_back(newRoad);

	for (int i = 2; i <= 25 + difficulty * 5; ++i) {
		std::string type = allRoadType[randomNumber(0, 1)];

		if (type == "Road") {
			float speed = float(randomNumber(300, 250000)) / 10000;

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
				Vehicle newCar = Vehicle(float(randomNumber(0, 1919)), i * widthLane, 48, 48, "Blue");
				newRoad.addCar(newCar);
			}
		}

		lanes.push_back(newRoad);
	}
}

Base::Base(std::mt19937_64 seed)
	: rng(seed) {}