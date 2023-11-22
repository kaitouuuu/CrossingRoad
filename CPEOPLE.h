#ifndef CPEOPLE_H
#define CPEOPLE_H

#include <SFML/Graphics.hpp>
#include <iostream>
class CPEOPLE
{
public:
    CPEOPLE() : speed(10.f), position(400.f,600.f), movingCalled(false), isDead(false) {};
    char checkDirection(sf::RenderWindow& window);
    float getSpeed();
    sf::Vector2f getPosition();
    bool checkCollision(float xObject, float yObject, float width, float height); 
private:
    float speed;
    sf::Vector2f position;
    float peopleWidth;
    float peopleHeight;
    bool movingCalled;
    bool isDead;
    char lastKeyPressed;
};
#endif