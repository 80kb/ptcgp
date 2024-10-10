#pragma once

#include <SDL2/SDL.h>

class SDL_State {
	SDL_Window* _window;
	SDL_Renderer* _renderer;

public:
	SDL_State(const char* title);
	~SDL_State();
};
