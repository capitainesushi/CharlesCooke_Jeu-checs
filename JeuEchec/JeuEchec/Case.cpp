#include "Case.h"
#include "Piece.h"



Case::Case(int x, int y, Piece* apiece)
{
	m_X = x;
	m_Y = y;

	rect = { m_X,  m_Y, 125, 125 };
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
