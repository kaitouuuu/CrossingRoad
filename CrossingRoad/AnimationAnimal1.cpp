#include "AnimationAnimal1.h"

void AnimationAnimal1::setMove()
{
	walkingAnimation.setSpriteSheet(texture);
	walkingAnimation.addFrame(sf::IntRect( 0, 13, 18, 13));
	walkingAnimation.addFrame(sf::IntRect(18, 13, 18, 13));
	walkingAnimation.addFrame(sf::IntRect(36, 13, 18, 13));
	walkingAnimation.addFrame(sf::IntRect(54, 13, 18, 13));
}

void AnimationAnimal1::setStable()
{
	walkingAnimation.setSpriteSheet(texture);
	walkingAnimation.addFrame(sf::IntRect( 0, 0, 18, 13));
	walkingAnimation.addFrame(sf::IntRect(18, 0, 18, 13));
}

AnimationAnimal1::AnimationAnimal1(string fileName, float x, float y, float width, float height, bool paused, bool looped)
{
	if (!texture.loadFromFile(fileName))
	{
		cout << "Failed to load player spritesheet!" << endl;
	}

	setMove();

	currentAnimation = &walkingAnimation;

	AnimatedSprite tmp(seconds(0.2f), true, false);
	tmp.setPosition(x, y);
	animatedSprite = tmp;

	Animal1 tmpp(x, y);
	animal1 = tmpp;

	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

	isMoved = true;
}

void AnimationAnimal1::update(float speed)
{
	Time frameTime = clock.restart();

	Vector2f movement(speed, 0.f);

	if (speed == 0) {
		if (isMoved) {
			walkingAnimation.clearFrame();
			isMoved = false;
		}
		for (int i = 0; i < 25; ++i) 
			setStable();
	}
	else {
		if (!isMoved) {
			walkingAnimation.clearFrame();
			isMoved = true;
		}
		for (int i = 0; i < 25; ++i)
			setMove();
	}
	currentAnimation = &walkingAnimation;
	animatedSprite.play(*currentAnimation);
	animatedSprite.move(movement * frameTime.asSeconds());
	animatedSprite.update(frameTime);
	
	x = animatedSprite.getPosition().x;
	y = animatedSprite.getPosition().y;

	std::cout << "Update" << std::endl;
}

void AnimationAnimal1::draw(RenderWindow& window)
{
	window.draw(animatedSprite);
}

float AnimationAnimal1::getHeight()
{
	return animatedSprite.getLocalBounds().height;
}

float AnimationAnimal1::getWidth()
{
	return animatedSprite.getLocalBounds().width;
}

float AnimationAnimal1::getX()
{
	return x;
}

float AnimationAnimal1::getY()
{
	return y;
}