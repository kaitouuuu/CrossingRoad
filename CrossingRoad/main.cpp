#include <SFML/Graphics.hpp>
#include "displayMenu.h"

using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
	displayMenu(window);
}