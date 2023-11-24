#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include <deque>
#include <algorithm>

#include "Vehicle.h"
#include "Object.h"

class Road {
private:
	std::string type;
	float yPos;
	bool hasTrafficLight;
	int trafficLightColor; // 0: Green, 1: Yellow, 2: Red
	float speed;
	std::deque<Vehicle> cars;
	std::vector<Object> objects;

public:
	Road();

	std::string getTypeRoad() const;
	float getY() const;
	bool getHasTrafficLight() const;
	int getTrafficLightColor() const;
	float getSpeed() const;

	void addCar(const Vehicle& car);
	void updateCars();

	// For debug
	void printCar();
};

#endif // ROAD_H
