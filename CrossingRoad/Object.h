#pragma once
#include <vector>
#include "character.h"
class Stableobject {
private:
	float x;
	float y;
	float width;
	float height;
	Texture texture;
	Sprite sprite;
public:
	Stableobject(const float& x, const float& y, string filename, const float& width, const float& height);
	void draw(RenderWindow& window);
};
class Superlane {
private:
	float y;
	float x;
	float width;
	float height;

public:
	Superlane(const float& x, const float& y, const float& width, const float& height) : x(x), y(y),width(width),height(height){}
	virtual void draw(RenderWindow& window)=0;
};
class Lawn: public Superlane  {
private:
	std::vector<Stableobject*> smallobstacle;
	Texture texture;
	Sprite sprite;
public:
	Lawn(const float& x, const float& y, const float& width, const float& height,string filename) : Superlane(x, y, width, height){
		if (!texture.loadFromFile(filename)) {
			cout << "Failed to load grass spritesheet!" << endl;
			exit(0);
		}
		IntRect rectangle(x, y, width, height);
		sprite.setTexture(texture);
		sprite.setTextureRect(rectangle);
	}
	void draw(RenderWindow& window) override;
};
class Road: public Superlane {
private:
	// vehicle class 
};
