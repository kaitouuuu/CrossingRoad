#include "AnimationCar1.h"

void AnimationCar1::setMove()
{
	walkingAnimation.setSpriteSheet(texture);
	walkingAnimation.addFrame(sf::IntRect(  0, 52, 72, 52));
	walkingAnimation.addFrame(sf::IntRect( 72, 52, 72, 52));
	walkingAnimation.addFrame(sf::IntRect(144, 52, 72, 52));
	walkingAnimation.addFrame(sf::IntRect(216, 52, 72, 52));
}

void AnimationCar1::setStable()
{
	waitAnimation.setSpriteSheet(texture);
	waitAnimation.addFrame(sf::IntRect( 0, 0, 72, 52));
	waitAnimation.addFrame(sf::IntRect(72, 0, 72, 52));
}

AnimationCar1::AnimationCar1()
{

}

AnimationCar1::AnimationCar1(std::string fileName, float x, float y, float width, float height, bool paused, bool looped)
{
	if (!texture.loadFromFile(fileName))
	{
		std::cout << "Failed to load player spritesheet!" << std::endl;
	}

	setMove();
	setStable();

	currentAnimation = &walkingAnimation;

	AnimatedSprite tmp(sf::seconds(0.2f), true, false);
	tmp.setPosition(x, y);
	animatedSprite = tmp;

	/*Car1 tmpp(x, y);
	car1 = tmpp;*/

	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

	isMoved = true;
}

void AnimationCar1::update(float speed)
{
	sf::Time frameTime = clock.restart();

	sf::Vector2f movement(speed, 0.f);

	if (speed == 0) {
		if (isMoved) {
			walkingAnimation.clearFrame();
			for (int i = 0; i < 20; ++i) {
				setMove();
			}
			isMoved = false;
		}
		for (int i = 0; i < 20; ++i) {
			setStable();
		}
		currentAnimation = &waitAnimation;
	}
	else {
		if (!isMoved) {
			walkingAnimation.clearFrame();
			for (int i = 0; i < 20; ++i) {
				setStable();
			}
			isMoved = true; 
		}
		for (int i = 0; i < 20; ++i) {
			setMove();
		}
		currentAnimation = &walkingAnimation;
	}
	
	animatedSprite.play(*currentAnimation);
	animatedSprite.move(movement * frameTime.asSeconds());
	animatedSprite.update(frameTime);

	if (x >= 1920)
	{
		animatedSprite.setPosition(x - 1920, y);
	}
	else if (x < 0)
	{
		animatedSprite.setPosition(x + 1920, y);
	}
	x = animatedSprite.getPosition().x;
	y = animatedSprite.getPosition().y;
}

void AnimationCar1::draw(sf::RenderWindow& window)
{
	window.draw(animatedSprite);
}

float AnimationCar1::getHeight()
{
	return animatedSprite.getLocalBounds().height;
}

float AnimationCar1::getWidth()
{
	return animatedSprite.getLocalBounds().width;
}

float AnimationCar1::getX()
{
	return x;
}

float AnimationCar1::getY()
{
	return y;
}