#include "Animal.h"

Animal::Animal()
	: xPos(0), yPos(0), width(0), height(0), type("") {

}

Animal::Animal(float xPos, float yPos, std::string type)
	: xPos(xPos), yPos(yPos), type(type) {
	height = 0;
	width = 0;
}

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
	return sprite.getLocalBounds().width;
}

float Animal::getHeight() const
{
	return sprite.getLocalBounds().height;
}

void Animal::setTexture(std::string tmp)
{
	texture.loadFromFile(tmp);
}

void Animal::setSprite()
{
	sprite.setTexture(texture);
}

std::string Animal::getType() const
{
	return type;
}

void Animal::updatePosition(float speed)
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
void Animal::draw(RenderWindow& window) {
	sprite.setTexture(texture);
	sprite.setPosition(xPos, yPos);

	width = getWidth();
	height = getHeight();

	window.draw(sprite);
	std::cout << getWidth() << " " << getHeight() << std::endl;
}
