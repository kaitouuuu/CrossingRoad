#include "Frontend.h"

void Frontend::displayMenu()
{
	std::ifstream INP;
	INP.open("file", std::ios::in);
	INP >> highScore;
	INP.close();

	RenderWindow window(sf::VideoMode(1920, 1080), "Crossing Road", sf::Style::Fullscreen);
	window.setFramerateLimit(60);
	std::string filename = "Content/Image/background.jpg";
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
		std::cout << "File unload" << std::endl;
		return;
	}
	Sprite escape_screen(escapescreen);
	escape_screen.setPosition(699, 339);

	GameState currentState = GameState::mainmenu;
	// Button main menu
	Button A("Content/Image/Game.png", 1452, 353, "Game");
	Button B("Content/Image/Rule.png", 1462, 466, "Rule");
	Button C("Content/Image/Setting.png", 1410, 579, "Setting");
	Button E("Content/Image/Exit.png", 1462, 692, "Exit");

	// Button game
	Button F("Content/Image/New Game.png", 1415, 410, "New game");
	Button G("Content/Image/Load game.png", 1406, 522, "Load game");
	Button H("Content/Image/Back.png", 1483, 634, "Back");

	// Button game mode
	Button stage_("Content/Image/Stage.png", 1458, 410, "Stage");
	Button endless_("Content/Image/Endless.png", 1443, 522, "Endless");
	Button back_("Content/Image/Back.png", 1483, 634, "Back");

	// BUtton lv stage
	Button lv1("Content/Image/Stage 1.png", 1409, 424, "Lv1");
	Button lv2("Content/Image/Stage 2.png", 1409, 517, "Lv2");
	Button lv3("Content/Image/Stage 3.png", 1409, 610, "Lv3");
	Button lv4("Content/Image/Stage 4.png", 1409, 703, "Lv4");
	Button lv5("Content/Image/Stage 5.png", 1409, 796, "Lv5");
	Button Backstage("Content/Image/Back.png", 1437, 889, "Back");
	std::vector<Button> stagelv;
	stagelv.push_back(lv1);
	stagelv.push_back(lv2);
	stagelv.push_back(lv3);
	stagelv.push_back(lv4);
	stagelv.push_back(lv5);
	stagelv.push_back(Backstage);
	// Button setting
	Button H2("Content/Image/Back.png", 1681, 945, "Back");

	// Button escape menu
	Button Es1("Content/Image/Back.png", 857, 369, "Back");
	Button Es2("Content/Image/New Game.png", 790, 499, "New game esc");
	Button Es3("Content/Image/Save.png", 804, 636, "Save");
	Button L2("Content/Image/Exit.png", 854, 636, "Exit");

	// Rule menu
	Button Rule1("Content/Image/Rule01.png", 379, 242, "Rule01");
	Button Rule2("Content/Image/Rule02.png", 379, 630, "Rule02");
	Button Ruleback("Content/Image/Back.png", 1628, 933, "Back");
	std::vector<Button> rulemenu;
	rulemenu.push_back(Rule1);
	rulemenu.push_back(Rule2);
	rulemenu.push_back(Ruleback);

	std::vector<Button> gamemodee;
	gamemodee.push_back(stage_);
	gamemodee.push_back(endless_);
	gamemodee.push_back(back_);

	std::vector<Button> b;
	b.push_back(A);
	b.push_back(B);
	b.push_back(C);
	b.push_back(E);

	std::vector<Button> c;
	c.push_back(F);
	c.push_back(G);
	c.push_back(H);

	std::vector<Button> cc;
	cc.push_back(F);
	cc.push_back(H);

	std::vector<Button> escapebut;
	escapebut.push_back(Es1);
	escapebut.push_back(Es2);
	escapebut.push_back(Es3);

	std::vector<Button> escapebut2;
	escapebut2.push_back(Es1);
	escapebut2.push_back(Es2);

	std::vector<Button> escapebut3;
	escapebut3.push_back(Es2);
	escapebut3.push_back(L2);

	bool isappearEscape = false;
	bool islose = false;

	TextBox At("Content/Font/SuperMario256.ttf", Color::White, "CROSSY ROAD", 100, 401, 157);
	TextBox Bt("Content/Font/SuperMario256.ttf", Color::White, "SETTING", 100, 445, 81);
	TextBox Ct("Content/Font/SuperMario256.ttf", Color::Black, "YOU LOSE!!!", 40, 827, 369);
	TextBox Dt("Content/Font/SuperMario256.ttf", Color::White, "RULE", 100, 412, 38);
	TextBox Et("Content/Font/SuperMario256.ttf", Color::White, "Highscore: ", 60, 1018, 820);
	std::vector<TextBox> t;
	std::vector<TextBox> tt;
	t.push_back(At);
	tt.push_back(Dt);
	Menu n(b, t);
	Menu q(c, t);
	Menu gmode(gamemodee, t);
	Menu slv(stagelv, t);
	Menu menurule(rulemenu, tt);

	Settingbut setbut;
	settingState setstate = settingState::Normal;
	std::string result;

	keyMap = {
		{"Move Left: ", sf::Keyboard::A},
		{"Move Right: ", sf::Keyboard::D},
		{"Move Up: ", sf::Keyboard::W},
		{"Move Down: ", sf::Keyboard::S},
		{"Change Skin: ", sf::Keyboard::F} };
	TextBox popuptext("Content/Font/SuperMario256.ttf", Color::White, "PRESS ANY KEY OR BUTTON", 100, 201, 325);
	Clock frameClock;

	Gametype currenttype = Gametype::none;
	Stagelv currentlv = Stagelv::none;

	fromSave = difficulty = numStage = stage = newStage = 0;
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

					if (currentState == GameState::mainmenu)
					{
						for (auto& button : b)
						{
							if (button.isClicked(mousePosF))
							{
								if (button.type() == "Game")
								{
									currentState = GameState::gamemode;
								}
								else if (button.type() == "Setting")
								{
									currentState = GameState::setting;
								}
								else if (button.type() == "Exit")
								{
									std::ifstream INP;
									INP.open("file", std::ios::in);
									int temp, temp2, temp3;
									INP >> temp >> temp2;
									if (temp2)
									{
										INP >> temp3;
										for (int i = 0; i < 20; ++i)
										{
											INP >> saveType[i] >> saveSpeed[i] >> saveNum[i];
										}
										INP >> saveX >> saveY;
									}
									INP.close();
									std::ofstream INP2;
									INP2.open("file", std::ios::out);
									INP2 << std::max(temp, highScore) << std::endl
										<< temp2;
									if (temp2)
									{
										INP2 << " " << temp3 << std::endl;
										for (int i = 0; i < 20; ++i)
										{
											INP2 << saveType[i] << " " << saveSpeed[i] << " " << saveNum[i] << std::endl;
										}
										INP2 << saveX << " " << saveY;
									}
									INP2.close();
									return;
								}
								else if (button.type() == "Rule")
								{
									currentState = GameState::rule;
								}
							}
						}
					}
					else if (currentState == GameState::rule)
					{
						if (Ruleback.isClicked(mousePosF))
						{
							currentState = GameState::mainmenu;
						}
					}

					else if (currentState == GameState::gamemode)
					{
						for (auto& button : gamemodee)
						{
							if (button.isClicked(mousePosF))
							{
								if (button.type() == "Stage")
								{
									currentState = GameState::stagemode;
									currenttype = Gametype::stage;
								}
								else if (button.type() == "Endless")
								{
									currentState = GameState::game;
									currenttype = Gametype::endless;
									currentlv = Stagelv::none;
								}
								else if (button.type() == "Back")
								{
									currentState = GameState::mainmenu;
									currenttype = Gametype::none;
								}
							}
						}
					}
					else if (currentState == GameState::stagemode)
					{
						currentlv = Stagelv::none;
						for (auto& button : stagelv)
						{
							if (button.isClicked(mousePosF))
							{
								if (button.type() == "Lv1")
								{
									currentState = GameState::newgame;
									currenttype = Gametype::stage;
									currentlv = Stagelv::lv1;
								}
								else if (button.type() == "Lv2")
								{
									currentState = GameState::newgame;
									currenttype = Gametype::stage;
									currentlv = Stagelv::lv2;
								}
								else if (button.type() == "Lv3")
								{
									currentState = GameState::newgame;
									currenttype = Gametype::stage;
									currentlv = Stagelv::lv3;
								}
								else if (button.type() == "Lv4")
								{
									currentState = GameState::newgame;
									currenttype = Gametype::stage;
									currentlv = Stagelv::lv4;
								}
								else if (button.type() == "Lv5")
								{
									currentState = GameState::newgame;
									currenttype = Gametype::stage;
									currentlv = Stagelv::lv5;
								}
								else if (button.type() == "Back")
								{
									currentState = GameState::gamemode;
									currentlv = Stagelv::none;
								}
							}
						}
					}
					else if (currentState == GameState::game)
					{
						if (currenttype != Gametype::endless)
						{
							currentState = GameState::newgame;
						}
						else
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
										inputSave();
										currentState = GameState::newgame;
									}
									else if (button.type() == "Back")
									{
										currentState = GameState::gamemode;
									}
								}
							}
						}
					}
					else if (currentState == GameState::setting)
					{
						if (H2.isClicked(mousePosF))
							currentState = GameState::mainmenu;
					}
				}
			}
			if (currentState == GameState::setting)
			{
				if (setstate == settingState::Normal)
				{
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
					for (auto iter = settingbutton.begin(); iter != settingbutton.end(); ++iter)
					{
						if ((*iter).first.isClicked(mousePosF))
						{
							std::string buttontext = (*iter).second.getText();
							int firstSpacePos = buttontext.find_first_of(":");
							result = buttontext.substr(0, firstSpacePos);
							if (result == "Move Left")
							{
								setbut = Settingbut::left;
							}
							else if (result == "Move Right")
							{
								setbut = Settingbut::right;
							}
							else if (result == "Move Up")
							{
								setbut = Settingbut::up;
							}
							else if (result == "Move Down")
							{
								setbut = Settingbut::down;
							}
							else if (result == "Change Skin")
							{
								setbut = Settingbut::changeskin;
							}
							setstate = settingState::Popup;
						}
					}
				}
				else if (setstate == settingState::Popup)
				{

					if (e.type == sf::Event::KeyPressed)
					{
						Keyboard::Key pressedKey = e.key.code;
						handleKeyPressed(e.key.code, result);
						setstate = settingState::Normal;
					}
				}
			}
			if (currentState == GameState::playingGame)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					isappearEscape = true;
				}
				else if (isappearEscape && !islose)
				{
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
					if (currentlv == Stagelv::none)
					{
						for (auto& but : escapebut)
						{
							if (but.isClicked(mousePosF))
							{
								if (but.type() == "Back")
								{
									isappearEscape = false;
								}
								else if (but.type() == "New game esc")
								{
									currentState = GameState::newgame;
									isappearEscape = false;
								}
								else if (but.type() == "Save")
								{
									outputSave();
									currentState = GameState::mainmenu;
									isappearEscape = false;
								}
							}
						}
					}
					else
					{
						for (auto& but : escapebut2)
						{
							if (but.isClicked(mousePosF))
							{
								if (but.type() == "Back")
								{
									isappearEscape = false;
								}
								else if (but.type() == "New game esc")
								{
									currentState = GameState::newgame;
									isappearEscape = false;
								}
							}
						}
					}
				}
				else if (isappearEscape && islose)
				{
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
					for (auto& but : escapebut3)
					{
						if (but.isClicked(mousePosF))
						{
							if (but.type() == "New game esc")
							{
								currentState = GameState::newgame;
								isappearEscape = false;
								islose = false;
							}
							else if (but.type() == "Exit")
							{
								currentState = GameState::mainmenu;
								isappearEscape = false;
								islose = false;
							}
						}
					}
					if (L2.isClicked(mousePosF))
					{
						currentState = GameState::mainmenu;
						isappearEscape = false;
						islose = false;
					}
				}
			}

			champ.changeSkin();
		}

		window.clear(Color::White);

		switch (currentState)
		{
		case GameState::setting:
			if (setstate == settingState::Normal)
			{
				createButtons();
				window.draw(setting_background);
				Bt.draw(window);
				H2.draw(window, mouse);
				for (auto iter = settingbutton.begin(); iter != settingbutton.end(); ++iter)
				{
					(*iter).first.draw(window, mouse);
					(*iter).second.draw(window);
				}
			}
			else if (setstate == settingState::Popup)
			{
				window.draw(pop_up_screen);
				popuptext.draw(window);
			}
			break;
		case GameState::mainmenu:
			window.draw(background);

			n.draw(window, mouse);
			break;
		case GameState::gamemode:
			window.draw(background);
			gmode.draw(window, mouse);
			break;
		case GameState::stagemode:
			window.draw(background);
			slv.draw(window, mouse);
			break;
		case GameState::rule:
			window.draw(setting_background);
			menurule.draw(window, mouse);
			break;
		case GameState::game:
			window.draw(background);

			q.draw(window, mouse);

			if (currenttype == Gametype::endless)
			{
				Et.draw(window);
				drawhighscore(highScore, window);
			}
			break;
		case GameState::highscore:
			// Optionally handle cleanup and exit the loop
			window.close();
			break;

		case GameState::newgame:
			if (currentlv == Stagelv::none)
			{
				difficulty = 1;
			}
			else if (currentlv == Stagelv::lv1)
			{
				difficulty = 2;
			}
			else if (currentlv == Stagelv::lv2)
			{
				difficulty = 4;
			}
			else if (currentlv == Stagelv::lv3)
			{
				difficulty = 7;
			}
			else if (currentlv == Stagelv::lv4)
			{
				difficulty = 11;
			}
			else
			{ // currentlv == Stagelv::lv5
				difficulty = 16;
			}
			if (currentlv != Stagelv::none)
			{
				numStage = 2 + std::min(std::min(difficulty / 3, 6) + difficulty / 10, 21);
			}
			else
			{
				numStage = 1 << 16;
			}
			if (fromSave == true)
			{
				champ = Character("Content/Image/Character1.png", saveX, saveY, 48.f, 48.f, true, false);
			}
			else
			{
				champ = Character("Content/Image/Character1.png", 1060.f, 500.f, 48.f, 48.f, true, false);
				stage = 1;
			}
			champ.updatekeymap(keyMap);
			newStage = true;
			currentState = GameState::playingGame;
			break;

		case GameState::playingGame:

			if (newStage == true)
			{
				if (fromSave == false)
				{
					champ = Character("Content/Image/Character1.png", 1060.f, 1080.f - 48.f, 40.f, 40.f, true, false);
				}
				else
				{
					champ = Character("Content/Image/Character1.png", saveX, saveY, 48.f, 48.f, true, false);
				}
				champ.updatekeymap(keyMap);

				if (stage < numStage / 4)
				{
					base.randomGame(std::max(difficulty - 1, 1), fromSave, saveType, saveSpeed, saveNum);
				}
				else if (stage == numStage)
				{
					base.randomGame(difficulty + 1, fromSave, saveType, saveSpeed, saveNum);
				}
				else
				{
					base.randomGame(difficulty, fromSave, saveType, saveSpeed, saveNum);
				}

				newStage = false;
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
				lane.updateVehicles(isappearEscape, champ.getX(), champ.getY(), champ.getWidth(), champ.getHeight());
				lane.updateAnimals(isappearEscape, champ.getX(), champ.getY(), champ.getWidth(), champ.getHeight());
			}

			for (Road& lane : base.lanes)
			{
				for (Object* object : lane.objects)
				{
					object->draw(window);
				}
				for (Vehicle* vehicle : lane.vehicles)
				{
					vehicle->draw(window);
				}
				for (Animal* animal : lane.animals)
				{
					animal->draw(window);
				}
			}

			int pos1 = std::max(int(champ.getY() / 54) - 1, 0);
			int pos2 = int(champ.getY() / 54);
			int pos3 = std::min(int(champ.getY() / 54) + 1, int(base.lanes.size() - 1));

			champ.update(frameClock, base.lanes[pos1], e, isappearEscape);
			champ.update(frameClock, base.lanes[pos2], e, isappearEscape);
			champ.update(frameClock, base.lanes[pos3], e, isappearEscape);

			int checkCondition = std::max(champ.checkCollision(base.lanes[pos1]),
				std::max(champ.checkCollision(base.lanes[pos2]), champ.checkCollision(base.lanes[pos3])));

			if (checkCondition == 1)
			{
				isappearEscape = true;
				islose = true;
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
					if (currentlv == Stagelv::none)
					{
						++difficulty;
					}
					newStage = true;
				}
			}

			champ.draw(window);
			if (isappearEscape)
			{
				if (!islose)
				{
					window.draw(escape_screen);
					Es1.draw(window, mouse);
					Es2.draw(window, mouse);
					if (currentlv == Stagelv::none)
					{
						Es3.draw(window, mouse);
					}
				}
				else
				{
					highScore = std::max(highScore, stage);
					window.draw(escape_screen);
					Ct.draw(window);
					Es2.draw(window, mouse);
					L2.draw(window, mouse);
				}
			}

			break;
		}

		window.display();
	}
}

