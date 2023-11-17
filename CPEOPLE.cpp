#include <SFML/Graphics.hpp>
#include "Champion.h"
#include <iostream>


void CPEOPLE::move(sf::RenderWindow& window, float peopleWidth, float peopleHeight)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && position.x > 0 && !movingCalled)
    {
        position.x -= speed;
        movingCalled = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && position.x < window.getSize().x - peopleWidth && !movingCalled)
    {
        position.x += speed;
        movingCalled = true;

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && position.y < window.getSize().y - peopleHeight && !movingCalled)
    {
        position.y += speed;
        movingCalled = true;

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && position.y > 0 && !movingCalled)
    {
        position.y -= speed;
        movingCalled = true;

    }

    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
        !sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
        !sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
        !sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        movingCalled = false;
    }
}

float CPEOPLE::getSpeed()
{
    return speed;
}

sf::Vector2f CPEOPLE::getPosition()
{
    return position; //position.x de lay x hoac position.y de lay y
}

int main() 
{
    CPEOPLE champion;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Example");

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        champion.move(window, 15.f, 30.f);
        std::cout << champion.getPosition().x << " " << champion.getPosition().y << std::endl;

    }
    return 0;
}

