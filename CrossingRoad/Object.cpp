#include "Object.h"

Object::Object()
	: xPos(0), yPos(0), width(0), height(0), type("") {}

Object::Object(float xPos, float yPos, int width, int height, std::string type)
	: xPos(xPos), yPos(yPos), width(width), height(height), type(type) {
	string filename;
	if (type == "thintree") {
		 filename = "Content/Image/thintree.png";
	}
	else if (type == "bigtree") {
		filename = "Content/Image/bigtree.png";
	}
	if (!texture.loadFromFile(filename))
	{
		cout << "Failed to load stable object!" << endl;
		
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

int Object::getWidth() const
{
	return width;
}

int Object::getHeight() const
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

bool Object::doesIntersect(Object* other)
{
	return this->sprite.getGlobalBounds().intersects(other->sprite.getGlobalBounds());
}

void Object::draw(RenderWindow& window)
{
	window.draw(sprite);
}