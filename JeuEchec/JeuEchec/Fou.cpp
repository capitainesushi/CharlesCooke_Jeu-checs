#include "Fou.h"



Fou::Fou(bool IsBlack)
	: Piece(IsBlack)
{
	if (IsBlack)
	{
		texture = IMG_Load("Images/chess/FouN.png");
	}
	else
	{
		texture = IMG_Load("Images/chess/Fou.png");
	}
}

Fou::~Fou()
{
}


std::vector<std::vector<int>> Fou::GetAvailableMove(const SDL_Rect* a_Rect, const std::vector<std::vector<Case*>> cases)
{
	std::vector<std::vector<int>> movesAvailables = std::vector<std::vector<int>>();

	int i = a_Rect->y / 125;
	int j = a_Rect->x / 125;

	bool UpRight = true;
	bool UpLeft = true;
	bool DownRight = true;
	bool DownLeft = true;


	for (int q = 1; q <= 8; q++)
	{
		// Vers Diagonale Haut-Droite
		if (UpRight && i - q >= 0 && j + q < 8 && cases[i - q][j + q]->piece == nullptr)
		{
			movesAvailables.push_back(std::vector<int>({ i - q, j + q }));
		}
		else
		{
			if (UpRight && i - q >= 0 && j + q < 8 && cases[i - q][j + q]->piece != nullptr && cases[i - q][j + q]->piece->IsWhite() != IsWhite())
			{
				movesAvailables.push_back(std::vector<int>({ i - q, j + q }));
			}
			UpRight = false;
		}

		// Vers Diagonale Haut-Gauche
		if (UpLeft && i - q >= 0 && j - q >= 0 && cases[i - q][j - q]->piece == nullptr)
		{
			movesAvailables.push_back(std::vector<int>({ i - q, j - q }));
		}
		else
		{
			if (UpLeft && i - q >= 0 && j - q >= 0 && cases[i - q][j - q]->piece != nullptr && cases[i - q][j - q]->piece->IsWhite() != IsWhite())
			{
				movesAvailables.push_back(std::vector<int>({ i - q, j - q }));
			}
			
			UpLeft = false;
		}

		// Vers Diagonale Bas-Droite
		if (DownRight && i + q < 8 && j + q < 8 && cases[i + q][j + q]->piece == nullptr)
		{
			movesAvailables.push_back(std::vector<int>({ i + q, j + q }));
		}
		else
		{
			if (DownRight && i + q < 8 && j + q < 8 && cases[i + q][j + q]->piece != nullptr && cases[i + q][j + q]->piece->IsWhite() != IsWhite())
			{
				movesAvailables.push_back(std::vector<int>({ i + q, j + q }));
			}
			
			DownRight = false;
		}

		// Vers Diagonale Bas-Gauche
		if (DownLeft && i + q < 8 && j - q >= 0 && cases[i + q][j - q]->piece == nullptr)
		{
			movesAvailables.push_back(std::vector<int>({ i + q, j - q }));
		}
		else
		{
			if (DownLeft && i + q < 8 && j - q >= 0 && cases[i + q][j - q]->piece != nullptr && cases[i + q][j - q]->piece->IsWhite() != IsWhite())
			{
				movesAvailables.push_back(std::vector<int>({ i + q, j - q }));
			}
			
			DownLeft = false;
		}

		


	}	
	return movesAvailables;
}
