#pragma once

#include "../GameObject.hpp"
#include <SDL2/SDL_ttf.h>
#include <functional>

class pkmButton : public pkmGameObject {
protected:
	std::function<void()> action;

	const char*	text;
	int 		r, g, b;

	TTF_Font* 	font;
	SDL_Color 	fontColor;
	SDL_Texture* 	textTexture;

public:
	pkmButton( SDL_Renderer* renderer );
	~pkmButton( void );

	void Render( void );
	void Update( void ) {}

	void MouseButtonDown( const SDL_Event& e );
	void MouseButtonUp( const SDL_Event& e );

	/*******************************************/
	/*******************************************/

	void SetText( const char* text );
	const char* GetText( void ) const {
		return text;
	}

	void SetColor( const int r, const int g, const int b ) { 
		this->r = r; 
		this->g = g;
		this->b = b;
	}

	void GetColor( int& r, int& g, int& b ) const {
		r = this->r; 
		g = this->g; 
		b = this->b; 
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

	void SetAction( const std::function<void()> action ) {
		this->action = action;
	}

	void CallAction() {
		action();
	}
};
