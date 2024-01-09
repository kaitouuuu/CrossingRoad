#include "Car1.h"

Car1::Car1()
{
}

Car1::Car1(float xPos, float yPos) : Vehicle(xPos + 8, yPos + 16, "Red")
{
	AnimationCar1 tmp("Content/Image/RedCarSprite.png", xPos, yPos, 72.f, 52.f, true, false);
	animationCar1 = tmp;
}

void Car1::clearAnimation()
{
	animationCar1.gameOver();
}

void Car1::updatePosition(float speed, bool isappearEsc)
{
	Vehicle::updatePosition(speed,isappearEsc);
	animationCar1.update(speed,isappearEsc);
}

void Car1::draw(RenderWindow& window)
{
	Vehicle::draw(window);
	animationCar1.draw(window);
}