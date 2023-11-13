#include <SFML/Graphics.hpp>
#include <iostream>

class Champion {
public:
    Champion() : speed(10.f), position(400.f, 300.f), movingCalled(false) {};

    void move(sf::RenderWindow& window, float x, float y) 
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && position.x > 0 && !movingCalled) 
        {
            position.x -= speed;
            movingCalled = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && position.x < window.getSize().x - x && !movingCalled) 
        {
            position.x += speed;
            movingCalled = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && position.y < window.getSize().y - y && !movingCalled) 
        {
            position.y += speed;
            movingCalled = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && position.y > 0 && !movingCalled) 
        {
            position.y -= speed;
            movingCalled = true;
        }

        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) 
        {
            movingCalled = false;
        }
    }
     
    float getSpeed()
    {
        return speed;
    }

    sf::Vector2f getPosition()
    {
        return position;
    }

private:
    float speed;
    sf::Vector2f position;
    bool movingCalled;
};

int main() {
    Champion champion;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Example");

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        champion.move(window, 400.f, 300.f);
    }
    return 0;
}

