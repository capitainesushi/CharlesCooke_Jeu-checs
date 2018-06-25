#include "Board.h"
#include <SDL_image.h>
#include "Case.h"
#include "King.h"
#include "Queen.h"
#include "Fou.h"
#include "Knight.h"
#include "Tower.h"
#include "Pion.h"
#include "Piece.h"

Board::Board()
{
	//Load PNG surface
	ChessBoard = IMG_Load("Images/chess/ChessBoard.jpg");	


	// Affiche les pièces à l'endroit approprié. Le for permet 
	for (int i = 0; i < 8; i++)
	{
		cases.push_back(vector<Case*>());
		for (int j = 0; j < 8; j++)
		{
		

			if (i == 0)
			{
				if (j == 0 || j == 7)
				{
					cases[i].push_back(new Case(j * 125, i * 125, new Tower(true)));
				}

				else if (j == 1 || j == 6)
				{
					cases[i].push_back(new Case(j * 125, i * 125, new Knight(true)));
				}

				else if (j == 2 || j == 5)
				{
					cases[i].push_back(new Case(j * 125, i * 125, new Fou(true)));
				}

				else if (j == 3)
				{					
					cases[i].push_back(new Case(j * 125, i * 125, new Queen(true)));
				}

				else if (j == 4)
				{					
					cases[i].push_back(new Case(j * 125, i * 125, new King(true)));
				}			

			}
			
			else if (i == 1)
			{
				cases[i].push_back(new Case(j * 125, i * 125, new Pion(true)));
			}

			else if (i == 6)
			{
				cases[i].push_back(new Case(j * 125, i * 125, new Pion(false)));
			}

			else if (i == 7)
			{
				if (j == 0 || j == 7)
				{
					cases[i].push_back(new Case(j * 125, i * 125, new Tower(false)));
				}

				else if (j == 1 || j == 6)
				{
					cases[i].push_back(new Case(j * 125, i * 125, new Knight(false)));
				}

				else if (j == 2 || j == 5)
				{
					cases[i].push_back(new Case(j * 125, i * 125, new Fou(false)));
				}

				else if (j == 3)
				{
					cases[i].push_back(new Case(j * 125, i * 125, new Queen(false)));
				}

				else if (j == 4)
				{								
					cases[i].push_back(new Case(j * 125, i * 125, new King(false)));
				}

			}

			else
			{
				cases[i].push_back(new Case(j * 125, i * 125));
			}

		}
	}
}


Board::~Board()
{
	//Free loaded image
	SDL_FreeSurface(ChessBoard);
	ChessBoard = NULL;
}

void Board::Render(SDL_Surface* gScreenSurface)
{
	SDL_BlitSurface(ChessBoard, NULL, gScreenSurface, NULL);

	for (int i = 0; i < 8; i++)
	{		
		for (int j = 0; j < 8; j++)
		{
			cases[i][j]->Render(gScreenSurface);
		}
	}
}
