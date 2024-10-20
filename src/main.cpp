#include "engine/game_state.hpp"
#include "engine/ui/button.hpp"
#include "engine/ui/label.hpp"

int main (void) {
	pkmGameState gameState;

	pkmLabel label( gameState.GetRenderer() );
	label.SetPosition( 100, 160 );
	label.SetSize( 100, 50 );
	label.SetText( "Geschichte" );

	bool toggle = true;

	pkmButton button( gameState.GetRenderer() );
	button.SetPosition( 100, 100 );
	button.SetSize( 100, 50 );
	button.SetText( "Schön" );
	button.SetColor( 255, 0, 70 );
	button.SetAction([&]( void ) {
		if ( toggle ) {
			label.SetText("Hello");
		} else {
			label.SetText("World!");
		}

		toggle = !toggle;
	});

	gameState.RegisterObject(&button);
	gameState.RegisterObject(&label);

	gameState.GameLoop();
}