void Frontend::outputSave()
{
	std::ofstream INP;
	INP.open("file", std::ios::out);
	INP << highScore << std::endl
		<< stage << " " << difficulty << std::endl;
	for (Road& lane : base.lanes)
	{
		std::string s = lane.getType();
		INP << s << " " << lane.getSpeed() << std::endl;
		if (s == "Road")
		{
			INP << lane.vehicles.size() << std::endl;
		}
		if (s == "Land")
		{
			INP << lane.animals.size() << std::endl;
		}
		if (s == "Field")
		{
			INP << lane.objects.size() << std::endl;
		}
	}
	INP << champ.getX() << " " << champ.getY();
	INP.close();
}

void Frontend::inputSave()
{
	std::ifstream INP;
	INP.open("file", std::ios::in);
	INP >> highScore >> stage;
	if (stage)
	{
		fromSave = true;
		INP >> difficulty;
		for (int i = 0; i < 20; ++i)
		{
			INP >> saveType[i] >> saveSpeed[i] >> saveNum[i];
		}
		INP >> saveX >> saveY;
	}
	INP.close();
}

void Frontend::createButtons()
{
	settingbutton.clear();
	float offsetY = 216.f;
	for (const auto& pair : keyMap)
	{
		const std::string action = pair.first;
		sf::Keyboard::Key key = pair.second;

		std::string keyString = keyToString(key);
		Button but("Content/Image/button.png", 683.f, offsetY, "but");

		TextBox b("Content/Font/SuperMario256.ttf", Color::White, action + keyToString(key), 40, 683.f, offsetY + 25.f);
		std::pair<Button, TextBox> buttonAndTextPair(but, b);

		settingbutton.push_back(buttonAndTextPair);

		offsetY += 135.0f;
	}
}

