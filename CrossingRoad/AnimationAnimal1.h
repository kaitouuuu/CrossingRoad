#ifndef ANIMATIONANIMAL1_H
#define ANIMATIONANIMAL1_H

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include "Road.h"
#include <iostream>

using namespace sf;
using namespace std;

class AnimationAnimal1
{
private:
	Texture texture;
	Clock clock;

	Animal1 animal1;

	AnimatedSprite animatedSprite;
	Animation walkingAnimation;
	Animation* currentAnimation;

	float speed;
	float x, y;
	float width, height;

	bool isMoved;

public:
	AnimationAnimal1(string fileName, float x, float y, float width, float height, bool paused, bool looped);

	void setMove();
	void setStable();

	void update(float speed);
	void draw(RenderWindow& window);

	float getY();
	float getX();
	float getWidth();
	float getHeight();
};

#endif // ANIMATIONANIMAL1_H
