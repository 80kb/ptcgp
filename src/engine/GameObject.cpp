#include "GameObject.hpp"

pkmGameObject::pkmGameObject( SDL_Renderer* renderer ) {
	this->renderer 	= renderer;
	clicked		= false;
	hovered		= false;

	boundingBox.h = 50;
	boundingBox.w = 50;
	boundingBox.x = 0;
	boundingBox.y = 0;
}

pkmGameObject::~pkmGameObject( void ) {
	SDL_DestroyTexture( texture );
}

bool pkmGameObject::MouseButtonDown( const SDL_Event& e ) {
	if ( e.type != SDL_MOUSEBUTTONDOWN ) {
		return false;
	}

	clicked = true;
	return true;
}

bool pkmGameObject::MouseButtonUp( const SDL_Event& e ) {
	if ( e.type != SDL_MOUSEBUTTONDOWN ) {
		return false;
	}

	if ( !clicked ) {
		return false;
	}

	clicked = false;
	return true;
}

bool pkmGameObject::MouseHoverEnter( const SDL_Event& e ) {
	if ( e.type != SDL_MOUSEMOTION ) {
		return false;
	}

	if ( hovered ) {
		return false;
	}

	hovered = true;
	return true;
}

bool pkmGameObject::MouseHoverLeave( const SDL_Event& e ) {
	if ( e.type != SDL_MOUSEMOTION ) {
		return false;
	}

	if ( !hovered ) {
		return false;
	}

	hovered = false;
	return true;
}

bool pkmGameObject::MouseColliding( int mouseX, int mouseY ) const {
	return mouseX >= boundingBox.x &&
	       mouseX <= boundingBox.x + boundingBox.w &&

	       mouseY >= boundingBox.y &&
	       mouseY <= boundingBox.y + boundingBox.h;
}

void pkmGameObject::SetPosition( const int x, const int y ) {
	boundingBox.x = x;
	boundingBox.y = y;
}

void pkmGameObject::GetPosition( int& x, int& y ) {
	x = boundingBox.x;
	y = boundingBox.y;
}

void pkmGameObject::SetSize( const int w, const int h ) {
	boundingBox.w = w;
	boundingBox.h = h;
}

void pkmGameObject::GetSize( int& w, int& h ) {
	w = boundingBox.w;
	h = boundingBox.h;
}
