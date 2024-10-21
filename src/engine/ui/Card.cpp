#include "Card.hpp"

pkmCard::pkmCard( SDL_Renderer* renderer, const char* path ) : pkmGameObject( renderer ) {
	faceTexturePath	= path;
	draggable 	= false;
	dragging	= false;
	hidden		= true;

	SetTexture( faceTexturePath );
}

pkmCard::~pkmCard( void ) {
	pkmGameObject::~pkmGameObject();
}

void pkmCard::Render( void ) {
	SDL_RenderCopy( renderer, texture, NULL, &boundingBox );
}

void pkmCard::Update( void ) {}

void pkmCard::SetTexture( const char* path ) {
	SDL_Surface* surface = SDL_LoadBMP( path );
	texture = SDL_CreateTextureFromSurface( renderer, surface );
	SDL_FreeSurface( surface );
}
