#include "Animal.h"

Animal::Animal()
	: xPos(0), yPos(0), width(0), height(0), type("")
{
}

Animal::Animal(float xPos, float yPos, std::string type)
	: xPos(xPos), yPos(yPos), type(type)
{
	if (!texture.loadFromFile("Content/Image/" + type + ".png")) {
		std::cout << "Can not load image\n";
		exit(0);
	}

	width = getWidth();
	height = getHeight();
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
	return width;
}

float Animal::getHeight() const
{
	return height;
}

void Animal::setWidthHeight(float x, float y)
{
	width = x;
	height = y;
}

std::string Animal::getType() const
{
	return type;
}

void Animal::updatePosition(float speed,bool isappearEsc)
{
	if (speed < 0)
	{
		sprite.setScale(-1.f, 1.f);
		sprite.setOrigin(getWidth(), 0);
	}

	sf::Time deltaTime = clock.restart();
	if (isappearEsc)
		return;
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

void Animal::draw(RenderWindow& window)
{
	sprite.setTexture(texture);
	sprite.setPosition(xPos, yPos);

	width = getWidth();
	height = getHeight();

	//window.draw(sprite);
}
