#pragma once

#include <SDL2/SDL.h>
#include <assert.h>

class pkmGameObject {
protected:
	SDL_Renderer* 	renderer;
	SDL_Texture* 	texture;
	SDL_Rect 	boundingBox;

	bool 		clicked;

public:
	pkmGameObject( SDL_Renderer* const renderer );
	~pkmGameObject( void ) {}

	virtual void Update( void ) = 0;
	virtual void Render( void ) = 0;

	virtual void MouseButtonDown( const SDL_Event& e ) {
		assert(e.type);
	}

	virtual void MouseButtonUp( const SDL_Event& e ) {
		assert(e.type);
	}

	virtual bool MouseColliding( int mouseX, int mouseY ) const {
		return mouseX >= boundingBox.x &&
		       mouseX <= boundingBox.x + boundingBox.w &&

		       mouseY >= boundingBox.y &&
		       mouseY <= boundingBox.y + boundingBox.h;
	}
};
