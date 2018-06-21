#include "King.h"



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

//std::list<std::vector<int>> King::GetAvailableMove(const SDL_Rect* a_Rect)

