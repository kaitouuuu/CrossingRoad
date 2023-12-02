#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include <string>
#include <vector>

#include "Object.h"

class Road {
private:
	std::string type;
	float yPos;
	bool hasTrafficLight;
	int trafficLightColor; // 0: Green, 1: Yellow, 2: Red
	float speed;
	std::vector<Object> objects;

public:
	Road();
	Road(std::string type, float yPos);

	std::string getType() const;
	float getY() const;
	bool getHasTrafficLight() const;
	int getTrafficLightColor() const;
	float getSpeed() const;
	void setSpeed(const float s);
	void setTrafficLight(const int color);

	void addObject(const Object& added);
	void updateObjects();

	// For debug
	void setY(const float y);
	void setType(const std::string t);
	void printAll();
};

#endif // ROAD_H
