#pragma once

#include "../game_object.hpp"
#include <SDL2/SDL_ttf.h>

class Label : public GameObject{
protected:
	const char* _text;
	TTF_Font* _font;
	SDL_Color _font_color;
	SDL_Texture* _text_texture;

public:
	Label(SDL_Renderer* renderer);
	~Label();

	/* Abstract methods */
	void render();
	void update() {}

	/* Accessor methods */
	void set_text(const char* text);
	const char* text() { return _text; }

	void set_position(int x, int y) { _bounding_box.x = x; _bounding_box.y = y; };
	void position(int& x, int& y) { x = _bounding_box.x; y = _bounding_box.y; };

	void set_size(int w, int h) { _bounding_box.w = w; _bounding_box.h = h; }
	void size(int& w, int& h) { w = _bounding_box.w; h = _bounding_box.h; }
};
