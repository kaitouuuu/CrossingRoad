#include "Car1.h"

Car1::Car1()
{

}

Car1::Car1(float xPos, float yPos) : Vehicle(xPos, yPos, "Red")
{
	AnimationCar1 tmp("Content/Image/RedCarSprite.png", xPos, yPos, 72.f, 52.f, true, false);
	animationCar1 = tmp;
}

void Car1::updatePosition(float speed)
{
	Vehicle::updatePosition(speed);
	animationCar1.update(speed);
}

void Car1::draw(RenderWindow& window)
{
	Vehicle::draw(window);
	animationCar1.draw(window);
}