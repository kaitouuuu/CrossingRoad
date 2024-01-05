#ifndef ANIMATIONCARL1_H
#define ANIMATIONCAR1_H

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include <iostream>

class AnimationCar1
{
private:
	sf::Texture texture;
	sf::Clock clock;

	AnimatedSprite animatedSprite;
	Animation walkingAnimation;
	Animation waitAnimation;
	Animation* currentAnimation;

	float speed;
	float x, y;
	float width, height;

	bool isMoved;

public:
	AnimationCar1();
	AnimationCar1(std::string fileName, float x, float y, float width, float height, bool paused, bool looped);

	void setMove();
	void setStable();

	void update(float speed,bool isappearesc);
	void draw(sf::RenderWindow& window);

	float getY();
	float getX();
	float getWidth();
	float getHeight();
};

#endif // ANIMATIONCAR1_H
