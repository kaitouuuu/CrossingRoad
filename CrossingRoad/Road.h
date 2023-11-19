#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include <deque>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "Vehicle.h"

class Road {
private:
	float yPos;
	bool hasTrafficLight;
	sf::Color trafficLightColor;
	float speed;
	std::deque<Vehicle> cars;

public:
	Road(float yPos, bool hasTrafficLight, sf::Color trafficLightColor, float speed);

	float getYPosition() const;
	bool getHasTrafficLight() const;
	sf::Color getTrafficLightColor() const;
	float getSpeed() const;

	void addCar(const Vehicle& car);
	void updateCars();

	// For debug
	void printCar();
};

#endif // ROAD_H
