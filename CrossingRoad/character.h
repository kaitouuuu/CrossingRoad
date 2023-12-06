#pragma once

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include "Object.h"
#include <iostream>

using namespace sf;
using namespace std;

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

	int skin = 0;

	float speed;
	float x, y;

	bool isCleared;
	bool noKeyWasPressed;
	bool isLose;

	int type;

public:
	bool checkCollision(vector<Object> o);

	Character(string fileName, float x, float y, bool paused, bool looped);

	void setMoveUp();
	void setMoveDown();
	void setMoveLeft();
	void setMoveRight();
	void setUp();
	void setDown();
	void setLeft();
	void setRight();
	void clearFrame();
	void update(Clock& frameClock, vector<Object> o);
	void changeSkin();
	void draw(RenderWindow& window);

	float getPositionX();
	float getPositionY();

	bool getIsLose() { return isLose; }
};