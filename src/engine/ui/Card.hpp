#pragma once

#include "../GameObject.hpp"

class pkmCard : public pkmGameObject {
protected:
	const char* 	faceTexturePath;
	bool 		draggable;
	bool 		dragging;
	bool 		hidden;

public:
	pkmCard( SDL_Renderer* renderer, const char* path );
	~pkmCard( void );

	void Render( void );
	void Update( void );
	void MouseButtonDown( const SDL_Event& e );
	void MouseButtonUp( const SDL_Event& e );
	void SetTexture( const char* path );
};
