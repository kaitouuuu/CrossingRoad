
#include "Object.h"

Stableobject::Stableobject(const float& x,const float& y, string filename, const float& width, const float& height) {
	this->x = x;
	this->y = y;
	if (!texture.loadFromFile(filename))
	{
		cout << "Failed to load grass spritesheet!" << endl;
		exit(0);
	}

	IntRect rectangle(x, y, width, height);
	sprite.setTexture(texture);
	sprite.setTextureRect(rectangle);
}

void Stableobject::draw(RenderWindow& window) {
	window.draw(sprite);
}

void Lawn::draw(RenderWindow& window){
	window.draw(sprite);
}