#ifndef CAR1_H
#define CAR1_H

#include "Vehicle.h"

class Car1 : public Vehicle {
public:
	Car1(float xPos, float yPos, std::string type) : Vehicle(xPos, yPos, type) {}

	void draw(RenderWindow& window) override;
};

#endif // CAR1_H
