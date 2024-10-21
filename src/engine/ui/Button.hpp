#pragma once

#include "../GameObject.hpp"
#include <SDL2/SDL_ttf.h>
#include <functional>

class pkmButton : public pkmGameObject {
	std::function<void()> 	action;
	TTF_Font* 		font;
	SDL_Color 		fontColor;
	const char*		text;
	int 			r, g, b;

public:
	pkmButton( SDL_Renderer* renderer );
	~pkmButton( void );

	void 		Render( void );
	void 		Update( void );
	void 		MouseButtonDown( const SDL_Event& e );
	void 		MouseButtonUp( const SDL_Event& e );
	void 		SetText( const char* text );
	const char* 	GetText( void ) const;
	void 		SetColor( const int r, const int g, const int b );
	void 		GetColor( int& r, int& g, int& b ) const;
	void 		SetAction( const std::function<void()> action );
};
