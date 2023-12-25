#include "Car3.h"

Car3::Car3()
{

}

Car3::Car3(float xPos, float yPos) : Vehicle(xPos, yPos, "Black")
{
	AnimationCar3 tmp("Content/Image/BlackCarSprite.png", xPos, yPos, 72.f, 52.f, true, false);
	animationCar3 = tmp;
}

void Car3::updatePosition(float speed)
{
	Vehicle::updatePosition(speed);
	animationCar3.update(speed);
}

void Car3::draw(RenderWindow& window)
{
	Vehicle::draw(window);
	animationCar3.draw(window);
}