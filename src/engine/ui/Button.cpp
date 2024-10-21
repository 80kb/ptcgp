#include "Button.hpp"
#include <assert.h>

pkmButton::pkmButton( SDL_Renderer* renderer ) : pkmGameObject( renderer ) {
	font 		= TTF_OpenFont( "./ttf/arial.ttf", 128 );
	fontColor 	= { 255, 255, 255, 255 };

	SetText( "button" );
	SetColor( 255, 0, 0 );
}

pkmButton::~pkmButton( void ) {
	pkmGameObject::~pkmGameObject();
}

void pkmButton::Render( void ) {
	SDL_SetRenderDrawColor( renderer, r, g, b, 255 );
	SDL_RenderFillRect( renderer, &boundingBox );
	SDL_RenderCopy( renderer, texture, NULL, &boundingBox );
}

void pkmButton::Update( void ) {}

void pkmButton::MouseButtonDown( const SDL_Event& e ) {
	pkmGameObject::MouseButtonDown( e );

	int r, g, b;

	clicked = true;
	GetColor( r, g, b );
	SetColor( r * 0.8, g * 0.8, b * 0.8 );
	action();
}

void pkmButton::MouseButtonUp( const SDL_Event& e ) {
	pkmGameObject::MouseButtonUp( e );

	int r, g, b;

	clicked = false;
	GetColor( r, g, b );
	SetColor( r / 0.8, g / 0.8, b / 0.8 );
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

void pkmButton::SetColor( const int r, const int g, const int b ) {
	this->r = r;
	this->g = g;
	this->b = b;
}

void pkmButton::GetColor( int& r, int& g, int& b ) const {
	r = this->r;
	g = this->g;
	b = this->b;
}

void pkmButton::SetAction( const std::function<void()> action ) {
	this->action = action;
}
