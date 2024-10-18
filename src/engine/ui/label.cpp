#include "label.hpp"

Label::Label (SDL_Renderer* renderer) : GameObject(renderer) {
	_font = TTF_OpenFont("./ttf/arial.ttf", 32);
	_font_color = {255, 255, 255, 255};

	set_text("label");
}

Label::~Label () {
	SDL_DestroyTexture(_text_texture);
}

void Label::render () {
	SDL_RenderCopy(_renderer, _text_texture, NULL, &_bounding_box);
}

void Label::set_text (const char* text) {
	_text = text;
	SDL_Surface* surface = TTF_RenderText_Solid(_font, _text, _font_color);
	_text_texture = SDL_CreateTextureFromSurface(_renderer, surface);
	SDL_FreeSurface(surface);
}
