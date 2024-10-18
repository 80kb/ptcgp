#include "engine/game_state.hpp"
#include "engine/ui/button.hpp"

int main (void) {
	GameState game_state;

	Button button(game_state.get_renderer());
	button.set_position(100, 100);
	button.set_size(100, 50);
	button.set_text("Scheisse");
	button.set_color(255, 0, 70);

	game_state.register_object(&button);

	game_state.game_loop();
}
