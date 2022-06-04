#include "game_of_life.h"
#include <iostream>
#include <ctime>

using namespace std; 
 


//private 
bool game_of_life::random_value()
{
	bool res = false;
	int r =rand() % (100-1 + 1) + 1;
	if (r < 25)
	{
		res = true; 
	}
	return res; 
}


//I don't understand what to do in this function 
/*bool game_of_life::cell_taken(int i, int j)
{
	
}*/


//public 
game_of_life::game_of_life()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			_generation[i][j] = random_value();
		}
	}
}



void game_of_life::next_generation()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			int cpt_alive = 0; 
			for (int k = -1; k < 2; k++)
			{
				for (int l = -1; l < 2; l++)
				{
					if (k != 0 && l != 0)
					{
						if (_generation[i + k][j + l])
							cpt_alive++; 
					}
				}
			}
			if (cpt_alive < 2)
			{
				_generation[i][j] = false;
			}
			else if (cpt_alive == 3)
			{
				_generation[i][j] = true;
			}
			else if (cpt_alive > 3)
			{
				_generation[i][j] = false;
			}
		}
	}
	
}

void game_of_life::draw()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (_generation[i][j] )
			{
				cout << "*";
			}
			else
				cout << "-";
		}
		cout << endl; 
	}
}