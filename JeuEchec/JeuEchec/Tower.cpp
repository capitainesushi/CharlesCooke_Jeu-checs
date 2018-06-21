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

std::list<std::vector<int>> Tower::GetAvailableMove(const SDL_Rect* a_Rect)
{
	std::cout << "Tower";

	std::list<std::vector<int>> movesAvailables = std::list<std::vector<int>>();	
	
	int i = a_Rect->x / 125;
	int j = a_Rect->y / 125;		
	
	movesAvailables.push_back(std::vector<int>({ i, j - 7 }));

	movesAvailables.push_back(std::vector<int>({ i - 7, j }));
	
	return movesAvailables;
}

