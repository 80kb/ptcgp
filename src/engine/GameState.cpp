#include "GameState.hpp"

pkmGameState::pkmGameState( void ) : sdlState( "PTCG Player" ) {
	quit = false;
}

void pkmGameState::GameLoop( void ) {
	while ( !quit ) {
		EventLoop();
		Update();
		Render();
	}
}

void pkmGameState::EventLoop( void ) {
	while ( SDL_PollEvent( &event ) ) {
		HandleEvent();
	}
}

void pkmGameState::HandleEvent( void ) {
	switch ( event.type ) {
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_MOUSEBUTTONDOWN:
			for ( size_t i = 0; i < gameObjects.size(); ++i ) {
				gameObjects[i]->MouseButtonDown( event );
			}
			break;
		case SDL_MOUSEBUTTONUP:
			for ( size_t i = 0; i < gameObjects.size(); ++i ) {
				gameObjects[i]->MouseButtonUp( event );
			}
			break;
	}
}

void pkmGameState::Update( void ) {
	for ( size_t i = 0; i < gameObjects.size(); ++i ) {
		gameObjects[i]->Update();
	}
}

void pkmGameState::Render( void ) {
	SDL_SetRenderDrawColor( sdlState.get_renderer(), 35, 27, 46, 255 );
	SDL_RenderClear( sdlState.get_renderer() );

	for ( size_t i = 0; i < gameObjects.size(); ++i ) {
		gameObjects[i]->Render();
	}

	SDL_RenderPresent( sdlState.get_renderer() );
}

void pkmGameState::RegisterObject( pkmGameObject* object ) {
	gameObjects.push_back( object );
}

SDL_Renderer* pkmGameState::GetRenderer( void ) const {
	return sdlState.get_renderer();
}

SDL_Window* pkmGameState::GetWindow( void ) const {
	return sdlState.get_window();
}
