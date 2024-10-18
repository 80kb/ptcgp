#include "button.hpp"
#include <assert.h>

Button::Button (SDL_Renderer* renderer) : GameObject(renderer) {
	set_text("button");
	set_color(255, 0, 0);
}

void Button::render () {
	SDL_SetRenderDrawColor(_renderer, _r, _g, _b, 255);
	SDL_RenderFillRect(_renderer, &_bounding_box);
}

void Button::mouse_button_down (SDL_Event& e) {
	assert(e.type == SDL_MOUSEBUTTONDOWN);

	if (!mouse_colliding(e.motion.x, e.motion.y)) return;
	_clicked = true;

	/* Update color */
	int r, g, b;
	color(r, g, b);
	set_color(r * 0.8, g * 0.8, b * 0.8);
}

void Button::mouse_button_up (SDL_Event& e) {
	assert(e.type == SDL_MOUSEBUTTONUP);

	if (!_clicked) return;
	_clicked = false;
	
	/* Update color */
	int r, g, b;
	color(r, g, b);
	set_color(r / 0.8, g / 0.8, b / 0.8);
}
