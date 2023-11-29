#include "Animal.h"

Animal::Animal()
	: xPos(0), yPos(0), width(0), height(0), type("") {}

Animal::Animal(float xPos, float yPos, float width, float height, std::string type)
	: xPos(xPos), yPos(yPos), width(width), height(height), type(type) {}

float Animal::getX() const
{
	return xPos;
}

float Animal::getY() const
{
	return yPos;
}

float Animal::getWidth() const
{
	return width;
}

float Animal::getHeight() const
{
	return height;
}

std::string Animal::getType() const
{
	return type;
}

void Animal::updatePosition(float speed)
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
