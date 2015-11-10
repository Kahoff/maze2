#ifndef __map_INCLUDED__
#define __map_INCLUDED__

using namespace std;

class Map{
	char * map;
	char * displayMap;
public:
	Map( );
	int checkMove( int charX, int charY );
	void refreshMap( int charX, int charY );
	void printMap();
	int checkVictory( int charX, int charY );
};

void refreshMap( char map [][4] , char display [][4] , int playerPos [] );

#endif
