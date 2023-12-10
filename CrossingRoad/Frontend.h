#ifndef FRONTEND_H
#define FRONTEND_H

#include "Base.h"
#include "MainMenu.h"

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

enum class GameState {
	mainmenu, game, setting, highscore, loadgame, newgame, playingGame
};

class Frontend {
public:
	
	void displayMenu();
};

#endif // FRONTEND_H
