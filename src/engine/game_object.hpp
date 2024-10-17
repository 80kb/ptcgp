#pragma once

#include <SDL2/SDL.h>

class GameObject {
protected:
	SDL_Renderer* _renderer;
	SDL_Rect _bounding_box;
	SDL_Texture* _texture;

public:
	GameObject(SDL_Renderer* renderer);
	~GameObject() {}

	virtual void update() = 0;
	virtual void render() = 0;

	virtual bool mouse_colliding (int mouseX, int mouseY) {
		return mouseX >= _bounding_box.x &&
		       mouseX <= _bounding_box.x + _bounding_box.w &&

		       mouseY >= _bounding_box.y &&
		       mouseY <= _bounding_box.y + _bounding_box.h;
	}
};
