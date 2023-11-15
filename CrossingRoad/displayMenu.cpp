#include "displayMenu.h"

void displayMenu(RenderWindow& window)
{
	window.setFramerateLimit(60);

	Button A("Content/Image/test0.png", 50, 50);
	Button B("Content/Image/test0.png", 50, 150);
	Button C("Content/Image/test0.png", 50, 250);

	vector<Button> b;
	b.push_back(A);
	b.push_back(B);
	b.push_back(C);
	
	TextBox At("Content/Font/SuperMario256.ttf", Color::Black, "Hi", 25, 500, 500);
	TextBox Bt("Content/Font/SuperMario256.ttf", Color::Black, "Hello", 25, 500, 650);
	TextBox Ct("Content/Font/SuperMario256.ttf", Color::Black, "Bye", 25, 500, 800);

	vector<TextBox> t;
	t.push_back(At);
	t.push_back(Bt);
	t.push_back(Ct);

	MainMenu m(t, b);

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

		character.update(frameClock);

		window.clear(Color::White);
		character.draw(window);
		m.draw(window, mouse);
		window.display();
	}
}