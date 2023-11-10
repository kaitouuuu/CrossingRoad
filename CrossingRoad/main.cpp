#include <SFML/Graphics.hpp>
#include "Button.h"

using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
	Button B("Content/Image/test0.png", 50, 50);

	while (window.isOpen())
	{
		Vector2f mouse = window.mapPixelToCoords(Mouse::getPosition(window));

		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) {
				window.close();
			}
		}

		window.clear();
		B.draw(window, mouse);
		window.display();
	}
}