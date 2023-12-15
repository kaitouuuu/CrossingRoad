#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Animal {
private:
	float xPos;
	float yPos;
	float width;
	float height;

	std::string type;

	Texture texture;
	Sprite sprite;
	Clock clock;

public:
	Animal();
	Animal(float xPos, float yPos, std::string type);

	float getX() const;
	float getY() const;
	float getWidth() const;
	float getHeight() const;

	Sprite getSprite();
	void setSprite(Sprite& other);

	std::string getType() const;

	void updatePosition(float speed);
	virtual void draw(RenderWindow& window);
};

#endif // VEHICLE_H
