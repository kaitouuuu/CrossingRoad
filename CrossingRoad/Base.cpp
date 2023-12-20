#include "Base.h"

Base::Base()
	: rng(std::chrono::steady_clock::now().time_since_epoch().count()) {}

// Get random integer in range [l, r]
int Base::randomNumber(int l, int r)
{
	return std::uniform_int_distribution<int>(l, r)(rng);
}

void Base::randomGame(int difficulty)
{
	const float widthLane = 54.0;
	const int numLane = 20;
	std::string allRoadType[] = {"Road", "Field", "Land"};
	std::string allObjectType[] = {"thintree", "bigtree"};
	float allObjectSize[] = {36.0, 48.0};

	// Initial road
	lanes.clear();
	Road newRoad = Road("Field", 0);
	lanes.push_back(newRoad);

	for (int i = 1; i < numLane - 1; ++i)
	{
		std::string type = allRoadType[randomNumber(0, 2)];

		// The harder the game the fewer Field type roads appear
		if (difficulty > 3 && type == "Field")
		{
			std::string type = allRoadType[randomNumber(0, 2)];
		}
		if (difficulty > 10 && type == "Field")
		{
			std::string type = allRoadType[randomNumber(0, 2)];
		}
		if (difficulty > 28 && type == "Field")
		{
			std::string type = allRoadType[randomNumber(0, 2)];
		}
		if (difficulty > 67 && type == "Field")
		{
			std::string type = allRoadType[randomNumber(0, 2)];
		}

		newRoad = Road(type, widthLane * i);

		if (type == "Road")
		{
			float speed = float(randomNumber(400 + std::min(difficulty * 200, 190000), 250000 + std::min(difficulty * 2500, 240000))) / 10000 + 60;
			float xPosition = float(randomNumber(960 - 250, 960 + 250));
			newRoad.initTrafficLight(xPosition, widthLane*i);
			if (lanes.back().getType() == "Road")
			{
				// Consecutive roads will have the same direction
				if (lanes.back().getSpeed() < 0)
				{
					speed = -speed;
				}
			}
			else
			{
				// Random vehicle direction
				if (randomNumber(0, 1))
				{
					speed = -speed;
				}
			}

			newRoad.setSpeed(speed);

			int numCar = min(1 + difficulty + randomNumber(0, difficulty), 18);

			for (int j = 1; j <= numCar; ++j)
			{
				int random = randomNumber(0, 2);
				if (random == 0) {
					Car1 newVehicle = Car1(float(randomNumber(0, 1919)), widthLane * i, "blue_car");
					newRoad.addVehicle(newVehicle);
				}
				else if (random == 1) {
					Car2 newVehicle = Car2(float(randomNumber(0, 1919)), widthLane * i, "blue_car");
					newRoad.addVehicle(newVehicle);
				}
				else if (random == 2) {
					Car3 newVehicle = Car3(float(randomNumber(0, 1919)), widthLane * i, "blue_car");
					newRoad.addVehicle(newVehicle);
				}
			}
		}

		if (type == "Field")
		{
			int numObj = randomNumber(0, std::max(0, difficulty - 1));

			for (int j = 1; j <= numObj; ++j)
			{
				int temp = randomNumber(0, 1);
				Object newObj = Object(float(randomNumber(0, 1919)), widthLane * i, allObjectSize[temp],
									   allObjectSize[temp], allObjectType[temp]);
				newRoad.addObject(newObj);
			}
		}

		if (type == "Land")
		{
			float speed = float(randomNumber(400 + std::min(difficulty * 200, 150000), 250000 + std::min(difficulty * 2500, 200000))) / 10000;

			// Random vehicle direction
			if (randomNumber(0, 1))
			{
				speed = -speed;
			}

			newRoad.setSpeed(speed);

			int numAnimal = difficulty + std::max(0, randomNumber(0, difficulty) - 1) - 1;

			for (int j = 1; j <= numAnimal; ++j)
			{
				int random = randomNumber(0, 4);
				if (random == 0) {
					Animal1 newAnimal = Animal1(float(randomNumber(0, 1919)), widthLane * i, "Cat");
					newRoad.addAnimal(newAnimal);
				}
				else if (random == 1) {
					Animal1 newAnimal = Animal1(float(randomNumber(0, 1919)), widthLane * i, "Dragonfly");
					newRoad.addAnimal(newAnimal);
				}
				else if (random == 2) {
					Animal1 newAnimal = Animal1(float(randomNumber(0, 1919)), widthLane * i, "Hedgehog");
					newRoad.addAnimal(newAnimal);
				}
				else if (random == 3) {
					Animal1 newAnimal = Animal1(float(randomNumber(0, 1919)), widthLane * i, "Porcupine");
					newRoad.addAnimal(newAnimal);
				}
				else if (random == 4) {
					Animal1 newAnimal = Animal1(float(randomNumber(0, 1919)), widthLane * i, "Fox");
					newRoad.addAnimal(newAnimal);
				}
			}
		}

		lanes.push_back(newRoad);
	}

	// Last road
	newRoad = Road("Field", widthLane * (numLane - 1));
	lanes.push_back(newRoad);
}

//Base::Base(std::mt19937_64 seed)
//	: rng(seed) {}
//
//void Base::printAll()
//{
//	for (Road &road : lanes)
//	{
//		road.printAll();
//		std::cout << "-------------" << std::endl;
//	}
//}
