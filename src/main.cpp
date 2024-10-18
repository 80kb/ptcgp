#include "engine/game_state.hpp"
#include "engine/ui/button.hpp"
#include "engine/ui/label.hpp"

int main (void) {
	GameState game_state;

	Label label(game_state.get_renderer());
	label.set_position(100, 160);
	label.set_size(100, 50);
	label.set_text("Geschichte");

	bool toggle = true;

	Button button(game_state.get_renderer());
	button.set_position(100, 100);
	button.set_size(100, 50);
	button.set_text("Schön");
	button.set_color(255, 0, 70);
	button.set_action([&]() {
		if (toggle)	label.set_text("Hello");
		else		label.set_text("World!");
		toggle = !toggle;
	});

	game_state.register_object(&button);
	game_state.register_object(&label);

	game_state.game_loop();
}
