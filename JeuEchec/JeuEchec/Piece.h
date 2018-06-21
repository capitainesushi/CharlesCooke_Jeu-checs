#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <list>
#include <vector>
#include <iostream>

class Piece
{
public:
	Piece(bool IsBlack);
	~Piece();

	void Render(SDL_Surface* gScreenSurface, SDL_Rect* rect);

	bool IsWhite()
	{
		return !m_IsBlack;
	}

	virtual std::list<std::vector<int>> GetAvailableMove(const SDL_Rect* a_Rect)
	{
		std::cout << "Piece" << std::endl;
		return std::list<std::vector<int>>();
	}
	
	

protected:
SDL_Surface* texture = NULL;

bool m_IsBlack;

private:	
};

