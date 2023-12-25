#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include <string>
#include <vector>

#include "Object.h"
#include "Vehicle.h"

#include "Car1.h"
#include "Car2.h"
#include "Car3.h"
#include "Car4.h"
#include "Car5.h"

#include "Animal.h"
#include "Animal1.h"
#include "Animal2.h"
#include "Animal3.h"
#include "Animal4.h"
#include "Animal5.h"

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
	std::vector<Vehicle*> vehicles;
	std::vector<Animal*> animals;

	Road();
	Road(std::string type, float yPos);

	std::string getType() const;
	float getY() const;
	void initTrafficLight(float xPos, float yPos);
	void updateTrafficLight();
	float getSpeed() const;
	void setSpeed(const float s);
	void addVehicle(Vehicle* added);
	void addAnimal(const Animal& added);
	void addObject(const Object& added);
	void updateVehicles();
	void updateAnimals();
	void draw(RenderWindow& window);
	// For debug
	void setY(const float y);
	void setType(const std::string t);
	void printAll();
};

#endif // ROAD_H
