#include "CPEOPLE.h"
#include "Object.h"
#include <iostream>

char CPEOPLE::checkDirection(sf::RenderWindow& window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !movingCalled)
    {
        movingCalled = true;
        return 'A';
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !movingCalled)
    {
        movingCalled = true;
        return 'D';
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !movingCalled)
    {
        movingCalled = true;
        return 'S';
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !movingCalled)
    {
        movingCalled = true;
        return 'W';
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
        !sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
        !sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
        !sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        movingCalled = false;
    }
    return '\0';
}


float CPEOPLE::getSpeed()
{
    return speed;
}

sf::Vector2f CPEOPLE::getPosition()
{
    return position; // position.x de lay x hoac position.y de lay y
}

bool CPEOPLE::checkCollision(float xObject, float yObject, float objectWidth, float objectHeight)
{
    //return 1 if collided
    return ((position.x + peopleWidth >= xObject) &&
        (position.y + peopleHeight >= yObject) &&
        (position.y - objectHeight <= yObject) &&
        (position.x - objectWidth <= xObject));
}

int main()
{
    CPEOPLE champion;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Example");
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        champion.checkDirection(window);
    }
    return 0;
}

