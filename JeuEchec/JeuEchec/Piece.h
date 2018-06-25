#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <list>
#include <vector>
#include <iostream>
#include "Case.h"
#include <string>

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

	
	virtual std::vector<std::vector<int>> GetAvailableMove(const SDL_Rect* a_Rect, const std::vector<std::vector<Case*>> cases)
	{
		std::cout << "Piece" << std::endl;
		return std::vector<std::vector<int>>();
	}

	virtual std::string GetPieceType() { return IsWhite() ? "Blanc" : "Noir"; }

	bool m_IsBlack;

	

protected:
SDL_Surface* texture = NULL;



private:	
};

