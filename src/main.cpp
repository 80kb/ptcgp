#include "sdl/sdl_boiler.hpp"
#include "engine/game_state.hpp"

int main (void) {
	SDLState sdl_state("PTCG Player");
	GameState game_state;

	game_state.game_loop();
}
