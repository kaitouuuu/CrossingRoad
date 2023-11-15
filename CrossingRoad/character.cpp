#include "character.h"

void Character::setUp()
{
	walkingAnimationUp.setSpriteSheet(texture);
	walkingAnimationUp.addFrame(sf::IntRect(  0, 48, 48, 48));
	walkingAnimationUp.addFrame(sf::IntRect( 48, 48, 48, 48));
	walkingAnimationUp.addFrame(sf::IntRect( 96, 48, 48, 48));
	walkingAnimationUp.addFrame(sf::IntRect(144, 48, 48, 48));
}

void Character::setDown()
{
	walkingAnimationDown.setSpriteSheet(texture);
	walkingAnimationDown.addFrame(sf::IntRect(  0, 0, 48, 48));
	walkingAnimationDown.addFrame(sf::IntRect( 48, 0, 48, 48));
	walkingAnimationDown.addFrame(sf::IntRect( 96, 0, 48, 48));
	walkingAnimationDown.addFrame(sf::IntRect(144, 0, 48, 48));
}

void Character::setLeft()
{
	walkingAnimationLeft.setSpriteSheet(texture);
	walkingAnimationLeft.addFrame(sf::IntRect(  0, 96, 48, 48));
	walkingAnimationLeft.addFrame(sf::IntRect( 48, 96, 48, 48));
	walkingAnimationLeft.addFrame(sf::IntRect( 96, 96, 48, 48));
	walkingAnimationLeft.addFrame(sf::IntRect(144, 96, 48, 48));
}

void Character::setRight()
{
	walkingAnimationRight.setSpriteSheet(texture);
	walkingAnimationRight.addFrame(sf::IntRect(  0, 144, 48, 48));
	walkingAnimationRight.addFrame(sf::IntRect( 48, 144, 48, 48));
	walkingAnimationRight.addFrame(sf::IntRect( 96, 144, 48, 48));
	walkingAnimationRight.addFrame(sf::IntRect(144, 144, 48, 48));
}

Character::Character(string fileName, float x, float y, bool paused, bool looped)
{	
	if (!texture.loadFromFile(fileName))
	{
		cout << "Failed to load player spritesheet!" << endl;
	}

	setUp();
	setDown();
	setLeft();
	setRight();

	currentAnimation = &walkingAnimationDown;

	AnimatedSprite tmp(seconds(0.2f), true, false);
	tmp.setPosition(x, y);
	animatedSprite = tmp;

	speed = 80.f;
	this->x = x;
	this->y = y;

	isLose = false;
	noKeyWasPressed = true;
}

void Character::update(Clock& frameClock)
{
	Time frameTime = frameClock.restart();

	Vector2f movement(0.f, 0.f);

	if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
	{
		currentAnimation = &walkingAnimationUp;
		movement.y = -speed;
		noKeyWasPressed = false;
		setUp();
	}

	if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
	{
		currentAnimation = &walkingAnimationDown;
		movement.y = speed;
		noKeyWasPressed = false;
		setDown();
	}

	if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
	{
		currentAnimation = &walkingAnimationLeft;
		movement.x = -speed;
		noKeyWasPressed = false;
		setLeft();
	}

	if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
	{
		currentAnimation = &walkingAnimationRight;
		movement.x = speed;
		noKeyWasPressed = false;
		setRight();
	}

	animatedSprite.play(*currentAnimation);
	animatedSprite.move(movement * frameTime.asSeconds());

	if (noKeyWasPressed)
	{
		animatedSprite.stop();
	}
	noKeyWasPressed = true;

	animatedSprite.update(frameTime);
}

void Character::draw(RenderWindow& window)
{
	window.draw(animatedSprite);
}

bool Character::collision_car() { return true; }
bool Character::collision_obj() { return false; }
void Character::changeskin(){}