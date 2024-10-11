#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "game_object.h"

class GameState {
	int _mouseX, _mouseY;
	int _quit;
	std::vector<GameObject*> _game_objects;
	SDL_Event _event;

	void event_loop();
	void handle_event (int type);
	void update();
	void render();

public:
	GameState() {
		_quit = 0;
	}

	void game_loop ();
};
