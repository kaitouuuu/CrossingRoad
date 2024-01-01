#include "Frontend.h"

void Frontend::displayMenu()
{
	RenderWindow window(sf::VideoMode(1920, 1080), "Crossing Road");
	//RenderWindow window(sf::VideoMode(1920, 1080), "Crossing Road", sf::Style::Fullscreen);
	window.setFramerateLimit(60);
	string filename = "Content/Image/background.jpg";
	Texture backgroundTexture;

	if (!backgroundTexture.loadFromFile(filename))
	{
		// Handle error if the image fails to load
		return;
	}

	Sprite background(backgroundTexture);

	filename = "Content/Image/setting_background.png";
	Texture setting_backgroundTexture;
	if (!setting_backgroundTexture.loadFromFile(filename))
	{
		// Handle error if the image fails to load
		return;
	}
	Sprite setting_background(setting_backgroundTexture);

	filename = "Content/Image/pop up screen.png";
	Texture pop_up_background;
	if (!pop_up_background.loadFromFile(filename))
	{
		// Handle error if the image fails to load
		return;
	}
	Sprite pop_up_screen(pop_up_background);


	filename = "Content/Image/Escape screen.png";
	Texture escapescreen;
	if (!escapescreen.loadFromFile(filename))
	{
		return;
	}
	Sprite escape_screen(escapescreen);
	escape_screen.setPosition(699, 339);

	GameState currentState = GameState::mainmenu;
	// Button main menu
	Button A("Content/Image/Game.png", 1452, 353, "Game");
	Button B("Content/Image/Rule.png", 1462, 466, "Rule");
	Button C("Content/Image/Setting.png", 1410, 579, "Setting");
	Button D("Content/Image/High score.png", 1403, 692, "High score");
	Button E("Content/Image/Exit.png", 1465, 811, "Exit");

	//Button game
	Button F("Content/Image/New Game.png", 1415, 410, "New game");
	Button G("Content/Image/Load game.png", 1406, 522, "Load game");
	Button H("Content/Image/Back.png", 1483, 634, "Back");

	//Button setting
	Button H2("Content/Image/Back.png", 1681, 945, "Back");

	//Button escape menu
	Button Es1("Content/Image/Back.png", 857, 369, "Back");
	Button Es2("Content/Image/New Game.png", 790, 499, "New game esc");
	Button Es3("Content/Image/Save.png", 804, 636, "Save");

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

	vector<Button> escapebut;
	escapebut.push_back(Es1);
	escapebut.push_back(Es2);
	escapebut.push_back(Es3);

	bool isappearEscape = false;

	TextBox At("Content/Font/SuperMario256.ttf", Color::White, "CROSSY ROAD", 100, 401, 157);
	TextBox Bt("Content/Font/SuperMario256.ttf", Color::White, "SETTING", 100, 445, 81);
	vector<TextBox> t;
	
	t.push_back(At);
	
	//t.push_back(Bt);
	//t.push_back(Ct);
	Menu n(b, t);
	Menu q(c, t);
	
	//Menu p(d, y);
	//MainMenu m(b);

	Settingbut setbut;
	settingState setstate = settingState::Normal;
	string result;
	
	keyMap = {
			{"Move Left: ", sf::Keyboard::A},
			{"Move Right: ", sf::Keyboard::D},
			{"Move Up: ", sf::Keyboard::W},
			{"Move Down: ", sf::Keyboard::S},
			{"Change Skin: ", sf::Keyboard::Tab}
		
	};
	TextBox popuptext("Content/Font/SuperMario256.ttf", Color::White, "PRESS ANY KEY OR BUTTON", 100, 201, 325);
	Clock frameClock;

	// base game
	Base base;
	base.randomGame(1);
	Character champ;
	int difficulty;
	int numStage;
	int stage ;
	bool newStage;
	champ.updatekeymap(keyMap);
	while (window.isOpen())
	{
		
		Vector2f mouse = window.mapPixelToCoords(Mouse::getPosition(window));
		Event e;

		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}

			if (e.type == sf::Event::Resized)
			{
				// Calculate the scaling factors for the background image
				float scaleX = static_cast<float>(e.size.width) / background.getLocalBounds().width;
				float scaleY = static_cast<float>(e.size.height) / background.getLocalBounds().height;

				// Set the scale of the background sprite
				background.setScale(scaleX, scaleY);
			}
			if (e.type == sf::Event::MouseButtonPressed)
			{
				if (e.mouseButton.button == sf::Mouse::Left)
				{
					// Get the mouse position
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
	
					if (currentState == GameState::mainmenu) {
						for (auto& button : b)
						{
							if (button.isClicked(mousePosF))
							{
								if (button.type() == "Game")
								{
									currentState = GameState::game;
								}
								else if (button.type() == "Setting")
								{
									currentState = GameState::setting;
									 
								}
								else if (button.type() == "Exit")
								{
									return;
								}
							}
						}
					}
					else if (currentState==GameState::game)
					{
						for (auto& button : c)
						{
							if (button.isClicked(mousePosF))
							{
								if (button.type() == "New game")
								{
									currentState = GameState::newgame;
								}
								else if (button.type() == "Load game")
								{
									currentState = GameState::loadgame;
								}
								else if (button.type() == "Back")
								{
									currentState = GameState::mainmenu;
								}
							}
						}
					}
					else if (currentState == GameState::setting) {
						if(H2.isClicked(mousePosF))
						currentState = GameState::mainmenu;
					}
					
				}
			}
			if (currentState == GameState::setting) {
				if (setstate == settingState::Normal) {
					cout << "Normal" << endl;
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
					for (auto iter = settingbutton.begin(); iter != settingbutton.end(); ++iter) {
						if ((*iter).first.isClicked(mousePosF)) {
							std::string buttontext = (*iter).second.getText();
							int firstSpacePos = buttontext.find_first_of(":");
							result = buttontext.substr(0, firstSpacePos);
							cout << result << endl;
							if (result == "Move Left") {
								setbut = Settingbut::left;
							}
							else if (result == "Move Right") {
								setbut = Settingbut::right;
							}
							else if (result == "Move Up") {
								setbut = Settingbut::up;
							}
							else if (result == "Move Down") {
								setbut = Settingbut::down;
							}
							else if (result == "Change Skin") {
								setbut = Settingbut::changeskin;
							}
							setstate = settingState::Popup;
						}

					}
					
				}
				else if (setstate == settingState::Popup) {
					
					if (e.type == sf::Event::KeyPressed) {
						Keyboard::Key pressedKey = e.key.code;
						//cout << "presskey: " << pressedKey;
						handleKeyPressed(e.key.code, result);
						setstate = settingState::Normal;
					}


				}
			}
			if (currentState == GameState::playingGame) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					isappearEscape = true;
				}
				else if (isappearEscape) {
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
					for (auto &but : escapebut) {
						if (but.isClicked(mousePosF)) {
							if (but.type() == "Back") {
								isappearEscape = false;
							}
							else if (but.type() == "New game esc") {
								currentState = GameState::newgame;
								isappearEscape = false;
							}
							else if (but.type() == "Save") {

								// DO STH HERE WITH SAVE
								currentState = GameState::mainmenu;
							}
						}
					}
				}
			}
			
			champ.changeSkin();
		}

		window.clear(Color::White);
		//character.draw(window);

		switch (currentState) {
		case GameState::setting:
			if (setstate == settingState::Normal) {
				createButtons();
				window.draw(setting_background);
				Bt.draw(window);
				H2.draw(window, mouse);
				for (auto iter = settingbutton.begin(); iter != settingbutton.end(); ++iter) {
					(*iter).first.draw(window, mouse);
					(*iter).second.draw(window);
				}
			}
			else if (setstate == settingState::Popup) {
				window.draw(pop_up_screen);
				popuptext.draw(window);
			}
			break;
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

		case GameState::newgame:
			difficulty = 1;
			numStage = 1 + std::min(std::min(difficulty, 6) + difficulty / 12, 24);
			champ = Character("Character1.png", 1060.f, 500.f //1080.f - 48.f
				, 48.f, 48.f, true, false);
			champ.updatekeymap(keyMap);
			stage = 1;
			newStage = true;
			currentState = GameState::playingGame;
			break;

		case GameState::playingGame:
			
			if (newStage == true) {
				if (stage < numStage / 4)
				{
					base.randomGame(std::max(difficulty - 1, 1));
				}
				else if (stage == numStage)
				{
					base.randomGame(difficulty + 1);
				}
				else
				{
					base.randomGame(difficulty);
				}

				newStage = false;
				champ = Character("Character1.png", 1060.f, 1080.f - 48.f, 48.f, 48.f, true, false);
				champ.updatekeymap(keyMap);
			}
			
			for (Road& lane : base.lanes)
			{
				lane.draw(window);
			}
			
				for (Road& lane : base.lanes)
				{
					if (lane.getType() == "Road")
					{
						lane.updateTrafficLight();
					}
					lane.updateVehicles(isappearEscape);
					lane.updateAnimals();
				}
			
			for (Road& lane : base.lanes)
			{
				for (Vehicle* vehicle : lane.vehicles)
				{
					vehicle->draw(window);
				}
				for (Animal* animal : lane.animals)
				{
					animal->draw(window);
				}
			}

			int pos1 = max(int(champ.getY() / 54) - 1, 0);
			int pos2 = int(champ.getY() / 54);
			int pos3 = min(int(champ.getY() / 54) + 1, int(base.lanes.size() - 1));
			
				champ.update(frameClock, base.lanes[pos1], e,isappearEscape);
				champ.update(frameClock, base.lanes[pos2], e,isappearEscape);
				champ.update(frameClock, base.lanes[pos3], e,isappearEscape);

				int checkCondition = max(champ.checkCollision(base.lanes[pos1]),
					max(champ.checkCollision(base.lanes[pos2]), champ.checkCollision(base.lanes[pos3])));

				if (checkCondition == 1)
				{
					currentState = GameState::newgame;
				}
				else if (checkCondition == 2)
				{
					++stage;
					if (stage > numStage)
					{
						currentState = GameState::mainmenu;
					}
					else
					{
						newStage = true;
					}
				}
			
			champ.draw(window);
			if (isappearEscape) {
				window.draw(escape_screen);
				Es1.draw(window, mouse);
				Es2.draw(window, mouse);
				Es3.draw(window, mouse);
			}
			
			break;
		
		
		
		}
		

		window.display();
	}
	
}


