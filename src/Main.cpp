#include "engine/GameState.hpp"
#include "engine/obj/Card.hpp"
#include "engine/obj/BoardSpace.hpp"

#include <vector>

int main (void) {
	pkmGameState gameState;

	std::vector<pkmCard*> cards;

	pkmCard card0( gameState.GetRenderer(), "./res/darkrai.bmp" );
	card0.SetPosition( 100, 400 );
	cards.push_back( &card0 );

	pkmCard card1( gameState.GetRenderer(), "./res/darkrai.bmp" );
	card1.SetPosition( 180, 400 );
	cards.push_back( &card1 );

	pkmCard card2( gameState.GetRenderer(), "./res/darkrai.bmp" );
	card2.SetPosition( 260, 400 );
	cards.push_back( &card2 );

	pkmCard card3( gameState.GetRenderer(), "./res/darkrai.bmp" );
	card3.SetPosition( 340, 400 );
	cards.push_back( &card3 );

	pkmBoardSpace space( gameState.GetRenderer() );
	space.SetPosition( 500, 500 );
	space.AddCard( card2 );

	pkmBoardSpace space2( gameState.GetRenderer() );
	space2.SetPosition( 600, 500 );

	space.RemoveCard();
	space2.AddCard( card2 );

	gameState.RegisterObject( &space2 );
	gameState.RegisterObject( &space );

	for ( pkmCard* card : cards ) {
		gameState.RegisterObject( card );
	}

	gameState.GameLoop();
}
