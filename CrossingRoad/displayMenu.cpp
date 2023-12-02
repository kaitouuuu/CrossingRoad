#include "displayMenu.h"

void displayMenu(RenderWindow& window)
{
	window.setFramerateLimit(60);
	string filename = "Content/Image/background.jpg";
	Texture backgroundTexture;
	if (!backgroundTexture.loadFromFile(filename)) {
		// Handle error if the image fails to load
		return;
	}
	
	Sprite background(backgroundTexture);
	

	GameState currentState = GameState::mainmenu;

	Button A("Content/Image/Game.png", 1452, 353,"Game");
	Button B("Content/Image/Rule.png", 1462, 466, "Rule");
	Button C("Content/Image/Setting.png", 1410, 579,"Setting");
	Button D("Content/Image/High score.png", 1403, 692, "High score");
	Button E("Content/Image/Exit.png", 1465, 811, "Exit");
	Button F("Content/Image/New Game.png", 1415, 410, "New game");
	Button G("Content/Image/Load game.png", 1406, 522, "Load game");
	Button H("Content/Image/Back.png", 1483, 634, "Back");
	vector<Button> b;
	b.push_back(A);
	b.push_back(B);
	b.push_back(C);
	b.push_back(D);
	b.push_back(E);


	vector<Button> c;
	c.push_back(F);
	c.push_back(G);
	c.push_back(H);

	TextBox At("Content/Font/SuperMario256.ttf", Color::White, "CROSSY ROAD", 100, 401, 157);
	//TextBox Bt("Content/Font/SuperMario256.ttf", Color::Black, "Hello", 25, 500, 650);
	//TextBox Ct("Content/Font/SuperMario256.ttf", Color::Black, "Bye", 25, 500, 800);

	vector<TextBox> t;
	t.push_back(At);
	//t.push_back(Bt);
	//t.push_back(Ct);
	Menu n(b, t);
	Menu q(c, t);
	//MainMenu m(b);

	//Character character("Content/Image/Character1.png", 500, 500, true, false);



	Clock frameClock;

	while (window.isOpen()) {
		Vector2f mouse = window.mapPixelToCoords(Mouse::getPosition(window));
		Event e;

		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) {
				window.close();
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
					sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
					if(currentState==GameState::mainmenu)
						for (auto& button : b) {
							if (button.isClicked(mousePosF) ){
								if (button.type() == "Game") {
									currentState = GameState::game;
								}
								else if (button.type() == "Setting") {
									currentState = GameState::setting;
								}
								else if (button.type() == "Exit") {
									exit(0);
								}
							}
						}
					else 
						for (auto& button : c) {
							if (button.isClicked(mousePosF)) {
								if (button.type() == "New game") {
									currentState = GameState::newgame;
								}
								else if (button.type() == "Load game") {
									currentState = GameState::loadgame;
								}
								else if (button.type() == "Back") {
									currentState = GameState::mainmenu;
								}
							}
						}
				}
			}
		}
		//character.update(frameClock);

		window.clear(Color::White);
		//character.draw(window);

		switch (currentState) {
		case GameState::mainmenu:
			window.draw(background);
			
			n.draw(window, mouse);
			break;
		case GameState::game:
			window.draw(background);
			
			q.draw(window, mouse);
			
			break;
		case GameState::highscore:
			// Optionally handle cleanup and exit the loop
			window.close();
			break;
		}
	
		window.display();
	}
}