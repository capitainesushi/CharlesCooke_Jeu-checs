#include "Pion.h"
#include <iostream>
#include <vector>

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


std::vector<std::vector<int>> Pion::GetAvailableMove(const SDL_Rect* a_Rect, const std::vector<std::vector<Case*>> cases)
{
	std::vector<std::vector<int>> movesAvailables = std::vector<std::vector<int>>();

	if (IsWhite()) 
	{
		int i = a_Rect->y / 125;
		int j = a_Rect->x / 125;
		
		if (i - 1 >= 0 && cases[i - 1][j]->piece == nullptr)
		{
			movesAvailables.push_back(std::vector<int>({ i - 1, j }));
		}

		if (i == 6 && cases[i - 2][j]->piece == nullptr)
		{
			movesAvailables.push_back(std::vector<int>({ i - 2, j }));
		}

		if (j + 1 < 8 && i - 1 >= 0 && cases[i - 1][j + 1]->piece != nullptr && cases[i - 1][j + 1]->piece->IsWhite() != IsWhite())
		{
			movesAvailables.push_back(std::vector<int>({ i - 1, j + 1 }));
		}
		if (j - 1 >= 0 && i - 1 >= 0 && cases[i - 1][j - 1]->piece != nullptr && cases[i - 1][j - 1]->piece->IsWhite() != IsWhite())
		{
			movesAvailables.push_back(std::vector<int>({ i - 1, j - 1 }));
		}
	} 
	else
	{
		int i = a_Rect->y / 125;
		int j = a_Rect->x / 125;

		if ( i + 1 < 8  && cases[i + 1][j]->piece == nullptr)
		{
			movesAvailables.push_back(std::vector<int>({ i + 1, j}));
		}		

		if (i == 1 && cases[i + 2][j]->piece == nullptr)
		{
			movesAvailables.push_back(std::vector<int>({ i + 2, j }));
		}

		if (j + 1 < 8 && i + 1 < 8 && cases[i + 1][j + 1]->piece != nullptr && cases[i + 1][j + 1]->piece->IsWhite() != IsWhite())
		{
			movesAvailables.push_back(std::vector<int>({ i + 1, j + 1 }));
		}
		if (j - 1 >= 0 && i + 1 < 8 && cases[i + 1][j - 1]->piece != nullptr && cases[i + 1][j - 1]->piece->IsWhite() != IsWhite())
		{
			movesAvailables.push_back(std::vector<int>({ i + 1, j - 1 }));
		}
	}
	return movesAvailables;
}