void Frontend::createButtons() {
	settingbutton.clear();
	float offsetY = 216.f;
	//cout << "keymap: " << keyMap.size();
	for (const auto& pair : keyMap) {
		//cout << "over\n";
		const std::string action = pair.first;
		//cout << action << endl;
		sf::Keyboard::Key key = pair.second;
		
		std::string keyString = keyToString(key);
		//cout << keyString << endl;
		Button but("Content/Image/button.png", 683.f, offsetY,"but");
		
		TextBox b("Content/Font/SuperMario256.ttf", Color::White, action+keyToString(key), 40, 683.f, offsetY + 25.f);
		//cout << "Go\n";
		std::pair<Button, TextBox> buttonAndTextPair(but, b);

		settingbutton.push_back(buttonAndTextPair);

		offsetY += 135.0f;
	}
	
}
std::string Frontend::keyToString(sf::Keyboard::Key key) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) return "Space";
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) return "Shift";
	else if (key == sf::Keyboard::Up) return "Up Arrow";
	else if (key == sf::Keyboard::Down) return "Down Arrow";
	else if (key >= sf::Keyboard::A && key <= sf::Keyboard::Z) {
		char letter = static_cast<char>('A' + (key - sf::Keyboard::A));
		return std::string(1, letter);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) return "Tab";
	else return "None";
}

void Frontend::handleKeyPressed(sf::Keyboard::Key keyCode, const std::string& result) {
	
		// Update the key mapping for the selected action
	std::string selectedAction = result + ": ";
	keyMap[selectedAction] = keyCode;
	std::string updatedtext = selectedAction + keyToString(keyCode);
	for (auto iter = settingbutton.begin(); iter != settingbutton.end(); ++iter) {
		std::string buttontext = (*iter).second.getText();
		int firstSpacePos = buttontext.find_first_of(":");
		string get_result = buttontext.substr(0, firstSpacePos);
		if (result == get_result) {
			(*iter).second.setText(updatedtext);
			break;
		}
		
	}
	
}
