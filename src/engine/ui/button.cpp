#include "button.hpp"
#include <assert.h>

pkmButton::pkmButton( SDL_Renderer* renderer ) : pkmGameObject( renderer ) {
	font 		= TTF_OpenFont( "./ttf/arial.ttf", 128 );
	fontColor 	= { 255, 255, 255, 255 };

	SetText( "button" );
	SetColor( 255, 0, 0 );
}

pkmButton::~pkmButton( void ) {
	SDL_DestroyTexture( textTexture );
}

void pkmButton::Render( void ) {
	SDL_SetRenderDrawColor( renderer, r, g, b, 255 );
	SDL_RenderFillRect( renderer, &boundingBox );
	SDL_RenderCopy( renderer, textTexture, NULL, &boundingBox );
}

void pkmButton::MouseButtonDown( const SDL_Event& e ) {
	int r, g, b;

	if ( e.type != SDL_MOUSEBUTTONDOWN ) {
		return;
	}

	if ( !MouseColliding( e.motion.x, e.motion.y ) ) {
		return;
	}

	clicked = true;
	GetColor( r, g, b );
	SetColor( r * 0.8, g * 0.8, b * 0.8 );
	CallAction();
}

void pkmButton::MouseButtonUp( const SDL_Event& e ) {
	int r, g, b;

	if ( e.type != SDL_MOUSEBUTTONUP ) {
		return;
	}

	if ( !clicked ) {
		return;
	}

	clicked = false;
	GetColor( r, g, b );
	SetColor( r / 0.8, g / 0.8, b / 0.8 );
}

void pkmButton::SetText( const char* text ) {
	this->text 		= text;
	SDL_Surface* surface 	= TTF_RenderText_Solid( font, text, fontColor );
	textTexture 		= SDL_CreateTextureFromSurface( renderer, surface );

	SDL_FreeSurface( surface );
}
