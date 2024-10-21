#pragma once

#include "../GameObject.hpp"
#include <SDL2/SDL_ttf.h>

class pkmLabel : public pkmGameObject {
protected:
	const char*	text;
	TTF_Font* 	font;
	SDL_Color 	fontColor;
	SDL_Texture* 	textTexture;

public:
	pkmLabel( SDL_Renderer* renderer );
	~pkmLabel( void );

	void Render( void );
	void Update( void ) {}

	/*******************************************/
	/*******************************************/

	void SetText( const char* text );
	const char* GetText() const {
		return text;
	}

	void SetPosition( const int x, const int y ) { 
		boundingBox.x = x;
		boundingBox.y = y; 
	}

	void GetPosition( int& x, int& y ) const {
		x = boundingBox.x;
		y = boundingBox.y; 
	}

	void SetSize( const int w, const int h ) { 
		boundingBox.w = w;
		boundingBox.h = h; 
	}

	void GetSize( int& w, int& h ) const {
		w = boundingBox.w;
		h = boundingBox.h;
	}
};
