#include "map.h"

Map::Map( )
{
	char map [4][4];
	//map = *newMap;
	for( int i = 0; i < 4; i++)
	{
		for( int j = 0; j < 4; j++)
		{
			map[i][j] = '0';
		}
	}
	map[0][1] = 'X';
	map[1][1] = 'X';
	map[2][1] = 'X';
	map[2][2] = 'X';
	map[0][3] = 'X';
	map[0][2] = 'w';
}

int Map::checkMove( int charX, int charY )
{
	return 0;
}

void Map::refreshMap( int charX, int charY )
{

}

void Map::printMap()
{

}

int Map::checkVictory( int charX, int charY )
{
	return 0;
}

void refreshMap( char map [][4] , char display [][4] , int playerPos [] )
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ( i == playerPos[0] && j == playerPos[1])
			{
				display[i][j] = '*';
			}
			else
			{
				display[i][j] = map[i][j];
			}

		}

	}

}
