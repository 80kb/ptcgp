#pragma once

#include <SDL2/SDL.h>
#include <vector>

#include "GameObject.hpp"
#include "sdl/sdl_boiler.hpp"

class pkmGameState {
	std::vector<pkmGameObject*> 	gameObjects;
	SDL_Event 			event;
	SDL_State 			sdlState;
	bool 				quit;

	void EventLoop( void );
	void HandleEvent( void );
	void Update( void );
	void Render( void );

	void MouseButtonDown( void );
	void MouseButtonUp( void );
	void MouseMotion( void );

public:
	pkmGameState( void );

	void 		GameLoop( void );
	void 		RegisterObject( pkmGameObject* object );

	SDL_Renderer* 	GetRenderer( void ) const;
	SDL_Window* 	GetWindow( void ) const;
};
