#include "BoardSpace.hpp"
#include "../Palette.hpp"

pkmBoardSpace::pkmBoardSpace( SDL_Renderer* renderer ) : pkmGameObject( renderer ) {
	card = NULL;

	SetSize( DEFAULT_SPACE_W, DEFAULT_SPACE_H );
}

pkmBoardSpace::~pkmBoardSpace( void ) {
	pkmGameObject::~pkmGameObject();
}

void pkmBoardSpace::Render( void ) {
	SDL_SetRenderDrawColor( renderer, COLOR_BOARDSPACE );
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
