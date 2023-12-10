
#pragma once
#include <SFML/Graphics.hpp>
#include "Base.h"
#include "MainMenu.h"
using namespace sf;
using namespace std;
//void Frontend();
enum class GameState {
	mainmenu, game, setting, highscore, loadgame, newgame, playingGame
};
class Frontend {

public:
	
	void displayMenu();
};