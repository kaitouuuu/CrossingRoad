#ifndef CHAMPION_H
#define CHAMPION_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Champion {
public:
    Champion();

    void move(sf::RenderWindow& window, float x, float y);

    float getSpeed();

    sf::Vector2f getPosition();
private:
    float speed;
    sf::Vector2f position;
    bool movingCalled;
};
#endif