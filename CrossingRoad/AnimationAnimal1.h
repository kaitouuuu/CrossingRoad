#ifndef ANIMATIONANIMAL1_H
#define ANIMATIONANIMAL1_H

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include <iostream>

class AnimationAnimal1
{
private:
	sf::Texture texture;
	sf::Clock clock;

	AnimatedSprite animatedSprite;
	Animation walkingAnimation;
	Animation waitAnimation;
	Animation deadAnimal;
	Animation* currentAnimation;

	float speed;
	float x, y;
	float width, height;

	bool isMoved;
	bool gameEnd;

public:
	AnimationAnimal1();
	AnimationAnimal1(std::string fileName, float x, float y, float width, float height, bool paused, bool looped);

	void setMove();
	void setStable();
	void setCollision();
	void gameOver();
	void changeState();

	void update(float speed);
	void draw(sf::RenderWindow& window);

	float getY();
	float getX();
	float getWidth();
	float getHeight();
};

#endif // ANIMATIONANIMAL1_H
