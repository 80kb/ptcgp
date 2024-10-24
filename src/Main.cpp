#include "engine/GameState.hpp"
#include "engine/gobj/Card.hpp"

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

	for ( pkmCard* card : cards ) {
		gameState.RegisterObject( card );
	}

	gameState.GameLoop();
}
