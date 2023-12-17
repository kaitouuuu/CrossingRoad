#ifndef CAR3_H
#define CAR3_H

#include "Vehicle.h"

class Car3 : public Vehicle {
public:
	Car3(float xPos, float yPos, std::string type) : Vehicle(xPos, yPos, type) {
		setSpriteColor(Color(173, 99, 29));
	}

	void draw(RenderWindow& window) override;
};

#endif // CAR3_H
