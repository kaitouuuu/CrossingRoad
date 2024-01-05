#ifndef ANIMATIONCARL5_H
#define ANIMATIONCAR5_H

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include <iostream>

class AnimationCar5
{
private:
	sf::Texture texture;
	sf::Clock clock;

	AnimatedSprite animatedSprite;
	Animation walkingAnimation;
	Animation waitAnimation;
	Animation deadCar;
	Animation* currentAnimation;

	float speed;
	float x, y;
	float width, height;

	bool isMoved;

public:
	AnimationCar5();
	AnimationCar5(std::string fileName, float x, float y, float width, float height, bool paused, bool looped);

	void setMove();
	void setStable();
	void setCollision();
	void gameOver();

	void update(float speed, bool isappearesc);
	void draw(sf::RenderWindow& window);

	float getY();
	float getX();
	float getWidth();
	float getHeight();
};

#endif // ANIMATIONCAR1_H
