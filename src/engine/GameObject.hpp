#pragma once

#include <SDL2/SDL.h>
#include <assert.h>

class pkmGameObject {
protected:
	SDL_Renderer* 	renderer;
	SDL_Texture* 	texture;
	SDL_Rect 	boundingBox;
	bool 		clicked;

public:
	pkmGameObject( SDL_Renderer* const renderer );
	~pkmGameObject( void );

	virtual void Update( void ) = 0;
	virtual void Render( void ) = 0;
	virtual void MouseButtonDown( const SDL_Event& e );
	virtual void MouseButtonUp( const SDL_Event& e );
	virtual bool MouseColliding( int mouseX, int mouseY ) const;
	virtual void SetPosition( const int x, const int y );
	virtual void GetPosition( int& x, int& y );
	virtual void SetSize( const int w, const int h );
	virtual void GetSize( int& w, int& h );
};
