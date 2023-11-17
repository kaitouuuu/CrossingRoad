#ifndef CHAMPION_H
#define CHAMPION_H

#include <SFML/Graphics.hpp>
#include <iostream>
class CPEOPLE
{
public:
    CPEOPLE() : speed(10.f), position(400.f,600.f), movingCalled(false), isDead(false) {};
    void move(sf::RenderWindow& window, float peopleWidth, float peopleHeight);
    float getSpeed();
    sf::Vector2f getPosition();
private:
    float speed;
    sf::Vector2f position;
    bool movingCalled;
    bool isDead;
};
#endif