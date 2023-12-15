#include "Animal.h"

Animal::Animal()
	: xPos(0), yPos(0), width(0), height(0), type("") {
	if (!texture.loadFromFile("Content/Image/Car.png")) {
		std::cout << "Can not load image\n";

		exit(0);
	}
}

Animal::Animal(float xPos, float yPos, std::string type)
	: xPos(xPos), yPos(yPos), type(type) {
	if (!texture.loadFromFile("Content/Image/Car.png")) {
		std::cout << "Can not load image\n";

		exit(0);
	}

	width = getWidth();
	height = getHeight();
	std::cout << xPos << std::endl;
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

Sprite Animal::getSprite()
{
	return sprite;
}

void Animal::setSprite(Sprite& other)
{
	sprite = other;
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
	sprite.setTextureRect(IntRect(0, 48, 48, 48));
	sprite.setPosition(xPos, yPos);

	width = getWidth();
	height = getHeight();

	window.draw(sprite);
}
