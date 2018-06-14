#include "Piece.h"



Piece::Piece()
{	
}


Piece::~Piece()
{
	SDL_FreeSurface(texture);
	texture = NULL;
}

void Piece::Render(SDL_Surface* gScreenSurface, SDL_Rect* rect)
{
	SDL_BlitSurface(texture, NULL, gScreenSurface, rect);
}