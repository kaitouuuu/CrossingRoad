#include "Road.h"

Road::Road()
	: type(false), yPos(0), hasTrafficLight(false), trafficLightColor(0), speed(0) {}

bool Road::getTypeRoad() const {
	return type;
}

float Road::getY() const
{
	return yPos;
}

bool Road::getHasTrafficLight() const
{
	return hasTrafficLight;
}

int Road::getTrafficLightColor() const
{
	return trafficLightColor;
}

float Road::getSpeed() const
{
	return speed;
}

void Road::addCar(const Vehicle& addedCar)
{
	cars.push_back(addedCar);

	for (int i = 0; i < cars.size(); ++i)
	{
		if (cars[i].getX() > addedCar.getX())
		{
			std::swap(cars[i], cars.back());
			break;
		}
	}
}

void Road::updateCars()
{
	bool deleteCarFront = false;
	bool deleteCarBack = false;
	Vehicle rotateCar;

	for (Vehicle& car : cars)
	{
		car.updatePosition(speed);
		if (car.getX() >= 1920)
		{
			rotateCar = car;
			deleteCarBack = true;
		}
		if (car.getX() < 0)
		{
			rotateCar = car;
			deleteCarFront = true;
		}
	}

	if (deleteCarBack == true)
	{
		cars.pop_back();
		rotateCar.rotatePosition(false);
		cars.push_front(rotateCar);
	}

	if (deleteCarFront == true)
	{
		cars.pop_front();
		rotateCar.rotatePosition(true);
		cars.push_back(rotateCar);
	}
}

void Road::printCar() {
	for (Vehicle& car : cars)
	{
		std::cout << car.getX() << " " << car.getY() << " ";
	}
	std::cout << std::endl;
}
