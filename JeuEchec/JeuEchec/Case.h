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

	SDL_Rect* GetRect()
	{
		return &rect;
	}

	void Reset()
	{
		rect.x = m_X;
		rect.y = m_Y;
	}

private:
	SDL_Rect rect;
	int m_X;
	int m_Y;
	
};

