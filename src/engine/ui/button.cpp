#include "button.hpp"

/* Initialize button to default values
 */
Button::Button (SDL_Renderer* renderer) : GameObject(renderer) {
	set_text("button");
	set_color(255, 0, 0);
}

/* Render the button
 */
void Button::render () {
	SDL_SetRenderDrawColor(_renderer, _r, _g, _b, 255);
	SDL_RenderFillRect(_renderer, &_bounding_box);
}

void Button::mouse_button_down (SDL_Event& e) {
	int r, g, b;
	color(r, g, b);
	set_color(r * 0.8, g * 0.8, b * 0.8);
}

void Button::mouse_button_up (SDL_Event& e) {
	int r, g, b;
	color(r, g, b);
	set_color(r / 0.8, g / 0.8, b / 0.8);
}
