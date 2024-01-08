#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Vehicle {
private:
	float xPos;
	float yPos;
	float width;
	float height;
	float check;
	std::string type;

	Texture texture;
	Sprite sprite;
	Clock clock;

public:
	Vehicle();
	Vehicle(float xPos, float yPos, std::string type);

	float getX() const;
	float getY() const;
	float getWidth() const;
	float getHeight() const;

	void setSpriteColor(const Color& color);

	virtual void clearAnimation() = 0;

	std::string getType() const;

	virtual void updatePosition(float speed, bool isappearEsc);
	virtual void draw(RenderWindow& window);
};

#endif // VEHICLE_H
