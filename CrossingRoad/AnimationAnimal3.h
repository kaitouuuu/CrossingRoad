#ifndef ANIMATIONANIMAL3_H
#define ANIMATIONANIMAL3_H

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include <iostream>

class AnimationAnimal3
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
	AnimationAnimal3();
	AnimationAnimal3(std::string fileName, float x, float y, float width, float height, bool paused, bool looped);

	void setMove();
	void setStable();

	void update(float speed);
	void draw(sf::RenderWindow& window);

	float getY();
	float getX();
	float getWidth();
	float getHeight();
};

#endif // ANIMATIONANIMAL3_H
