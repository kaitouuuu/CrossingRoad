#include "Road.h"

Road::Road()
	: type(""), yPos(0), hasTrafficLight(false), trafficLightColor(0), speed(0)
{
	objects.clear();
}

Road::Road(std::string type, float yPos)
	: type(type), yPos(yPos), hasTrafficLight(false), trafficLightColor(0), speed(0)
{
	objects.clear();
}

std::string Road::getType() const
{
	return type;
}

float Road::getY() const
{
	return yPos;
}

bool Road::getHasTrafficLight() const
{
	return hasTrafficLight;
}

int Road::getTrafficLightColor() const
{
	return trafficLightColor;
}

float Road::getSpeed() const
{
	return speed;
}

void Road::setSpeed(const float s)
{
	speed = s;
}

void Road::setTrafficLight(const int color)
{
	hasTrafficLight = true;
	trafficLightColor = color;
}

void Road::addObject(const Object &added)
{
	for (Object &object : objects)
	{
		float objX = object.getX();
		float objX2 = objX + object.getWidth();
		float addedObjX = added.getX();
		float addedObjX2 = addedObjX + added.getWidth();

		if (objX <= addedObjX && addedObjX <= objX2 || addedObjX <= objX && objX <= addedObjX2)
		{
			return;
		}
	}

	objects.push_back(added);
}

void Road::addVehicle(const Vehicle &added)
{
	for (Vehicle &vehicle : vehicles)
	{
		float objX = vehicle.getX();
		float objX2 = objX + vehicle.getWidth();
		float addedObjX = added.getX();
		float addedObjX2 = addedObjX + added.getWidth();

		if (objX <= addedObjX && addedObjX <= objX2 || addedObjX <= objX && objX <= addedObjX2)
		{
			return;
		}
	}

	vehicles.push_back(added);
}

void Road::updateVehicles()
{
	if (type != "Field")
	{
		for (Vehicle &vehicle : vehicles)
		{
			vehicle.updatePosition(speed);
		}
	}
}

void Road::setY(const float y)
{
	yPos = y;
}

void Road::setType(const std::string t)
{
	type = t;
}

void Road::printAll()
{
	std::cout << type << " " << speed << std::endl
			  << "Car: ";

	for (Vehicle &vehicle : vehicles)
	{
		std::cout << vehicle.getX() << ":" << vehicle.getY() << " ";
	}

	std::cout << std::endl
			  << "Object: ";

	for (Object &object : objects)
	{
		std::cout << object.getX() << ":" << object.getY() << " ";
	}

	std::cout << std::endl;
}
