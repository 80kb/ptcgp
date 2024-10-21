#include "Label.hpp"

pkmLabel::pkmLabel( SDL_Renderer* renderer ) : pkmGameObject( renderer ) {
	font 		= TTF_OpenFont( "./ttf/arial.ttf", 128 );
	fontColor 	= { 255, 255, 255, 255 };

	SetText( "label" );
}

pkmLabel::~pkmLabel ( void ) {
	pkmGameObject::~pkmGameObject();
}

void pkmLabel::Render ( void ) {
	SDL_RenderCopy( renderer, texture, NULL, &boundingBox );
}

void pkmLabel::SetText( const char* text ) {
	this->text = text;
	SDL_Surface* surface = TTF_RenderText_Solid( font, text, fontColor );
	texture = SDL_CreateTextureFromSurface( renderer, surface );
	SDL_FreeSurface( surface );
}

const char* pkmLabel::GetText( void ) const {
	return text;
}
