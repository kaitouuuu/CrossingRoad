#include "Road.h"

Road::Road()
	: type(""), yPos(0), hasTrafficLight(false), trafficLightColor(0), speed(0)
{
	cars.clear();
	objects.clear();
}

Road::Road(std::string type, float yPos)
	: type(type), yPos(yPos), hasTrafficLight(false), trafficLightColor(0), speed(0)
{
	cars.clear();
	objects.clear();
}

std::string Road::getType() const
{
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

void Road::setSpeed(const float s) {
	speed = s;
}

void Road::setTrafficLight(const int color) {
	hasTrafficLight = true;
	trafficLightColor = color;
}

void Road::addCar(const Vehicle& addedCar)
{
	for (Vehicle& car : cars) {
		float carX = car.getX();
		float carX2 = carX + car.getWidth();
		float addedCarX = addedCar.getX();
		float addedCarX2 = addedCarX + addedCar.getWidth();

		if (carX <= addedCarX && addedCarX <= carX2 || addedCarX <= carX && carX <= addedCarX2) {
			return;
		}
	}

	cars.push_back(addedCar);
}

void Road::updateCars()
{
	for (Vehicle& car : cars)
	{
		car.updatePosition(speed);
	}
}

void Road::addObject(const Object& addedObject) {
	for (Object& object : objects) {
		float objX = object.getX();
		float objX2 = objX + object.getWidth();
		float addedObjX = addedObject.getX();
		float addedObjX2 = addedObjX + addedObject.getWidth();

		if (objX <= addedObjX && addedObjX <= objX2 || addedObjX <= objX && objX <= addedObjX2) {
			return;
		}
	}

	objects.push_back(addedObject);
}

void Road::setY(const float y) {
	yPos = y;
}

void Road::setType(const std::string t) {
	type = t;
}

void Road::printAll() {
	std::cout << type << std::endl;
	std::cout << "Car: ";

	for (Vehicle& car : cars)
	{
		std::cout << car.getX() << ":" << car.getY() << " ";
	}

	std::cout << std::endl << "Object: ";

	for (Object& object : objects) {
		std::cout << object.getX() << ":" << object.getY() << " ";
	}

	std::cout << std::endl;
}