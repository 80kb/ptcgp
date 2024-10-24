#include "Button.hpp"
#include <assert.h>

pkmButton::pkmButton( SDL_Renderer* renderer ) : pkmGameObject( renderer ) {
	font 		= TTF_OpenFont( "./res/ttf/arial.ttf", 128 );
	fontColor 	= { 255, 255, 255, 255 };

	SetText( "button" );
	SetColor( 255, 0, 0, 255 );
}

pkmButton::~pkmButton( void ) {
	pkmGameObject::~pkmGameObject();
}

void pkmButton::Render( void ) {
	SDL_SetRenderDrawColor( renderer, r, g, b, a );
	SDL_RenderFillRect( renderer, &boundingBox );
	SDL_RenderCopy( renderer, texture, NULL, &boundingBox );
}

void pkmButton::Update( void ) {}

bool pkmButton::MouseButtonDown( const SDL_Event& e ) {
	if ( !pkmGameObject::MouseButtonDown( e ) ) {
		return false;
	}

	int r, g, b, a;
	GetColor( r, g, b, a );
	SetColor( r * 0.8, g * 0.8, b * 0.8, 255 );
	action();
	return true;
}

bool pkmButton::MouseButtonUp( const SDL_Event& e ) {
	if ( !pkmGameObject::MouseButtonUp( e ) ) {
		return false;
	}

	int r, g, b, a;
	GetColor( r, g, b, a );
	SetColor( r / 0.8, g / 0.8, b / 0.8, 255 );
	return true;
}

void pkmButton::SetText( const char* text ) {
	this->text = text;
	SDL_Surface* surface = TTF_RenderText_Solid( font, text, fontColor );
	texture = SDL_CreateTextureFromSurface( renderer, surface );
	SDL_FreeSurface( surface );
}

const char* pkmButton::GetText( void ) const {
	return text;
}

void pkmButton::SetColor( const int r, const int g, const int b, const int a ) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

void pkmButton::GetColor( int& r, int& g, int& b, int& a ) const {
	r = this->r;
	g = this->g;
	b = this->b;
	a = this->a;
}

void pkmButton::SetAction( const std::function<void()> action ) {
	this->action = action;
}
