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

//std::list<std::vector<int>> Fou::GetAvailableMove(const SDL_Rect* a_Rect)
