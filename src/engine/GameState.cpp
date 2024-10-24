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
			MouseButtonDown();
			break;
		case SDL_MOUSEBUTTONUP:
			MouseButtonUp();
			break;
		case SDL_MOUSEMOTION:
			MouseMotion();
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

void pkmGameState::MouseButtonDown( void ) {
	for ( size_t i = 0; i < gameObjects.size(); ++i ) {
		if ( gameObjects[i]->MouseColliding( event.motion.x, event.motion.y ) ) {
			gameObjects[i]->MouseButtonDown( event );
		}
	}
}

void pkmGameState::MouseButtonUp( void ) {
	for ( size_t i = 0; i < gameObjects.size(); ++i ) {
		gameObjects[i]->MouseButtonUp( event );
	}
}

void pkmGameState::MouseMotion( void ) {
	for ( size_t i = 0; i < gameObjects.size(); ++i ) {
		if ( gameObjects[i]->MouseColliding( event.motion.x, event.motion.y ) ) {
			gameObjects[i]->MouseHoverEnter( event );
		} else {
			gameObjects[i]->MouseHoverLeave( event );
		}
	}
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
