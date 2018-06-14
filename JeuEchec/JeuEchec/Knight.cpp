#include "Knight.h"



Knight::Knight(bool IsBlack)
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
