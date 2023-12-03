#include "character.h"

void Character::setMoveUp()
{
	int w = 48;
	walkingAnimationUp.setSpriteSheet(texture);
	walkingAnimationUp.addFrame(sf::IntRect(1 * w, 1 * w, 1 * w, 1 * w));
	walkingAnimationUp.addFrame(sf::IntRect(2 * w, 1 * w, 1 * w, 1 * w));
	walkingAnimationUp.addFrame(sf::IntRect(1 * w, 1 * w, 1 * w, 1 * w));
	walkingAnimationUp.addFrame(sf::IntRect(3 * w, 1 * w, 1 * w, 1 * w));
}

void Character::setMoveDown()
{
	int w = 48;
	walkingAnimationDown.setSpriteSheet(texture);
	walkingAnimationDown.addFrame(sf::IntRect(1 * w, 0 * w, 1 * w, 1 * w));
	walkingAnimationDown.addFrame(sf::IntRect(2 * w, 0 * w, 1 * w, 1 * w));
	walkingAnimationDown.addFrame(sf::IntRect(1 * w, 0 * w, 1 * w, 1 * w));
	walkingAnimationDown.addFrame(sf::IntRect(3 * w, 0 * w, 1 * w, 1 * w));
}

void Character::setMoveLeft()
{
	int w = 48;
	walkingAnimationLeft.setSpriteSheet(texture);
	walkingAnimationLeft.addFrame(sf::IntRect(1 * w, 2 * w, 1 * w, 1 * w));
	walkingAnimationLeft.addFrame(sf::IntRect(2 * w, 2 * w, 1 * w, 1 * w));
	walkingAnimationLeft.addFrame(sf::IntRect(1 * w, 2 * w, 1 * w, 1 * w));
	walkingAnimationLeft.addFrame(sf::IntRect(3 * w, 2 * w, 1 * w, 1 * w));
}

void Character::setMoveRight()
{
	int w = 48;
	walkingAnimationRight.setSpriteSheet(texture);
	walkingAnimationRight.addFrame(sf::IntRect(1 * w, 3 * w, 1 * w, 1 * w));
	walkingAnimationRight.addFrame(sf::IntRect(2 * w, 3 * w, 1 * w, 1 * w));
	walkingAnimationRight.addFrame(sf::IntRect(1 * w, 3 * w, 1 * w, 1 * w));
	walkingAnimationRight.addFrame(sf::IntRect(3 * w, 3 * w, 1 * w, 1 * w));
}

void Character::setUp()
{
	int w = 48;
	walkingAnimationUp.setSpriteSheet(texture);
	walkingAnimationUp.addFrame(sf::IntRect(0 * w, 1 * w, 1 * w, 1 * w));
	walkingAnimationUp.addFrame(sf::IntRect(1 * w, 1 * w, 1 * w, 1 * w));
}

void Character::setDown()
{
	int w = 48;
	walkingAnimationDown.setSpriteSheet(texture);
	walkingAnimationDown.addFrame(sf::IntRect(0 * w, 0 * w, 1 * w, 1 * w));
	walkingAnimationDown.addFrame(sf::IntRect(1 * w, 0 * w, 1 * w, 1 * w));
}

void Character::setLeft()
{
	int w = 48;
	walkingAnimationLeft.setSpriteSheet(texture);
	walkingAnimationLeft.addFrame(sf::IntRect(0 * w, 2 * w, 1 * w, 1 * w));
	walkingAnimationLeft.addFrame(sf::IntRect(1 * w, 2 * w, 1 * w, 1 * w));
}

void Character::setRight()
{
	int w = 48;
	walkingAnimationRight.setSpriteSheet(texture);
	walkingAnimationRight.addFrame(sf::IntRect(0 * w, 3 * w, 1 * w, 1 * w));
	walkingAnimationRight.addFrame(sf::IntRect(1 * w, 3 * w, 1 * w, 1 * w));
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

	isCleared = true;
	type = 1;

	noKeyWasPressed = true;
	isLose = false;
}

