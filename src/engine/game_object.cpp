#include "game_object.hpp"

GameObject::GameObject (SDL_Renderer* renderer) : _renderer(renderer), _clicked(false) {
	_bounding_box.h = 50;
	_bounding_box.w = 50;
	_bounding_box.x = 0;
	_bounding_box.y = 0;
}
