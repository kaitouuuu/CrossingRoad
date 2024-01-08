#include "Road.h"

Road::Road()
	: type(""), yPos(0), speed(0)
{
	objects.clear();
}

Road::Road(std::string type, float yPos)
	: type(type), yPos(yPos), speed(0)
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

void Road::initTrafficLight(float xPos, float yPos)
{
	trafficLight = TrafficLight(xPos, yPos);
}

void Road::updateTrafficLight()
{
	trafficLight.operation();
}
float Road::getSpeed() const
{
	return speed;
}

void Road::setSpeed(const float s)
{
	speed = s;
}

void Road::addObject(Object* added)
{
	for (Object* object : objects)
	{
		float objX = object->getX();
		float objX2 = objX + object->getWidth();
		float addedObjX = added->getX();
		float addedObjX2 = addedObjX + added->getWidth();

		if (objX <= addedObjX && addedObjX <= objX2 || addedObjX <= objX && objX <= addedObjX2)
		{
			return;
		}
	}

	objects.push_back(added);
}

void Road::addVehicle(Vehicle* added)
{
	for (Vehicle* vehicle : vehicles)
	{
		float objX = vehicle->getX();
		float objX2 = objX + vehicle->getWidth();
		float addedObjX = added->getX();
		float addedObjX2 = addedObjX + added->getWidth();

		if (objX <= addedObjX && addedObjX <= objX2 || addedObjX <= objX && objX <= addedObjX2)
		{
			return;
		}
	}

	vehicles.push_back(added);
}

void Road::addAnimal(Animal* added)
{
	for (Animal* animal : animals)
	{
		float objX = animal->getX();
		float objX2 = objX + animal->getWidth();
		float addedObjX = added->getX();
		float addedObjX2 = addedObjX + added->getWidth();

		if (objX <= addedObjX && addedObjX <= objX2 || addedObjX <= objX && objX <= addedObjX2)
		{
			return;
		}
	}

	animals.push_back(added);
}

void Road::updateVehicles(bool isappearEsc, float x, float y,float width, float height)
{
	if (trafficLight.getColor() != 2)
		for (Vehicle* vehicle : vehicles)
		{
			float checkX = max(vehicle->getX(), x);
			float checkY = max(vehicle->getY(), y);
			float checkX2 = min(vehicle->getX() + vehicle->getWidth(), x + width);
			float checkY2 = min(vehicle->getY() + vehicle->getHeight(), y + height);
			if (checkX <= checkX2 && checkY <= checkY2)
			{
				vehicle->updatePosition(speed, false);
				continue;
			}
			vehicle->updatePosition(speed,isappearEsc);
		}
	else
		for (Vehicle* vehicle : vehicles)
		{
			float checkX = max(vehicle->getX(), x);
			float checkY = max(vehicle->getY(), y);
			float checkX2 = min(vehicle->getX() + vehicle->getWidth(), x + width);
			float checkY2 = min(vehicle->getY() + vehicle->getHeight(), y + height);
			if (checkX <= checkX2 && checkY <= checkY2)
			{
				vehicle->updatePosition(0, false);
				continue;
			}
			vehicle->updatePosition(0,isappearEsc);
		}
}

void Road::updateAnimals(bool isappearEsc, float x, float y, float width, float height)
{
	for (Animal* animal : animals)
	{
		float checkX = max(animal->getX(), x);
		float checkY = max(animal->getY(), y);
		float checkX2 = min(animal->getX() + animal->getWidth(), x + width);
		float checkY2 = min(animal->getY() + animal->getHeight(), y + height);
		if (checkX <= checkX2 && checkY <= checkY2)
		{
			animal->updatePosition(speed, false);
			continue;
		}
		animal->updatePosition(speed, isappearEsc);
	}
}

void Road::draw(RenderWindow &window)
{

	std::string filename;
	if (type == "Road")
	{
		filename = "Content/Image/Road.png";
	}
	else if (type == "Field")
	{
		filename = "Content/Image/Field.png";
	}
	else if (type == "Land")
	{
		filename = "Content/Image/Land.png";
	}
	if (!texture.loadFromFile(filename))
	{
		std::cout << filename << std::endl;
		std::cout << "Can not load image\n";

		exit(0);
	}
	sprite.setTexture(texture);
	sprite.setPosition(0.f, yPos);
	window.draw(sprite);
	trafficLight.draw(window);
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
}
