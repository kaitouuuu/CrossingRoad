#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include <string>
#include <vector>

#include "Object.h"
#include "Vehicle.h"
#include "TrafficLight.h"

class Road {
private:
	std::string type;
	float yPos;
	bool hasTrafficLight;
	int trafficLightColor; // 0: Green, 1: Yellow, 2: Red
	float speed;
	Texture texture;
	Sprite sprite;

public:
    std::vector<Object> objects;
	std::vector<Vehicle> vehicles;

	Road();
	Road(std::string type, float yPos);

	std::string getType() const;
	float getY() const;
	void setTrafficLight(bool having) const;
	bool getHasTrafficLight() const;
	int getTrafficLightColor() const;
	float getSpeed() const;
	void setSpeed(const float s);
	void setTrafficLight(const int color);
	void addVehicle(const Vehicle& added);
	void addObject(const Object& added);
	void updateVehicles(Clock& frameClock);
	void draw(RenderWindow& window);
	// For debug
	void setY(const float y);
	void setType(const std::string t);
	void printAll();
};

#endif // ROAD_H
