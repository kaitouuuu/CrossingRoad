#include "Object.h"

Object::Object()
	: xPos(0), yPos(0), width(0), height(0), type("") {}

Object::Object(float xPos, float yPos, int width, int height, std::string type)
	: xPos(xPos), yPos(yPos), width(width), height(height), type(type) {}

float Object::getX() const
{
	return xPos;
}

float Object::getY() const
{
	return yPos;
}

int Object::getWidth() const
{
	return width;
}

int Object::getHeight() const
{
	return height;
}

std::string Object::getType() const
{
	return type;
}
