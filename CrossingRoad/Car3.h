#ifndef CAR3_H
#define CAR3_H

#include "Vehicle.h"
#include "AnimationCar3.h"

class Car3 : public Vehicle {
private:
	AnimationCar3 animationCar3;

public:
	Car3();
	Car3(float xPos, float yPos);

	void updatePosition(float speed) override;
	void draw(RenderWindow& window) override;
};

#endif // CAR3_H
