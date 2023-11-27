#include "Object.h"

Object::Object(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

float Object::getX()
{
	return x;
}

float Object::getY()
{
	return y;
}

float Object::getWidth()
{
	return width;
}

float Object::getHeight()
{
	return height;
}