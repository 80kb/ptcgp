#include "BoardSpace.hpp"
#include "../Palette.hpp"

pkmBoardSpace::pkmBoardSpace( SDL_Renderer* renderer ) : pkmGameObject( renderer ) {
	card = NULL;

	SetSize( DEFAULT_SPACE_W, DEFAULT_SPACE_H );
	SetColor( COLOR_BOARDSPACE );
}

pkmBoardSpace::~pkmBoardSpace( void ) {
	pkmGameObject::~pkmGameObject();
}

void pkmBoardSpace::Render( void ) {
	SDL_SetRenderDrawColor( renderer, r, g, b, a );
	SDL_RenderFillRect( renderer, &boundingBox );
}

void pkmBoardSpace::Update( void ) {}

void pkmBoardSpace::AddCard( pkmCard& card ) {
	card.SetPosition( boundingBox.x + (PADDING / 2), boundingBox.y + (PADDING / 2) );
	card.SetSize( boundingBox.w - PADDING, boundingBox.h - PADDING );
	this->card = &card;
}

void pkmBoardSpace::RemoveCard( void ) {
	if ( card == NULL ) {
		return;
	}

	card = NULL;
}

void pkmBoardSpace::SetColor( int r, int g, int b, int a ) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

void pkmBoardSpace::GetColor( int& r, int& g, int& b, int& a ) {
	r = this->r;
	g = this->g;
	b = this->b;
	a = this->a;
}
