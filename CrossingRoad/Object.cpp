#include "Object.h"

Object::Object()
	: xPos(0), yPos(0), width(0), height(0), type("") {}

Object::Object(float xPos, float yPos, std::string type)
	: xPos(xPos), yPos(yPos), type(type)
{

	std::string filename;

	if (type == "big1")
	{
		filename = "Content/Image/BigSquareObject1.png";
		width = height = 48;
	}
	else if (type == "big2")
	{
		filename = "Content/Image/BigSquareObject2.png";
		width = height = 48;
	}
	else if (type == "square1")
	{
		filename = "Content/Image/SquareObject1.png";
		width = height = 24;
	}
	else if (type == "square2")
	{
		filename = "Content/Image/SquareObject2.png";
		width = height = 24;
	}
	else if (type == "square3")
	{
		filename = "Content/Image/SquareObject3.png";
		width = height = 24;
	}
	else if (type == "square4")
	{
		filename = "Content/Image/SquareObject4.png";
		width = height = 24;
	}
	else if (type == "square5")
	{
		filename = "Content/Image/SquareObject5.png";
		width = height = 24;
	}
	else if (type == "square6")
	{
		filename = "Content/Image/SquareObject6.png";
		width = height = 24;
	}
	else if (type == "vertical1")
	{
		filename = "Content/Image/VerticalObject1.png";
		width = 24;
		height = 48;
	}

	if (!texture.loadFromFile(filename))
	{
		std::cout << "Failed to load stable object!" << std::endl;
	}
}

float Object::getX() const
{
	return xPos;
}

float Object::getY() const
{
	return yPos;
}

float Object::getWidth() const
{
	return width;
}

float Object::getHeight() const
{
	return height;
}

std::string Object::getType() const
{
	return type;
}

FloatRect Object::getglobalBounds()
{
	return sprite.getGlobalBounds();
}

bool Object::doesIntersect(Object *other)
{
	return this->sprite.getGlobalBounds().intersects(other->sprite.getGlobalBounds());
}

void Object::draw(RenderWindow &window)
{
	sprite.setTexture(texture);
	sprite.setPosition(Vector2f(xPos, yPos));

	width = getWidth();
	height = getHeight();

	window.draw(sprite);
}
