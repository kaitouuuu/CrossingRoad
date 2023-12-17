#ifndef CAR2_H
#define CAR2_H

#include "Vehicle.h"

class Car2 : public Vehicle {
public:
	Car2(float xPos, float yPos, std::string type) : Vehicle(xPos, yPos, type) {
		setSpriteColor(Color::White);
	}

	void draw(RenderWindow& window) override;
};

#endif // CAR2_H
