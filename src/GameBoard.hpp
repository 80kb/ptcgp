#pragma once

#include <vector>
#include "engine/GameObject.hpp"
#include "engine/obj/BoardSpace.hpp"

class pkmGameBoard {
	SDL_Renderer*			renderer;
	std::vector<pkmGameObject*> 	objects;
	std::vector<pkmBoardSpace*>	boardSpaces;

	int				p1BenchSize;
	int				p2BenchSize;

public:
	pkmGameBoard( SDL_Renderer* renderer );
	~pkmGameBoard( void );

	void 		InitP1Active( void );
	void 		InitP2Active( void );
	void 		InitP1Bench( void );
	void 		InitP2Bench( void );
	void		InitLostZone( void );
	void		InitStadium( void );
	void		InitP1Discard( void );
	void		InitP2Discard( void );

	int		GetObjectCount( void ) const;
	int		GetSpaceCount( void ) const;
	pkmGameObject*	GetObject( const int index ) const;
	pkmBoardSpace*	GetSpace( const int index ) const;
};
