#include "King.h"
#include <iostream>



King::King(bool IsBlack)
	: Piece(IsBlack)
{
	if (IsBlack)
	{
		texture = IMG_Load("Images/chess/KingN.png");
	}
	else
	{
		texture = IMG_Load("Images/chess/King.png");
	}
}


King::~King()
{
}

std::vector<std::vector<int>> King::GetAvailableMove(const SDL_Rect* a_Rect, const std::vector<std::vector<Case*>> cases)
{
	std::vector<std::vector<int>> movesAvailables = std::vector<std::vector<int>>();

	int i = a_Rect->y / 125;
	int j = a_Rect->x / 125;


	// Haut-Droite
	if (i - 1 >= 0 && j + 1 < 8 && (cases[i - 1][j + 1]->piece == nullptr || cases[i - 1][j + 1]->piece->IsWhite() != IsWhite()))
	{
		movesAvailables.push_back(std::vector<int>({ i - 1, j + 1 }));			
	}
	// Bas-Droite
	if (i + 1 < 8 && j + 1 < 8 && (cases[i + 1][j + 1]->piece == nullptr || cases[i + 1][j + 1]->piece->IsWhite() != IsWhite()))
	{
		movesAvailables.push_back(std::vector<int>({ i + 1, j + 1 }));
	}


	// Bas-Gauche
	if (i + 1 < 8 && j - 1 >= 0 && (cases[i + 1][j - 1]->piece == nullptr || cases[i + 1][j - 1]->piece->IsWhite() != IsWhite()))
	{
		movesAvailables.push_back(std::vector<int>({ i + 1, j - 1 }));
	}


	// Haut-Gauche
	if (i - 1 >= 0 && j - 1 >= 0 && (cases[i - 1][j - 1]->piece == nullptr || cases[i - 1][j - 1]->piece->IsWhite() != IsWhite()))
	{
		movesAvailables.push_back(std::vector<int>({ i - 1, j - 1 }));
	}


	// Haut
	if (i - 1 >= 0 && (cases[i - 1][j]->piece == nullptr || cases[i - 1][j]->piece->IsWhite() != IsWhite()))
	{
		movesAvailables.push_back(std::vector<int>({ i - 1, j}));
	}

	// Droite
	if (j + 1 < 8 && (cases[i][j + 1]->piece == nullptr || cases[i][j + 1]->piece->IsWhite() != IsWhite()))
	{
		movesAvailables.push_back(std::vector<int>({ i, j + 1 }));
	}


	// Bas
	if (i + 1 < 8 && (cases[i + 1][j]->piece == nullptr || cases[i + 1][j]->piece->IsWhite() != IsWhite()))
	{
		movesAvailables.push_back(std::vector<int>({ i + 1, j }));
	}

	// Gauche
	if (j - 1 >= 0 && (cases[i][j - 1]->piece == nullptr || cases[i][j - 1]->piece->IsWhite() != IsWhite()))
	{
		movesAvailables.push_back(std::vector<int>({ i, j - 1 }));
	}





	return movesAvailables;
}


