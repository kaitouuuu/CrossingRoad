#include "Vehicle.h"

Vehicle::Vehicle(float xPos, float yPos, std::string type)
	: xPos(xPos), yPos(yPos), type(type) {}

Vehicle::Vehicle()
	: xPos(0), yPos(0), type("") {}

float Vehicle::getXPosition() const
{
	return xPos;
}

float Vehicle::getYPosition() const
{
	return yPos;
}

std::string Vehicle::getType() const
{
	return type;
}

void Vehicle::updatePosition(float speed)
{
	xPos += speed;
}

void Vehicle::rotatePosition(bool gotoBack)
{
	if (gotoBack == true) {
		xPos += 1920;
	}
	else
	{
		xPos -= 1920;
	}
}
