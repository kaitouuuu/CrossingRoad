#ifndef CAR1_H
#define CAR1_H

#include "Vehicle.h"
#include "AnimationCar1.h"

class Car1 : public Vehicle {
private:
	AnimationCar1 animationCar1;

public:
	Car1();
	Car1(float xPos, float yPos);

	void clearAnimation();

	void updatePosition(float speed, bool isappearEsc) override;
	void draw(RenderWindow& window) override;
};

#endif // CAR1_H
