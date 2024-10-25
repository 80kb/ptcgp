#include "engine/GameState.hpp"
#include "GameBoard.hpp"

#include "engine/obj/Card.hpp"

int main (void) {
	pkmGameState gameState;

	pkmGameBoard board( gameState.GetRenderer() );

	pkmCard card( gameState.GetRenderer(), "res/img/darkrai.bmp" );
	card.Show();	

	board.GetSpace( 0 )->AddCard( card );

	for ( int i = 0; i < board.GetObjectCount(); i++ ) {
		gameState.RegisterObject( board.GetObject( i ) );
	}

	for ( int i = 0; i < board.GetSpaceCount(); i++ ) {
		gameState.RegisterObject( board.GetSpace( i ) );
	}

	gameState.RegisterObject( &card );

	gameState.GameLoop();
}
