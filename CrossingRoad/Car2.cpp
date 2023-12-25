#include "Car2.h"

Car2::Car2()
{

}

Car2::Car2(float xPos, float yPos) : Vehicle(xPos, yPos, "Blue")
{
	AnimationCar2 tmp("Content/Image/BlueCarSprite.png", xPos, yPos, 72.f, 52.f, true, false);
	animationCar2 = tmp;
}

void Car2::updatePosition(float speed)
{
	Vehicle::updatePosition(speed);
	animationCar2.update(speed);
}

void Car2::draw(RenderWindow& window)
{
	Vehicle::draw(window);
	animationCar2.draw(window);
}