#pragma once

#include "../GameObject.hpp"
#include <SDL2/SDL_ttf.h>

class pkmLabel : public pkmGameObject {
	const char*	text;
	TTF_Font* 	font;
	SDL_Color 	fontColor;

public:
	pkmLabel( SDL_Renderer* renderer );
	~pkmLabel( void );

	void 		Render( void );
	void 		Update( void ) {}
	void 		SetText( const char* text );
	const char* 	GetText( void ) const;
};
