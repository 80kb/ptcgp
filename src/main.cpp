#include "engine/game_state.hpp"
#include "engine/ui/button.hpp"

int main (void) {
	GameState game_state;

	Button button(game_state.get_renderer());
	game_state.register_object(&button);

	game_state.game_loop();
}
