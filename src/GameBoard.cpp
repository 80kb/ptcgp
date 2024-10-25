#include "GameBoard.hpp"
#include "engine/obj/BoardSpace.hpp"
#include "engine/ui/Label.hpp"

pkmGameBoard::pkmGameBoard( SDL_Renderer* renderer ) {
	this->renderer 	= renderer;
	p1BenchSize	= 5;
	p2BenchSize	= 5;

	InitP1Active();
	InitP2Active();
	InitP1Bench();
	InitP2Bench();
	InitLostZone();
	InitStadium();
	InitP1Discard();
	InitP2Discard();
}

pkmGameBoard::~pkmGameBoard( void ) {
	for ( size_t i = 0; i < objects.size(); i++ ) {
		delete objects[i];
	}
}

void pkmGameBoard::InitP2Active( void ) {
	pkmLabel* label = new pkmLabel( renderer );
	label->SetText( "P2 Active" );
	label->SetSize( 75, 18 );
	label->SetPosition( 400, 25 );
	objects.push_back( label );

	pkmBoardSpace* activeSpace = new pkmBoardSpace( renderer );
	activeSpace->SetPosition( 400, 50 );
	activeSpace->SetSize( 200, 300 );
	objects.push_back( activeSpace );
}

void pkmGameBoard::InitP1Active( void ) {
	pkmLabel* label = new pkmLabel( renderer );
	label->SetText( "P1 Active" );
	label->SetSize( 75, 18 );
	label->SetPosition( 400, 475 );
	objects.push_back( label );

	pkmBoardSpace* activeSpace = new pkmBoardSpace( renderer );
	activeSpace->SetPosition( 400, 500 );
	activeSpace->SetSize( 200, 300 );
	objects.push_back( activeSpace );
}

void pkmGameBoard::InitP2Bench( void ) {
	int startPoint = 610;

	pkmLabel* label = new pkmLabel( renderer );
	label->SetText( "P2 Bench" );
	label->SetSize( 70, 18 );
	label->SetPosition( startPoint, 25 );
	objects.push_back( label );

	for ( int i = 0; i < p2BenchSize; i++ ) {
		pkmBoardSpace* benchSpace = new pkmBoardSpace( renderer );
		benchSpace->SetPosition( startPoint + (i * 110), 50 );
		benchSpace->SetSize( 110, 165 );
		objects.push_back( benchSpace );
	}
}

void pkmGameBoard::InitP1Bench( void ) {
	int startPoint = 610;

	pkmLabel* label = new pkmLabel( renderer );
	label->SetText( "P1 Bench" );
	label->SetSize( 70, 18 );
	label->SetPosition( startPoint, 610 );
	objects.push_back( label );

	for ( int i = 0; i < p1BenchSize; i++ ) {
		pkmBoardSpace* benchSpace = new pkmBoardSpace( renderer );
		benchSpace->SetPosition( startPoint + (i * 110), 635 );
		benchSpace->SetSize( 110, 165 );
		objects.push_back( benchSpace );
	}
}

void pkmGameBoard::InitLostZone( void ) {
	pkmLabel* label = new pkmLabel( renderer );
	label->SetText( "Lost Zone" );
	label->SetSize( 75, 18 );
	label->SetPosition( 730, 285 );
	objects.push_back( label );

	pkmBoardSpace* lostSpace = new pkmBoardSpace( renderer );
	lostSpace->SetPosition( 730, 310 );
	lostSpace->SetSize( 150, 225 );
	objects.push_back( lostSpace );
}

void pkmGameBoard::InitStadium( void ) {
	pkmLabel* label = new pkmLabel( renderer );
	label->SetText( "Stadium" );
	label->SetSize( 70, 18 );
	label->SetPosition( 890, 285 );
	objects.push_back( label );

	pkmBoardSpace* stadiumSpace = new pkmBoardSpace( renderer );
	stadiumSpace->SetPosition( 890, 310 );
	stadiumSpace->SetSize( 150, 225 );
	objects.push_back( stadiumSpace );
}

void pkmGameBoard::InitP1Discard( void ) {
	int startPoint = 620 + (p1BenchSize * 110);

	pkmLabel* label = new pkmLabel( renderer );
	label->SetText( "P1 Discard" );
	label->SetSize( 75, 18 );
	label->SetPosition( startPoint, 610 );
	objects.push_back( label );

	pkmBoardSpace* benchSpace = new pkmBoardSpace( renderer );
	benchSpace->SetPosition( startPoint, 635 );
	benchSpace->SetSize( 110, 165 );
	objects.push_back( benchSpace );
}

void pkmGameBoard::InitP2Discard( void ) {
	int startPoint = 620 + (p2BenchSize * 110);

	pkmLabel* label = new pkmLabel( renderer );
	label->SetText( "P2 Discard" );
	label->SetSize( 75, 18 );
	label->SetPosition( startPoint, 25 );
	objects.push_back( label );

	pkmBoardSpace* benchSpace = new pkmBoardSpace( renderer );
	benchSpace->SetPosition( startPoint, 50 );
	benchSpace->SetSize( 110, 165 );
	objects.push_back( benchSpace );
}

int pkmGameBoard::GetSize( void ) const {
	return objects.size();
}

pkmGameObject* pkmGameBoard::GetObject( const int index ) const {
	return objects[ index ];
}
