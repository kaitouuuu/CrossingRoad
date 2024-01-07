#ifndef FRONTEND_H
#define FRONTEND_H

#include "Base.h"
#include "MainMenu.h"
#include <map>
#include <SFML/Graphics.hpp>
#include <utility> // for std pair
#include <string>
using namespace sf;
using namespace std;

enum class GameState {
	mainmenu, game, setting, highscore, loadgame, newgame, playingGame, gamemode,stagemode
};
enum class Gametype {
	none, stage, endless
};
enum class Stagelv {
	lv1,lv2,lv3,lv4,lv5,none
};

enum class Settingbut {
	left,right,up,down,changeskin
};

enum class settingState {
	Normal,
	Popup,
};

class Frontend {
public:
	//Frontend();
	void displayMenu();
	
private:
	map<std::string, sf::Keyboard::Key> keyMap;
    vector<std::pair<Button, TextBox>>settingbutton;
	void createButtons();
	std::string keyToString(sf::Keyboard::Key key);
	void handleKeyPressed(sf::Keyboard::Key keyCode, const std::string& selectedAction);
	

};

#endif // FRONTEND_H
