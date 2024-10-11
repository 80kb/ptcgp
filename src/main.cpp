#include "sdl/sdl_boiler.h"
#include "engine/game_state.h"

int main (void) {
	SDLState sdl_state("PTCG Player");
	GameState game_state;

	game_state.game_loop();
}
