#include "Pion.h"
#include <iostream>

Pion::Pion(bool IsBlack)
	: Piece(IsBlack)
{
	if (IsBlack)
	{
		texture = IMG_Load("Images/chess/PionN.png");
	}
	else
	{
		texture = IMG_Load("Images/chess/Pion.png");

	}
}


Pion::~Pion()
{
}

std::list<std::vector<int>> Pion::GetAvailableMove(const SDL_Rect* a_Rect)
{

	std::cout << "Pion";

	std::list<std::vector<int>> movesAvailables = std::list<std::vector<int>>();
	if (IsWhite()) 
	{
		int i = a_Rect->x / 125;
		int j = a_Rect->y / 125;
		
		movesAvailables.push_back(std::vector<int>({ i, j - 1 }));
		if (j == 6) 
		{
			movesAvailables.push_back(std::vector<int>({ i, j - 2 }));
		}
	} 
	else
	{
		int i = a_Rect->x / 125;
		int j = a_Rect->y / 125;

		movesAvailables.push_back(std::vector<int>({ i, j + 1 }));
		if (j == 1)
		{
			movesAvailables.push_back(std::vector<int>({ i, j + 2 }));
		}
	}
	return movesAvailables;
}