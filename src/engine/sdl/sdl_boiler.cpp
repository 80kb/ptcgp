#include "sdl_boiler.hpp"
#include <SDL2/SDL_ttf.h>

SDL_State::SDL_State (const char* title) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Failed to initialize SDL\n");
		SDL_Quit();
		return;
	}

	if (TTF_Init() < 0) {
		printf("Failed to initialize SDL_ttf\n");
		SDL_Quit();
		return;
	}

	_window = SDL_CreateWindow(
		title,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		600, 400,
		SDL_WINDOW_SHOWN
	);

	if (_window == NULL) {
		printf("Failed to create window\n");
		SDL_Quit();
		return;
	}
	SDL_SetWindowResizable( _window, SDL_TRUE );

	_renderer = SDL_CreateRenderer( _window, -1,
		SDL_RENDERER_PRESENTVSYNC |
		SDL_RENDERER_ACCELERATED
	);

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
}

SDL_State::~SDL_State () {
	SDL_DestroyRenderer( _renderer );
	SDL_DestroyWindow( _window );
	SDL_Quit();
}
