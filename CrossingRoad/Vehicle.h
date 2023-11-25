#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Vehicle {
private:
	float xPos;
	float yPos;
	int width;
	int height;
	std::string type;
	Texture texture;
	Sprite sprite;

public:
	Vehicle();
	Vehicle(float xPos, float yPos, int width, int height, std::string type);

	float getX() const;
	float getY() const;
	int getWidth() const;
	int getHeight() const;
	std::string getType() const;
	void updatePosition(float speed);
};

#endif // VEHICLE_H
