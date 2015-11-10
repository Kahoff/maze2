#include <conio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h> 
#include <math.h>
#include "map.h"
using namespace std;



int winCheck( char map [][4], char display [][4], int player [] )
{
	if ( map[player[0]][player[1]] == 'w' )
	{
		system("CLS");
		refreshMap( map, display, player );
		for( int i = 0; i < 4; i++)
		{
			for( int j = 0; j < 4; j++)
			{
				cout << display[i][j] << " ";
			}
			cout << endl;
		}
		cout << "You win!\n";
		return 1;
	}
	return 0;
}

void inputLoop()
{
	int key_code;
	char map [4][4];
	char display [4][4];
	int player [2];
	player[0] = 0;
	player[1] = 0;
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
	//string dataEntered = "";
	//string displayData = ">";
	double lastFrame = fmod( double( clock() ), double( CLOCKS_PER_SEC ) );
	double currentFrame;
	double frameRate = 12.0;
	system("CLS");
	while(1)
	{
		currentFrame = double(clock());
		currentFrame -= fmod( currentFrame, ( double( CLOCKS_PER_SEC ) / frameRate )  );
		if (currentFrame > lastFrame )
		{
			lastFrame = currentFrame;
			system("CLS");
			refreshMap( map, display, player );
			for( int i = 0; i < 4; i++)
			{
				for( int j = 0; j < 4; j++)
				{
					cout << display[i][j] << " ";
				}
				cout << endl;
			}
			//cout << dataEntered;
		}

		if ( kbhit() )
		{
			key_code = getch();
			if ( key_code == 0x1B )
			{
				cout << endl;
				return;
			}
			else if ( key_code == 224 )
			{
				key_code = getch();
				if (  key_code == 72 )
				{
					//up
					if (player[0] > 0)
					{
						if ( map[player[0] - 1 ][player[1]] != 'X' )
						{
							player[0]--;
							if (winCheck( map, display, player ))
							{
								return;
							}
						}
						
					}
				}
				else if (  key_code == 75 )
				{
					//left
					if (player[1] > 0)
					{
						if ( map[player[0]][player[1] - 1 ] != 'X' )
						{
							player[1]--;
							if (winCheck( map, display, player ))
							{
								return;
							}
						}
					}
				}
				else if (  key_code == 77 )
				{
					if (player[1] < 4 - 1 )
					{
						if ( map[player[0]][player[1] + 1 ] != 'X' )
						{
							player[1]++;
							if (winCheck( map, display, player ))
							{
								return;
							}
						}
					}
				}
				else if (  key_code == 80 )
				{
					if (player[0] < 4 - 1 )
					{
						if ( map[player[0] + 1 ][player[1]] != 'X' )
						{
							player[0]++;
							if (winCheck( map, display, player ))
							{
								return;
							}
						}
					}
				}
				//cout << key_code << endl;
			}
			key_code = 0;
			

		}

	}

	return;

}