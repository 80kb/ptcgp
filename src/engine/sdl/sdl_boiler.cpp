#include "sdl_boiler.hpp"

SDL_State::SDL_State (const char* title) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Failed to initialize SDL\n");
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
}

SDL_State::~SDL_State () {
	SDL_DestroyRenderer( _renderer );
	SDL_DestroyWindow( _window );
	SDL_Quit();
}
