#include "Queen.h"



Queen::Queen(bool IsBlack)
	: Piece(IsBlack)
{
	if (IsBlack)
	{
		texture = IMG_Load("Images/chess/QueenN.png");
	}
	else
	{
		texture = IMG_Load("Images/chess/Queen.png");
	}
}


Queen::~Queen()
{
}

//std::list<std::vector<int>> Queen::GetAvailableMove(const SDL_Rect* a_Rect)

