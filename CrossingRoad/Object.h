#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Object {
private:
	float xPos;
	float yPos;
	float width;
	float height;
	std::string type;
	Texture texture;
	Sprite sprite;

public:
	Object();
	Object(float xPos, float yPos, float width, float height, std::string type);

	float getX() const;
	float getY() const;
	float getWidth() const;
	float getHeight() const;
	std::string getType() const;

	FloatRect getglobalBounds();
	bool doesIntersect(Object* other);
	void draw(RenderWindow& window);
};


#endif // OBJECT_H
