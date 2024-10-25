#include "engine/GameState.hpp"
#include "GameBoard.hpp"

int main (void) {
	pkmGameState gameState;

	pkmGameBoard board( gameState.GetRenderer() );

	for ( int i = 0; i < board.GetSize(); i++ ) {
		gameState.RegisterObject( board.GetObject( i ) );
	}

	gameState.GameLoop();
}
