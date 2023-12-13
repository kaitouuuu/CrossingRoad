#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include "Road.h"
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
	Animation *currentAnimation;

	int skin = 0;

	float speed;
	float x, y;
	float width, height;

	bool isCleared;
	bool noKeyWasPressed;

	int type;

public:
	int checkCollision(Road &aRoad);

	Character();
	Character(string fileName, float x, float y, float width, float height, bool paused, bool looped);

	void setMoveUp();
	void setMoveDown();
	void setMoveLeft();
	void setMoveRight();
	void setUp();
	void setDown();
	void setLeft();
	void setRight();
	void changeSkin();
	void update(Clock &frameClock, Road &aRoad);
	void draw(RenderWindow &window);

	float getY();
	float getX();
	float getWidth();
	float getHeight();

	bool condition(float xTL, float yTL, float objH, float objW);
};

#endif // CHARACTER_H
