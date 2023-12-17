#include "Vehicle.h"

Vehicle::Vehicle()
	: xPos(0), yPos(0), width(0), height(0), type("") {
	if (!texture.loadFromFile("Content/Image/Car.png")) {
		std::cout << "Can not load image\n";

		exit(0);
	}
}

Vehicle::Vehicle(float xPos, float yPos, std::string type)
	: xPos(xPos), yPos(yPos), type(type) {
	if (!texture.loadFromFile("Content/Image/Car.png")) {
		std::cout << "Can not load image\n";

		exit(0);
	}

	width = getWidth();
	height = getHeight();
	std::cout << xPos << std::endl;
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
	return sprite.getLocalBounds().width;
}

float Vehicle::getHeight() const
{
	return sprite.getLocalBounds().height;
}

void Vehicle::setSpriteColor(const Color& color)
{
	sprite.setColor(color);
}

std::string Vehicle::getType() const
{
	return type;
}

void Vehicle::updatePosition(float speed)
{
	if (speed < 0) {
		sprite.setScale(-1.f, 1.f);
	}

	sf::Time deltaTime = clock.restart();
	xPos += speed * deltaTime.asSeconds();

	if (xPos >= 1920)
	{
		xPos -= 1920;
	}
	else if (xPos < 0)
	{
		xPos += 1920;
	}
}
void Vehicle::draw(RenderWindow& window) {
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 48, 48, 48));
	sprite.setPosition(xPos, yPos);

	width = getWidth();
	height = getHeight();

	window.draw(sprite);
}
