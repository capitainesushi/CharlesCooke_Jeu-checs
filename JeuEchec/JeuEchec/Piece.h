#pragma once
#include <SDL.h>
#include <SDL_image.h>
class Piece
{
public:
	Piece();
	~Piece();

	void Render(SDL_Surface* gScreenSurface, SDL_Rect* rect);
	
	

protected:
SDL_Surface* texture = NULL;

private:	
};

