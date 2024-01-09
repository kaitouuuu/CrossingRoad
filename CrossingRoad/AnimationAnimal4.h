#ifndef ANIMATIONANIMAL4_H
#define ANIMATIONANIMAL4_H

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include <iostream>

class AnimationAnimal4
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
	AnimationAnimal4();
	AnimationAnimal4(std::string fileName, float x, float y, float width, float height, bool paused, bool looped);

	void setMove();
	void setStable();
	void setCollision();
	void gameOver();
	void changeState();

	void update(float speed,bool isappearEsc);
	void draw(sf::RenderWindow& window);

	float getX() const;
	float getY() const;
	float getWidth();
	float getHeight();
};

#endif // ANIMATIONANIMAL1_H