void Character::update(Clock& frameClock, vector<Object> o)
{
	Time frameTime = frameClock.restart();

	Vector2f movement(0.f, 0.f);

	if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
	{
		if (checkCollision(o)) {
			if (!isCleared) {
				walkingAnimationUp.clearFrame();
				walkingAnimationDown.clearFrame();
				walkingAnimationLeft.clearFrame();
				walkingAnimationRight.clearFrame();
				isCleared = true;
			}
			for (int i = 0; i < 100; ++i)
				setUp();
		}
		else {
			if (isCleared) {
				walkingAnimationUp.clearFrame();
				walkingAnimationDown.clearFrame();
				walkingAnimationLeft.clearFrame();
				walkingAnimationRight.clearFrame();
				isCleared = false;
			}
			for (int i = 0; i < 100; ++i)
				setMoveUp();
			movement.y = -speed;
		}
		type = 0;
		noKeyWasPressed = false;
		currentAnimation = &walkingAnimationUp;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
	{
		if (checkCollision(o)) {
			if (!isCleared) {
				walkingAnimationUp.clearFrame();
				walkingAnimationDown.clearFrame();
				walkingAnimationLeft.clearFrame();
				walkingAnimationRight.clearFrame();
				isCleared = true;
			}
			for (int i = 0; i < 100; ++i)
				setDown();
		}
		else {
			if (isCleared) {
				walkingAnimationUp.clearFrame();
				walkingAnimationDown.clearFrame();
				walkingAnimationLeft.clearFrame();
				walkingAnimationRight.clearFrame();
				isCleared = false;
			}
			for (int i = 0; i < 100; ++i)
				setMoveDown();
			movement.y = speed;
		}
		type = 1;
		noKeyWasPressed = false;
		currentAnimation = &walkingAnimationDown;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
	{
		if (checkCollision(o)) {
			if (!isCleared) {
				walkingAnimationUp.clearFrame();
				walkingAnimationDown.clearFrame();
				walkingAnimationLeft.clearFrame();
				walkingAnimationRight.clearFrame();
				isCleared = true;
			}
			for (int i = 0; i < 100; ++i)
				setLeft();
		}
		else {
			if (isCleared) {
				walkingAnimationUp.clearFrame();
				walkingAnimationDown.clearFrame();
				walkingAnimationLeft.clearFrame();
				walkingAnimationRight.clearFrame();
				isCleared = false;
			}
			for (int i = 0; i < 100; ++i)
				setMoveLeft();
			movement.x = -speed;
		}
		type = 2;
		noKeyWasPressed = false;
		currentAnimation = &walkingAnimationLeft;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
	{
		if (checkCollision(o)) {
			if (!isCleared) {
				walkingAnimationUp.clearFrame();
				walkingAnimationDown.clearFrame();
				walkingAnimationLeft.clearFrame();
				walkingAnimationRight.clearFrame();
				isCleared = true;
			}
			for (int i = 0; i < 100; ++i)
				setRight();
		}
		else {
			if (isCleared) {
				walkingAnimationUp.clearFrame();
				walkingAnimationDown.clearFrame();
				walkingAnimationLeft.clearFrame();
				walkingAnimationRight.clearFrame();
				isCleared = false;
			}
			for (int i = 0; i < 100; ++i)
				setMoveRight();
			movement.x = speed;
		}
		type = 3;
		noKeyWasPressed = false;
		currentAnimation = &walkingAnimationRight;
	}

	if (noKeyWasPressed)
	{
		if (type == 0) {
			if (!isCleared) {
				walkingAnimationUp.clearFrame();
				walkingAnimationDown.clearFrame();
				walkingAnimationLeft.clearFrame();
				walkingAnimationRight.clearFrame();
				isCleared = true;
			}
			for (int i = 0; i < 100; ++i)
				setUp();
			currentAnimation = &walkingAnimationUp;
		}

		if (type == 1) {
			if (!isCleared) {
				walkingAnimationUp.clearFrame();
				walkingAnimationDown.clearFrame();
				walkingAnimationLeft.clearFrame();
				walkingAnimationRight.clearFrame();
				isCleared = true;
			}
			for (int i = 0; i < 100; ++i)
				setDown();
			currentAnimation = &walkingAnimationDown;
		}

		if (type == 2) {
			if (!isCleared) {
				walkingAnimationUp.clearFrame();
				walkingAnimationDown.clearFrame();
				walkingAnimationLeft.clearFrame();
				walkingAnimationRight.clearFrame();
				isCleared = true;
			}
			for (int i = 0; i < 100; ++i)
				setLeft();
			currentAnimation = &walkingAnimationLeft;
		}

		if (type == 3) {
			if (!isCleared) {
				walkingAnimationUp.clearFrame();
				walkingAnimationDown.clearFrame();
				walkingAnimationLeft.clearFrame();
				walkingAnimationRight.clearFrame();
				isCleared = true;
			}
			for (int i = 0; i < 100; ++i)
				setRight();
			currentAnimation = &walkingAnimationRight;
		}
	}

	animatedSprite.play(*currentAnimation);
	animatedSprite.move(movement * frameTime.asSeconds());

	noKeyWasPressed = true;

	animatedSprite.update(frameTime);

	x = animatedSprite.getPosition().x;
	y = animatedSprite.getPosition().y;
}

void Character::draw(RenderWindow& window)
{
	window.draw(animatedSprite);
}

bool Character::checkCollision(vector<Object> o)
{
	float tmpx = x;
	float tmpy = y;
	if (type == 0) {
		tmpy -= 0.1f;
	}
	else if (type == 1) {
		tmpy += 0.1f;
	}
	else if (type == 2) {
		tmpx -= 0.1f;
	}
	else if (type == 3) {
		tmpx += 0.1f;
	} 
	for (int i = 0; i < o.size(); ++i) {
		if ((tmpx + 48 >= o[i].getX()) && (tmpy + 48 >= o[i].getY()) && (tmpy - o[i].getHeight() <= o[i].getY()) && (tmpx - o[i].getWidth() <= o[i].getX())) {
			if (type == 0) {
				y = o[i].getY() + o[i].getHeight() + 0.01f;
				animatedSprite.setPosition(x, y);
			}
			else if (type == 1) {
				y = o[i].getY() - 48.01f;
				animatedSprite.setPosition(x, y);
			}
			else if (type == 2) {
				x = o[i].getX() + o[i].getWidth() + 0.01f;
				animatedSprite.setPosition(x, y);
			}
			else if (type == 3) {
				x = o[i].getX() - 48.01f;
				animatedSprite.setPosition(x, y);
			}
			return true;
		}
	}
	return false;
}

float Character::getY()
{
	return y;
}

float Character::getX()
{
	return x;
}
void Character::changeskin() {}