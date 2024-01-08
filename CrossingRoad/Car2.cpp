#include "Car2.h"

Car2::Car2()
{

}

Car2::Car2(float xPos, float yPos) : Vehicle(xPos + 8, yPos + 16, "Blue")
{
	AnimationCar2 tmp("Content/Image/BlueCarSprite.png", xPos, yPos, 72.f, 52.f, true, false);
	animationCar2 = tmp;
}

void Car2::clearAnimation()
{
	animationCar2.gameOver();
}

void Car2::updatePosition(float speed, bool isappearEsc)
{
	Vehicle::updatePosition(speed,isappearEsc);
	
	animationCar2.update(speed,isappearEsc);
}

void Car2::draw(RenderWindow& window)
{
	Vehicle::draw(window);
	animationCar2.draw(window);
}