#include "Object.h"

Object::Object()
	: xPos(0), yPos(0), width(0), height(0), type("") {}

Object::Object(float xPos, float yPos, float width, float height, std::string type)
	: xPos(xPos), yPos(yPos), width(width), height(height), type(type) {

	std::string filename;

	if (type == "thin_tree")
	{
		 filename = "Content/Image/thintree.png";
	}
	else if (type == "big_tree")
	{
		filename = "Content/Image/bigtree.png";
	}

	if (!texture.loadFromFile(filename))
	{
		std::cout << "Failed to load stable object!" << std::endl;	
	}

	sprite.setTexture(texture);
	sprite.setPosition(Vector2f(xPos, yPos));

	// Calculate the scaling factors
	float scaleX = width / sprite.getLocalBounds().width;
	float scaleY = height / sprite.getLocalBounds().height;

	// Set the scale of the sprite
	sprite.setScale(scaleX, scaleY);
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

void Object::updatePosition(float speed)
{
	xPos += speed;
	if (xPos >= 1920)
	{
		xPos -= 1920;
	}
	else if (xPos < 0)
	{
		xPos += 1920;
	}
}

FloatRect Object::getglobalBounds()
{
	return sprite.getGlobalBounds();
}

bool Object::doesIntersect(Object* other)
{
	return this->sprite.getGlobalBounds().intersects(other->sprite.getGlobalBounds());
}

void Object::draw(RenderWindow& window)
{
	window.draw(sprite);
}
