#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
private:
    float xPos;
    float yPos;
    std::string type;

public:
    Vehicle();
    Vehicle(float xPos, float yPos, std::string type);

    float getXPosition() const;
    float getYPosition() const;
    std::string getType() const;

    void updatePosition(float speed);
    void rotatePosition(bool gotoBack);
};

#endif // VEHICLE_H