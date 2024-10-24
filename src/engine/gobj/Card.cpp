#include "Card.hpp"

pkmCard::pkmCard( SDL_Renderer* renderer, const char* path ) : pkmGameObject( renderer ) {
	faceTexturePath	= path;
	draggable 	= true;
	dragging	= false;
	hidden		= true;
	growFactor	= 10;

	SDL_Surface* surface = SDL_LoadBMP( BACK_TEXTURE );
	backTexture = SDL_CreateTextureFromSurface( renderer, surface );
	SDL_FreeSurface( surface );

	SetTexture( faceTexturePath );
	SetSize( DEFAULT_CARD_W, DEFAULT_CARD_H );
}

pkmCard::~pkmCard( void ) {
	pkmGameObject::~pkmGameObject();
}

void pkmCard::Render( void ) {
	if ( hidden ) {
		SDL_RenderCopy( renderer, backTexture, NULL, &boundingBox );
	} else {
		SDL_RenderCopy( renderer, texture, NULL, &boundingBox );
	}
}

void pkmCard::Update( void ) {}

bool pkmCard::MouseHoverEnter( const SDL_Event& e ) {
	if ( !pkmGameObject::MouseHoverEnter( e ) ) {
		return false;
	}

	if ( draggable ) {
		int w, h, x, y;
		GetSize( w, h );
		SetSize( w + growFactor, h + growFactor );

		GetPosition( x, y );
		SetPosition( x - (growFactor / 2), y - (growFactor / 2) );
	}

	return true;
}

bool pkmCard::MouseHoverLeave( const SDL_Event& e ) {
	if ( !pkmGameObject::MouseHoverLeave( e ) ) {
		return false;
	}

	if ( draggable ) {
		int w, h, x, y;
		GetSize( w, h );
		SetSize( w - growFactor, h - growFactor );

		GetPosition( x, y );
		SetPosition( x + (growFactor / 2), y + (growFactor / 2) );
	}

	return true;
}

void pkmCard::SetTexture( const char* path ) {
	SDL_Surface* surface = SDL_LoadBMP( path );
	texture = SDL_CreateTextureFromSurface( renderer, surface );
	SDL_FreeSurface( surface );
}

void pkmCard::Hide( void ) {
	hidden = true;
}

void pkmCard::Show( void ) {
	hidden = false;
}
