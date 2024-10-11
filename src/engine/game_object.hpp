#pragma once

#include <SDL2/SDL.h>

class GameObject {
protected:
	SDL_Rect bounding_box;
	SDL_Texture* texture;

	bool mouse_colliding (int mouseX, int mouseY) {
		return mouseX >= bounding_box.x &&
		       mouseX <= bounding_box.x + bounding_box.w &&

		       mouseY >= bounding_box.y &&
		       mouseY <= bounding_box.y + bounding_box.h;
	}
public:
	virtual void handle_input (SDL_Event& event) = 0;
	virtual void update() = 0;
	virtual void render() = 0;
};
