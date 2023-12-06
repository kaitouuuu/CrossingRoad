#include "displayMenu.h"

void displayMenu(RenderWindow& window)
{
	//Test
	window.setFramerateLimit(60);
	View view;
	view.setCenter(960, 540);
	view.setSize(Vector2f(1920, 1080));
	window.setView(view);

	Texture Image;
	Image.loadFromFile("Content/Image/Screen.png");
	Sprite Screen(Image);
	Screen.setPosition(0, 0);

	Button A("Content/Image/test0.png", 0, 0);
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

	Character character("Content/Image/Character1.png", 700, 200, true, false);

	Object ob1(500, 500, 48, 48);
	Object ob2(600, 600, 48, 48);
	Object wall1(-20, -100000, 20, 101080);
	Object wall2(1920, -100000, 20, 101080);

	vector<Object> o;
	o.push_back(ob1);
	o.push_back(ob2);
	o.push_back(wall1);
	o.push_back(wall2);

	Clock frameClock;

	while (window.isOpen()) {
		Vector2f mouse = window.mapPixelToCoords(Mouse::getPosition(window));
		Event e;

		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) {
				window.close();
			}
			character.changeSkin();
		}

		character.update(frameClock, o);
		//cout << window.getPosition().x << " " << window.getPosition().y << endl;
		if (character.getPositionY() < view.getCenter().y - 540) {
			view.setCenter(960, view.getCenter().y - 1016);
			window.setView(view);
		}

		window.clear(Color::White);
		window.draw(Screen);

		sf::RectangleShape rectangle(sf::Vector2f(48, 48));  // Rectangle size (width, height)
		rectangle.setFillColor(sf::Color::Black);  // Set the fill color to black
		rectangle.setPosition(500, 500);  // Set the position of the rectangle
		window.draw(rectangle);  // Draw the rectangle to the window

		sf::RectangleShape rectangle1(sf::Vector2f(48, 48));  // Rectangle size (width, height)
		rectangle1.setFillColor(sf::Color::Black);  // Set the fill color to black
		rectangle1.setPosition(600, 600);  // Set the position of the rectangle
		window.draw(rectangle1);  // Draw the rectangle to the window

		character.draw(window);
		m.draw(window, mouse);
		window.display();
	}
}

//void displayMenu(RenderWindow& window)
//{
//	window.setFramerateLimit(60);
//
//	Texture Image;
//	Image.loadFromFile("Content/Image/Screen.png");
//	Sprite Screen(Image);
//	Screen.setPosition(0, 0);
//
//	Button NewGame("Content/Image/NewGame0.png", 500, 500);
//	Button Rule("Content/Image/Rule0.png", 500, 600);
//	Button C("Content/Image/test0.png", 50, 250);
//
//	vector<Button> b;
//	b.push_back(NewGame);
//	b.push_back(Rule);
//	b.push_back(C);
//
//	TextBox At("Content/Font/SuperMario256.ttf", Color::Black, "Hi", 25, 500, 500);
//	TextBox Bt("Content/Font/SuperMario256.ttf", Color::Black, "Hello", 25, 500, 650);
//	TextBox Ct("Content/Font/SuperMario256.ttf", Color::Black, "Bye", 25, 500, 800);
//
//	vector<TextBox> t;
//	t.push_back(At);
//	t.push_back(Bt);
//	t.push_back(Ct);
//
//	MainMenu m(t, b);
//
//	while (window.isOpen()) {
//		Vector2f mouse = window.mapPixelToCoords(Mouse::getPosition(window));
//		Event e;
//
//		while (window.pollEvent(e)) {
//			if (e.type == Event::Closed) {
//				window.close();
//			}
//		}
//
//		window.clear(Color::White);
//
//		window.draw(Screen);
//
//		m.draw(window, mouse);
//
//		window.display();
//	}
//}