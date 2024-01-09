#include "Car4.h"

Car4::Car4()
{
}

Car4::Car4(float xPos, float yPos) : Vehicle(xPos + 8, yPos + 16, "White")
{
	AnimationCar4 tmp("Content/Image/WhiteCarSprite.png", xPos, yPos, 72.f, 52.f, true, false);
	animationCar4 = tmp;
}

void Car4::clearAnimation()
{
	animationCar4.gameOver();
}

void Car4::updatePosition(float speed, bool isappearEsc)
{
	Vehicle::updatePosition(speed,isappearEsc);
	animationCar4.update(speed,isappearEsc);
}

void Car4::draw(RenderWindow& window)
{
	Vehicle::draw(window);
	animationCar4.draw(window);
}