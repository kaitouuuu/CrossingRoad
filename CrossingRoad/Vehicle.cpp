#include "Vehicle.h"

Vehicle::Vehicle()
	: xPos(0), yPos(0), width(0), height(0), type("") {}

Vehicle::Vehicle(float xPos, float yPos, float width, float height, std::string type)
	: xPos(xPos), yPos(yPos), width(width), height(height), type(type) {
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
	std::string filename = "Content/Image/bigtree.png";
	if (!texture.loadFromFile(filename)) {
		std::cout << "Can not load image\n";

		exit(0);
	}
	sprite.setTexture(texture);
	sprite.setPosition(xPos, yPos);
	window.draw(sprite);
}
