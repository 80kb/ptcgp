#pragma once

#include <SDL2/SDL.h>

class SDLState {
	SDL_Window* _window;
	SDL_Renderer* _renderer;

public:
	SDLState (const char* title);
	~SDLState();
};
