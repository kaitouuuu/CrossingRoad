#include "Base.h"

Base::Base()
	: rng(std::chrono::steady_clock::now().time_since_epoch().count()) {}

// Get random integer in range [l, r]
int Base::randomNumber(int l, int r)
{
	return std::uniform_int_distribution<int>(l, r)(rng);
}

// TODO: Random traffic light
void Base::randomGame(int difficulty)
{
	const float widthLane = 54.0;
	const int numLane = 20;
	std::string allRoadType[] = {"Road", "Field", "Land"};
	std::string allObjectType[] = {"thin_tree", "big_tree"};
	float allObjectSize[] = {36.0, 48.0};

	// Initial road
	lanes.clear();
	Road newRoad = Road("Field", widthLane);
	lanes.push_back(newRoad);

	for (int i = 2; i < numLane; ++i)
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
			float speed = float(randomNumber(400 + std::min(difficulty * 200, 150000), 250000 + std::min(difficulty * 2500, 200000))) / 10000;
			float xPosition = float(randomNumber(960 - 250, 960 + 250));
			TrafficLight newTrafficLight(xPosition, widthLane * i);
			std::cout << newTrafficLight.getX() << " " << newTrafficLight.getY() << std::endl;
			newRoad.setTrafficLight(0);
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

			int numCar = 1 + difficulty + randomNumber(0, difficulty);

			for (int j = 1; j <= numCar; ++j)
			{
				Vehicle newVehicle = Vehicle(float(randomNumber(0, 1919)), widthLane * i, 48, 48, "blue_car");
				newRoad.addVehicle(newVehicle);
			}
		    //std::cout << "Road created" << std::endl;
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
				Vehicle newAnimal = Vehicle(float(randomNumber(0, 1919)), widthLane * i, 48, 48, "brown_dog");
				newRoad.addVehicle(newAnimal);
			}
		}

		lanes.push_back(newRoad);
	}

	// Last road
	newRoad = Road("Field", widthLane);
	lanes.push_back(newRoad);
}

// TODO: Testing with Character
void Base::playGame(int difficulty)
{
	int numStage = 1 + std::min(std::min(difficulty, 6) + difficulty / 12, 24);
	std::cout << 11 << numStage << std::endl;
	Character champ("Character1.png", 960.f, 1070.f, true, false);
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Crossing Road");
	sf::Clock clock;
	for (int i = 1; i <= numStage; ++i)
	{
		if (i < numStage / 4)
		{
			randomGame(std::max(difficulty - 1, 1));
		}
		else if (i == numStage)
		{
			randomGame(difficulty + 1);
		}
		else
		{
			randomGame(difficulty);
		}
		champ.update(clock, lanes[champ.getY() / 54]);
		// if (champ.getCondition())
		// For debug
		printAll();
		int temp;
		std::cin >> temp;
	}
}

Base::Base(std::mt19937_64 seed)
	: rng(seed) {}

void Base::printAll()
{
	for (Road &road : lanes)
	{
		road.printAll();
		std::cout << "-------------" << std::endl;
	}
}
