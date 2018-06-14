#include "Tower.h"



Tower::Tower(bool IsBlack)
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
