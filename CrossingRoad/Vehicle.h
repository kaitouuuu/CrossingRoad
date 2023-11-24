#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
private:
	float xPos;
	float yPos;
	int width;
	int height;
	std::string type;

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
