#include "Pion.h"

Pion::Pion(bool IsBlack)
{
	if (IsBlack)
	{
		texture = IMG_Load("Images/chess/PionN.png");
	}
	else
	{
		texture = IMG_Load("Images/chess/Pion.png");

	}
}


Pion::~Pion()
{
}
