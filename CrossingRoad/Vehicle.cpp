#include "Vehicle.h"

Vehicle::Vehicle()
	: xPos(0), yPos(0), width(0), height(0), type("") {}

Vehicle::Vehicle(float xPos, float yPos, int width, int height, std::string type)
	: xPos(xPos), yPos(yPos), width(width), height(height), type(type) {}

float Vehicle::getX() const
{
	return xPos;
}

float Vehicle::getY() const
{
	return yPos;
}

int Vehicle::getWidth() const
{
	return width;
}

int Vehicle::getHeight() const
{
	return height;
}

std::string Vehicle::getType() const
{
	return type;
}

void Vehicle::updatePosition(float speed)
{
	const float screenLimit = 1920 + 48;
	xPos += speed;

	if (xPos >= screenLimit)
	{
		xPos -= screenLimit;
	}
	else if (xPos < 0 - 48)
	{
		xPos += screenLimit;
	}

}