#pragma once

#include <SDL2/SDL.h>
#include <vector>

#include "game_object.hpp"
#include "sdl/sdl_boiler.hpp"

class GameState {
	int _mouseX, _mouseY;
	bool _quit;
	std::vector<GameObject*> _game_objects;
	SDL_Event _event;
	SDL_State _sdl_state;

	void event_loop();
	void handle_event();
	void update();
	void render();

public:
	GameState() : _quit(false), _sdl_state("PTCG Player") { }

	void game_loop ();
	void register_object(GameObject* object);

	SDL_Renderer* get_renderer() { return _sdl_state.get_renderer(); }
	SDL_Window* get_window() { return _sdl_state.get_window(); }
};
