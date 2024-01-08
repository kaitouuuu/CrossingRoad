#include "Vehicle.h"

Vehicle::Vehicle()
	: xPos(0), yPos(0), width(0), height(0),check(0), type("") {
	if (!texture.loadFromFile("Content/Image/" + type + "Car.png")) {
		std::cout << "Can not load image\n";
		exit(0);
	}
	width = 64;
	height = 32;
}

Vehicle::Vehicle(float xPos, float yPos, std::string type)
	: xPos(xPos), yPos(yPos), type(type),check(xPos) {
	if (!texture.loadFromFile("Content/Image/" + type + "Car.png")) {
		std::cout << "Can not load image\n";
		exit(0);
	}
	width = 64;
	height = 32;
}

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

void Vehicle::setSpriteColor(const Color& color)
{
	sprite.setColor(color);
}

std::string Vehicle::getType() const
{
	return type;
}

void Vehicle::updatePosition(float speed, bool isappearEsc)
{
	if (speed < 0) {
		sprite.setScale(-1.f, 1.f);
		sprite.setOrigin(getWidth(), 0);
	}
	sf::Time deltaTime = clock.restart();
	if (isappearEsc) {
		check = xPos;
	}
	else {
		if (check != xPos) exit(0);
		xPos += speed * deltaTime.asSeconds();
		check = xPos;

		if (xPos >= 1920)
		{
			xPos -= 1920;
			check = xPos;
		}
		else if (xPos < 0)
		{
			xPos += 1920;
			check = xPos;
		}
	}
}

void Vehicle::draw(RenderWindow& window) {
	sprite.setTexture(texture);
	sprite.setPosition(xPos, yPos);

	width = getWidth();
	height = getHeight();
}
