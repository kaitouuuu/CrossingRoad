#ifndef CAR2_H
#define CAR2_H

#include "Vehicle.h"
#include "AnimationCar2.h"

class Car2 : public Vehicle {
private:
	AnimationCar2 animationCar2;

public:
	Car2();
	Car2(float xPos, float yPos);

	void updatePosition(float speed, bool isappearEsc) override;
	void draw(RenderWindow& window) override;
};

#endif // CAR2_H
