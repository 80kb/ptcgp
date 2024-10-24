#pragma once

#include "../GameObject.hpp"

#define DEFAULT_CARD_W 75
#define DEFAULT_CARD_H ( DEFAULT_CARD_W + ( DEFAULT_CARD_W / 2 ) )
#define BACK_TEXTURE "./res/back.bmp"

class pkmCard : public pkmGameObject {
	SDL_Texture*	backTexture;
	const char* 	faceTexturePath;
	bool 		draggable;
	bool 		dragging;
	bool 		hidden;
	int		growFactor;

public:
	pkmCard( SDL_Renderer* renderer, const char* path );
	~pkmCard( void );

	void Render( void ) override;
	void Update( void ) override;

	bool MouseHoverEnter( const SDL_Event& e ) override;
	bool MouseHoverLeave( const SDL_Event& e ) override;

	void SetTexture( const char* path );
	void Hide( void );
	void Show( void );
};
