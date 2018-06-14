#include "Fou.h"



Fou::Fou(bool IsBlack)
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
