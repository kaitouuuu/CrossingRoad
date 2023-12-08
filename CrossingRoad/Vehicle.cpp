#include "Vehicle.h"

Vehicle::Vehicle()
	: xPos(0), yPos(0), width(0), height(0), type("") {}

Vehicle::Vehicle(float xPos, float yPos, float width, float height, std::string type)
	: xPos(xPos), yPos(yPos), width(width), height(height), type(type) {}

float Vehicle::getX() const
{
	return xPos;
}

float Vehicle::getY() const
{
	return yPos;
}

float Vehicle::getWidth() const
{
	return width;
}

float Vehicle::getHeight() const
{
	return height;
}

std::string Vehicle::getType() const
{
	return type;
}

void Vehicle::updatePosition(float speed)
{
	xPos += speed;

	if (xPos >= 1920)
	{
		xPos -= 1920;
	}
	else if (xPos < 0)
	{
		xPos += 1920;
	}
}
