#include "AnimationAnimal4.h"

void AnimationAnimal4::setMove()
{
	walkingAnimation.setSpriteSheet(texture);
	walkingAnimation.addFrame(sf::IntRect(0, 48, 48, 48));
	walkingAnimation.addFrame(sf::IntRect(48, 48, 48, 48));
	walkingAnimation.addFrame(sf::IntRect(96, 48, 48, 48));
	walkingAnimation.addFrame(sf::IntRect(144, 48, 48, 48));
}

void AnimationAnimal4::setStable()
{
	waitAnimation.setSpriteSheet(texture);
	waitAnimation.addFrame(sf::IntRect(0, 0, 48, 48));
	waitAnimation.addFrame(sf::IntRect(48, 0, 48, 48));
	waitAnimation.addFrame(sf::IntRect(96, 0, 48, 48));
}

AnimationAnimal4::AnimationAnimal4()
{

}

AnimationAnimal4::AnimationAnimal4(std::string fileName, float x, float y, float width, float height, bool paused, bool looped)
{
	if (!texture.loadFromFile(fileName))
	{
		std::cout << "Failed to load player spritesheet!" << std::endl;
		exit(0);
	}

	setMove();
	setStable();

	currentAnimation = &walkingAnimation;

	AnimatedSprite tmp(sf::seconds(0.2f), true, false);
	tmp.setPosition(x, y);
	animatedSprite = tmp;

	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

	isMoved = true;
}

void AnimationAnimal4::update(float speed)
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
	if (speed < 0) {
		animatedSprite.setScale(-1.f, 1.f);
		animatedSprite.setOrigin(getWidth(), 0);
	}

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

void AnimationAnimal4::draw(sf::RenderWindow& window)
{
	window.draw(animatedSprite);
}

float AnimationAnimal4::getHeight()
{
	return animatedSprite.getLocalBounds().height;
}

float AnimationAnimal4::getWidth()
{
	return animatedSprite.getLocalBounds().width;
}

float AnimationAnimal4::getX()
{
	return x;
}

float AnimationAnimal4::getY()
{
	return y;
}