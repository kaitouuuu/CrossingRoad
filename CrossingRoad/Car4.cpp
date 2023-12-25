#include "Car4.h"

Car4::Car4()
{

}

Car4::Car4(float xPos, float yPos) : Vehicle(xPos, yPos, "White")
{
	AnimationCar4 tmp("Content/Image/WhiteCarSprite.png", xPos, yPos, 72.f, 52.f, true, false);
	animationCar4 = tmp;
}

void Car4::updatePosition(float speed)
{
	Vehicle::updatePosition(speed);
	animationCar4.update(speed);
}

void Car4::draw(RenderWindow& window)
{
	Vehicle::draw(window);
	animationCar4.draw(window);
}