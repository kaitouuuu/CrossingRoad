#include "Car3.h"

Car3::Car3()
{
}

Car3::Car3(float xPos, float yPos) : Vehicle(xPos + 8, yPos + 16, "Black")
{
	AnimationCar3 tmp("Content/Image/BlackCarSprite.png", xPos, yPos, 72.f, 52.f, true, false);
	animationCar3 = tmp;
}

void Car3::clearAnimation()
{
	animationCar3.gameOver();
}

void Car3::updatePosition(float speed, bool isappearEsc)
{
	Vehicle::updatePosition(speed,isappearEsc);
	animationCar3.update(speed,isappearEsc);
}

void Car3::draw(RenderWindow& window)
{
	Vehicle::draw(window);
	animationCar3.draw(window);
}
