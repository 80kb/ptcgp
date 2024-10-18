#pragma once

#include "../game_object.hpp"

class Button : public GameObject {
protected:
	const char* _text;
	int _r, _g, _b;

public:
	Button(SDL_Renderer* renderer);
	~Button() {}

	/* Abstract methods */
	void render();
	void update() {}

	/* Event handling */
	void mouse_button_down(SDL_Event& e);
	void mouse_button_up(SDL_Event& e);

	/* Accessor methods */
	void set_text(const char* text)	{ _text = text; }
	const char* text() { return _text; }

	void set_color(int r, int g, int b) { _r = r; _g = g; _b = b; }
	void color(int& r, int& g, int& b) { r = _r; g = _g; b = _b; }

	void set_position(int x, int y) { _bounding_box.x = x; _bounding_box.y = y; };
	void position(int& x, int& y) { x = _bounding_box.x; y = _bounding_box.y; };
};
