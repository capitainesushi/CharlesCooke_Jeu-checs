#pragma once
#include <SDL.h>

class Piece;

class Case
{
public:
	Case(int x, int y, Piece* piece = nullptr);
	~Case();

	void Render(SDL_Surface* gScreenSurface);
	Piece* piece = nullptr;

private:
	SDL_Rect rect;
	
};

