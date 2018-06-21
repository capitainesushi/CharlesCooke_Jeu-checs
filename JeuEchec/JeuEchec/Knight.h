#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(bool IsBlack);
	~Knight();

	//virtual std::list<std::vector<int>> GetAvailableMove(const SDL_Rect* a_Rect);
};

