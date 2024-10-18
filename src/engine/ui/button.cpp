#include "button.hpp"
#include <assert.h>

Button::Button (SDL_Renderer* renderer) : GameObject(renderer) {
	_font = TTF_OpenFont("./ttf/arial.ttf", 128);
	_font_color = {255, 255, 255, 255};

	set_text("button");
	set_color(255, 0, 0);
}

Button::~Button () {
	SDL_DestroyTexture(_text_texture);
}

void Button::render () {
	SDL_SetRenderDrawColor(_renderer, _r, _g, _b, 255);
	SDL_RenderFillRect(_renderer, &_bounding_box);
	SDL_RenderCopy(_renderer, _text_texture, NULL, &_bounding_box);
}

void Button::mouse_button_down (SDL_Event& e) {
	assert(e.type == SDL_MOUSEBUTTONDOWN);

	if (!mouse_colliding(e.motion.x, e.motion.y)) return;
	_clicked = true;

	/* Update color */
	int r, g, b;
	color(r, g, b);
	set_color(r * 0.8, g * 0.8, b * 0.8);

	/* Run action */
	action();
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

void Button::set_text (const char* text) {
	_text = text;
	SDL_Surface* surface = TTF_RenderText_Solid(_font, _text, _font_color);
	_text_texture = SDL_CreateTextureFromSurface(_renderer, surface);
	SDL_FreeSurface(surface);
}
