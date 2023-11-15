#pragma once

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include <iostream>

using namespace sf;
using namespace std;

enum Skin {
	red, blue, green
};

enum Direction {
	front, left, right
};

class Character 
{
private:
	Texture texture;

	AnimatedSprite animatedSprite;
	Animation walkingAnimationUp;
	Animation walkingAnimationDown;
	Animation walkingAnimationLeft;
	Animation walkingAnimationRight;
	Animation* currentAnimation;

	float speed;
	float x, y;
	
	bool noKeyWasPressed;
	bool isLose;

	Skin skin;

public:
	bool collision_car();
	bool collision_obj();
	void changeskin();

	Character(string fileName, float x, float y, bool paused, bool looped);

	void setUp();
	void setDown();
	void setLeft();
	void setRight();
	void update(Clock& frameClock);
	void draw(RenderWindow& window);

	bool getIsLose() { return isLose; }
};