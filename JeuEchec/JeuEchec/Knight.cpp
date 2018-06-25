#include "Knight.h"
#include <iostream>



Knight::Knight(bool IsBlack)
	: Piece(IsBlack)
{
	if (IsBlack)
	{
		texture = IMG_Load("Images/chess/KnightN.png");
	}
	else
	{
		texture = IMG_Load("Images/chess/Knight.png");

	}
}


Knight::~Knight()
{
}


std::vector<std::vector<int>> Knight::GetAvailableMove(const SDL_Rect* a_Rect, const std::vector<std::vector<Case*>> cases)
{
	std::vector<std::vector<int>> movesAvailables = std::vector<std::vector<int>>();

	int i = a_Rect->y / 125;
	int j = a_Rect->x / 125;

	
	// 2 Haut 1 Droite
	if (i - 2 >= 0 && j + 1 < 8 && (cases[i - 2][j + 1]->piece == nullptr || cases[i - 2][j + 1]->piece->IsWhite() != IsWhite()))
	{		
		movesAvailables.push_back(std::vector<int>({ i - 2, j + 1 }));
	}
	

	// 1 Haut 2 Droite
	if (i - 1 >= 0 && j + 2 < 8 && (cases[i - 1][j + 2]->piece == nullptr || cases[i - 1][j + 2]->piece->IsWhite() != IsWhite()))
	{
		movesAvailables.push_back(std::vector<int>({ i - 1, j + 2 }));
	}
	

	// 1 Bas 2 Droite
	if (i + 1 < 8 && j + 2 < 8 && (cases[i + 1][j + 2]->piece == nullptr || cases[i + 1][j + 2]->piece->IsWhite() != IsWhite()))
	{
		movesAvailables.push_back(std::vector<int>({ i + 1, j + 2}));
	}
	

	// 2 Bas 1 Droite
	if (i + 2 < 8 && j + 1 < 8 && (cases[i + 2][j + 1]->piece == nullptr || cases[i + 2][j + 1]->piece->IsWhite() != IsWhite()))
	{
		movesAvailables.push_back(std::vector<int>({ i + 2, j + 1 }));
	}
	

	// 2 Bas 1 Gauche
	if (i + 2 < 8 && j - 1 >= 0 && (cases[i + 2][j - 1]->piece == nullptr || cases[i + 2][j - 1]->piece->IsWhite() != IsWhite()))
	{
		movesAvailables.push_back(std::vector<int>({ i + 2, j - 1 }));
	}
	
	// 1 Bas 2 Gauche3
	if (i + 1 < 8 && j - 2 >= 0 && (cases[i + 1][j - 2]->piece == nullptr || cases[i + 1][j - 2]->piece->IsWhite() != IsWhite()))
	{
		movesAvailables.push_back(std::vector<int>({ i + 1, j - 2 }));
	}
	

	// 1 Haut 2 Gauche
	if (i - 1 >= 0 && j - 2 >= 0 && (cases[i - 1][j - 2]->piece == nullptr || cases[i - 1][j - 2]->piece->IsWhite() != IsWhite()))
	{
		movesAvailables.push_back(std::vector<int>({ i - 1, j - 2}));
	}
	
	// 2 Haut 1 Gauche
	if (i - 2 >= 0 && j - 1 >= 0 && (cases[i - 2][j - 1]->piece == nullptr || cases[i - 2][j - 1]->piece->IsWhite() != IsWhite()))
	{
		movesAvailables.push_back(std::vector<int>({ i - 2, j - 1 }));
	}
		

		
	

	return movesAvailables;
}

