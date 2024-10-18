#pragma once

#include "../game_object.hpp"
#include <SDL2/SDL_ttf.h>

class Button : public GameObject {
protected:
	const char* _text;
	int _r, _g, _b;

	TTF_Font* _font;
	SDL_Color _font_color;
	SDL_Texture* _text_texture;

public:
	Button(SDL_Renderer* renderer);
	~Button();

	/* Abstract methods */
	void render();
	void update() {}

	/* Event handling */
	void mouse_button_down(SDL_Event& e);
	void mouse_button_up(SDL_Event& e);

	/* Accessor methods */
	void set_text(const char* text);
	const char* text() { return _text; }

	void set_color(int r, int g, int b) { _r = r; _g = g; _b = b; }
	void color(int& r, int& g, int& b) { r = _r; g = _g; b = _b; }

	void set_position(int x, int y) { _bounding_box.x = x; _bounding_box.y = y; };
	void position(int& x, int& y) { x = _bounding_box.x; y = _bounding_box.y; };

	void set_size(int w, int h) { _bounding_box.w = w; _bounding_box.h = h; }
	void size(int& w, int& h) { w = _bounding_box.w; h = _bounding_box.h; }
};
