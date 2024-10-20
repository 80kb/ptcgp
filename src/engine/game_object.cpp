#include "game_object.hpp"

pkmGameObject::pkmGameObject( SDL_Renderer* renderer ) : renderer( renderer ), clicked( false ) {
	boundingBox.h = 50;
	boundingBox.w = 50;
	boundingBox.x = 0;
	boundingBox.y = 0;
}
