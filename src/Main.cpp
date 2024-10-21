#include "engine/GameState.hpp"
#include "engine/ui/Button.hpp"
#include "engine/gobj/Card.hpp"

int main (void) {
	pkmGameState gameState;

	pkmCard card( gameState.GetRenderer(), "./res/darkrai.bmp" );
	card.SetPosition( 100, 170 );
	card.SetSize( 400, 600 );

	bool hideToggle = false;

	pkmButton button( gameState.GetRenderer() );
	button.SetPosition( 100, 100 );
	button.SetSize( 100, 50 );
	button.SetText( "Show" );
	button.SetColor( 255, 0, 70 );
	button.SetAction([&]( void ) {
		if ( hideToggle ) {
			card.Hide();
			button.SetText( "Show" );
		} else {
			card.Show();
			button.SetText( "Hide" );
		}

		hideToggle = !hideToggle;
	});

	gameState.RegisterObject( &card );
	gameState.RegisterObject( &button );

	gameState.GameLoop();
}
