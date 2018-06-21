#include "Knight.h"



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

//std::list<std::vector<int>> Knight::GetAvailableMove(const SDL_Rect* a_Rect)

