#include "Base.h"

Base::Base()
	: rng(std::chrono::steady_clock::now().time_since_epoch().count()) {}

// Get random integer in range [l, r]
int Base::randomNumber(int l, int r)
{
	if (l <= r)
	{
		return std::uniform_int_distribution<int>(l, r)(rng);
	}
	return 0;
}

void Base::randomGame(int difficulty, bool& fromSave, std::string saveType[], float saveSpeed[], int saveNum[])
{
	const float widthLane = 54.0;
	const int numLane = 20;
	std::string allRoadType[] = { "Road", "Field", "Land" };
	std::string allObjectType[] = { "big1", "big2", "square1", "square2", "square3", "square4", "square5", "square6", "vertical1" };

	if (fromSave == true)
	{
		fromSave = false;
		lanes.clear();
		Road newRoad;
		for (int i = 0; i < numLane; ++i)
		{
			newRoad = Road(saveType[i], i * widthLane);
			if (saveType[i] == "Road")
			{
				float speed = float(randomNumber(400 + std::min(difficulty * 200, 190000), 250000 + std::min(difficulty * 2500, 240000))) / 10000 + 60;
				float xPosition = float(randomNumber(960 - 321, 960 + 321));
				newRoad.initTrafficLight(xPosition, widthLane * i);
			}
			if (saveType[i] != "Field")
			{
				newRoad.setSpeed(saveSpeed[i]);
			}
			if (saveType[i] == "Road")
			{
				while (newRoad.vehicles.size() < saveNum[i])
				{
					int random = randomNumber(0, 4);
					if (random == 0)
					{
						Car1* newVehicle = new Car1(float(randomNumber(0, 1919)), widthLane * i);
						newRoad.addVehicle(newVehicle);
					}
					else if (random == 1)
					{
						Car2* newVehicle = new Car2(float(randomNumber(0, 1919)), widthLane * i);
						newRoad.addVehicle(newVehicle);
					}
					else if (random == 2)
					{
						Car3* newVehicle = new Car3(float(randomNumber(0, 1919)), widthLane * i);
						newRoad.addVehicle(newVehicle);
					}
					else if (random == 3)
					{
						Car4* newVehicle = new Car4(float(randomNumber(0, 1919)), widthLane * i);
						newRoad.addVehicle(newVehicle);
					}
					else if (random == 4)
					{
						Car5* newVehicle = new Car5(float(randomNumber(0, 1919)), widthLane * i);
						newRoad.addVehicle(newVehicle);
					}
				}
			}
			else if (saveType[i] == "Field")
			{
				while (newRoad.objects.size() < saveNum[i])
				{
					int temp = randomNumber(0, 8);
					Object* newObj = new Object(float(randomNumber(0, 1919)), widthLane * i, allObjectType[temp]);
					newRoad.addObject(newObj);
				}
			}
			else
			{
				while (newRoad.animals.size() < saveNum[i])
				{
					int random = randomNumber(0, 4);
					if (random == 0)
					{
						Animal1* newAnimal = new Animal1(float(randomNumber(0, 1919)), widthLane * i);
						newRoad.addAnimal(newAnimal);
					}
					else if (random == 1)
					{
						Animal2* newAnimal = new Animal2(float(randomNumber(0, 1919)), widthLane * i);
						newRoad.addAnimal(newAnimal);
					}
					else if (random == 2)
					{
						Animal3* newAnimal = new Animal3(float(randomNumber(0, 1919)), widthLane * i);
						newRoad.addAnimal(newAnimal);
					}
					else if (random == 3)
					{
						Animal4* newAnimal = new Animal4(float(randomNumber(0, 1919)), widthLane * i);
						newRoad.addAnimal(newAnimal);
					}
					else if (random == 4)
					{
						Animal5* newAnimal = new Animal5(float(randomNumber(0, 1919)), widthLane * i);
						newRoad.addAnimal(newAnimal);
					}
				}
			}

			lanes.push_back(newRoad);
		}
		return;
	}

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
			type = allRoadType[randomNumber(0, 2)];
		}

		if (difficulty > 10 && type == "Field")
		{
			type = allRoadType[randomNumber(0, 2)];
		}

		if (difficulty > 28 && type == "Field")
		{
			type = allRoadType[randomNumber(0, 2)];
		}

		if (difficulty > 67 && type == "Field")
		{
			type = allRoadType[randomNumber(0, 2)];
		}

		if (i == 1 || i == numLane - 2)
		{
			type = "Field";
		}

		newRoad = Road(type, widthLane * i);

		if (type == "Road")
		{
			float speed = float(randomNumber(400 + std::min(difficulty * 200, 190000), 250000 + std::min(difficulty * 2500, 240000))) / 10000 + 60;
			float xPosition = float(randomNumber(960 - 321, 960 + 321));
			newRoad.initTrafficLight(xPosition, widthLane * i);
			if (randomNumber(0, 1))
			{
				speed = -speed;
			}
			if (difficulty <= 10)
			{
				if (lanes.back().getType() == "Road")
				{
					// Consecutive roads will have the same direction
					if (lanes.back().getSpeed() < 0)
					{
						speed = -speed;
					}
				}
			}

			newRoad.setSpeed(speed);

			int numCar = std::min(1 + difficulty / 10 + randomNumber(0, difficulty / 3), 16);

			for (int j = 1; j <= numCar; ++j)
			{
				int random = randomNumber(0, 4);
				if (random == 0)
				{
					Car1* newVehicle = new Car1(float(randomNumber(0, 1919)), widthLane * i);
					newRoad.addVehicle(newVehicle);
				}
				else if (random == 1)
				{
					Car2* newVehicle = new Car2(float(randomNumber(0, 1919)), widthLane * i);
					newRoad.addVehicle(newVehicle);
				}
				else if (random == 2)
				{
					Car3* newVehicle = new Car3(float(randomNumber(0, 1919)), widthLane * i);
					newRoad.addVehicle(newVehicle);
				}
				else if (random == 3)
				{
					Car4* newVehicle = new Car4(float(randomNumber(0, 1919)), widthLane * i);
					newRoad.addVehicle(newVehicle);
				}
				else if (random == 4)
				{
					Car5* newVehicle = new Car5(float(randomNumber(0, 1919)), widthLane * i);
					newRoad.addVehicle(newVehicle);
				}
			}
		}

		if (type == "Field")
		{
			int numObj = randomNumber(std::min(std::min(difficulty / 10, 6), std::min(14, randomNumber(0, std::max(0, difficulty - 1)))), std::min(14, randomNumber(0, std::max(0, difficulty - 1))));

			for (int j = 1; j <= numObj; ++j)
			{
				int temp = randomNumber(0, 8);
				Object* newObj = new Object(float(randomNumber(0, 1919)), widthLane * i, allObjectType[temp]);
				newRoad.addObject(newObj);
			}
		}

		if (type == "Land")
		{
			float speed = float(randomNumber(600 + std::min(difficulty * 200, 150000), 250000 + std::min(difficulty * 2500, 200000))) / 10000;

			// Random vehicle direction
			if (randomNumber(0, 1))
			{
				speed = -speed;
			}

			newRoad.setSpeed(speed);

			int numAnimal = std::min(15, std::max(0, randomNumber(0, difficulty / 3) - 1));

			for (int j = 1; j <= numAnimal; ++j)
			{
				int random = randomNumber(0, 4);
				if (random == 0)
				{
					Animal1* newAnimal = new Animal1(float(randomNumber(0, 1919)), widthLane * i);
					newRoad.addAnimal(newAnimal);
				}
				else if (random == 1)
				{
					Animal2* newAnimal = new Animal2(float(randomNumber(0, 1919)), widthLane * i);
					newRoad.addAnimal(newAnimal);
				}
				else if (random == 2)
				{
					Animal3* newAnimal = new Animal3(float(randomNumber(0, 1919)), widthLane * i);
					newRoad.addAnimal(newAnimal);
				}
				else if (random == 3)
				{
					Animal4* newAnimal = new Animal4(float(randomNumber(0, 1919)), widthLane * i);
					newRoad.addAnimal(newAnimal);
				}
				else if (random == 4)
				{
					Animal5* newAnimal = new Animal5(float(randomNumber(0, 1919)), widthLane * i);
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
