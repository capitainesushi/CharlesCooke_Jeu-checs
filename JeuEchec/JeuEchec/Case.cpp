#include "Case.h"
#include "Piece.h"



Case::Case(int x, int y, Piece* apiece)
{
	rect = { x,  y, 125, 125 };
	piece = apiece;
}


Case::~Case()
{
}

void Case::Render(SDL_Surface* gScreenSurface)
{
	if (piece != nullptr)
	{
		piece->Render(gScreenSurface, &rect);
	}
	
}
