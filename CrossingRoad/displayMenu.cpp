#include "displayMenu.h"

void displayMenu(RenderWindow& window)
{
	window.setFramerateLimit(60);
	string filename = "Content/Image/UI.jpg";
	Texture backgroundTexture;
	if (!backgroundTexture.loadFromFile(filename)) {
		// Handle error if the image fails to load
		return;
	}

	Sprite background(backgroundTexture);

	Button A("Content/Image/newgame.png", 50, 50);
	Button B("Content/Image/quit.png", 50, 200);
	Button C("Content/Image/loadgame.png", 50, 350);

	vector<Button> b;
	b.push_back(A);
	b.push_back(B);
	b.push_back(C);
	
	//TextBox At("Content/Font/SuperMario256.ttf", Color::Black, "Hi", 25, 500, 500);
	//TextBox Bt("Content/Font/SuperMario256.ttf", Color::Black, "Hello", 25, 500, 650);
	//TextBox Ct("Content/Font/SuperMario256.ttf", Color::Black, "Bye", 25, 500, 800);

	//vector<TextBox> t;
	//t.push_back(At);
	//t.push_back(Bt);
	//t.push_back(Ct);

	MainMenu m( b);

	Character character("Content/Image/Character1.png", 500, 500, true, false);

	Clock frameClock;

	while (window.isOpen()) {
		Vector2f mouse = window.mapPixelToCoords(Mouse::getPosition(window));
		Event e;

		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) {
				window.close();
			}
		}
		if (e.type == sf::Event::Resized) {
			// Calculate the scaling factors for the background image
			float scaleX = static_cast<float>(e.size.width) / background.getLocalBounds().width;
			float scaleY = static_cast<float>(e.size.height) / background.getLocalBounds().height;

			// Set the scale of the background sprite
			background.setScale(scaleX, scaleY);
		}
		if (e.type == sf::Event::MouseButtonPressed) {
			if (e.mouseButton.button == sf::Mouse::Left) {
				// Get the mouse position
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				for (auto& button : b) {
					// Check if the mouse is over the button
					if (button.getglobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
						std::cout << "Button clicked!" << std::endl;
						break;
					}
				}
			}
		}

		character.update(frameClock);

		window.clear(Color::White);
		window.draw(background);
		character.draw(window);
		m.draw(window, mouse);
		window.display();
	}
}