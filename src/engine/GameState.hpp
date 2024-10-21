#pragma once

#include <SDL2/SDL.h>
#include <vector>

#include "GameObject.hpp"
#include "sdl/sdl_boiler.hpp"

class pkmGameState {
	std::vector<pkmGameObject*> gameObjects;
	SDL_Event 	event;
	SDL_State 	sdlState;
	bool 		quit;

	void EventLoop( void );
	void HandleEvent( void);
	void Update( void );
	void Render( void );

public:
	pkmGameState( void ) : sdlState( "PTCG Player" ), quit( false ) { }

	void GameLoop( void );
	void RegisterObject( pkmGameObject* object );

	SDL_Renderer* GetRenderer() const {
		return sdlState.get_renderer();
	}

	SDL_Window* GetWindow() const {
		return sdlState.get_window(); 
	}
};
