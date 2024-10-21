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

public:
	pkmCard( SDL_Renderer* renderer, const char* path );
	~pkmCard( void );

	void Render( void );
	void Update( void );
	void SetTexture( const char* path );
	void Hide( void );
	void Show( void );
};
