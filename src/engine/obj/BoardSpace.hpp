#pragma once

#include "../GameObject.hpp"
#include "Card.hpp"

#define PADDING 15

#define DEFAULT_SPACE_W DEFAULT_CARD_W + PADDING
#define DEFAULT_SPACE_H DEFAULT_CARD_H + PADDING

class pkmBoardSpace : public pkmGameObject {
	pkmCard* 	card;	
	int 		r, g, b, a;

public:
	pkmBoardSpace( SDL_Renderer* renderer );
	~pkmBoardSpace( void );

	void Render( void ) override;
	void Update( void ) override;

	void AddCard( pkmCard& card );
	void RemoveCard( void );
	void SetColor( const int r, const int g, const int b, const int a );
	void GetColor( int& r, int& g, int& b, int& a ) const;
};
