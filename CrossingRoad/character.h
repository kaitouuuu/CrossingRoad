#pragma once

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include "Road.h"
#include <iostream>

using namespace sf;
using namespace std;

enum Skin
{
	red,
	blue,
	green
};

enum Direction
{
	front,
	left,
	right
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
	Animation *currentAnimation;

	float speed;
	float x, y;
	float width, height;

	bool isCleared;
	bool noKeyWasPressed;

	int type;

	Skin skin;

public:
	bool checkCollision(Road &aRoad);
	void changeskin();

	Character(string fileName, float x, float y, float width, float height, bool paused, bool looped);

	void setMoveUp();
	void setMoveDown();
	void setMoveLeft();
	void setMoveRight();
	void setUp();
	void setDown();
	void setLeft();
	void setRight();
	void update(Clock &frameClock, Road &aRoad);
	void draw(RenderWindow &window);
	float getY();
	float getX();
	float getWidth();
	float getHeight();
	bool condition(float xTL, float yTL, float objH, float objW);
};