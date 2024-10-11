#pragma once

#include <SDL2/SDL.h>

class SDL_State {
	SDL_Window* _window;
	SDL_Renderer* _renderer;

public:
	SDL_State(const char* title);
	~SDL_State();

	SDL_Window* get_window() { return _window; }
	SDL_Renderer* get_renderer() { return _renderer; }
};
