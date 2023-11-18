#include "Road.h"

Road::Road(float yPos, bool hasTrafficLight, sf::Color trafficLightColor, float speed)
    : yPos(yPos), hasTrafficLight(hasTrafficLight),
    trafficLightColor(trafficLightColor), speed(speed) {}

float Road::getYPosition() const
{
    return yPos;
}

bool Road::getHasTrafficLight() const
{
    return hasTrafficLight;
}

sf::Color Road::getTrafficLightColor() const
{
    return trafficLightColor;
}

float Road::getSpeed() const
{
    return speed;
}

void Road::addCar(const Vehicle& addedCar)
{
    cars.push_back(addedCar);

    for (int i = 0; i < cars.size(); ++i)
    {
        if (cars[i].getXPosition() > addedCar.getXPosition())
        {
            std::swap(cars[i], cars.back());
            break;
        }
    }
}

void Road::updateCars()
{
    bool deleteCarFront = false;
    bool deleteCarBack = false;
    Vehicle rotateCar;

    for (Vehicle& car : cars)
    {
        car.updatePosition(speed);
        if (car.getXPosition() >= 1920)
        {
            rotateCar = car;
            deleteCarBack = true;
        }
        if (car.getXPosition() < 0)
        {
            rotateCar = car;
            deleteCarFront = true;
        }
    }

    if (deleteCarBack == true)
    {
        cars.pop_back();
        rotateCar.rotatePosition(false);
        cars.push_front(rotateCar);
    }

    if (deleteCarFront == true)
    {
        cars.pop_front();
        rotateCar.rotatePosition(true);
        cars.push_back(rotateCar);
    }
}

void Road::printCar() {
    for (Vehicle& car : cars)
    {
        std::cout << car.getXPosition() << " " << car.getYPosition() << " ";
    }
    std::cout << std::endl;
}