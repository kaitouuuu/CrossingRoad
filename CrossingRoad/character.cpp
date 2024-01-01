#include "Character.h"

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

Character::Character() 
{

}

Character::Character(string fileName, float x, float y, float width, float height, bool paused, bool looped)
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

	speed = 120.f;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

	isCleared = true;
	type = 1;

	noKeyWasPressed = true;
}

void Character::update(Clock& frameClock, Road& aRoad,Event& e,bool isappearesc)
{
	Time frameTime = frameClock.restart();

	Vector2f movement(0.f, 0.f);
	
	if (!isappearesc) {
		std::string action;
		for (const auto& pair : keyMap) {
			if (sf::Keyboard::isKeyPressed(pair.second)) {
				cout << "Keyboard is pressed\n";
				action = pair.first;
			}
		}
		if (action == "Move Up: ")
		{
			if (checkCollision(aRoad) == 1)
			{
				if (!isCleared)
				{
					walkingAnimationUp.clearFrame();
					walkingAnimationDown.clearFrame();
					walkingAnimationLeft.clearFrame();
					walkingAnimationRight.clearFrame();
					isCleared = true;
				}
				for (int i = 0; i < 100; ++i)
					setUp();
			}
			else
			{
				if (isCleared)
				{
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
		else if (action == "Move Down: ")
		{
			if (checkCollision(aRoad) == 1)
			{
				if (!isCleared)
				{
					walkingAnimationUp.clearFrame();
					walkingAnimationDown.clearFrame();
					walkingAnimationLeft.clearFrame();
					walkingAnimationRight.clearFrame();
					isCleared = true;
				}
				for (int i = 0; i < 100; ++i)
					setDown();
			}
			else
			{
				if (isCleared)
				{
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
		else if (action == "Move Left: ")
		{
			if (checkCollision(aRoad) == 1)
			{
				if (!isCleared)
				{
					walkingAnimationUp.clearFrame();
					walkingAnimationDown.clearFrame();
					walkingAnimationLeft.clearFrame();
					walkingAnimationRight.clearFrame();
					isCleared = true;
				}
				for (int i = 0; i < 100; ++i)
					setLeft();
			}
			else
			{
				if (isCleared)
				{
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
		else if (action == "Move Right: ")
		{
			if (checkCollision(aRoad) == 1)
			{
				if (!isCleared)
				{
					walkingAnimationUp.clearFrame();
					walkingAnimationDown.clearFrame();
					walkingAnimationLeft.clearFrame();
					walkingAnimationRight.clearFrame();
					isCleared = true;
				}
				for (int i = 0; i < 100; ++i)
					setRight();
			}
			else
			{
				if (isCleared)
				{
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
			if (type == 0)
			{
				if (!isCleared)
				{
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

			if (type == 1)
			{
				if (!isCleared)
				{
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

			if (type == 2)
			{
				if (!isCleared)
				{
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

			if (type == 3)
			{
				if (!isCleared)
				{
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
	}
		x = animatedSprite.getPosition().x;
		y = animatedSprite.getPosition().y;
		//}
	//}
	
}

void Character::draw(RenderWindow &window)
{
	window.draw(animatedSprite);
}

float Character::getWidth()
{
	return width;
}

float Character::getHeight()
{
	return height;
}

bool Character::condition(float xTL, float yTL, float objH, float objW)
{
	float checkX = max(xTL, x);
	float checkY = max(yTL, y);
	float checkX2 = min(xTL + objW, x + width);
	float checkY2 = min(yTL + objH, y + height);
	if (checkX <= checkX2 && checkY <= checkY2) {
		//std::cout << xTL << " " << yTL << " " << objH << " " << objW << " " << x << " " << y << " " << width << " " << height << std::endl;
		return true;
	}
	return false;
}

int Character::checkCollision(Road &aRoad)
{
	float tmpx = x;
	float tmpy = y;
	// 0: Up, 1: Down, 2: Left, 3: Right
	if (type == 0)
	{
		tmpy -= 0.1f;
	}
	else if (type == 1)
	{
		tmpy += 0.1f;
	}
	else if (type == 2)
	{
		tmpx -= 0.1f;
	}
	else if (type == 3)
	{
		tmpx += 0.1f;
	}
	if (!(0 <= tmpx && tmpx + 48 < 1920 && 0 <= tmpy && tmpy + 48 < 1080)) // check out of bound
	{
		if (type == 0)
		{
			y = 0.01f;
			animatedSprite.setPosition(x, y);
			return 2;
		}
		else if (type == 1)
		{
			y = 1080 - 48.01f;
			animatedSprite.setPosition(x, y);
		}
		else if (type == 2)
		{
			x = 0.01f;
			animatedSprite.setPosition(x, y);
		}
		else if (type == 3)
		{
			x = 1920 - 48.01f;
			animatedSprite.setPosition(x, y);
		}
	}
	if (aRoad.getType() != "Field")
	{
		for (int i = 0; i < aRoad.vehicles.size(); ++i)
		{
			// tmpx + 48 >= aRoad.vehicles[i].getX()) && (tmpy + 48 >= aRoad.vehicles[i].getY()) && (tmpy - aRoad.vehicles[i].getHeight() <= aRoad.vehicles[i].getY()) && (tmpx - aRoad.vehicles[i].getWidth() <= aRoad.vehicles[i].getX()))
			if (condition(aRoad.vehicles[i]->getX(), aRoad.vehicles[i]->getY(), aRoad.vehicles[i]->getHeight(), aRoad.vehicles[i]->getWidth()))
			{
				return 1;
			}
		}
	}
	else
	{
		for (int i = 0; i < aRoad.objects.size(); ++i)
		{
			if (condition(aRoad.objects[i].getX(), aRoad.objects[i].getY(), aRoad.objects[i].getHeight(), aRoad.objects[i].getWidth()))
			{
				if (type == 0)
				{
					y = aRoad.objects[i].getY() + aRoad.objects[i].getHeight() + 0.01f;
					animatedSprite.setPosition(x, y);
				}
				else if (type == 1)
				{
					y = aRoad.objects[i].getY() - 48.01f;
					animatedSprite.setPosition(x, y);
				}
				else if (type == 2)
				{
					x = aRoad.objects[i].getX() + aRoad.objects[i].getWidth() + 0.01f;
					animatedSprite.setPosition(x, y);
				}
				else if (type == 3)
				{
					x = aRoad.objects[i].getX() - 48.01f;
					animatedSprite.setPosition(x, y);
				}
			}
		}
	}
	return 0;
}

float Character::getY()
{
	return y;
}

float Character::getX()
{
	return x;
}

void Character::changeSkin()
{
	std::string action;
	for (const auto& pair : keyMap) {
		if (sf::Keyboard::isKeyPressed(pair.second)) {
			cout << "Keyboard is pressed\n";
			action = pair.first;
		}
	}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
	if(action=="Change Skin: "){
		if (skin < 4) {
			++skin;
		}
		else {
			skin = 0;
		}

		if (skin == 0) {
			animatedSprite.setColor(Color::White);
		}
		else if (skin == 1) {
			animatedSprite.setColor(Color(255, 165, 79));
		}
		else if (skin == 2) {
			animatedSprite.setColor(Color(139, 69, 19));
		}
		else if (skin == 3) {
			animatedSprite.setColor(Color(82, 84, 41));
		}
		else if (skin == 4) {
			animatedSprite.setColor(Color(176, 250, 255));
		}
	}
}

void Character::updatekeymap(map<std::string, sf::Keyboard::Key> keyMap) {
	this->keyMap.clear();
	for (const auto& pair : keyMap) {
		this->keyMap.emplace(pair);
	}
}