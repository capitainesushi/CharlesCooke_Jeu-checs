#include "Queen.h"



Queen::Queen(bool IsBlack)
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