std::string Frontend::keyToString(sf::Keyboard::Key key)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		return "Space";
	else if (key == sf::Keyboard::Up)
		return "Up Arrow";
	else if (key == sf::Keyboard::Down)
		return "Down Arrow";
	else if (key == sf::Keyboard::Left)
		return "Left Arrow";
	else if (key == sf::Keyboard::Right)
		return "Right Arrow";
	else if (key >= sf::Keyboard::A && key <= sf::Keyboard::Z)
	{
		char letter = static_cast<char>('A' + (key - sf::Keyboard::A));
		return std::string(1, letter);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
		return "Tab";
	else
		return "None";
}

void Frontend::handleKeyPressed(sf::Keyboard::Key keyCode, const std::string& result)
{
	// Update the key mapping for the selected action
	std::string selectedAction = result + ": ";
	keyMap[selectedAction] = keyCode;
	std::string updatedtext = selectedAction + keyToString(keyCode);
	for (auto iter = settingbutton.begin(); iter != settingbutton.end(); ++iter)
	{
		std::string buttontext = (*iter).second.getText();
		int firstSpacePos = buttontext.find_first_of(":");
		std::string get_result = buttontext.substr(0, firstSpacePos);
		if (result == get_result)
		{
			(*iter).second.setText(updatedtext);
			break;
		}
	}
}

void Frontend::drawhighscore(int highscore, RenderWindow& window)
{
	std::string scorestr = std::to_string(highscore);
	TextBox score("Content/Font/SuperMario256.ttf", Color::White, scorestr, 60, 1428.f, 820.f);
	score.draw(window);
}
