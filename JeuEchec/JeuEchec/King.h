#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	King(bool IsBlack);
	~King();

	//virtual std::list<std::vector<int>> GetAvailableMove(const SDL_Rect* a_Rect);
};

