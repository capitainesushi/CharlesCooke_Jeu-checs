#include "King.h"



King::King(bool IsBlack)
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
