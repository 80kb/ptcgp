#include <stdio.h>
#include <SDL2/SDL.h>

int main (void) {
	SDL_Window* window 	= NULL;
	SDL_Renderer* renderer 	= NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Failed to initialize SDL\n");
		SDL_Quit();
		return -1;
	}

	window = SDL_CreateWindow(
		"PTCG Player",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		600, 400,
		SDL_WINDOW_SHOWN
	);

	if (window == NULL) {
		printf("Failed to create window\n");
		SDL_Quit();
		return -1;
	}
	SDL_SetWindowResizable( window, SDL_TRUE );

	renderer = SDL_CreateRenderer( window, -1,
		SDL_RENDERER_PRESENTVSYNC |
		SDL_RENDERER_ACCELERATED
	);

	SDL_Quit();
	return 0;
}
