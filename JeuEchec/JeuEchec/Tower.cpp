#include "Tower.h"



Tower::Tower(bool IsBlack)
	: Piece(IsBlack)
{
	if (IsBlack)
	{
		texture = IMG_Load("Images/chess/TowerN.png");
	}
	else
	{
		texture = IMG_Load("Images/chess/Tower.png");
	}
}
	


Tower::~Tower()
{
}




std::vector<std::vector<int>> Tower::GetAvailableMove(const SDL_Rect* a_Rect, const std::vector<std::vector<Case*>> cases)
{
	std::vector<std::vector<int>> movesAvailables = std::vector<std::vector<int>>();	
	
	int i = a_Rect->y / 125;
	int j = a_Rect->x / 125;		

	bool checkUp = true;
	bool checkDown = true;
	bool checkLeft = true;
	bool checkRight = true;

	
	for (int q = 1; q <= 8; q++)
	{
		// Vers le bas
		if (checkDown && i + q < 8 && cases[i + q][j]->piece == nullptr)
		{
			movesAvailables.push_back(std::vector<int>({ i + q, j }));
		}		
		else
		{
			if (checkDown && i + q < 8 && cases[i + q][j]->piece != nullptr && cases[i + q][j]->piece->IsWhite() != IsWhite())
			{
				movesAvailables.push_back(std::vector<int>({ i + q, j }));
			}
			checkDown = false;

		}

		// Vers la droite
		if (checkRight && j + q < 8 && cases[i][j + q]->piece == nullptr)
		{
			movesAvailables.push_back(std::vector<int>({ i, j + q }));
		}
		else
		{
			if (checkRight && j + q < 8 && cases[i][j + q]->piece != nullptr && cases[i][j + q]->piece->IsWhite() != IsWhite())
			{
				movesAvailables.push_back(std::vector<int>({ i, j + q}));
			}
			checkRight = false;
		}

		// Vers le haut
		if (checkUp && i - q >= 0 && cases[i - q][j]->piece == nullptr)
		{
			movesAvailables.push_back(std::vector<int>({ i - q, j }));
		}
		else
		{
			if (checkUp && i - q >= 0 && cases[i - q][j]->piece != nullptr && cases[i - q][j]->piece->IsWhite() != IsWhite())
			{
				movesAvailables.push_back(std::vector<int>({ i - q, j }));
			}
			checkUp = false;
		}

		// Vers la gauche
		if (checkLeft && j - q >= 0 && cases[i][j - q]->piece == nullptr)
		{
			movesAvailables.push_back(std::vector<int>({ i, j - q }));
		}
		else
		{
			if (checkLeft && j - q >= 0 && cases[i][j - q]->piece != nullptr && cases[i][j - q]->piece->IsWhite() != IsWhite())
			{
				movesAvailables.push_back(std::vector<int>({ i, j - q }));
			}
			checkLeft = false;
		}

		// Si aucun mouvement possible, break du for
		if (checkUp && checkDown && checkLeft && checkRight) 
		{
			break;
		}
	}	

	return movesAvailables;
}
