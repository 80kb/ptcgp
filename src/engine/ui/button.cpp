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
