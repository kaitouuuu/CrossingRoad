#include "AnimationCar4.h"

void AnimationCar4::setMove()
{
	walkingAnimation.setSpriteSheet(texture);
	walkingAnimation.addFrame(sf::IntRect(0, 52, 72, 52));
	walkingAnimation.addFrame(sf::IntRect(72, 52, 72, 52));
	walkingAnimation.addFrame(sf::IntRect(144, 52, 72, 52));
	walkingAnimation.addFrame(sf::IntRect(216, 52, 72, 52));
}

void AnimationCar4::setStable()
{
	waitAnimation.setSpriteSheet(texture);
	waitAnimation.addFrame(sf::IntRect(0, 0, 72, 52));
	waitAnimation.addFrame(sf::IntRect(72, 0, 72, 52));
}

void AnimationCar4::setCollision()
{
	deadCar.setSpriteSheet(texture);
	deadCar.addFrame(sf::IntRect(0, 104, 72, 60));
	deadCar.addFrame(sf::IntRect(72, 104, 72, 60));
	deadCar.addFrame(sf::IntRect(144, 104, 72, 60));
	deadCar.addFrame(sf::IntRect(216, 104, 72, 60));
}

void AnimationCar4::gameOver()
{
	waitAnimation.clearFrame();
	walkingAnimation.clearFrame();
	for (int i = 0; i < 20; ++i)
	{
		setCollision();
	}
	currentAnimation = &deadCar;
	changeState();
}

void AnimationCar4::changeState()
{
	gameEnd = true;
}

AnimationCar4::AnimationCar4()
{
}

AnimationCar4::AnimationCar4(std::string fileName, float x, float y, float width, float height, bool paused, bool looped)
{
	if (!texture.loadFromFile(fileName))
	{
		std::cout << "Failed to load player spritesheet!" << std::endl;
	}

	setMove();
	setStable();
	setCollision();

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

void AnimationCar4::update(float speed, bool isappearesc)
{
	sf::Time frameTime = clock.restart();

	sf::Vector2f movement(speed, 0.f);

	if (gameEnd)
	{
		if (!isappearesc)
		{
			animatedSprite.play(*currentAnimation);
			animatedSprite.update(frameTime);
		}
		return;
	}

	if (!isappearesc)
	{
		if (speed == 0)
		{
			if (isMoved)
			{
				walkingAnimation.clearFrame();
				for (int i = 0; i < 20; ++i)
				{
					setMove();
				}
				isMoved = false;
			}
			for (int i = 0; i < 20; ++i)
			{
				setStable();
			}
			currentAnimation = &waitAnimation;
		}
		else
		{
			if (!isMoved)
			{
				walkingAnimation.clearFrame();
				for (int i = 0; i < 20; ++i)
				{
					setStable();
				}
				isMoved = true;
			}
			for (int i = 0; i < 20; ++i)
			{
				setMove();
			}
			currentAnimation = &walkingAnimation;
		}

		animatedSprite.play(*currentAnimation);
		animatedSprite.move(movement * frameTime.asSeconds());
		animatedSprite.update(frameTime);
	}

	if (speed < 0)
	{
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

void AnimationCar4::draw(sf::RenderWindow& window)
{
	window.draw(animatedSprite);
}

float AnimationCar4::getHeight()
{
	return animatedSprite.getLocalBounds().height;
}

float AnimationCar4::getWidth()
{
	return animatedSprite.getLocalBounds().width;
}

float AnimationCar4::getX() const
{
	return x;
}

float AnimationCar4::getY() const
{
	return y;
}