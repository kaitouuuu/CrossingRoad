#pragma once

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include "Object.h"
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

	bool isCleared;
	bool noKeyWasPressed;
	bool isLose;

	int type;

	Skin skin;

public:
	bool checkCollision(vector<Object> o);
	void changeskin();

	Character(string fileName, float x, float y, bool paused, bool looped);

	void setMoveUp();
	void setMoveDown();
	void setMoveLeft();
	void setMoveRight();
	void setUp();
	void setDown();
	void setLeft();
	void setRight();
	void update(Clock& frameClock, vector<Object> o);
	void draw(RenderWindow& window);
    float getY();
	float getX();
	bool getIsLose() { return isLose; }
};