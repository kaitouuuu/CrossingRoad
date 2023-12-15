#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include <string>
#include <vector>

#include "Object.h"
#include "Vehicle.h"
#include "Car1.h"
#include "TrafficLight.h"

class Road {
private:
	std::string type;
	float yPos;
	// 0: Green, 1: Yellow, 2: Red
	float speed;
	TrafficLight trafficLight;
	Texture texture;
	Sprite sprite;

public:
    std::vector<Object> objects;
	std::vector<Vehicle> vehicles;

	Road();
	Road(std::string type, float yPos);

	std::string getType() const;
	float getY() const;
	void initTrafficLight(float xPos, float yPos);
	void updateTrafficLight();
	float getSpeed() const;
	void setSpeed(const float s);
	void addVehicle(const Vehicle& added);
	void addObject(const Object& added);
	void updateVehicles();
	void draw(RenderWindow& window);
	// For debug
	void setY(const float y);
	void setType(const std::string t);
	void printAll();
};

#endif // ROAD_H
