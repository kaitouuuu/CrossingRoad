#ifndef CAR4_H
#define CAR4_H

#include "Vehicle.h"
#include "AnimationCar4.h"

class Car4 : public Vehicle {
private:
	AnimationCar4 animationCar4;

public:
	Car4();
	Car4(float xPos, float yPos);

	void updatePosition(float speed) override;
	void draw(RenderWindow& window) override;
};

#endif // CAR4_H
