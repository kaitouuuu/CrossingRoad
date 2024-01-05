#ifndef CAR5_H
#define CAR5_H

#include "Vehicle.h"
#include "AnimationCar5.h"

class Car5 : public Vehicle {
private:
	AnimationCar5 animationCar5;

public:
	Car5();
	Car5(float xPos, float yPos);

	void clearAnimation();
	void updatePosition(float speed, bool isappearEsc) override;
	void draw(RenderWindow& window) override;
};


#endif // CAR5_H
