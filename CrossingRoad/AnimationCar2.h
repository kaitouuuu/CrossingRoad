#ifndef ANIMATIONCARL2_H
#define ANIMATIONCAR2_H

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include <iostream>

class AnimationCar2
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
	bool gameEnd;

public:
	AnimationCar2();
	AnimationCar2(std::string fileName, float x, float y, float width, float height, bool paused, bool looped);

	void setMove();
	void setStable();
	void setCollision();
	void gameOver();
	void changeState();

	void update(float speed, bool isappearesc);
	void draw(sf::RenderWindow& window);

	float getX() const;
	float getY() const;
	float getWidth();
	float getHeight();
};

#endif // ANIMATIONCAR2_H
